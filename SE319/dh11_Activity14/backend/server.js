/*
Daniel Hargrave
dh11@iastate.edu
Date: 5/09/2025
*/
const express = require("express");
const db = require("./db.js");
const cors = require("cors");
const app = express();
const PORT = 8080;
app.use(cors());
app.use(express.json());
app.listen(PORT, () => {
  console.log(`Server is running on ${PORT}`);
});
//Route to get all posts
app.get("/catalog", async (req, res) => {
  try {
    const query = "SELECT * FROM fakestore_catalog";
    const [result] = await db.query(query); // Execute the query and wait for the result
    console.log("Success in Reading MySQL");
    res.status(200).send(result); // Send the results as the response
  } catch (err) {
    // If an error occurs, catch it and send an appropriate error response
    console.error("Error in Reading MySQL :", err);
    res.status(500).send({ error: "An error occurred while fetching items." });
  }
});

app.get("/test-db", async (req, res) => {
  try {
    await db.query("SELECT 1");
    res.send("DB connection works!");
  } catch (err) {
    console.error("Test DB connection error:", err);
    res.status(500).send({ error: "DB connection failed" });
  }
});

app.get("/catalog/:id", async (req, res) => {
  try {
    // Read id from frontend
    const id = req.params.id;
    const query = "SELECT * FROM fakestore_catalog WHERE id = ?";
    const [result] = await db.query(query, [id]); // Ensure to use array for parameters even if it's just one
    console.log("Success in Reading MySQL");
    res.status(200).send(result);
  } catch (err) {
    // If an error occurs, catch it and send an appropriate error response
    console.error("Error in Reading MySQL :", err);
    res.status(500).send({ error: "An error occurred while fetching items." });
  }
});

// Assuming `db` is from mysql2/promise
app.post("/catalog", async (req, res) => {
  try {
    // Validate if body contains data
    if (!req.body || Object.keys(req.body).length === 0) {
      const msg = "POST:Bad request: No data provided.";
      console.log(msg);
      return res.status(400).send({ error: msg });
    }
    // Check if the table exists
    const [tableExists] = await db.query(
      "SHOW TABLES LIKE 'fakestore_catalog'"
    );
    if (tableExists.length === 0) {
      const msg = "POST:Table does not exist";
      console.log(msg);
      return res.status(404).send({ error: msg });
    }
    // Check if the 'product' exists
    const itemId = req.body.id;
    const [productExists] = await db.query(
      "SELECT * FROM fakestore_catalog WHERE id = ?",
      [itemId]
    );
    if (productExists.length > 0) {
      // Item exists
      const msg = "POST:Item already exists";
      console.log(msg);
      return res.status(409).send({ error: msg });
    }
    // Proceed to add new item
    const { id, title, price, description, category, image, rating } = req.body;
    const insertSql =
      "INSERT INTO fakestore_catalog (id, title, price, description, category, image, rating) VALUES (?, ?, ?, ?, ?, ?, ?)";
    const insertResult = await db.query(insertSql, [
      id,
      title,
      price,
      description,
      category,
      image,
      rating,
    ]);
    // success
    const msg = "POST:Success in Posting MySQL" + insertResult;
    console.log(msg);
    return res.status(200).send({ success: msg });
  } catch (err) {
    // Handle any error
    const msg = "POST: An error occurred while adding product " + err;
    console.error(msg);
    res.status(500).send({ error: msg });
  }
});

// Route to delete a post
app.delete("/catalog/:id", async (req, res) => {
  try {
    // Read id from frontend
    const itemId = req.params.id;
    // Verify if item already exists
    console.log("DELETE DELETE DELETE ", itemId);
    const [rows] = await db.query(
      "SELECT * FROM fakestore_catalog WHERE id = ?",
      [itemId]
    );
    if (rows.length <= 0) {
      // Item does NOT exist
      const msg = "DELETE:Item " + itemId + " does NOT exist";
      console.log(msg);
      return res.status(409).send({ error: msg });
    }
    // Proceed to delete it
    const id = req.params.id;
    await db.query("DELETE FROM fakestore_catalog WHERE id= ?", [id]);
    // success
    const msg = "Success in DELETE item :" + id;
    console.log(msg);
    return res.status(200).send({ success: msg });
  } catch (err) {
    // Handle any error
    const msg = "DELETE: An ERROR occurred in Delete" + err;
    console.error(msg);
    res.status(500).send({ error: msg });
  }
});

// Route for update a post
app.put("/catalog/:id", async (req, res) => {
  try {
    // Read id from frontend and verify if item exists
    const itemId = req.params.id;
    const [productExists] = await db.query(
      "SELECT * FROM fakestore_catalog WHERE id = ?",
      [itemId]
    );
    if (productExists.length <= 0) {
      // Item does NOT exist
      const msg = "PUT:Item does NOT exist";
      console.log(msg);
      return res.status(409).send({ error: msg });
    }
    // Load body in local variables
    const id = req.body.id;
    const title = req.body.title;
    const price = req.body.price;
    const description = req.body.description;
    const category = req.body.category;
    const image = req.body.image;
    const rating = req.body.rating;
    // all fields at once
    // const { id, title, price, description, category, image, rating } = req.body;
    // Update MySQL
    const updateSql =
      "UPDATE fakestore_catalog SET title=?, price=?, description=?, category=?, image=?, rating=? WHERE id=?";
    const updateResult = await db.query(updateSql, [
      title,
      price,
      description,
      category,
      image,
      rating,
      id,
    ]);
    // success
    const msg = "Success in UPDATE item :" + updateResult;
    console.log(msg);
    return res.status(200).send({ success: msg });
  } catch (err) {
    // Handle any error
    const msg = "PUT: An ERROR occurred in Update" + err;
    console.error(msg);
    res.status(500).send({ error: msg });
  }
});
