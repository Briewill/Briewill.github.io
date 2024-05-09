const { Recipe } = require("../models")
const express = require("express");
const router = express.Router()

router.get('/', async (req, res) => {
  try {
    const recipe = await Recipe.find()
    res.status(200).json({ data: recipe })
  } catch {
    res.status(500).json({ msg: "error getting recipe" })
  }
})

router.get('/:recipeId', async (req, res) => {
  try {
    const {recipeId } = req.params
    const recipe = await Recipe.findById(recipeId)
    res.status(200).json({ data: recipe })
  } catch {
    res.status(500).json({ msg: "error getting recipe" })
  }
})

router.post('/createrecipe/:authorId', async (req, res) => {
  try {
    const {title, ingredients, instructions} = req.body;
    const {authorId} = req.params

    const recipe = await Recipe.create({
      authorId,
      title,
      ingredients,
      instructions
    })

    res.status(201).json({data: recipe})
  } catch {
    res.status(500).json({ msg: "error creating recipe" })
  }
  
})

router.put('/editrecipes/:id', async (req, res) => {
  const recipeId = req.params.id;
  const { title, ingredients, instructions } = req.body;

  try {
    const updatedRecipe = await Recipe.findByIdAndUpdate(
      recipeId,
      { $set: { title, ingredients, instructions } },
      { new: true }
    );

    if (!updatedRecipe) {
      return res.status(404).json({ message: 'Recipe not found' });
    }

    res.status(200).json(updatedRecipe);
  } catch (err) {
    res.status(500).json({ message: 'Error updating recipe' });
  }
});

router.delete('/delete/:recipeid', (req, res) => {
  try {
    const {recipeId} = req.params
    Recipe.findByIdAndDelete(recipeId)
    res.status(201).json({msg: "successful deletion"})
  } catch {
    res.status(500).json({ msg: "error deleting" })
  }
})

module.exports = router

// const bearerHeader = req.headers['authorization'];
  
//   if (typeof bearerHeader !== 'undefined') {
//     const bearer = bearerHeader.split(' ');
//     const token = bearer[1];
//     req.token = token;
//     next();
//   } else {
//     res.sendStatus(403); // Forbidden if token is missing
//   }
