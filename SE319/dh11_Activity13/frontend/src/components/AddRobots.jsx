/*
Author: Daniel Hargrave
ISU NetID: dh11@iastate.edu
Date: May 9th, 2025
*/
import React, { useState } from "react";

const AddRobots = () => {
  const [formData, setFormData] = useState({
    id: "",
    name: "",
    price: "",
    description: "",
    imageUrl: "",
  });

  const handleChange = (event) => {
    const { name, value } = event.target;
    setFormData((prev) => ({
      ...prev,
      [name]: value,
    }));
  };

  const handleSubmit = async (event) => {
    event.preventDefault();
    const url = "http://127.0.0.1:8080/addRobot";
    try {
      const response = await fetch(url, {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify(formData),
      });
      if (!response.ok) {
        throw new Error("Failed to add new Robot");
      }
      const result = await response.json();
      console.log("Success:", result);
      alert("Robot added successfully!");
      setFormData({
        id: "",
        name: "",
        price: "",
        description: "",
        imageUrl: "",
      });
    } catch (error) {
      console.error("Error:", error);
      alert("Error adding Robot");
    }
  };

  return (
    <div>
      <h2>Add Robot</h2>
      <form onSubmit={handleSubmit}>
        <input
          type="number"
          name="id"
          placeholder="ID"
          value={formData.id}
          onChange={handleChange}
          required
        />
        <input
          type="text"
          name="name"
          placeholder="Name"
          value={formData.name}
          onChange={handleChange}
          required
        />
        <input
          type="number"
          name="price"
          placeholder="Price"
          value={formData.price}
          onChange={handleChange}
          required
        />
        <input
          type="text"
          name="description"
          placeholder="Description"
          value={formData.description}
          onChange={handleChange}
          required
        />
        <input
          type="text"
          name="imageUrl"
          placeholder="Image URL"
          value={formData.imageUrl}
          onChange={handleChange}
          required
        />
        <button type="submit">Add Robot</button>
      </form>
    </div>
  );
};

export default AddRobots;
