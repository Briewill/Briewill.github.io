const { Comment } = require("../models")

const router = require("express").Router()

router.get('/comments/:recipeId/average-stars', async (req, res) => {
    try {
        const { recipeId } = req.params;

        const averageStars = await Comment.aggregate([
            { $match: { recipeId: recipeId } }, // Match comments for the specific recipeId
            {
                $group: {
                    _id: null,
                    averageStars: { $avg: '$stars' } // Calculate average stars for matching comments
                }
            }
        ]);

        if (averageStars.length > 0) {
            res.json({ averageStars: averageStars[0].averageStars });
        } else {
            res.json({ averageStars: 0 }); // Return 0 if no comments found for the recipe
        }
    } catch (err) {
        res.status(500).json({ message: err.message, stars: "check code" });
    }
});

router.get('/', async (req, res) => {
    try {
        const comments = await Comment.find()
        res.status(200).json({ data: comments })
    } catch {
        res.status(500).json({ msg: "error getting comment" })
    }
})

router.get('comment/:commentId', async (req, res) => {
    try {
        const { commentId } = req.params
        const comments = await Comment.findById(commentId)
        res.status(200).json({ data: comments })
    } catch {
        res.status(500).json({ msg: "error getting comment" })
    }
})

router.get('/:recipeId', async (req, res) => {
    try {
        const { recipeId } = req.params
        const comments = await Comment.find({ recipeId: recipeId })
        res.status(200).json({ data: comments })
    } catch {
        res.status(500).json({ msg: "error getting comment" })
    }
})



router.post('/createcomment/:userId/:recipeId', async (req, res) => {
    try {
        const { comments, stars } = req.body;
        const { userId, recipeId } = req.params

        const comment = await Comment.create({
            recipeId,
            userId,
            comments,
            stars
        })

        res.status(201).json({ data: comment })
    } catch {
        res.status(500).json({ msg: "error creating comment" })
    }

})

router.put('/', (req, res) => {
    try {

    } catch {
        res.status(500).json({ msg: "error registering" })
    }
})

router.delete('/', (req, res) => {
    try {

    } catch {
        res.status(500).json({ msg: "error registering" })
    }
})

module.exports = router