import React, {useState, useEffect} from 'react'
import Nav from 'react-bootstrap/Nav';
import { Link } from "react-router-dom"

export default function Recipes() {
    const [recipes, setRecipes] = useState([])

    useEffect(() => {
        const getRecipies = () => {
            fetch("http://localhost:3001/api/recipe")
            .then((response) => {
              
                return response.json()
            })
            .then((result) => {
              console.log(result.data);
               setRecipes(result.data)
            })

        }
        getRecipies()
      
    }, [])
    
  // key required when iterating through array
  //back-tick allows sting without plus sign
  return (
    <div>
      <div>
        {recipes && recipes.length > 0 && (
          recipes.map((recipe)=>{
            return(
              <div style={{paddingBottom: "20px"}} key={recipe._id}>
                <h6 className='titleRecipe'>{recipe.title}</h6>
                <h6>Instructions:</h6>
               <span className="recipeInst">  {recipe.instructions[0].substring(0, 30)}...</span>
                
                <Nav.Link><Link className='text-decoration-none' to={`/recipe/${recipe._id}`} >See this recipe</Link></Nav.Link>
              </div>
            )
          })
        )}
      </div>
    </div>
  )
}
