#define ledBIT0 4
#define ledBIT1 5
#define ledBIT2 6
#define ledBIT3 7

#define triggerPin_0 13
#define echoPin_0 12
#define triggerPin_1 11
#define echoPin_1 10

#define sensorCount 1 // Number of sensors, zero indexed (subtract 1 from total count)

int triggerPins[] = {triggerPin_0, triggerPin_1};
int echoPins[] = { echoPin_0, echoPin_1};

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
  pinMode(triggerPin_0, OUTPUT); //Sensor Trigger
  pinMode(echoPin_0, INPUT); // Echo Input
  pinMode(triggerPin_1, OUTPUT); //Sensor Trigger
  pinMode(echoPin_1, INPUT); // Echo Input
}

// the loop function runs over and over again forever
void loop() {
  for (int c=0; c<= sensorCount; c++)
  {
    long duration, distance; //variables for pulsing
    digitalWrite(triggerPins[c], LOW); // set trigger low
    delayMicroseconds(2); // delay
    digitalWrite(triggerPins[c], HIGH); //set trigger high
    delayMicroseconds(5); //delay
    digitalWrite(triggerPins[c], LOW); // set trigger low
    int state0 = LOW; 
    int state1 = HIGH; 
  
    duration = pulseIn(echoPins[c], HIGH); //wait for echo to go high, returns time
    distance = duration / 74 / 2; //convert time to distance
   
   LED15();
    if (distance < 60) //if detection within 5 feet --- 60 inches = 5ft
    {  
      if (c == 0)
      {
        LED0();
        LED1();
        LED2();
      }
      else if (c == 1)
      {
        LED3();
        LED4();
        LED5();
      }
    else if (distance < 120) //if detection within 10 feet --- 120 inches = 10ft
    {
      if (c == 0)
      {
        LED0();
        LED1();
      }
      else if (c == 1)
      {
        LED3();
        LED4();
      }
    }
    else if (distance < 240) //if detection within 15 feet --- 180 inches = 15 ft
    {
      if (c == 0)
      {
        LED0();        
      }
      else if (c == 1)
      {
        LED3();
      }
      
    }
    else //If nothing detected 
    {
      LED15();
      }
    }
  }
}
