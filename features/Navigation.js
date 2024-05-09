import React, {useContext, useEffect} from 'react'
import Nav from 'react-bootstrap/Nav';
import {Link } from "react-router-dom"
import Container from 'react-bootstrap/Container';
import Navbar from 'react-bootstrap/Navbar';
import { RecipeContext } from '../components/RecipeProvider';

export default function Navigation() {
  const [isloggedin, setIsloggedin] = useContext(RecipeContext)
  return (
    <div>
      <Navbar bg="dark" data-bs-theme="dark">
        <Container>
          <Navbar.Brand ><Link className='text-decoration-none' to="/">Home</Link></Navbar.Brand>
          <Nav className="me-auto">
            <Nav.Link><Link className='text-decoration-none' to="/Recipe">Recipes</Link></Nav.Link>
            {!isloggedin && <Nav.Link><Link className='text-decoration-none' to="/Login">Login</Link></Nav.Link>}
            {isloggedin && <Nav.Link><Link className='text-decoration-none' to="/Logout">Logout</Link></Nav.Link>}
            {isloggedin && <Nav.Link><Link className='text-decoration-none' to="/createrecipe">Post Recipes</Link></Nav.Link>}
            {!isloggedin && <Nav.Link><Link className='text-decoration-none' to="/Register">Register</Link></Nav.Link>}
            
          </Nav>
        </Container>
      </Navbar>
     
      
    
      
    
    </div>
  )
}
