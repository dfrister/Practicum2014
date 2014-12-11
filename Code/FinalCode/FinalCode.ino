/*T04 Motorcycle Proximity Sensor
December 11th, 2014
github.com/dfrister/practicum2014 

This code will poll three sensors for distances of an object
and will control the outputs to 3 seperate banks of 3 LEDs each in
order to function as a proximity detector for the application of a
blindspot detector for a motorcycle*/

//Arduino pins to circuit
#define muxBit0 0 //Arduino Pin 0, Atmega pin 2 to mux A0
#define muxBit1 1 //Arduino Pin 1, Atmega pin 3 to mux A1
#define muxBit2 2 //Arduino Pin 2, Atmega pin 4 to mux A2
#define muxBit3 3 //Arduino Pin 3, Atmega pin 5 to mux A3
#define triggerPin_left 4 //Arduino Pin 4, Atmega pin 6 to sensor header 1 //LEFT
#define echoPin_left 5 //Arduino Pin 5, Atmega pin 11 to sensor header 2 //LEFT
#define triggerPin_rear 6 //Arduino Pin 6, Atmega pin 12 to sensor header 3 // RIGHT
#define echoPin_rear 7 //Arduino Pin 7, Atmega pin 13 to sensor header 4 // RIGHT
#define triggerPin_right 8  //Arduino Pin 8, Atmega pin 14 to sensor header 5 // RIGHT
#define echoPin_right 9 //Arduino Pin 9, Atmega pin 15 to sensor header 6 // RIGHT
#define enable 10 //Arduino pin 10, Atmega pin 16, to mux enable

#define farDist 15
#define midDist 10
#define closeDist 5

/*The mux() function takes in four arguments that represent a 4-bit binary code
which will output the code to a multiplexer in order to control 16 outputs.
Note that 0/false/LOW and 1/true/HIGH are interchangable*/
void mux(bool bit3, bool bit2, bool bit1, bool bit0) {
  digitalWrite(muxBit0, bit0);
  digitalWrite(muxBit1, bit1);
  digitalWrite(muxBit2, bit2);
  digitalWrite(muxBit3, bit3);
  delayMicroseconds(100);
  digitalWrite(enable,0);
  delayMicroseconds(100);
  digitalWrite(enable,1);
  delayMicroseconds(100);
}

/*The setup function runs on startup*/
void setup() {
  pinMode(muxBit0, OUTPUT); //Set muxBit0 as an output
  pinMode(muxBit1, OUTPUT); //Set muxBit1 as an output
  pinMode(muxBit2, OUTPUT); //Set muxBit2 as an output
  pinMode(muxBit3, OUTPUT); //Set muxBit3 as an output
  pinMode(triggerPin_left, OUTPUT); //Set Sensor 1 Trigger as an output
  pinMode(echoPin_left, INPUT); //Set sensor 1 Echo as an input
  pinMode(triggerPin_right, OUTPUT); //Set Sensor 2 Trigger as an output
  pinMode(echoPin_right, INPUT); //Set sensor 2 Echo as an input  
  pinMode(triggerPin_rear, OUTPUT); //Set Sensor 3 Trigger as an output
  pinMode(echoPin_rear, INPUT); //Set sensor 3 Echo as an input
  pinMode(enable, OUTPUT);
  
  mux(0,1,1,1);
  mux(1,0,1,1);
  mux(0,0,1,1);
 
}
void loop() {
  
  long duration_left = 0;
  float distance_left = 0;
  //This will poll the sensors
  digitalWrite(triggerPin_left, 0); //set trigger low
  delayMicroseconds(2); //low for 2 microseconds
  digitalWrite(triggerPin_left, 1); //set trigger high
  delayMicroseconds(5); //high for 5 microseconds
  digitalWrite(triggerPin_left, 0); //set trigger low
  duration_left = pulseIn(echoPin_left, 1); //wait for echo to go high, returns time
  distance_left = duration_left / 876 / 2; //distance is in feet, sound travels one foot in 876 microseconds

  long duration_right = 0;
  float distance_right = 0;
  //This will poll the sensors
  digitalWrite(triggerPin_right, 0); //set trigger low
  delayMicroseconds(2); //low for 2 microseconds
  digitalWrite(triggerPin_right, 1); //set trigger high
  delayMicroseconds(5); //high for 5 microseconds
  digitalWrite(triggerPin_right, 0); //set trigger low
  duration_right = pulseIn(echoPin_right, 1); //wait for echo to go high, returns time
  distance_right = duration_right / 876 / 2; //distance is in feet, sound travels one foot in 876 microseconds  
 
  long duration_rear = 0;
  float distance_rear = 0;
  //This will poll the sensors
  digitalWrite(triggerPin_rear, 0); //set trigger low
  delayMicroseconds(2); //low for 2 microseconds
  digitalWrite(triggerPin_rear, 1); //set trigger high
  delayMicroseconds(5); //high for 5 microseconds
  digitalWrite(triggerPin_rear, 0); //set trigger low
  duration_rear = pulseIn(echoPin_rear, 1); //wait for echo to go high, returns time
  distance_rear = duration_rear / 876 / 2; //distance is in feet, sound travels one foot in 876 microseconds
  
  mux(0,1,1,1);
  mux(1,0,1,1);
  mux(0,0,1,1);    
  
  if (distance_left < farDist) { //green
    mux(1,0,0,0);
  }
  if (distance_left < midDist) { //yellow
    mux(1,0,0,1);          
  }
  if (distance_left < closeDist) { //red
    mux(1,0,1,0);          
  }

  if (distance_right < farDist) { //green
    mux(0,0,0,0);
  }
  if (distance_right < midDist) { //yellow
    mux(0,0,0,1);          
  }
  if (distance_right < closeDist) { //red
    mux(0,0,1,0);          
  }

  if (distance_rear < farDist) { //green

    mux(0,1,0,0);
  }
  if (distance_rear < midDist) { //yellow

    mux(0,1,0,1);          
  }
  if (distance_rear < closeDist) { //red

    mux(0,1,1,0);          
  }
  delay(0.05);
}
