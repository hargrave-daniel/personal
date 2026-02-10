/*
Author: Daniel Hargrave
ISU NetID: dh11@iastate.edu
Date: May 9th, 2025
*/
var express = require("express");
var cors = require("cors");
var app = express();
var fs = require("fs");
var bodyParser = require("body-parser");
app.use(cors());
app.use(bodyParser.json());
const port = "8080";
const host = "localhost";
app.listen(port, () => {
console.log("App listening at http://%s:%s",
host, port);
});
const { MongoClient } = require("mongodb");
// MongoDB
const url = "mongodb://127.0.0.1:27017";
const dbName = "secoms319";
const client = new MongoClient(url);
const db = client.db(dbName);
app.get("/robots", async (req, res) => {
    await client.connect();
    console.log("Connected to the MongoDB collection for GET");
    const query = {};
    const results = await db
    .collection("robots")
    .find(query)
    .limit(100)
    .toArray();
    console.log(results);
    res.status(200);
    res.send(results);
    });

app.post("/addRobot", async (req, res) => {
    try {
    await client.connect();
    const newDocument = {
    id: req.body.id,
    name: req.body.name,
    price: req.body.price,
    description: req.body.description,
    imageUrl: req.body.imageUrl,
    };
    const result = await db.collection("robots").insertOne(newDocument);
    res.status(200);
    res.send(result);
    } catch (error) {
    console.error("Could not add the new Robot" + error);
    res.status(500);
    res.send("Error adding new robot");
        } finally {
    await client.close();
    }
    });
app.put("/updateRobot/:id", async (req, res) => {
    try {
    await client.connect();
    const updateDoc = {
    $set: req.body,
    };
    const result = await db
    .collection("robots")
    .updateOne({ id: Number(req.params.id) }, updateDoc);
    if (result.modifiedCount === 0) {
    return res.status(404).send({ error: "No robot found with that ID" });
    }
    res.status(200).send(result);
    } catch (error) {
    console.error("Error updating robot:", error);
    res.status(500).send({ error: "An internal server error occurred" });
    } finally {
    await client.close();
    }
    });
app.delete("/deleteRobot/:id", async (req, res) => {
    try {
    await client.connect();
    const result = await db
    .collection("robots")
    .deleteOne({ id: Number(req.params.id) });
    if (result.deletedCount === 0) {
    return res.status(404).send({ error: "No robot found with that ID" });
    }
    res.status(200).send(result);
    } catch (error) {
    console.error("Error deleting Robot:", error);
    res.status(500).send({ error: "An internal server error occurred" });
    } finally {
    await client.close();
    }
    });