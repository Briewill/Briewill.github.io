import React, { useContext } from 'react';
import './App.css';
import 'bootstrap/dist/css/bootstrap.min.css';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Home from './features/Home';
import RecipeContainer from './features/RecipeContainer';
import Header from './components/Header';
import Footer from "./components/Footer";
import RecipeComment from './features/RecipeComment';
import Login from './components/Login';
import RecipeForm from './components/RecipeForm';
import { RecipeContext } from './components/RecipeProvider';
import Recipe from './components/Recipe';
import Register from './components/Register';
import Logout from './components/Logout';
import EditRecipe from './components/EditRecipe';


function App() {
  const [isloggedin, setIsloggedin] = useContext(RecipeContext)

  return (
    <div className="App">
      <Router >
        <Header />
        <Routes>
          <Route path="/" element={<Home />} />
        </Routes>
        <Routes>
          <Route path="/Recipe" element={<RecipeContainer />} />
        </Routes>
         <Routes>
          <Route path="/recipecomments" element={<RecipeComment />} />
        </Routes>
        <Routes>
          <Route path="/login" element={<Login />} />
        </Routes>
        <Routes>
          <Route path="/logout" element={<Logout />} />
        </Routes>
        <Routes>
          <Route path="/Recipe/:recipeId" element={<Recipe />} />
        </Routes>
        {isloggedin ?
          <Routes>
            <Route path="/createrecipe" element={<RecipeForm />} />
          </Routes> : ""}
          {isloggedin ?
          <Routes>
            <Route path="/editrecipe/:recipeId" element={<EditRecipe />} />
          </Routes> : ""}
          <Routes>
            <Route path="/register" element={<Register />} />
          </Routes>   
          <Footer />
      </Router>
    </div>
  );
}

export default App;
