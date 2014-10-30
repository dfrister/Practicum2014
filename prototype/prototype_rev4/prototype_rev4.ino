/*T04 Motorcycle Proximity Sensor
October 27, 2014
github.com/dfrister/practicum2014
*/

/* This code will poll three sensors for distances of an object
and will control the outputs to 3 seperate banks of 3 LEDs each in
order to function as a proximity detector for the application of a
blindspot detector for a motorcycle*/

//Arduino pins to circuit
#define muxBit0 0 //Arduino Pin 0, Atmega pin 2 to mux A0
#define muxBit1 1 //Arduino Pin 1, Atmega pin 3 to mux A1
#define muxBit2 2 //Arduino Pin 2, Atmega pin 4 to mux A2
#define muxBit3 3 //Arduino Pin 3, Atmega pin 5 to mux A3
#define triggerPin_0 4 //Arduino Pin 4, Atmega pin 6 to sensor header 1
#define echoPin_0 5 //Arduino Pin 5, Atmega pin 11 to sensor header 2
#define triggerPin_1 6  //Arduino Pin 6, Atmega pin 12 to sensor header 3
#define echoPin_1 7 //Arduino Pin 7, Atmega pin 13 to sensor header 4
#define triggerPin_2 8 //Arduino Pin 8, Atmega pin 14 to sensor header 5
#define echoPin_2 9 //Arduino Pin 9, Atmega pin 15 to sensor header 6

#define sensorCount 1 //Number of sensors, zero indexed (subtract 1 from total count)

/*The mux() function takes in four arguments that represent a 4-bit binary code
which will output the code to a multiplexer in order to control 16 outputs.
Note that 0/false/LOW and 1/true/HIGH are interchangable*/
void mux(bool bit0, bool bit1, bool bit2, bool bit3) {
  digitalWrite(muxBit0, bit0);
  digitalWrite(muxBit1, bit1);
  digitalWrite(muxBit2, bit2);
  digitalWrite(muxBit3, bit3);
}
/*Variables for the setup and loop function)*/
int triggerPins[] = {triggerPin_0, triggerPin_1, triggerPin_2};
int echoPins[] = {echoPin_0, echoPin_1, echoPin_2};

/*The setup function runs on startup*/
void setup() {
  pinMode(muxBit0, OUTPUT); //Set muxBit0 as an output
  pinMode(muxBit1, OUTPUT); //Set muxBit1 as an output
  pinMode(muxBit2, OUTPUT); //Set muxBit2 as an output
  pinMode(muxBit3, OUTPUT); //Set muxBit3 as an output
  pinMode(triggerPin_0, OUTPUT); //Set Sensor 1 Trigger as an output
  pinMode(echoPin_0, INPUT); //Set sensor 1 Echo as an input
  pinMode(triggerPin_1, OUTPUT); //Set Sensor 2 Trigger as an output
  pinMode(echoPin_1, INPUT); //Set sensor 2 Echo as an input  
  pinMode(triggerPin_2, OUTPUT); //Set Sensor 3 Trigger as an output
  pinMode(echoPin_2, INPUT); //Set sensor 3 Echo as an input
}

/*Variables for checking if the state changed*/
bool change = false;
int a, b, c, d;
int newbin[] = {0,0,0};
int oldbin[] = {0,0,0};

void loop() {
  for (int c=0; c<= sensorCount; c++) { //Loop for polling sensors, is this needed
    long duration = 0;
    long distance = 0;
    /*This will poll the sensors*/
    digitalWrite(triggerPins[c], 0); //set trigger low
    delayMicroseconds(2); //low for 2 microseconds
    digitalWrite(triggerPins[c], 1); //set trigger high
    delayMicroseconds(5); //high for 5 microseconds
    digitalWrite(triggerPins[c], 0); //set trigger low
    duration = pulseIn(echoPins[c], 1); //wait for echo to go high, returns time
    //speed travels at 1130 feet per second, so divide duration by 2 (out to in) and multiply by 442 microseconds per feet
    //distance = duration / 73.746 / 2; //distance is in feet, sound travels on foot in
    distance = duration / 876 / 2; //distance is in feet, sound travels one foot in 876 microseconds
    if ( 0 < distance <= 5 ) {newbin[c] = 1;}
    else if ( 5 < distance <= 10 ) {newbin[c] = 2;}
    else if ( 10 < distance <= 20 ) {newbin[c] = 3;}
    else {newbin[c] = 0;}
    
    if (oldbin[c] = newbin[c]) {change = false;};
    
    switch (c) {
      case 0: //sensor 1 left sensor
      if (change == true) {
        if (distance < 20) {
          a=0;
          b=1;
          c=1;
          d=0;
          mux(a,b,c,d);
        }
        if (distance < 10) {
          a=0;
          b=1;
          c=1;
          d=0;
          mux(a,b,c,d);
        }
        if (distance < 5) {
          a=0;
          b=1;
          c=1;
          d=0;
          mux(a,b,c,d);
        }
      }
      else if (change == false) {
         mux(a,b,c,d); //send last code
      }
      break;
      case 1: //sensor 2 right sensor
      if (change == true) {
        if (distance < 20) {
          a=0;
          b=1;
          c=1;
          d=0;
          mux(a,b,c,d);
        }
        if (distance < 10) {
          a=0;
          b=1;
          c=1;
          d=0;
          mux(a,b,c,d);
        }
        if (distance < 5) {
          a=0;
          b=1;
          c=1;
          d=0;
          mux(a,b,c,d);
        }
      }
      else if (change == false) {
         mux(a,b,c,d); //last code
      }
      break;      
      case 2: //sensor 3 rear sensor
      if (change == true) {
        if (distance < 20) {
          a=0;
          b=1;
          c=1;
          d=0;
          mux(a,b,c,d);
        }
        if (distance < 10) {
          a=0;
          b=1;
          c=1;
          d=0;
          mux(a,b,c,d);
        }
        if (distance < 5) {
          a=0;
          b=1;
          c=1;
          d=0;
          mux(a,b,c,d);
        }
      }
      else if (change == false) {
         mux(a,b,c,d); //last code
      }
      break;
    } // end of switch
    oldbin[c] = newbin[c];
  } //end of for
} //end of void
