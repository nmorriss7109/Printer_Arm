import processing.serial.*;

Serial port;
String portname = "COM16";
int baudrate = 9600;
int value = 0;

void setup(){
  size(55,55);
  port = new Serial(this, portname, baudrate);
}

void draw(){
  if(keyPressed){
    if(key == 'w'){
      port.write("w");
    } 
    if(key == 'a'){
      port.write("a");
    } 
    if(key == 's'){
      port.write("s");
    } 
    if(key == 'd'){
      port.write("d");
    } 
    if(key == 'q'){
      port.write("q");
    } 
    if(key == 'e'){
      port.write("e");
    } 
  }
  else if (!keyPressed){
    port.write('.'); 
  }
}

