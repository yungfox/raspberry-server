const joystickModel = require('./model')

module.exports.store = async(req, res, next) => {
    try {
        const tmp = await joystickModel.store(req.body)
        res.json(tmp)
        res.status(201)
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