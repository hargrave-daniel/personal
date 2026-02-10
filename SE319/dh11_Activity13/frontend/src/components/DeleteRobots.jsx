/*
Author: Daniel Hargrave
ISU NetID: dh11@iastate.edu
Date: May 9th, 2025
*/
import React, { useState } from "react";

const DeleteRobots = () => {
  const [id, setId] = useState("");

  const handleChange = (event) => {
    setId(event.target.value);
  };

  const handleDelete = async (event) => {
    event.preventDefault();
    const url = `http://127.0.0.1:8080/deleteRobot/${id}`;
    try {
      const response = await fetch(url, {
        method: "DELETE",
      });
      if (!response.ok) {
        throw new Error("Failed to delete Robot");
      }
      const result = await response.json();
      console.log("Success:", result);
      alert("Robot deleted successfully!");
      setId("");
    } catch (error) {
      console.error("Error:", error);
      alert("Error deleting Robot");
    }
  };

  return (
    <div>
      <h2>Delete Robot</h2>
      <form onSubmit={handleDelete}>
        <input
          type="number"
          placeholder="ID"
          value={id}
          onChange={handleChange}
          required
        />
        <button type="submit">Delete Robot</button>
      </form>
    </div>
  );
};

export default DeleteRobots;
