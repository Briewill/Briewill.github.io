import React, {useContext, useEffect} from 'react'
import { RecipeContext } from './RecipeProvider'
import { useNavigate } from 'react-router-dom'

export default function Logout() {
    const [isloggedin, setIsloggedin] = useContext(RecipeContext)
    const navigate = useNavigate()
    useEffect(() => {
      setIsloggedin(false)
      //localStorage.clear()
      //localStorage.removeItem("token")
      navigate("/login") 
    }, [])
    
  return (
    <div>... logging out</div>
  )
}
