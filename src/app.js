const express = require('express')
const morgan = require('morgan')
const app = express()
const routes = require('./api/router')
const cors = require('cors')
const mongoose = require('mongoose')
const errorHandlers = require('./errors')

//connessione a mongo
mongoose.connect('mongodb://localhost:27017/esp32joystick', { useNewUrlParser: true, useUnifiedTopology: true })
mongoose.set('debug', true)

app.use(cors())
app.use(express.json({ extended: true }))
app.use(morgan('tiny'))
app.use('/api', routes)

app.use(errorHandlers)

module.exports = app