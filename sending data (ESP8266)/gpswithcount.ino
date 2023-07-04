#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <FirebaseESP8266.h>
#define FIREBASE_HOST "esp8266-eba20-default-rtdb.firebaseio.com"//Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "Txg6loNE9hXAAIedow593kHd8lbOMoKEQMpbFpQW" //Your Firebase Database Secret goes here
TinyGPSPlus gps;
SoftwareSerial SerialGPS(4, 5);
#define WIFI_SSID "Nothing phone (1)" //WiFi SSID to which you want NodeMCU to connect
#define WIFI_PASSWORD "connect2317" // password 
// Declare the Firebase Data object in the global scope
FirebaseData firebaseData;
#define SENSOR 12 // for metal sensor and remeber its ground and arduino ground must be common https://electropeak.com/learn/wp-content/uploads/2020/12/LJ12A3-4-ZBY-Circuit.jpg
//Servo s1;
int AnalogPin = A0;    // rain sensor pin
int output_value = 0;  // converts rain sensor values present in analog and maps it
int irPin = 14;
//int servoPin = 9;
int Irstatus = 0;
int drycount = 0;
int wetcount = 0;
float Latitude , Longitude;
String LatitudeString , LongitudeString;
void setup() {
  // put your setup code here, to run once:
  pinMode(irPin, INPUT);
  Serial.begin(9600);
  // Define the pin for metal sensor and and pullup te intial voltage to high when
  // when a object is detected make it zero
  pinMode(SENSOR, INPUT_PULLUP);
  //s1.attach(servoPin);
  //s1.write(90);
  Serial.println("Serial communication started\n\n");

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);



  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }


  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase

  Firebase.reconnectWiFi(true);
  delay(1000);
}

void loop() {
  while (SerialGPS.available() > 0) {
    Serial.println("Entering GPS state 1 ");
    if (gps.encode(SerialGPS.read()))
    {
      Serial.println("Entering GPS state 2");
      if (gps.location.isValid())
      {
        Serial.println("Entering GPS state 3");
        Latitude = gps.location.lat();
        LatitudeString = String(Latitude , 6);
        Longitude = gps.location.lng();
        LongitudeString = String(Longitude , 6);
        Serial.println("Latitude: " + LatitudeString);
        Serial.println("Longitude " + LongitudeString);

        if (Firebase.setString(firebaseData, "/latitude", LatitudeString))
        { // On successful Write operation, function returns 1
          Serial.println("Entering GPS state 4");
          Serial.println("Value Uploaded Successfully");
          Serial.println("Latitude: " + LatitudeString);
          Serial.println("\n");
          delay(1000);
        }

        else {
          Serial.println(firebaseData.errorReason());
        }

        if (Firebase.setString(firebaseData, "/longitude", LongitudeString))
        { // On successful Write operation, function returns 1
          Serial.println("Value Uploaded Successfully");
          Serial.println("Longitude " + LongitudeString);
          Serial.println("\n");
          delay(1000);
        }

        else {
          Serial.println(firebaseData.errorReason());
        }

      }
    }
  }
  // put your main code here, to run repeatedly:
  int RainValues = analogRead(AnalogPin);
  Serial.println(String(drycount) + "drycount");
  Serial.println(String(wetcount) + "wetcount");
  Serial.println(drycount + "drycount");
  Serial.println(wetcount + "wetcount");
  output_value = map(RainValues, 1023, 0, 100, 0);
  Irstatus = digitalRead(irPin);
  int status = digitalRead(SENSOR);  // read the sensor
  //Serial.println(status);
  //  if (drycount == 10)
  //  {
  //    drycount = 10;
  //  }
  //  else if (wetcount == 10)
  //  {
  //    wetcount = 10;
  //  }
  if (output_value <= 90 && Irstatus == 0 && status == 1 && wetcount < 10)
  {
    Serial.println("WET WASTE and NON-METAL");
    //s1.write(135);
    wetcount++;
    delay(5000);
    if (Firebase.setInt(firebaseData, "/wetwastecount", wetcount))
    { // On successful Write operation, function returns 1
      Serial.println("Value Uploaded Successfully");
      Serial.println("wetwastecount: " + String(wetcount));
      Serial.println("\n");
      delay(1000);
    }

    else {
      Serial.println(firebaseData.errorReason());
    }
  }
  else if (output_value <= 90 && Irstatus == 0 && status == 0 && wetcount < 10)
  {
    Serial.println("WET WASTE and METAL");
    //    s1.write(45);
    wetcount++;
    delay(5000);
    if (Firebase.setInt(firebaseData, "/wetwastecount", wetcount))
    { // On successful Write operation, function returns 1
      Serial.println("Value Uploaded Successfully");
      Serial.println("wetwastecount: " + String(wetcount));
      Serial.println("\n");
      delay(1000);
    }

    else {
      Serial.println(firebaseData.errorReason());
    }
  }
  else if (output_value > 90 && Irstatus == 0 && status == 1 && drycount < 10)
  {
    Serial.println("DRY WASTE and NON-METAL");
    //s1.write(45);
    drycount++;
    delay(5000);
    if (Firebase.setInt(firebaseData, "/drywastecount", drycount))
    { // On successful Write operation, function returns 1
      Serial.println("Value Uploaded Successfully");
      Serial.println("drywastecount: " + String(drycount));
      Serial.println("\n");
      delay(1000);
    }

    else {
      Serial.println(firebaseData.errorReason());
    }
  }
  else if (output_value > 90 && Irstatus == 0 && status == 0 && drycount < 10)
  {
    Serial.println("DRY WASTE and METAL");
    drycount++;
    //s1.write(45);
    delay(5000);
    if (Firebase.setInt(firebaseData, "/drywastecount", drycount))
    { // On successful Write operation, function returns 1
      Serial.println("Value Uploaded Successfully");
      Serial.println("drywastecount: " + String(drycount));
      Serial.println("\n");
      delay(1000);
    }

    else {
      Serial.println(firebaseData.errorReason());
    }
  }
  else
  {
    Serial.println("DETECTING....");
    Serial.println(output_value);
    //s1.write(90);
    delay(5000);
  }
}
