import './App.css';
import Home from './components/Home';
import { BrowserRouter, Routes, Route } from 'react-router-dom';
import Locations from './components/Locations';
import About from './components/About';
import Location1 from './components/Location1';

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/locations" element={<Locations />} />
        <Route path="/about" element={<About />} />
        <Route path="/location1" element={<Location1 />} />
      </Routes>
    </BrowserRouter>
  );
}

export default App;
