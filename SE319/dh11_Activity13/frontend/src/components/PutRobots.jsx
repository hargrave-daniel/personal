/*
Author: Daniel Hargrave
ISU NetID: dh11@iastate.edu
Date: May 9th, 2025
*/
import React, { useState } from "react";

const PutRobots = () => {
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
    const url = `http://127.0.0.1:8080/updateRobot/${formData.id}`;
    try {
      const response = await fetch(url, {
        method: "PUT",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({
          name: formData.name,
          price: formData.price,
          description: formData.description,
          imageUrl: formData.imageUrl,
        }),
      });
      if (!response.ok) {
        throw new Error("Failed to update Robot");
      }
      const result = await response.json();
      console.log("Success:", result);
      alert("Robot updated successfully!");
      setFormData({
        id: "",
        name: "",
        price: "",
        description: "",
        imageUrl: "",
      });
    } catch (error) {
      console.error("Error:", error);
      alert("Error updating Robot");
    }
  };

  return (
    <div>
      <h2>Update Robot</h2>
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
        <button type="submit">Update Robot</button>
      </form>
    </div>
  );
};

export default PutRobots;
