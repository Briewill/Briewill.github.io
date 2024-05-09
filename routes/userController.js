require("dotenv").config()
const router = require("express").Router()
const { User } = require("../models")
const bcrypt = require("bcrypt")
const jwt = require("jsonwebtoken")

router.get('/', async (req, res) => {
  try {
    const user = await User.find()
    res.status(200).json({ data: user })
  } catch {
    res.status(500).json({ msg: "error registering" })
  }
})

router.post('/register', async (req, res) => {
  try {
    const { username, email, password } = req.body

    const hashedPass = await bcrypt.hash(password, 10)

    const newUser = await User.create({
      username,
      email,
      password: hashedPass
    })
    res.status(201).json({ msg: "user registered successfully", user: newUser })
  } catch {
    res.status(500).json({ msg: "error registering" })
  }

})

router.put('/', async (req, res) => {
  try {
    const { username, email, password } = req.body
  } catch {
    res.status(500).json({ msg: "error registering" })
  }
})

router.delete('/:userid', async (req, res) => {
  try {
    const { userid } = req.params
    const result = await User.findByIdAndDelete(userid)
    console.log("result", result)
    res.status(201).json({ msg: "successful deletion" })
  } catch {
    res.status(500).json({ msg: "error registering" })
  }
})

router.post('/login', async (req, res) => {
  try {
    const { username, password } = req.body
    const user = await User.findOne({ username: username })

    if (!user) {
      return res.status(401).json({ msg: "invalid username or password" })
    }

    const matchPasswd = await bcrypt.compare(password, user.password)

    if (!matchPasswd) {
      return res.status(401).json({ msg: "invalid username or password" })
    }

    const token = jwt.sign({ username: user.username, id: user._id }, process.env.JWT_SECRET)

    res.status(201).json({ token: token })
  } catch {
    res.status(500).json({ msg: "error registering" })
  }

})


module.exports = router