import React from 'react';
import './About.css';

function About() {
  return (
    <div className="about">
      Our goal to is to implement a smart waste segregation system using IOT .
      This website enables to live monitor wastes present in various locations
      throughout a city using a gps module.
      <br />{' '}
      <span style={{ display: 'flex' }}>
        Implemented by : Shreyas Lakshman Swamy
      </span>
      <span>
        Team members include:{' '}
        <ul>
          <li>Manish Rai</li>
          <li>Vivek V Kamath</li>
          <li>Parikshith M</li>
        </ul>
      </span>
    </div>
  );
}

export default About;
