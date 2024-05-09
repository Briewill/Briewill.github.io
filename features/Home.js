import React from 'react'
import recipeImg from "../images/Recipe01.jpg"

export default function Home() {
  return (
    <div className="home">
      <div className='home-1'>
        <h3>Welcome to my Recipe Site</h3>
      </div>
      <div className='home-2'>
        <img src={recipeImg} />
      </div>
    </div>
  )
}
