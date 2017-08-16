/* Pro Micro Test Code
   by: Nathan Seidle
   modified by: Jim Lindblom
   SparkFun Electronics
   date: September 16, 2013
   license: Public Domain - please use this code however you'd like.
   It's provided as a learning tool.

   This code is provided to show how to control the SparkFun
   ProMicro's TX and RX LEDs within a sketch. It also serves
   to explain the difference between Serial.print() and
   Serial1.print().
*/
int RED = 8;
int YELLOW = 4;
int GREEN = 2;

int RXLED = 17;  // The RX LED has a defined Arduino pin
// The TX LED was not so lucky, we'll need to use pre-defined
// macros (TXLED1, TXLED0) to control that.
// (We could use the same macros for the RX LED too -- RXLED1,
//  and RXLED0.)

void setup()
{
 pinMode(RED, OUTPUT);  // Set RX LED as an output
  pinMode(YELLOW, OUTPUT);  // Set RX LED as an output
   pinMode(GREEN, OUTPUT);  // Set RX LED as an output
 // TX LED is set as an output behind the scenes

 Serial.begin(9600); //This pipes to the serial monitor
 //Serial1.begin(9600); //This is the UART, pipes to sensors attached to board
}
void light(int light, int time){
  digitalWrite(light, HIGH);
  delay(time);
  digitalWrite(light, LOW);
  delay(50);
}

void light(int light, int time, int postdelay){
  digitalWrite(light, HIGH);
  delay(time);
  digitalWrite(light, LOW);
  delay(postdelay);
}

void randLight(){
  int rndLight = random(1,4);
  int minSpeed = 50;
  int maxSpeed = 1000;
  switch (rndLight){
    case 1:
      light(GREEN, random(minSpeed,maxSpeed));
      break;
    case 2:
      light(YELLOW, random(minSpeed,maxSpeed));
      break;
    case 3:
      light(RED, random(minSpeed,maxSpeed));
      break;
    default:
      Serial.print("DANGER WILL ROBINSON! YOU GOT AN ERROR!");
      break;
    }
}

void robotStart(){
  light(RED, 5000);
  light(YELLOW, random(1000,10000));
  light(GREEN, 10000);
}

void stopLight(){
  light(RED, 7000);
  light(YELLOW, 1000);
  light(GREEN, 10000);
}

void cascade(){
  int curLight = random(0,3);
  for (int i = 0; i < 1250; i = i + 50){
    switch (curLight){
      case 0:
        light(GREEN, i);
        curLight++;
        break;
      case 1:
        light(YELLOW, i);
        curLight++;
        break;
      case 2:
        light(RED, i);
        curLight = 0;
        break;
      default:
        curLight = 0;
        break;
    }
  }
}

void sandstorm(){
  int dah = 75
  for(int i = 0; i < 6 ; i++){
    light(YELLOW, dah);
  }
  delay(4000);
  light(GREEN, 500);
  delay(100);
  for(int i = 0; i < 6 ; i++){
    light(YELLOW, dah);
  }
  delay(1100);
  for(int i = 0; i < 6 ; i++){
    light(YELLOW, dah);
  }
  delay(4000);
  light(GREEN, 500);
  delay(100);
  for(int i = 0; i < 5 ; i++){
    light(RED, dah);
  }
  light(YELLOW, 50);
  delay(4000);
  for(int j = 0; j < 4 ; j++){
    for(int i = 0; i < 6 ; i++){
      light(YELLOW, dah);
    }
    delay(1100);
    light(GREEN, 500);
    delay(100);
    for(int i = 0; i < 6 ; i++){
      light(YELLOW, dah);
    }
    delay(1100);
    for(int i = 0; i < 6 ; i++){
      light(YELLOW, dah);
    }
    delay(1100);
    light(GREEN, 500);
    delay(100);
    for(int i = 0; i < 6 ; i++){
      light(YELLOW, dah);
    }
    delay(1100);
  }
}

void loop()
{
  sandstorm();
  cascade();
  stopLight();
  robotStart();
  delay(100);
    
}
