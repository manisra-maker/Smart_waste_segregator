import React, { useEffect, useState } from 'react';
import './AllLocations.css';
import wetwaste from './wet_waste.jpg';
import drywaste from './dry_waste.jpg';
import { latRef, lngRef, app, dryRef, wetRef } from './firebase';
import { getDatabase, ref, onValue } from 'firebase/database';

function Location1() {
  const [dryWasteCount, setDryWasteCount] = useState(null);
  const [wetWasteCount, setWetWasteCount] = useState(null);
  const [latitude, setLatitude] = useState(null);
  const [longitude, setLongitude] = useState(null);
  const [isButtonDisabled, setIsButtonDisabled] = useState(false);

  useEffect(() => {
    onValue(latRef, (snapshot) => {
      const data = snapshot.val();
      setLatitude(data);
    });

    onValue(lngRef, (snapshot) => {
      const data = snapshot.val();
      setLongitude(data);
    });

    onValue(wetRef, (snapshot) => {
      const data = snapshot.val();
      setWetWasteCount(data);
    });

    onValue(dryRef, (snapshot) => {
      const data = snapshot.val();
      setDryWasteCount(data);
    });
  }, []);

  const zoomLevel = 15;
  const mapUrl = `https://www.google.com/maps?q=${latitude},${longitude}${zoomLevel}`;

  const shouldDisableButton = true;

  return (
    <div className="location">
      <div className="location__header">VVCE</div>
      <div className="contents">
        <div className="wastes">
          <img src={wetwaste} alt="" />
          <img src={drywaste} alt="" />
        </div>
        <div className="levels">
          <div className="wet_level">
            <div
              style={{
                width:
                  wetWasteCount < 10 && wetWasteCount > 0
                    ? `calc(${wetWasteCount} * (10%))`
                    : '300px',
                backgroundColor: 'green',
                height: '30px',
                borderRadius: '15px',
              }}
            ></div>
          </div>

          <div className="dry_level">
            <div
              style={{
                width:
                  dryWasteCount < 10 && dryWasteCount > 0
                    ? `calc(${dryWasteCount} * (10%))`
                    : '300px',
                backgroundColor: 'green',
                height: '30px',
                borderRadius: '15px',
              }}
            ></div>
          </div>
        </div>
        <button
          disabled={shouldDisableButton || isButtonDisabled}
          className={shouldDisableButton || isButtonDisabled ? 'disabled' : ''}
        >
          <a href={mapUrl} className="waste_loc">
            COLLECT WASTE
          </a>
        </button>
      </div>
    </div>
  );
}

export default Location1;
