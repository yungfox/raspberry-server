const express = require('express')
const router = express.Router()
const controller = require('./controller')

router.get('/', controller.find)
router.post('/', controller.store)
router.patch('/', controller.store)

module.exports = router