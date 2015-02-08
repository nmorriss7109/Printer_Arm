#include <Servo.h> 

Servo servoBase;
Servo servoShoulder;
Servo servoElbow;
Servo servoWrist;
Servo servoButton;

int valBase = 0;
int valShoulder = 0;
int valElbow = 0;
int valWrist = 0;
int valButton = 0;

char in;

int debug = 13;

void setup(){
  //initialize stuffad
  Serial.begin(9600);
  servoBase.attach(11);
  servoShoulder.attach(10);
  servoElbow.attach(9);
  servoWrist.attach(6);
  servoButton.attach(5);
}

void loop(){
  //servo code here 
  
  if (Serial.available()>0){
    in = (char)Serial.read();
  }
  servoBase.write(valBase);
  servoShoulder.write(valShoulder);
  servoElbow.write(valElbow);
  servoWrist.write(valWrist);
  servoButton.write(valButton);
  
  switch (in){
  case 'q':
  valShoulder--;
  delay(5);
  Debug();
  break;
  
  case 'w':
  Debug();
  
  break;
  
  case 'e':
  valShoulder++;
  delay(5);
  Debug();
  break;
  
  case 'a':
  valBase++;
  delay(5);
  Debug();
  break;
  
  case 's':
  
  Debug();
  break;
  
  case 'd':
  valBase--;
  delay(5);
  Debug();
  break;
  
  case ',':
  
  Debug();
  break;
  }

  if(valBase >= 179){
    valBase = 179; 
  }
  else if(valBase < 0){
    valBase = 0; 
  }
}

int forward(){
  
  return 0;
}

int backward(){
  Debug();
  return 0;
}


void Debug(){
  digitalWrite(debug, HIGH);
  delay(5);
  digitalWrite(debug, LOW); 
}
