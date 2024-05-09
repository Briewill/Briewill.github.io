import React from 'react'
import { Link } from 'react-router-dom'
import NavLink from 'react-bootstrap/esm/NavLink'

export default function Footer() {
  return (
    <footer className="footer">
      <div className="footer-links">
        {/* Links */}
        <ul>
        <li><NavLink><Link to="/">Home </Link></NavLink></li>
        </ul>
      </div>
      
      <div className="contact-info">
        {/* Contact Information */}
        <p>Email: contactme@email.com</p>
        <p>Phone: 123-456-7890</p>
        {/* Add more contact info if required */}
      </div>
    </footer>
  )
}
