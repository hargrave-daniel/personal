import React from 'react';

const Cart = ({ cart, setCart, setStep }) => {
  // Remove a course entirely
  const handleRemove = (offering_id) => {
    setCart(prevCart => prevCart.filter(course => course.offering_id !== offering_id));
  };

  // Update quantity for a course
  const updateQuantity = (offering_id, newQuantity) => {
    if (newQuantity < 1) return; // Prevent zero or negative quantities
    setCart(prevCart =>
      prevCart.map(course =>
        course.offering_id === offering_id
          ? { ...course, quantity: newQuantity }
          : course
      )
    );
  };

  // Initialize quantity to 1 if not present
  const cartWithQuantities = cart.map(course => ({
    ...course,
    quantity: course.quantity || 1,
  }));

  // Calculate subtotal (sum of price * quantity)
  const subtotal = cartWithQuantities.reduce(
    (sum, course) => sum + Number(course.price) * course.quantity,
    0
  );

  const TAX_RATE = 0.07;
  const tax = subtotal * TAX_RATE;
  const total = subtotal + tax;

  return (
    <div className="max-w-3xl mx-auto p-6">
      <h2 className="text-3xl font-bold mb-4">Your Cart</h2>

      {cartWithQuantities.length === 0 ? (
        <div className="text-gray-500 italic mb-4">Your cart is empty. Add courses to continue.</div>
      ) : (
        <div className="bg-white rounded shadow p-6 space-y-6">
          <ul>
            {cartWithQuantities.map(course => (
              <li
                key={course.offering_id}
                className="flex items-center justify-between py-3 border-b last:border-b-0"
              >
                <div className="flex flex-col">
                  <h3 className="font-semibold text-lg">{course.title}</h3>
                  <p className="text-gray-600 text-sm">Instructor: {course.instructor}</p>
                  <p className="text-gray-600 text-sm">${course.price}</p>
                </div>

                {/* Quantity controls */}
                <div className="flex items-center space-x-2">
                  <button
                    onClick={() => updateQuantity(course.offering_id, course.quantity - 1)}
                    className="bg-gray-300 hover:bg-gray-400 text-gray-800 font-bold py-1 px-3 rounded"
                  >
                    -
                  </button>
                  <span className="w-8 text-center">{course.quantity}</span>
                  <button
                    onClick={() => updateQuantity(course.offering_id, course.quantity + 1)}
                    className="bg-gray-300 hover:bg-gray-400 text-gray-800 font-bold py-1 px-3 rounded"
                  >
                    +
                  </button>
                </div>

                {/* Remove button */}
                <button
                  onClick={() => handleRemove(course.offering_id)}
                  className="bg-red-500 hover:bg-red-700 text-white py-2 px-4 rounded transition ml-4"
                >
                  Remove
                </button>
              </li>
            ))}
          </ul>

          {/* Pricing summary */}
          <div className="space-y-2 text-right">
            <div>
              <span className="font-semibold">Subtotal: </span>${subtotal.toFixed(2)}
            </div>
            <div>
              <span className="font-semibold">Tax (7%): </span>${tax.toFixed(2)}
            </div>
            <div className="text-xl font-bold">
              <span>Total: </span>${total.toFixed(2)}
            </div>
          </div>
        </div>
      )}

      {/* Cart actions */}
      <div className="mt-8 flex justify-between">
        <button
          onClick={() => setStep("browse")}
          className="bg-blue-600 hover:bg-blue-700 text-white py-3 px-6 rounded transition"
        >
          Continue Shopping
        </button>
        <button
          onClick={() => setStep("payment")}
          disabled={cartWithQuantities.length === 0}
          className={`bg-green-600 hover:bg-green-700 text-white py-3 px-6 rounded transition
            ${cartWithQuantities.length === 0 ? 'opacity-50 cursor-not-allowed' : ''}
          `}
        >
          Proceed to Checkout
        </button>
      </div>
    </div>
  );
};

export default Cart;
