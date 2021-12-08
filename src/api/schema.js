const mongoose = require('mongoose')

let joystickSchema = mongoose.Schema({
    date: Date,
    xPosition: { type: Number, required: true },
    yPosition: { type: Number, required: true },
    switch: false
}, {
    collection: 'history'
})

module.exports = mongoose.model('history', joystickSchema)