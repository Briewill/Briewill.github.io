import React, { useState, useEffect, useContext } from 'react'
import { useNavigate, useParams } from 'react-router-dom'
import { RecipeContext } from './RecipeProvider'
import { jwtDecode } from "jwt-decode";
import Nav from 'react-bootstrap/Nav';
import { Link } from "react-router-dom"
import Form from 'react-bootstrap/Form';
import Button from 'react-bootstrap/Button';
import ListGroup from 'react-bootstrap/ListGroup';



export default function Recipe() {
    const [isloggedin] = useContext(RecipeContext)
    const [isCurrentUsers, setIsCurrentUsers] = useState(isloggedin)
    const [recipe, setRecipe] = useState({})
    const [comment, setComment] = useState([])
    const [isowner, setIsOwner] = useState(false)
    const [newcomment, setNewComment] = useState("")
    const [currenttoken, setCurrentToken] = useState({})
    const [star, setStar] = useState(1)
    const { recipeId } = useParams()
    const navigate = useNavigate()

    const getRecipeUrl = `http://localhost:3001/api/recipe/${recipeId}`
    const getComments = `http://localhost:3001/api/comment/${recipeId}`
    const getStars = `http://localhost:3001/api/comment/comments/${recipeId}/average-stars`

    const fetchData = async () => {
        const token = localStorage.getItem("token");

        const decodedToken = jwtDecode(token);
        setCurrentToken(decodedToken)
        console.log(decodedToken)
        try {
            const [responseRecipe, responseComment, responseStars] = await Promise.all([
                fetch(getRecipeUrl),
                fetch(getComments),
                fetch(getStars)
            ])

            if (responseRecipe.ok && responseComment.ok && responseStars.ok) {
                const commentData = await responseComment.json()
                const recipeData = await responseRecipe.json()
                const starsData = await responseStars.json()

                console.log("comment: ", commentData.data)
                console.log("recipe: ", recipeData.data)
                console.log("stars: ", starsData.data)
                if (recipeData.data.authorId === decodedToken.id) {
                    console.log("TRUEEEEEEEEE")
                    setIsOwner(true)
                } else {
                    console.log("FALESEEEEEEE")
                }
                
                setRecipe(recipeData.data)
                setComment(commentData.data)

            }

        } catch (error) {
            console.log(error)
        }

    }


    useEffect(() => {


        fetchData()

    }, [])

    const handleDelete = (event) => {
        fetch(`http://localhost:3001/api/recipe/delete/${recipeId}`, {
            method: "DELETE",
            headers: {
                "Authorization": `Bearer ${localStorage.getItem("token")}`,
            }
        })
            .then((resp) => {
                return resp.json()
            })
            .then((result) => {
                console.log(result)
                navigate("/recipe")
            })
            .catch((err) => {
                console.log(err)
            })
    }

    const handleChange = (event) => {
        const { name, value } = event.target
        if (name === "comment") {
            setNewComment(value)
        } else if (name === "star") {
            setStar(value)
        }

    }

    const handleSubmit = (event) => {
        event.preventDefault()
        fetch(`http://localhost:3001/api/comment/createcomment/${currenttoken.id}/${recipeId}`, {
            method: "POST",
            headers: {
                "content-type": "application/json",
                "accept": "application/json"
            },
            body: JSON.stringify({
                comments: {
                    post: newcomment
                },
                stars: star
            })
        })
            .then((resp) => {
                return resp.json()
            })
            .then((result) => {
                console.log(result)
                //add new comment to array
                setComment((prev) => {
                    return ([
                        ...prev, newcomment
                    ])
                })
                navigate("/recipe")
            })
            .catch((err) => {
                console.log(err)
            })
    }

    // key required when iterating through array
    //back-tick allows sting without plus sign
    return (
        <div className='recipe-container'>
            <div>
                <h3>{recipe.title}</h3>
                {Object.keys(recipe).length > 0 && (
                    <div style={{ paddingBottom: "20px" }} key={recipe._id}>
                        <h6>Ingredients</h6>
                        <ListGroup as="ol" numbered>
                            {recipe.ingredients.map((ing, index) => {
                                return (
                                    <ListGroup.Item as="li" key={index}>
                                      <spam>Name: {ing.name}</spam>  <spam>Quantity: {ing.quantity}</spam>
                                    </ListGroup.Item>
                                )
                            })}
                        </ListGroup >
                        <h6>Instructions:</h6>
                        <ListGroup as="ol" numbered>
                        {recipe.instructions.map((inst, index) => {
                            return (
                                <ListGroup.Item as="li" key={index}>
                                    {inst}
                                </ListGroup.Item>
                            )
                        })}
                        </ListGroup>
                    </div>


                )}
                <h6>comments</h6>
                {comment.map((com) => {
                    return (
                        <div key={com._id}>
                            <p>{com.comments && com.comments.post}</p>
                            <p>Out of 5 Stars: {com.stars}</p>
                        </div>
                    )
                })}
            </div>
            <div>
                <Form onSubmit={handleSubmit}>
                    <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
                        <Form.Label>Comment on this recipe:</Form.Label>
                        <Form.Control type="textarea" value={newcomment} name="comment" onChange={handleChange} placeholder="Comment here" />
                    </Form.Group>
                    <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
                        <Form.Label>Rate this recipe out of 5 stars:</Form.Label>
                        <Form.Control type="number" min="1" max="5" value={star} name="star" onChange={handleChange} />
                    </Form.Group>
                    <Button as="input" type="submit" value="Post Comment" />
                </Form>
            </div>
            {isCurrentUsers && isowner && <div>
                <button type='click' onClick={handleDelete}>Delete Recipe</button>
                <Nav.Link><Link className='text-decoration-none' to={`/editrecipe/${recipeId}`}>Edit Recipe</Link></Nav.Link>
            </div>}
        </div>
    )
}

