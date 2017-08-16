  const int greenPin = 2;
  const int redPin = 8;
  const int yellowPin = 4;
  const int buttonPin = 9;
  const int maxDelay = 8;
  const int minDelay = 2;
  const bool buttonPressed = false;

void setup() {
  // put your setup code here, to run once:

  pinMode(buttonPin, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  
}

void loop() {
  if(digitalRead(buttonPin) == HIGH){
    competition();    
  }
  else{
    demo();
  }
     
  // put your main code here, to run repeatedly:

}

void lightBulb(int bulb){
  digitalWrite(bulb, HIGH);
}

void extinguishBulb(int bulb){
  digitalWrite(bulb, LOW);
}

void timeBulb(int bulb, int time){
  lightBulb(bulb);
  delay(time);
  extinguishBulb(bulb);
}

void demo() {
  while(true){
    
  }
}

void competition(){
  while(true){
    lightBulb(redPin);
    delay(1);
    int buttonState = digitalRead(buttonPin);
    while(buttonState == LOW){
    }
    while(buttonState == HIGH){
    }
    extinguishBulb(redPin);
    lightBulb(yellowPin);
    delay(random(minDelay,maxDelay));
    extinguishBulb(yellowPin);
    lightBulb(greenPin);
    while(buttonState == LOW){
    }
    while(buttonState == HIGH){
    }
  }
}

