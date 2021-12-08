const express = require('express')
const router = express.Router()
const controller = require('./controller')

//definizione dele api relative ai todo
console.log('entrato in router')

router.get('/', controller.find)
router.post('/', controller.store)

module.exports = router