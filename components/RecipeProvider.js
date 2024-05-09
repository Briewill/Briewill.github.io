import React, {createContext, useState} from 'react'

export const RecipeContext = createContext()


export default function RecipeProvider({children}) {
  const [isloggedin, setIsloggedin] = useState(false)
  return (
    <RecipeContext.Provider value={[isloggedin, setIsloggedin]}>
      {children}
    </RecipeContext.Provider>
  )
}
