const express = require("express")
const userRoute = require("./userController")
const recipieRoute = require("./recipeController")
const commentRoute = require("./commentController")

const router = express.Router()
router.use("/user", userRoute)
router.use("/recipe", recipieRoute)
router.use("/comment", commentRoute)

module.exports = router