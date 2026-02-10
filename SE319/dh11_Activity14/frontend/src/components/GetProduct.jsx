// Prepared By: Pranava Sai Maganti
/*
I don't know if I should put this since it was just from Pranava but just in case
Daniel Hargrave
dh11@iastate.edu
Date: 5/09/2025
*/
import React, { useState, useEffect } from "react";
import "bootstrap/dist/css/bootstrap.min.css";
import { Card, Row, Col, Container } from "react-bootstrap";
const Products = () => {
  const [Products, setProducts] = useState([]);
  useEffect(() => {
    getProducts();
  }, []);
  function getProducts() {
    fetch("http://127.0.0.1:8080/catalog")
      .then((response) => response.json())
      .then((data) => {
        setProducts(data);
      })
      .catch((error) => {
        console.error("Error fetching Products:", error);
      });
  }
  return (
    <>
      <div>
        <Container>
          <h1>Products</h1>
          <Row
            xs={1}
            md={2}
            lg={3}
            className="g-4 d-flex flex-row align-items-stretch"
          >
            {Products.map((Product) => (
              <Col key={Product.id}>
                <Card>
                  <Card.Img
                    variant="top"
                    src={Product.image}
                    style={{ height: "350px" }}
                    alt={Product.name}
                  />
                  <Card.Body>
                    <Card.Title style={{ fontSize: "18px" }}>
                      {Product.name}
                    </Card.Title>
                    <Card.Text style={{ color: "#000000" }}>
                      <strong>Price: </strong>${Product.price}
                    </Card.Text>
                    <Card.Text style={{ color: "#000000" }}>
                      <strong>Cast: </strong>
                      {Product.description}
                    </Card.Text>
                  </Card.Body>
                </Card>
              </Col>
            ))}
          </Row>
        </Container>
      </div>
    </>
  );
};
export default Products;
