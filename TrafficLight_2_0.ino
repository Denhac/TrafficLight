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
int REDLIGHT = 8;
int YELLOWLIGHT = 4;
int GREENLIGHT = 2;

int RXLED = 17;  // The RX LED has a defined Arduino pin
// The TX LED was not so lucky, we'll need to use pre-defined
// macros (TXLED1, TXLED0) to control that.
// (We could use the same macros for the RX LED too -- RXLED1,
//  and RXLED0.)

void setup()
{
 pinMode(REDLIGHT, OUTPUT);  // Set RX LED as an output
  pinMode(YELLOWLIGHT, OUTPUT);  // Set RX LED as an output
   pinMode(GREENLIGHT, OUTPUT);  // Set RX LED as an output
 // TX LED is set as an output behind the scenes

 //Serial.begin(9600); //This pipes to the serial monitor
 //Serial1.begin(9600); //This is the UART, pipes to sensors attached to board
}

void loop()
{
 digitalWrite(REDLIGHT, HIGH);   // set the LED on
 digitalWrite(YELLOWLIGHT, LOW);
 delay(10000);              // wait for a second
  digitalWrite(GREENLIGHT, HIGH);   // set the LED on
 digitalWrite(REDLIGHT, LOW);
 delay(10000);  
  digitalWrite(YELLOWLIGHT, HIGH);   // set the LED on
 digitalWrite(GREENLIGHT, LOW);
 delay(3000);    
}
