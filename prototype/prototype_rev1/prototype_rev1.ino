/*
 This code will send a pulse to a HC-SR04 ultrasonic sensor and 
 receive a return signal. The input from the sensor will light 
 up a set of LED's based off the distance of an object
 in the sensors line of sight. 
 */


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT); // Close LED
  pinMode(8, OUTPUT); // Mid LED
  pinMode(7, OUTPUT); //Far LED
  pinMode(4, OUTPUT); //Sensor Trigger
  pinMode(12, INPUT); // Echo Input
  
  /*the variables state0 and state1 are used in case of a high-active or
  low-active switch (transistor type). State0 and state1 can be changed
  from HIGH to LOW or vice versa to change all the LED signals at once*/
  

}

// the loop function runs over and over again forever
void loop() {
  long duration, distance; //variables for pulsing
  digitalWrite(4, LOW); // set trigger low
  delayMicroseconds(2); // delay
  digitalWrite(4, HIGH); //set trigger high
  delayMicroseconds(5); //delay
  digitalWrite(4, LOW); // set trigger low
   int state0 = LOW; 
  int state1 = HIGH; 
  
  duration = pulseIn(12, HIGH); //wait for echo to go high, returns time
  distance = duration / 74 / 2; //convert time to distance
  
  digitalWrite(13, state0); //turn off close LED
  digitalWrite(8, state0); //turn off  mid LED
  digitalWrite(7, state0); //turn off far LED
  
  if (distance < 60) //if detection within 5 feet --- 60 inches = 5ft
   {  
     digitalWrite(13, state1); //turn on close LED
     digitalWrite(8, state1); //turn on mid LED
     digitalWrite(7, state1); //turn on far LED
   }
  else if (distance < 120) //if detection within 10 feet --- 120 inches = 10ft
   {
     digitalWrite(8, state1); //turn on mid LED
     digitalWrite(7, state1); //turn on far LED

   }
   else if (distance < 180) //if detection within 15 feet --- 180 inches = 15 ft
   {
     digitalWrite(7, state1); //turn on far LED
   }
   else //If nothing detected 
   {
     digitalWrite(13, state0); //turn off close LED
     digitalWrite(8, state0); //turn off  mid LED
     digitalWrite(7, state0); //turn off far LED
   }
}
