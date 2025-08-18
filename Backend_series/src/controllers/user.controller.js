import asyncHandler from "../utils/asynchandler.js"
import { ApiError } from "../utils/ApiError.js"
import { User } from "../models/user.model.js"
import { uploadOnCloudinary } from "../utils/cloudinary.js"
import { ApiResponse } from "../utils/ApiResponse.js"

const registerUser = asyncHandler(async (req, res) => {
    //Get details from the body
    const { fullName, email, password, username } = req.body;

    //Validation
    if ([fullName, email, password, username].some((field) => field?.trim === "")) {
        throw new ApiError(400, "All fields are required")
    }

    //Check if the user already exits
    const existedUser = User.findOne({
        $or: [{ username }, { email }]
    })
    if (existedUser) {
        throw new ApiError(409, "User with the same email or username already exists")
    }

    //Check if Avatar exits
    const avatarLocalPath = req.files?.avatar[0]?.path
    const coverImageLocalPath = req.files?.coverImage[0]?.path
    if (!avatarLocalPath) {
        throw new ApiError(400, "Avatar is required")
    }
    console.log(req.files)

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
        coverImage: coverImage?.url,
        username: username.toLowerCase(),
        email,
        password

    })

    //Check if user was created and remove the Password and RefreshToken from the response
    const createdUser = await User.findById(user._id).select(
        "-password -refreshToken"
    )
    if(!createdUser){
        throw new ApiError(500, "Something went wrong while registering the user")
    }

    return res.status(201).json(
        new ApiResponse(createdUser, 200,  "User registered Succesfully")
    )
})

export { registerUser }