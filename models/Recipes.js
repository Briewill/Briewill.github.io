const mongoose = require('mongoose');
const { Schema } = mongoose;

const recipeSchema = new Schema({

    //similar to creating table in mysqli 
    authorId: {
        type: Schema.Types.ObjectId,
        ref: "User",
        required: true
    },
    title: {
        type: String,
        required: true
    },
    ingredients: [{
        name: {
            type: String,
            required: true
        },
        quantity: {
            type: String,
            required: true
        },

    }],
    instructions: [{
        type: String,
        required: true
    }]
});

const Recipe = mongoose.model("Recipe", recipeSchema)
module.exports = Recipe