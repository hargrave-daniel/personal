/*
Author: Daniel Hargrave
ISU NetID: dh11@iastate.edu
Date: May 9th, 2025
*/
import React, { useState, useEffect } from "react";
import "bootstrap/dist/css/bootstrap.min.css";
import { Card, Row, Col, Container } from "react-bootstrap";

const Robots = () => {
  const [robots, setRobots] = useState([]);

  useEffect(() => {
    getRobots();
  }, []);

  function getRobots() {
    fetch("http://127.0.0.1:8080/robots")
      .then((response) => response.json())
      .then((data) => {
        setRobots(data);
      })
      .catch((error) => {
        console.error("Error fetching Robots:", error);
      });
  }

  return (
    <Container>
      <h1>Robots</h1>
      <Row xs={1} md={2} lg={3} className="g-4 d-flex flex-row align-items-stretch">
        {robots.map((robot) => (
          <Col key={robot.id}>
            <Card>
              <Card.Img
                variant="top"
                src={robot.imageUrl}
                style={{ height: "350px" }}
                alt={robot.name}
              />
              <Card.Body>
                <Card.Title style={{ fontSize: "18px" }}>
                  {robot.name}
                </Card.Title>
                <Card.Text style={{ color: "#000000" }}>
                  <strong>Price: </strong>${robot.price}
                </Card.Text>
                <Card.Text style={{ color: "#000000" }}>
                  <strong>Description: </strong>
                  {robot.description}
                </Card.Text>
              </Card.Body>
            </Card>
          </Col>
        ))}
      </Row>
    </Container>
  );
};

export default Robots;
