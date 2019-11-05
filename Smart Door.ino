#include<Servo.h>
int btn=2;
int btnStatus=0;
Servo myservo;
int servopin=3;

//Sonar
int trig=4;
float echo=5;
float distance=0.0;
float val=0.0;

void setup() {
  pinMode(btn,INPUT);
  Serial.begin(9600);
  myservo.attach(servopin);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {

  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  
  btnStatus=digitalRead(btn);
  val=pulseIn(echo,HIGH);
  distance=val*.034/2;
  Serial.println(distance);
  delay(50);

  if (btnStatus==HIGH){
    if(distance<10){
    myservo.write(180);
    delay(1000);
    
    
    }else{
      myservo.write(-180);
      delay(1000);
      }}
}
