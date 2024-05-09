import React, { useState, useContext } from 'react'
import Form from 'react-bootstrap/Form';
import Button from 'react-bootstrap/Button';
import { useNavigate } from 'react-router-dom';
import { RecipeContext } from './RecipeProvider';

export default function Login() {
    const [logininfo, setLogininfo] = useState({ username: "", password: "" })
    const navigate = useNavigate()
    const [isloggedin, setIsloggedin] = useContext(RecipeContext)

    const handleChange = (evt) => {
        console.log(evt.target.name)
        if (evt.target.name === "username") {
            setLogininfo((prev) => {
                return ({ ...prev, username: evt.target.value })
            })
        } else if (evt.target.name === "password") {
            setLogininfo((prev) => {
                return ({ ...prev, password: evt.target.value })
            })
        }

    }

    const handleSubmit = (evt) => {
        evt.preventDefault()
        console.log(logininfo)
        setLogininfo({ username: "", password: "" })

        fetch("http://localhost:3001/api/user/login", {
            method: "POST",
            headers: {
                "content-type": "application/json",
                "accept": "application/json"
            },
            body: JSON.stringify(logininfo)
        })
            .then((response) => {
                return response.json()
            })
            .then((result) => {
                console.log(result)
                //localStorage.clear()
                //localStorage.removeItem("token")
                localStorage.setItem("token", result.token)
                setIsloggedin(true)
                navigate("/createrecipe")
            })
    }

    return (
        <div className='recipe-container'>
            <Form onSubmit={handleSubmit}>
                <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
                    <Form.Label>Username</Form.Label>
                    <Form.Control type="text" value={logininfo.username} name="username" onChange={handleChange} placeholder="Enter your username" />
                </Form.Group>
                <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
                    <Form.Label>Password</Form.Label>
                    <Form.Control type="password" value={logininfo.password} name="password" onChange={handleChange} placeholder="Enter your password" />
                </Form.Group>
                <Button as="input" type="submit" value="Submit" />
            </Form>
        </div>
    )
}
