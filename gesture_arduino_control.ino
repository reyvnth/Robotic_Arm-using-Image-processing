// created by Revanth Krishna

#include <Servo.h>
 
Servo servothumb;         
Servo servoindex;         
Servo servomiddle;
Servo servoring;
Servo servolittle;
 
char number[50];
char c;
int state = 0;
String myStringRec;
int stringCounter = 0;
bool stringCounterStart = false;
String myRevivedString;
int stringLength = 6;
 
int servolittle,servoMiddle,servoIndex,servoThumb,servoRing;
int myVals[] ={0,0,0,0,0} ;
 
bool portable;
 
void setup() {
 
  Serial.begin(9600);
  servothumb.attach(9); 
  servoindex.attach(10); 
  servolittle.attach(11);
  servoring.attach(12);
  servomiddle.attach(13);
  portable = true;
   
}
 
void loop() {
 
if (portable == true){
      allON();
      }

else{
   
receiveData();
if (servolittle ==1){  servolittle.write(180);}else{servolittle.write(0);}
if (servoIndex ==1){  servoindex.write(180);}else{servoindex.write(0);}
if (servoMiddle ==1){  servomiddle.write(180);}else{servomiddle.write(0);}
if (servoThumb ==1){  servothumb.write(180);}else{servothumb.write(0);}
if (servoRing ==1){  servoring.write(180);}else{servoring.write(0);}
}
 
}
 
void allON(){
   
servolittle.write(180);
servoindex.write(180);
servomiddle.write(180);
servothumb.write(180);
servoring.write(180);
   
  }
 
 
 
void receiveData() {
  int i = 0;
  while (Serial.available()) {
   char c = Serial.read();
   
    if (c == '$') {
      stringCounterStart = true;
    }
    if (stringCounterStart == true )
    {
      if (stringCounter < stringLength)
      {
        myRevivedString = String(myRevivedString + c);
        stringCounter++;
      }
      if (stringCounter >= stringLength) {
        stringCounter = 0; stringCounterStart = false;
        servolittle = myRevivedString.substring(1, 2).toInt();
        servoRing = myRevivedString.substring(2, 3).toInt();
        servoMiddle = myRevivedString.substring(3, 4).toInt();
        servoIndex = myRevivedString.substring(4, 5).toInt();
        servoThumb = myRevivedString.substring(5, 6).toInt();
        myRevivedString = "";
      }
    }
  }
}
