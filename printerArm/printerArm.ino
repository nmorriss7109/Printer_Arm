#include <Servo.h> 

Servo servoBase;
Servo servoShoulder;
Servo servoElbow;
Servo servoWrist;
Servo servoButton;

int valBase = 0;
int valShoulder = 90;
int valElbow = 0;
int valWrist = 0;
int valButton = 0;

char in;

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
  
  if (in == 'q'){
    down(); 
  }
  if (in == 'w'){
    forward(); 
  }
  if (in == 'e'){
    up(); 
  }
  if (in == 'a'){
    left(); 
  }
  if (in == 's'){
    backward(); 
  }
  if (in == 'd'){
    right(); 
  }
  
  if(valBase > 1023){
    valBase = 1023; 
  }
  else if(valBase < 0){
    valBase = 0; 
  }
}

int forward(){
  
  return valBase;
  return valShoulder;
  return valElbow;
  return valWrist;
  return valButton;
}

int backward(){
  
  return valBase;
  return valShoulder;
  return valElbow;
  return valWrist;
  return valButton;
}

int left(){
  valBase++;
  delay(10);
  return valBase;
  return valShoulder;
  return valElbow;
  return valWrist;
  return valButton;
}

int right(){
  valBase--;
  delay(10);
  return valBase;
  return valShoulder;
  return valElbow;
  return valWrist;
  return valButton;
}

int up(){
  valShoulder++;
  delay(10);
  return valBase;
  return valShoulder;
  return valElbow;
  return valWrist;
  return valButton;
}

int down(){
  valShoulder--;
  delay(10);
  return valBase;
  return valShoulder;
  return valElbow;
  return valWrist;
  return valButton;
}
