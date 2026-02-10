import React, { useState, useEffect } from 'react';
import { Courses } from '../data/Courses';

const validPrefixes = ['COMS', 'CPRE', 'SE', 'DS', 'STAT', 'EE', 'BIO', 'PHYS', 'ECON', 'LING'];

const Browse = ({ cart, setCart, setStep }) => {
  const [searchQuery, setSearchQuery] = useState('');
  const [prefixOptions, setPrefixOptions] = useState([]);
  const [selectedPrefix, setSelectedPrefix] = useState('');
  const [difficultyFilter, setDifficultyFilter] = useState('');

  useEffect(() => {
    setTimeout(() => {
      setPrefixOptions(validPrefixes);
    }, 500);
  }, []);

  const filteredCourses = Courses.filter(course => {
    if (!course.title.toLowerCase().includes(searchQuery.toLowerCase())) {
      return false;
    }

    const match = course.id.match(/^([A-Z]+)(\d+)$/);
    if (!match) return false;

    const [_, prefix, numberStr] = match;

    if (selectedPrefix && prefix !== selectedPrefix) {
      return false;
    }

    const difficultyMap = {
      '1': 'Beginner',
      '2': 'Intermediate',
      '3': 'Advanced',
      '4': 'Expert',
      '5': 'Master'
    };
    const difficultyLevel = difficultyMap[numberStr.charAt(0)] || '';

    if (difficultyFilter && difficultyLevel !== difficultyFilter) {
      return false;
    }

    return true;
  });

  const addToCart = (course) => {
    setCart(prev => {
      if (prev.some(item => item.offering_id === course.offering_id)) {
        return prev;
      }
      return [...prev, course];
    });
  };

  const isInCart = (offering_id) => cart.some(item => item.offering_id === offering_id);

  return (
    <div className="max-w-7xl mx-auto p-4">
      <h2 className="text-3xl font-bold mb-6">Browse Courses</h2>

      {/* Search input (Extra Credit) */}
      <input
        type="text"
        placeholder="Search courses..."
        value={searchQuery}
        onChange={e => setSearchQuery(e.target.value)}
        className="w-full p-2 mb-4 border rounded"
      />

      {/* Prefix filter */}
      <div className="mb-4">
        <label className="block mb-1 font-semibold">Filter by Type:</label>
        <select
          value={selectedPrefix}
          onChange={e => setSelectedPrefix(e.target.value)}
          className="w-full p-2 border rounded"
        >
          <option value="">All Types</option>
          {prefixOptions.map((prefix) => (
            <option key={prefix} value={prefix}>{prefix}</option>
          ))}
        </select>
      </div>

      {/* Difficulty filter */}
      <div className="mb-4">
        <label className="block mb-1 font-semibold">Filter by Level:</label>
        <select
          value={difficultyFilter}
          onChange={e => setDifficultyFilter(e.target.value)}
          className="w-full p-2 border rounded"
        >
          <option value="">All Levels</option>
          {Object.entries({
            '1': 'Beginner',
            '2': 'Intermediate',
            '3': 'Advanced',
            '4': 'Expert',
            '5': 'Master'
          }).map(([num, level]) => (
            <option key={num} value={level}>{level}</option>
          ))}
        </select>
      </div>

      {/* Course list */}
      <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-8">
        {filteredCourses.map(course => {
          const added = isInCart(course.offering_id);
          return (
            <div key={course.offering_id} className="bg-white rounded shadow p-6 flex flex-col">
              <img src={course.image} alt={course.title} className="w-full h-40 object-cover rounded mb-4" />
              <h3 className="text-xl font-semibold mb-1">{course.title}</h3>
              <p className="text-sm text-gray-600 font-mono mb-2">{course.id}</p>
              <p className="text-gray-700 mb-3">{course.description}</p>
              <p className="text-sm text-gray-500 mb-1">Instructor: {course.instructor}</p>
              <p className="text-sm text-yellow-500 mb-3">Rating: {course.rating} ★</p>
              <p className="text-lg font-bold mb-6">${course.price}</p>
              <button
                onClick={() => addToCart(course)}
                disabled={added}
                className={`mt-auto rounded px-4 py-2 transition ${added ? 'bg-red-600 cursor-not-allowed' : 'bg-blue-600 hover:bg-blue-700 text-white'}`}
              >
                {added ? 'Added to Cart' : 'Add to Cart'}
              </button>
            </div>
          );
        })}
      </div>

      <button
        onClick={() => setStep('cart')}
        className="mt-10 bg-green-600 hover:bg-green-700 text-white rounded px-8 py-3 transition"
      >
        Go to Cart
      </button>
    </div>
  );
};

export default Browse;
