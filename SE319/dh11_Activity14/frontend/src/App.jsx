// Prepared By: Daniel Hargrave
// dh11@iastate.edu
// Date: 5/12/2025

import React, { useState } from 'react';
import Homepage from './components/Homepage';
import Login from './components/Login';
import Signup from './components/Signup';
import Tutors from './components/Tutors';
import Classes from './components/Classes';
import Schedule from './components/Schedule';
import TutorClasses from './components/TutorClasses';
import StudentClasses from './components/StudentClasses';
import Reviews from './components/Reviews';
import Navbar from './components/Navbar';

function App() {
  const [page, setPage] = useState("home");
  const [user, setUser] = useState(null);

  return (
    <div>
      <Navbar setPage={setPage} user={user} />
      {page === "home" && <Homepage setPage={setPage} />}
      {page === "login" && <Login setPage={setPage} onLogin={setUser} />}
      {page === "signup" && <Signup setPage={setPage} />}
      {page === "tutors" && <Tutors setPage={setPage} user={user} />}
      {page === "classes" && <Classes setPage={setPage} user={user} />}
      {page === "schedule" && <Schedule setPage={setPage} user={user} />}
      {page === "student-classes" && <StudentClasses setPage={setPage} user={user} />}
      {page === "tutor-classes" && <TutorClasses setPage={setPage} user={user} />}
      {page === "reviews" && <Reviews setPage={setPage} user={user} />}
    </div>
  );
}

export default App;
