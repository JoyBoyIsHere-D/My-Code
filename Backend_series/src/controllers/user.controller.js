import asyncHandler from "../utils/asynchandler.js"
import { ApiError } from "../utils/ApiError.js"
import { User } from "../models/user.model.js"
import { uploadOnCloudinary } from "../utils/cloudinary.js"
import { ApiResponse } from "../utils/ApiResponse.js"

const generateAccessAndRefreshTokens = async (userId) => {
    try {
        const user = User.findById(userId)
        const accessToken = user.generateAcessToken();
        const refreshToken = user.generateRefreshToken();

        user.refreshToken = refreshToken
        await user.save({ validateBeforeSave: false }) //To avoid resending all the details of the user

        return { accessToken, refreshToken }
    } catch (error) {
        throw new ApiError(500, "Error in token generation")
    }

}

const registerUser = asyncHandler(async (req, res) => {
    // get user details from frontend
    // validation - not empty
    // check if user already exists: username, email
    // check for images, check for avatar
    // upload them to cloudinary, avatar
    // create user object - create entry in db
    // remove password and refresh token field from response
    // check for user creation
    // return res

    //Get details from the body
    const { fullName, email, password, username } = req.body;

    //Validation
    if ([fullName, email, password, username].some((field) => field?.trim() === "")) {
        throw new ApiError(400, "All fields are required")
    }

    //Check if the user already exits
    const existedUser = await User.findOne({
        $or: [{ username }, { email }]
    })
    if (existedUser) {
        throw new ApiError(409, "User with the same email or username already exists")
    }

    //Check if Avatar exits
    const avatarLocalPath = req.files?.avatar[0]?.path

    let coverImageLocalPath;
    if (req.files && Array.isArray(req.files.coverImage) && req.files.coverImage.length > 0) {
        coverImageLocalPath = req.files.coverImage[0].path
    }
    if (!avatarLocalPath) {
        throw new ApiError(400, "Avatar is required")
    }

    //Upload on cloudinary
    const avatar = await uploadOnCloudinary(avatarLocalPath)
    const coverImage = await uploadOnCloudinary(coverImageLocalPath)

    if (!avatar) {
        throw new ApiError(400, "Avatar is required")
    }

    //Create an object and send it to DB
    const user = await User.create({
        fullName,
        avatar: avatar.url,
        coverImage: coverImage?.url || "",
        username: username.toLowerCase(),
        email,
        password

    })

    //Check if user was created and remove the Password and RefreshToken from the response
    const createdUser = await User.findById(user._id).select(
        "-password -refreshToken"
    )
    if (!createdUser) {
        throw new ApiError(500, "Something went wrong while registering the user")
    }

    return res.status(201).json(
        new ApiResponse(createdUser, 200, "User registered Succesfully")
    )
})

const loginUser = asyncHandler(async (req, res) => {
    const { username, email, password } = req.body

    if (!username || !email) {
        throw new ApiError(400, "Username or Email are required")
    }

    const user = await User.findOne({
        $or: [{ username }, { email }]
    })

    if (!user) {
        throw new ApiError(404, "User does not exist")
    }

    const isPasswordValid = await user.isPasswordValid(password)

    if (!isPasswordValid) {
        throw new ApiError(401, "Password incorrect")
    }

    const { accessToken, refreshToken } = await generateAccessAndRefreshTokens(user._id)
    //Another database query to get the new user with refresh Token
    const loggedInUser = User.findById(user._id).select("-password -refreshToken")

    //Send by cookies
    const options = {
        httpOnly: true, //Makes the cookies modifiable only by the server
        secure: true
    }

    return res.status(200).cookie("accessToken", accessToken, options)
        .cookie("refreshToken", refreshToken, options)
        .json(
            new ApiResponse(
                {
                    user: loggedInUser, accessToken, refreshToken
                },
                200,
                "User logged in succesfully"
            )
        )

})

const logoutUser = asyncHandler(async (req, res) => {
    await User.findByIdAndUpdate(req.user._id,
        {
            $set: {
                refreshToken: undefined
            }
        },
        {
            new: true //For new updated value
        }
    )

    const options = {
        httpOnly: true, //Makes the cookies modifiable only by the server
        secure: true
    }

    return res.status(200).clearCookie("accessToken", options).clearCookie("refreshToken", options)
    .json(
        new ApiResponse({},
            200,
            "User logged out successfully",
        )
    )
})



export { registerUser, loginUser, logoutUser }