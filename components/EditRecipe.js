import React, { useState, useEffect, useContext } from 'react'
import { useParams } from 'react-router-dom'
import Form from 'react-bootstrap/Form';
import Button from 'react-bootstrap/Button';
import { RecipeContext } from './RecipeProvider';
import Recipe from '../features/Recipes';
import { useNavigate } from 'react-router-dom';



export default function EditRecipe() {
    const { recipeId } = useParams()
    const [recipeUpdate, setRecipeUpdate] = useState({})
    const navigate = useNavigate()

    useEffect(() => {
        fetch(`http://localhost:3001/api/recipe/${recipeId}`, {
            method: "GET",
            headers: {
                "content-type": "application/json",
                "accept": "application/json"
            },
        })
            .then((response) => {
                return response.json()
            })
            .then((result) => {
                console.log(result.data)
                setRecipeUpdate(result.data)
            })
    }, [])

    const handleInputChange = (index, event) => {
        const { name, value } = event.target;
        const updatedIngredients = [...recipeUpdate.ingredients];
        updatedIngredients[index][name] = value;
        setRecipeUpdate({ ...recipeUpdate, ingredients: updatedIngredients });
    };

    const handleInstructionChange = (index, event) => {
        const updatedInstructions = [...recipeUpdate.instructions];
        updatedInstructions[index] = event.target.value;
        setRecipeUpdate({ ...recipeUpdate, instructions: updatedInstructions });
    };


    const addIngredient = () => {
        setRecipeUpdate({
            ...recipeUpdate,
            ingredients: [...recipeUpdate.ingredients, { name: '', quantity: '' }]
        });
    };

    const removeIngredient = (index) => {
        const updatedIngredients = [...recipeUpdate.ingredients];
        updatedIngredients.splice(index, 1);
        setRecipeUpdate({ ...recipeUpdate, ingredients: updatedIngredients });
    };

    const addInstruction = () => {
        setRecipeUpdate({
            ...recipeUpdate,
            instructions: [...recipeUpdate.instructions, '']
        });
    };

    const removeInstruction = (index) => {
        const updatedInstructions = [...recipeUpdate.instructions];
        updatedInstructions.splice(index, 1);
        setRecipeUpdate({ ...recipeUpdate, instructions: updatedInstructions });
    };

    const handleSubmit = (event) => {
        event.preventDefault();
        console.log(recipeUpdate);
       
        fetch(`http://localhost:3001/api/recipe/editrecipes/${recipeId}`, {
            method: "PUT",
            headers: {
                "content-type": "application/json",
                "accept": "application/json"
            },
            body: JSON.stringify(recipeUpdate)
        })
            .then((response) => {
                return response.json()
            })
            .then((result) => {
                console.log(result)
                navigate("/recipe")
            })
        }

    return (
        <div className="container text-start">
            <Form onSubmit={handleSubmit}>
                <Form.Group className="mb-3" controlId="recipe.ControlInput1">
                    <Form.Label>Recipe Title</Form.Label>
                    <Form.Control type="text"
                        name="title"
                        value={recipeUpdate.title}
                        onChange={(e) => setRecipeUpdate({ ...recipeUpdate, title: e.target.value })}
                        placeholder="Recipe" />
                </Form.Group>
                <br />
                <>
                    Ingredients:
                    {recipeUpdate && Object.keys(recipeUpdate).length > 0 && recipeUpdate.ingredients.map((ingredient, index) => (
                        <React.Fragment key={index}>
                            <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
                                <Form.Label>Ingredient name</Form.Label>
                                <Form.Control type="text"
                                    name="name"
                                    value={ingredient.name}
                                    onChange={(e) => handleInputChange(index, e)}
                                    placeholder="Ingredient" />
                            </Form.Group>
                            <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
                                <Form.Label>Ingredient quantity</Form.Label>
                                <Form.Control type="text"
                                    name="quantity"
                                    value={ingredient.quantity}
                                    onChange={(e) => handleInputChange(index, e)}
                                    placeholder="Quantity" />
                            </Form.Group>
                            <Button variant="primary" type="button" onClick={() => removeIngredient(index)}>-</Button>
                        </React.Fragment>
                    ))}
                    <Button variant="primary" type="button" onClick={addIngredient}>+</Button>
                </>
                <br />
                <label>
                    Instructions:
                    {recipeUpdate && Object.keys(recipeUpdate).length > 0 && recipeUpdate.instructions.map((instruction, index) => (
                        <React.Fragment key={index}>
                            <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
                                <Form.Label>Instructions</Form.Label>
                                <Form.Control type="textarea"
                                    placeholder="Instruction"
                                    value={instruction}
                                    onChange={(e) => handleInstructionChange(index, e)}
                                />
                            </Form.Group>
                            <Button className='d-inline-block' variant="primary" type="button" onClick={() => removeInstruction(index)}>-</Button>
                        </React.Fragment>
                    ))}
                    <Button className='d-inline' variant="primary" type="button" onClick={addInstruction}>+</Button>
                </label>
                <br />
                <Button variant="primary" type="submit">Submit</Button>
            </Form>
        </div>
    )
}
