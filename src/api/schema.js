const mongoose = require('mongoose')

let joystickSchema = mongoose.Schema({
    date: Date,
    xPosition: { type: Number, required: true },
    yPosition: { type: Number, required: true },
    switch: false,
}, {
    collection: 'status'
})

module.exports = mongoose.model('status', joystickSchema)