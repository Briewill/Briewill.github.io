const mongoose = require('mongoose');
const { Schema } = mongoose;

const commentPostSchema = new Schema({
    post: {
        type: String,
        required: true
    },
    reply: {
        type: String,
        required: false
    }
})

const commentSchema = new Schema({
    recipeId: {
        type: mongoose.ObjectId,
    },
    userId: {
        type: mongoose.ObjectId,
    },
    comments: commentPostSchema,
    date: { type: Date, default: Date.now },
    stars: {
        type: Number,
        min: 1,
        max: 5
    }
});

const Comment = mongoose.model("Comment", commentSchema)
module.exports = Comment