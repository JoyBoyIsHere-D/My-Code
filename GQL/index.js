import { ApolloServer } from "@apollo/server";
import { startStandaloneServer } from "@apollo/server/standalone";
import { typeDefs } from "./schema.js";
import db from "./_db.js";

const resolvers = {
    Query: {
        games() {
            return db.games;
        },
        authors() {
            return db.authors;
        },
        reviews() {
            return db.reviews;
        },
        review(parent, args, context){
            return db.reviews.find((review) => review.id === args.id)
        },
        author(parent, args, context){
            return db.authors.find((author) => author.id === args.id)
        },
        game(parent, args, context){
            return db.games.find((game) => game.id === args.id)
        }
    },
    Game: {
        review(parent){
            return db.reviews.filter((r)=> r.game_id === parent.id)
        }
    },
    Mutation: {
        addGame(parent, args){
            let game = {
                ...args.game,
                id: Math.floor(Math.random()*10000).toString()
            }
            db.games.push(game)
            return game
        },
        deleteGame(parent, args){
            db.games = db.games.filter((r)=> args.id !== r.id)
            return db.games;
        }
    }
    
}

const server = new ApolloServer({
    typeDefs,
    resolvers
})

const { url } = await startStandaloneServer(server, {
    listen: { port: 4000 }
})

console.log(`Server is running on port ${4000}`)