const joystickModel = require('./model')

module.exports.store = async(req, res, next) => {
    try {
        console.log('entrato nel controller')
        const tmp = await joystickModel.store(req.body)
        res.status(201)
        res.json(tmp)
    } catch (err) {
        next(err)
    }
}

module.exports.find = async(req, res, next) => {
    try {
        const list = await joystickModel.find(req.query)
        res.json(list)
    } catch (err) {
        next(err)
    }
}