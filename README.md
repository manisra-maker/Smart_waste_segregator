# How you should run this project 

At first you should RAINIRMETAL.h running in your Arduino uno and GPS count running in your ESP 8266 . For connections related to this project you can check out this circuit diagram 


![Smart-waste-segregator-circuit-diagram](https://github.com/manisra-maker/Smart_waste_segregator/assets/55314646/8f706a73-4149-41ac-9afc-81a75bb13ca4)


The brains of this project is a arduino uno r3 along with a rain sensor (to detect wet and dry wastes) , inductive proximity sensor (for metal detection) , an IR sensor to detect an object , GPS module neo 6m 
which helps me get location data of the bin , a ESP 8266 to send this data to my website and a servo to seperate the wastes. 

Additional improvements :

1. You can add a Ultrasonic sensor to improve the overall detection process of a object and to detect waste levels . 
2. You could use a camera module to detect  substances that are transparent . eg - a transparent waster bottle . 

Disadvantages :

1. Not entirely accurate.
2. Can detect wastes present in a bag or cover. 
