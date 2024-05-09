const mongoose = require("mongoose");

mongoose.connect("mongodb://127.0.0.1:27017/recipieProject") 
.catch(error => handleError(error));

const db = mongoose.connection;

module.exports = db;
