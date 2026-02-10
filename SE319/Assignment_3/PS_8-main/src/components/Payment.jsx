import React, { useState } from 'react';

const TAX_RATE = 0.07;

const Payment = ({ cart, setCart, setStep, onComplete = () => {} }) => {
  const [paymentInfo, setPaymentInfo] = useState({
    cardNumber: '',
    expiryDate: '',
    cvc: ''
  });

  const [userInfo, setUserInfo] = useState({
    name: '',
    email: '',
    address: ''
  });

  const [error, setError] = useState('');

  // Format card number with spaces every 4 digits
  const handleCardNumberChange = (e) => {
    let value = e.target.value.replace(/\D/g, ''); // Remove non-digits
    value = value.substring(0, 19); // Limit to 19 digits (max for card numbers)
    value = value.match(/.{1,4}/g)?.join(' ') || '';
    setPaymentInfo({ ...paymentInfo, cardNumber: value });
  };

  // Format expiry date as MM/YY with automatic /
  const handleExpiryChange = (e) => {
    let value = e.target.value.replace(/\D/g, ''); // Remove non-digits
    if (value.length > 4) value = value.slice(0, 4);
    if (value.length > 2) {
      value = value.slice(0, 2) + '/' + value.slice(2);
    }
    setPaymentInfo({ ...paymentInfo, expiryDate: value });
  };

  // CVC normal handler
  const handleChange = (e) => {
    const { name, value } = e.target;
    setPaymentInfo({ ...paymentInfo, [name]: value });
  };

  // User info change handler
  const handleUserChange = (e) => {
    const { name, value } = e.target;
    setUserInfo({ ...userInfo, [name]: value });
  };

  const cartWithQuantities = cart.map(course => ({
    ...course,
    quantity: course.quantity || 1,
  }));

  const subtotal = cartWithQuantities.reduce(
    (sum, course) => sum + Number(course.price) * course.quantity,
    0
  );
  const tax = subtotal * TAX_RATE;
  const total = subtotal + tax;

  const handleSubmit = (e) => {
    e.preventDefault();

    if (!userInfo.name || !userInfo.email || !userInfo.address) {
      setError('Please fill in all user information fields.');
      return;
    }

    // Remove spaces from card number for validation
    const cardNumberRaw = paymentInfo.cardNumber.replace(/\s/g, '');

    if (!cardNumberRaw || !paymentInfo.expiryDate || !paymentInfo.cvc) {
      setError('Please fill in all payment fields.');
      return;
    }
    if (cardNumberRaw.length < 12 || cardNumberRaw.length > 19) {
      setError('Card number should be between 12 and 19 digits.');
      return;
    }
    if (!/^\d{2}\/\d{2}$/.test(paymentInfo.expiryDate)) {
      setError('Expiry date should be in MM/YY format.');
      return;
    }
    if (paymentInfo.cvc.length < 3 || paymentInfo.cvc.length > 4) {
      setError('CVC should be 3 or 4 digits.');
      return;
    }

    setError('');
    onComplete(userInfo);
    setStep('summary');
  };

  return (
    <div className="max-w-3xl mx-auto p-6 space-y-6">
      <h2 className="text-3xl font-bold mb-4">Payment Details</h2>

      {/* Order Summary */}
      <div className="bg-white rounded shadow p-4 mb-6">
        <h3 className="text-xl font-semibold mb-2">Your Order:</h3>
        <ul>
          {cartWithQuantities.map(course => (
            <li key={course.offering_id} className="flex justify-between border-b py-2 last:border-b-0">
              <span>
                {course.title}
                {course.quantity > 1 && (
                  <span className="ml-2 text-gray-500">x{course.quantity}</span>
                )}
              </span>
              <span className="font-bold">
                ${(Number(course.price) * course.quantity).toFixed(2)}
              </span>
            </li>
          ))}
        </ul>
        <div className="flex justify-between mt-4">
          <span>Subtotal:</span>
          <span>${subtotal.toFixed(2)}</span>
        </div>
        <div className="flex justify-between mt-1">
          <span>Tax (7%):</span>
          <span>${tax.toFixed(2)}</span>
        </div>
        <div className="flex justify-between mt-1 text-lg font-bold">
          <span>Total:</span>
          <span>${total.toFixed(2)}</span>
        </div>
      </div>

      {/* User Information Form */}
      <div className="bg-white rounded shadow p-4 mb-6">
        <h3 className="text-xl font-semibold mb-2">Your Information</h3>
        <div className="space-y-4">
          <div>
            <label className="block mb-1 font-semibold">Name:</label>
            <input
              type="text"
              name="name"
              value={userInfo.name}
              onChange={handleUserChange}
              className="w-full border rounded p-2"
              placeholder="Your full name"
            />
          </div>
          <div>
            <label className="block mb-1 font-semibold">Email:</label>
            <input
              type="email"
              name="email"
              value={userInfo.email}
              onChange={handleUserChange}
              className="w-full border rounded p-2"
              placeholder="you@example.com"
            />
          </div>
          <div>
            <label className="block mb-1 font-semibold">Shipping Address:</label>
            <textarea
              name="address"
              value={userInfo.address}
              onChange={handleUserChange}
              className="w-full border rounded p-2"
              placeholder="Shipping address (if applicable)"
            ></textarea>
          </div>
        </div>
      </div>

      {/* Payment Info Form */}
      <form className="bg-white rounded shadow p-4 space-y-4" onSubmit={handleSubmit}>
        <div>
          <label className="block font-semibold mb-1">Card Number:</label>
          <input
            type="text"
            name="cardNumber"
            value={paymentInfo.cardNumber}
            onChange={handleCardNumberChange}
            className="w-full border rounded p-2"
            placeholder="1234 5678 9987 6543"
            maxLength={23}
            inputMode="numeric"
            autoComplete="cc-number"
          />
        </div>
        <div>
          <label className="block font-semibold mb-1">Expiry Date (MM/YY):</label>
          <input
            type="text"
            name="expiryDate"
            value={paymentInfo.expiryDate}
            onChange={handleExpiryChange}
            className="w-full border rounded p-2"
            placeholder="MM/YY"
            maxLength={5}
            autoComplete="cc-exp"
          />
        </div>
        <div>
          <label className="block font-semibold mb-1">CVC:</label>
          <input
            type="text"
            name="cvc"
            value={paymentInfo.cvc}
            onChange={handleChange}
            className="w-full border rounded p-2"
            placeholder="123"
            maxLength={4}
            inputMode="numeric"
            autoComplete="cc-csc"
          />
        </div>
        {error && <div className="text-red-600 font-semibold">{error}</div>}
        <button
          type="submit"
          className="bg-green-500 text-white py-2 px-6 rounded hover:bg-green-600 transition"
        >
          Submit Payment
        </button>
      </form>
    </div>
  );
};

export default Payment;
