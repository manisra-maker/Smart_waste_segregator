import React from 'react';
import './Home.css';
import { useNavigate } from 'react-router-dom';

function Home() {
  const navigate = useNavigate();

  const handleShowLocationsClick = () => {
    navigate('/locations');
  };

  const handleAboutUsClick = () => {
    navigate('/about');
  };

  return (
    <div className="home">
      <div className="home__header">WELCOME</div>
      <div className="home__body">
        <div className="home__bodyLogo">WASTE MANAGEMENT SOLUTIONS</div>
        <div className="home__bodyOptions">
          <button
            className="home__bodyShowLocations"
            onClick={handleShowLocationsClick}
          >
            SHOW LOCATIONS
          </button>
          <button className="home__bodyAboutUs" onClick={handleAboutUsClick}>
            ABOUT US
          </button>
        </div>
      </div>
    </div>
  );
}

export default Home;
