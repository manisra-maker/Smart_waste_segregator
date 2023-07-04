import React from 'react';
import './AllLocations.css';
import wetwaste from './wet_waste.jpg';
import drywaste from './dry_waste.jpg';

function Location3() {
  return (
    <div className="location">
      <div className="location__header">OYSTER BAY</div>
      <div className="contents">
        <div className="wastes">
          <img src={wetwaste} alt="" />
          <img src={drywaste} alt="" />
        </div>
        <div className="levels">
          <div className="wet_level"></div>
          <div className="dry_level"></div>
        </div>
        <button>COLLECT WASTE</button>
      </div>
    </div>
  );
}

export default Location3;
