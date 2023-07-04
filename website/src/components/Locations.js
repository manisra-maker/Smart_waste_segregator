import React from 'react';
import './Locations.css';
import { useNavigate } from 'react-router-dom';

function Locations() {
  const navigate = useNavigate();

  const handleLocation1Click = () => {
    navigate('/location1');
  };

  const handleLocation2Click = () => {
    navigate('/location2');
  };

  const handleLocation3Click = () => {
    navigate('/location3');
  };

  return (
    <div className="locationsPage">
      <p className="locations">LOCATIONS</p>
      <div className="each_loc">
        <br />
        <br />
        <p className="loc1" onClick={handleLocation1Click}>
          VVCE
        </p>
        {/* <br />
        <p className="loc2" onClick={handleLocation2Click}>
          LOCATION 2
        </p>
        <br />
        <p className="loc3" onClick={handleLocation3Click}>
          LOCATION 3
        </p>
        <br /> */}
      </div>
    </div>
  );
}

export default Locations;
