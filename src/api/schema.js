const mongoose = require('mongoose')

const joystickSchema = mongoose.Schema({
    date: Date,
    xPosition: Number,
    yPosition: Number,
    switch: Boolean
})

module.exports = mongoose.model('joystickData', joystickSchema)