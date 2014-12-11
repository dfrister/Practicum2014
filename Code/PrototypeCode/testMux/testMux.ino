

//Arduino pins to circuit
#define muxBit0 0 //Arduino Pin 0, Atmega pin 2 to mux A0
#define muxBit1 1 //Arduino Pin 1, Atmega pin 3 to mux A1
#define muxBit2 2 //Arduino Pin 2, Atmega pin 4 to mux A2
#define muxBit3 3 //Arduino Pin 3, Atmega pin 5 to mux A3
#define enable 10


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
  pinMode(enable, OUTPUT);
  pinMode(muxBit0, OUTPUT); //Set muxBit0 as an output
  pinMode(muxBit1, OUTPUT); //Set muxBit1 as an output
  pinMode(muxBit2, OUTPUT); //Set muxBit2 as an output
  pinMode(muxBit3, OUTPUT); //Set muxBit3 as an output

}


void loop() {

  
  mux(0,0,0,0);
  delay(500);
  mux(0,0,0,1);
  delay(500);
  mux(0,0,1,0);
  delay(500);
  mux(0,0,1,1);
  delay(500);
  
  
  mux(0,1,0,0);
  delay(500);
  mux(0,1,0,1);
  delay(500);
  mux(0,1,1,0);
  delay(500);
  mux(0,1,1,1);
  delay(500);
  
  
  mux(1,0,0,0);
  delay(500);
  mux(1,0,0,1);
  delay(500);
  mux(1,0,1,0);
  delay(500);
  mux(1,0,1,1);
  delay(500);
  
  /*hh COMMITTTT NUMBER 10000
  mux(1,1,0,0);
  delay(500);
  mux(1,1,0,1);
  delay(500);
  mux(1,1,1,0);
  delay(500);
  mux(1,1,1,1);
  delay(500);*/
  
} //end of void
