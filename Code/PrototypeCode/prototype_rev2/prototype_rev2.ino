#define ledBIT0 4
#define ledBIT1 5
#define ledBIT2 6
#define ledBIT3 7
#define triggerPin 11
#define echoPin 12

void LED0() {
   digitalWrite(ledBIT0, LOW);
   digitalWrite(ledBIT1, LOW);
   digitalWrite(ledBIT2, LOW);
   digitalWrite(ledBIT3, LOW);
}
void LED1() {
   digitalWrite(ledBIT0, HIGH);
   digitalWrite(ledBIT1, LOW);
   digitalWrite(ledBIT2, LOW);
   digitalWrite(ledBIT3, LOW);
}
void LED2() {
   digitalWrite(ledBIT0, LOW);
   digitalWrite(ledBIT1, HIGH);
   digitalWrite(ledBIT2, LOW);
   digitalWrite(ledBIT3, LOW);
}
void LED3() {
   digitalWrite(ledBIT0, HIGH);
   digitalWrite(ledBIT1, HIGH);
   digitalWrite(ledBIT2, LOW);
   digitalWrite(ledBIT3, LOW);
}
void LED4() {
   digitalWrite(ledBIT0, LOW);
   digitalWrite(ledBIT1, LOW);
   digitalWrite(ledBIT2, HIGH);
   digitalWrite(ledBIT3, LOW);
}
void LED5() {
   digitalWrite(ledBIT0, HIGH);
   digitalWrite(ledBIT1, LOW);
   digitalWrite(ledBIT2, HIGH);
   digitalWrite(ledBIT3, LOW);
}
void LED6() {
   digitalWrite(ledBIT0, LOW);
   digitalWrite(ledBIT1, HIGH);
   digitalWrite(ledBIT2, HIGH);
   digitalWrite(ledBIT3, LOW);
}
void LED7() {
   digitalWrite(ledBIT0, HIGH);
   digitalWrite(ledBIT1, HIGH);
   digitalWrite(ledBIT2, HIGH);
   digitalWrite(ledBIT3, LOW);
}
void LED8() {
   digitalWrite(ledBIT0, LOW);
   digitalWrite(ledBIT1, LOW);
   digitalWrite(ledBIT2, LOW);
   digitalWrite(ledBIT3, HIGH);
}
void LED9() {
   digitalWrite(ledBIT0, HIGH);
   digitalWrite(ledBIT1, LOW);
   digitalWrite(ledBIT2, LOW);
   digitalWrite(ledBIT3, HIGH);
}
void LED10() {
   digitalWrite(ledBIT0, LOW);
   digitalWrite(ledBIT1, HIGH);
   digitalWrite(ledBIT2, LOW);
   digitalWrite(ledBIT3, HIGH);
}
void LED11() {
   digitalWrite(ledBIT0, HIGH);
   digitalWrite(ledBIT1, HIGH);
   digitalWrite(ledBIT2, LOW);
   digitalWrite(ledBIT3, HIGH);
}
void LED12() {
   digitalWrite(ledBIT0, LOW);
   digitalWrite(ledBIT1, LOW);
   digitalWrite(ledBIT2, HIGH);
   digitalWrite(ledBIT3, HIGH);
}
void LED13() {
   digitalWrite(ledBIT0, HIGH);
   digitalWrite(ledBIT1, LOW);
   digitalWrite(ledBIT2, HIGH);
   digitalWrite(ledBIT3, HIGH);
}
void LED14() {
   digitalWrite(ledBIT0, LOW);
   digitalWrite(ledBIT1, HIGH);
   digitalWrite(ledBIT2, HIGH);
   digitalWrite(ledBIT3, HIGH);
}
void LED15() {
   digitalWrite(ledBIT0, HIGH);
   digitalWrite(ledBIT1, HIGH);
   digitalWrite(ledBIT2, HIGH);
   digitalWrite(ledBIT3, HIGH);
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(ledBIT0, OUTPUT); //for the mux
  pinMode(ledBIT1, OUTPUT); //for the mux
  pinMode(ledBIT2, OUTPUT); //for the mux
  pinMode(ledBIT3, OUTPUT); //for the mux
  pinMode(triggerPin, OUTPUT); //Sensor Trigger
  pinMode(echoPin, INPUT); // Echo Input
  
  /*the variables state0 and state1 are used in case of a high-active or
  low-active switch (transistor type). State0 and state1 can be changed
  from HIGH to LOW or vice versa to change all the LED signals at once*/
  

}

// the loop function runs over and over again forever
void loop() {
  long duration, distance; //variables for pulsing
  digitalWrite(triggerPin, LOW); // set trigger low
  delayMicroseconds(2); // delay
  digitalWrite(triggerPin, HIGH); //set trigger high
  delayMicroseconds(5); //delay
  digitalWrite(triggerPin, LOW); // set trigger low
  int state0 = LOW; 
  int state1 = HIGH; 
  
  duration = pulseIn(echoPin, HIGH); //wait for echo to go high, returns time
  distance = duration / 74 / 2; //convert time to distance
  
  
  if (distance < 60) //if detection within 5 feet --- 60 inches = 5ft
   {  
  LED1();
  LED2();
  LED3();
   }
  else if (distance < 120) //if detection within 10 feet --- 120 inches = 10ft
   {
     LED1();
     LED2();

   }
   else if (distance < 240) //if detection within 15 feet --- 180 inches = 15 ft
   {
     LED1();
   }
   else //If nothing detected 
   {
     LED0();
   }
}
