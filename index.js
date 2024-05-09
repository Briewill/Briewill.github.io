const express = require('express');
const cors = require('cors');
const db = require("./config/connection");
const app = express();
const port = 3001;
const mainRouter = require("./routes")

app.use(cors())

app.use(express.urlencoded({extended: false}))
app.use(express.json())

app.use("/api", mainRouter)

app.get('/', (req, res) => {
  res.send('Hello, Express!');
});

db.once('open', ()=>{
  console.log("connected to mongoDB");
  app.listen(port, () => {
  console.log(`Server is listening on port ${port}`);
  });
})




