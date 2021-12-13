const joystick = require('./schema')
const moment = require('moment')

module.exports.store = async(data) => {
    data.date = moment(new Date()).utcOffset(0, true)
    return joystick.create(data)
}

module.exports.find = async(query) => {
    return joystick.findOne(query).sort({ date: -1 })
}