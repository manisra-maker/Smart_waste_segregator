import { initializeApp } from 'firebase/app';
import { getDatabase, ref, onValue } from 'firebase/database';

const firebaseConfig = {
  apiKey: 'AIzaSyBdbw_jdcaB5VAcS5pjR9AvlPtpL9xfNQE',
  authDomain: 'esp8266-eba20.firebaseapp.com',
  databaseURL: 'https://esp8266-eba20-default-rtdb.firebaseio.com',
  projectId: 'esp8266-eba20',
  storageBucket: 'esp8266-eba20.appspot.com',
  messagingSenderId: '141242650568',
  appId: '1:141242650568:web:8166e741ef875f5ef1bafd',
  measurementId: 'G-4YETCT6BX8',
};

const app = initializeApp(firebaseConfig);
const latRef = ref(getDatabase(app), 'latitude');
const lngRef = ref(getDatabase(app), 'longitude');
const dryRef = ref(getDatabase(app), 'drywastecount');
const wetRef = ref(getDatabase(app), 'wetwastecount');

export { latRef, lngRef, dryRef, wetRef, app };
