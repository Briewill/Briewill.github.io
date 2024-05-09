import React, { useState, useContext, useEffect } from 'react';
import Form from 'react-bootstrap/Form';
import Button from 'react-bootstrap/Button';
import { RecipeContext } from './RecipeProvider';
import { jwtDecode } from "jwt-decode";
import Recipe from '../features/Recipes';
import { useNavigate } from 'react-router-dom';





const RecipeForm = () => {
    const navigate = useNavigate()
    const [isloggedin, setIsloggedin] = useContext(RecipeContext)
    const [recipe, setRecipe] = useState({
        title: '',
        ingredients: [{ name: '', quantity: '' }],
        instructions: [""]
    });

    const [decodedToken, setDecodedToken] = useState()

    useEffect(() => {
        const token = localStorage.getItem("token");
        console.log(localStorage.getItem("token"))
        setDecodedToken(jwtDecode(token));

    }, []);


    const handleInputChange = (index, event) => {
        const { name, value } = event.target;
        const updatedIngredients = [...recipe.ingredients];
        updatedIngredients[index][name] = value;
        setRecipe({ ...recipe, ingredients: updatedIngredients });
    };

    const handleInstructionChange = (index, event) => {
        const updatedInstructions = [...recipe.instructions];
        updatedInstructions[index] = event.target.value;
        setRecipe({ ...recipe, instructions: updatedInstructions });
    };


    const addIngredient = () => {
        setRecipe({
            ...recipe,
            ingredients: [...recipe.ingredients, { name: '', quantity: '' }]
        });
    };

    const removeIngredient = (index) => {
        const updatedIngredients = [...recipe.ingredients];
        updatedIngredients.splice(index, 1);
        setRecipe({ ...recipe, ingredients: updatedIngredients });
    };

    const addInstruction = () => {
        setRecipe({
            ...recipe,
            instructions: [...recipe.instructions, '']
        });
    };

    const removeInstruction = (index) => {
        const updatedInstructions = [...recipe.instructions];
        updatedInstructions.splice(index, 1);
        setRecipe({ ...recipe, instructions: updatedInstructions });
    };

    const handleSubmit = (event) => {
        event.preventDefault();
        console.log(recipe);

        fetch(`http://localhost:3001/api/recipe/createrecipe/${decodedToken.id}`, {
            method: "POST",
            headers: {
                "content-type": "application/json",
                "accept": "application/json"
            },
            body: JSON.stringify(recipe)
        })
            .then((response) => {
                return response.json()
            })
            .then((result) => {
                console.log(result)
                navigate("/recipe")
            })
    };

    return (
        <div className="recipe-container">
            <h3>Create Recipe </h3>
            <Form onSubmit={handleSubmit}>
                <Form.Group className="mb-3" controlId="recipe.ControlInput1">
                    <Form.Label>Recipe Title</Form.Label>
                    <Form.Control type="text"
                        name="title"
                        value={recipe.title}
                        onChange={(e) => setRecipe({ ...recipe, title: e.target.value })}
                        placeholder="Recipe" />
                </Form.Group>
                <br />
                <>
                    
                    {recipe.ingredients.map((ingredient, index) => (
                        <React.Fragment key={index}>
                            <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
                                <Form.Label>Ingredient name:</Form.Label>
                                <Form.Control type="text"
                                    name="name"
                                    value={ingredient.name}
                                    onChange={(e) => handleInputChange(index, e)}
                                    placeholder="Ingredient" />
                            </Form.Group>
                            <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
                                <Form.Label>Ingredient quantity:</Form.Label>
                                <Form.Control type="text"
                                    name="quantity"
                                    value={ingredient.quantity}
                                    onChange={(e) => handleInputChange(index, e)}
                                    placeholder="Quantity" />
                            </Form.Group>
                            <Button className='d-inline-block m-3' variant="primary" type="button" onClick={() => removeIngredient(index)}>-</Button>
                        </React.Fragment>
                    ))}
                    <Button className='d-inline-block m-3' variant="primary" type="button" onClick={addIngredient}>+</Button>
                </>
                <br />
                <label>
                    
                    {recipe.instructions.map((instruction, index) => (
                        <React.Fragment key={index}>
                            <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
                                <Form.Label>Instructions:</Form.Label>
                                <Form.Control type="textarea" style={{ dispay: "inline-block", width: "200px"}}
                                    placeholder="Instruction"
                                    value={instruction}
                                    onChange={(e) => handleInstructionChange(index, e)}
                                />
                            </Form.Group>
                            <Button className='d-inline-block m-3' variant="primary" type="button" onClick={() => removeInstruction(index)}>-</Button>
                        </React.Fragment>
                    ))}
                    <Button className='d-inline-block m-3' variant="primary" type="button" onClick={addInstruction}>+</Button>
                </label>
                <br />
                <Button variant="primary" type="submit">Submit</Button>
            </Form>
        </div>
    );
};

export default RecipeForm;
