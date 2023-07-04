#include <Servo.h>
#define SENSOR 2 // for metal sensor and remeber its ground and arduino ground must be common https://electropeak.com/learn/wp-content/uploads/2020/12/LJ12A3-4-ZBY-Circuit.jpg
Servo s1;
int AnalogPin = A0;    // rain sensor pin
int output_value = 0;  // converts rain sensor values present in analog and maps it
int irPin = 7;
int servoPin = 9;
int Irstatus = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(irPin, INPUT);
  Serial.begin(9600);
  // Define the pin for metal sensor and and pullup te intial voltage to high when
  // when a object is detected make it zero
  pinMode(SENSOR, INPUT_PULLUP);
  s1.attach(servoPin);
  s1.write(90);
}

void loop() {

  int RainValues = analogRead(AnalogPin);
  output_value = map(RainValues, 1023, 0, 100, 0);
  Irstatus = digitalRead(irPin);
  int status = digitalRead(SENSOR);  // read the sensor
  //Serial.println(status);
  delay(3000);
  if (output_value <= 90 && Irstatus == 0 && status == 1)
  {
    Serial.println("WET WASTE and NON-METAL");
    s1.write(135);
    delay(5000);
  }
  else if (output_value <= 90 && Irstatus == 0 && status == 0)
  {
    Serial.println("WET WASTE and METAL");
    s1.write(45);
    delay(5000);
  }
  else if (output_value > 90 && Irstatus == 0 && status == 1)
  {
    Serial.println("DRY WASTE and NON-METAL");
    s1.write(45);
    delay(5000);
  }
  else if (output_value > 90 && Irstatus == 0 && status == 0)
  {
    Serial.println("DRY WASTE and METAL");
    s1.write(45);
    delay(5000);
  }

  else
  {
    Serial.println("DETECTING....");
    Serial.println(output_value);
    s1.write(90);
    delay(5000);
  }
  //delay(200);
}
