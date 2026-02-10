// Prepared By: Pranava Sai Maganti
/*
I don't know if I should put this since it was just from Pranava but just in case
Daniel Hargrave
dh11@iastate.edu
Date: 5/09/2025
*/
import React, { useState } from "react";
const AddProducts = () => {
  const [formData, setFormData] = useState({
    id: "",
    name: "",
    price: "",
    description: "",
    image: "",
  });
  const handleChange = (event) => {
    const { name, value } = event.target;
    setFormData((prevState) => ({
      ...prevState,
      [name]: value,
    }));
  };
  const handleSubmit = async (event) => {
    event.preventDefault();
    const url = "http://127.0.0.1:8080/catalog";
    try {
      const response = await fetch(url, {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify(formData),
      });
      if (!response.ok) {
        throw new Error("Failed to add new Product");
      }
      const result = await response.json();
      console.log("Success:", result);
      alert("Product added successfully!");
      // Optionally reset form or navigate away
      setFormData({
        id: "",
        name: "",
        price: "",
        description: "",
        image: "",
      });
    } catch (error) {
      console.error("Error:", error);
      alert("Error adding Product");
    }
  };
  return (
    <>
      <form onSubmit={handleSubmit}>
        <input
          type="text"
          name="id"
          value={formData.id}
          onChange={handleChange}
          placeholder="ID"
          required
        />
        <br />
        <br />
        <input
          type="text"
          name="title"
          value={formData.title}
          onChange={handleChange}
          placeholder="Product Name"
          required
        />
        <br />
        <br />
        <input
          type="text"
          name="price"
          value={formData.price}
          onChange={handleChange}
          placeholder="Product Price"
          required
        />
        <br />
        <br />
        <input
          type="text"
          name="description"
          value={formData.description}
          onChange={handleChange}
          placeholder="Product Description"
          required
        />
        <br />
        <br />
        <textarea
          name="category"
          value={formData.category}
          onChange={handleChange}
          placeholder="Product Category"
          required
        />
        <br />
        <br />
        <textarea
          name="image"
          value={formData.image}
          onChange={handleChange}
          placeholder="Product Image URL"
          required
        />
        <br />
        <br />
        <textarea
          name="rating"
          value={formData.rating}
          onChange={handleChange}
          placeholder="Product Rating"
          required
        />
        <br />
        <br />
        <button type="submit">Add Product</button>
      </form>
    </>
  );
};
export default AddProducts;
