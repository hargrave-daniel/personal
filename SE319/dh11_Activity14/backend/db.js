/*
Daniel Hargrave
dh11@iastate.edu
Date: 5/09/2025
*/
const mysql = require("mysql2/promise");

const db = mysql.createPool({
    host: "127.0.0.1",
    user: "root",
    password: "secoms3190",
    database: "secoms3190",
});

module.exports = db;
