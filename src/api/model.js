const joystick = require('./schema')

module.exports.store = async(data) => {
    console.log('entrato nel model')
    return joystick.create(data)
}

module.exports.find = async(query) => {
    return joystick.find(query).sort({ date: -1 })
}