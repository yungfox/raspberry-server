const express = require('express');
const app = express();
const routes = require('./api/router');
const cors = require('cors');

// //connessione a mongo
// mongoose.connect('mongodb://localhost:27017/its_todo_2021', {useNewUrlParser: true, useUnifiedTopology: true});
// mongoose.set('debug', true);

app.use(cors());
// body parser
app.use(express.json({extended : true}));
app.use('/api', routes);

//app.use(errorHandlers);

module.exports = app;
