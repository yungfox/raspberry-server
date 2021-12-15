const joystick = require('./schema')
const moment = require('moment')

module.exports.store = async(data) => {
    data.date = moment(new Date()).utcOffset(0, true)
    if (await joystick.findOne()) {
        return await joystick.findOneAndUpdate({}, data, {returnOriginal: false})
    }
    return joystick.create(data)
}

module.exports.find = async(query) => {
    return await joystick.findOne(query)
}