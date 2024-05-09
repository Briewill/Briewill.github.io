import React, { useState } from 'react'
import Form from 'react-bootstrap/Form';
import Button from 'react-bootstrap/Button';
import { useNavigate } from 'react-router-dom';

export default function Register() {
    const [registerinfo, setRegisterInfo] = useState({ username: "", email: "", password: "" })
    const navigate = useNavigate()

    const handleChange = (evt) => {
        if (evt.target.name === "username") {
            setRegisterInfo((prev) => {
                return ({ ...prev, username: evt.target.value })
            })
        } else if (evt.target.name === "password") {
            setRegisterInfo((prev) => {
                return ({ ...prev, password: evt.target.value })
            })
        } else if (evt.target.name === "email") {
            setRegisterInfo((prev) => {
                return ({ ...prev, email: evt.target.value })
            })
        }

    }

    const handleSubmit = (evt) => {
        evt.preventDefault()
        console.log(registerinfo)
        setRegisterInfo({ username: "", email: "", password: "" })

        fetch("http://localhost:3001/api/user/register", {
            method: "POST",
            headers: {
                "content-type": "application/json",
                "accept": "application/json"
            },
            body: JSON.stringify(registerinfo)
        })
            .then((response) => {
                return response.json()
            })
            .then((result) => {
                console.log(result)
                navigate("/login")
            })
    }

    return (
        <div>
            <Form onSubmit={handleSubmit}>
                <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
                    <Form.Label>email</Form.Label>
                    <Form.Control type="text" value={registerinfo.email} name="email" onChange={handleChange} placeholder="Enter your email" />
                </Form.Group>
                <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
                    <Form.Label>Username</Form.Label>
                    <Form.Control type="text" value={registerinfo.username} name="username" onChange={handleChange} placeholder="Enter your username" />
                </Form.Group>
                <Form.Group className="mb-3" controlId="exampleForm.ControlInput1">
                    <Form.Label>Password</Form.Label>
                    <Form.Control type="password" value={registerinfo.password} name="password" onChange={handleChange} placeholder="Enter your password" />
                </Form.Group>
                <Button as="input" type="submit" value="Submit" />
            </Form>
        </div>
    )
}
