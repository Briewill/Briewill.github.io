const mongoose =require('mongoose');
const { Schema } = mongoose;

const userSchema = new Schema({
  
   //similar to creating table in mysqli 
  username: {
    type: String,
    required: true
  },
  password: {
    type: String,
    required: true
  },
  email: {
    type: String,
    required: true,
    unique: true
  },
});

const User = mongoose.model("User", userSchema) 
module.exports = User