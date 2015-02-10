#include <Servo.h> 

Servo servoBase;
Servo servoShoulder;
Servo servoElbow;
Servo servoWrist;
Servo servoButton;

int valBase = 90;
int valShoulder = 90;
int valElbow = 90;
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
  valElbow--;
  valWrist++;
  delay(2);
  Debug();
  break;
  
  case 'w':
  valShoulder++;
  valElbow--;
  delay(2);
  Debug();
  break;
  
  case 'e':
  valElbow++;
  valWrist--;
  delay(2);
  Debug();
  break;
  
  case 'a':
  valBase++;
  delay(2);
  Debug();
  break;
  
  case 's':
  valShoulder--;
  valElbow++;
  delay(2);
  Debug();
  break;
  
  case 'd':
  valBase--;
  delay(2);
  Debug();
  break;
  
  case ',':
  valButton = 180     ;
  Debug(); 
  break;
  
//  case !',':
//  valButton = 0;
//  break;
  }
  if(in!=',')
  {
    valButton=0;
  }
  
  

  if(valBase >= 179){
    valBase = 179; 
  }
  else if(valBase < 0){
    valBase = 0; 
  }
//  if(valShoulder >= 180){
//    valShoulder = 179; 
//  }
//  else if(valShoulder < 0){
//    valShoulder = 0; 
//  }
   if(valElbow >= 150){
    valElbow = 150; 
  }
  else if(valElbow < 0){
    valElbow = 0; 
  }
}


void Debug(){
  digitalWrite(debug, HIGH);
  delay(5);
  digitalWrite(debug, LOW); 
}
