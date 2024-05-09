import React, {useEffect, useState} from 'react'


export default function RecipeComment() {
    const [recipe, setRecipe] = useState({})
    const [comment, setComment] = useState({})

    const getRecipeUrl = "http://localhost:3001/api/recipe/655e7b73d7afcaf22344449f"
    const getComments = "http://localhost:3001/api/comment/65651476b86e6d3d082da4f5"

    const fetchData = async () => {
        try{
            const [responseRecipe, responseComment] = await Promise.all([
                fetch(getRecipeUrl),
                fetch(getComments)
            ])

            if(responseRecipe.ok && responseComment.ok) {
                const commentData = await responseComment.json() 
                const recipeData = await responseRecipe.json()

                console.log("comment: ", commentData.data)
                console.log("recipe: ", recipeData.data)
                setRecipe(recipeData)
                setComment(commentData.data)
            }

        } catch(error) {
            console.log(error)
        }

    }
    
    useEffect(() => {
        fetchData()
    }, [])
    
  return (
    <div style={{paddingBottom: "20px"}}>
        {/* {recipe ? <div>{"it works"}</div>: <div>does not work</div>} */}
        <h6>{Object.keys(comment).length > 0 ? comment.comments.post : 'No comments'}</h6>

    </div>
    
  )
}
