int rm1 = 7;//right motor output1
int rm2 = 6;//right motor output 2
int lm1 = 5;//left motor output 1
int lm2 = 4;//left motor output 2
int us1tri = 9;// ultrasonic sensor 1 trigger
int us2tri = 3;//ultrasonic sensor 2 trigger
int us1echo = 8;//ultrasonic sensor 1 echo
int us2echo = 2;//ultrasonic sensor 2 echo
int speedrm = 10;//pin used to control right motor speed
int speedlm = 11;//pin 
int motion = 12;
long duration1, inches1, duration2, inches2;


void setup() {
  Serial.begin(115200);

pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);
pinMode(lm1,OUTPUT);
pinMode(lm2,OUTPUT);
pinMode(us1tri,OUTPUT);
pinMode(us2tri,OUTPUT);
pinMode(us1echo,INPUT);
pinMode(us2echo,INPUT);
pinMode(speedrm,OUTPUT);
pinMode(speedlm,OUTPUT);
pinMode(motion,INPUT);
}

void loop() {
  int motion_s = digitalRead(motion);

if(motion_s == HIGH){
 stop();
 delay(3000);
} else{ 
fwd();
}

digitalWrite(us1tri,LOW);
digitalWrite(us2tri,LOW);
delay(0.005);
digitalWrite(us1tri,HIGH);
digitalWrite(us2tri,HIGH);
delay(0.01);
digitalWrite(us1tri,LOW);
digitalWrite(us2tri,LOW);

duration1 = pulseIn(us1echo,HIGH);
inches1 = (duration1/2)/74;
duration2 = pulseIn(us2echo,HIGH);
inches2 = (duration2/2)/74;


if( inches1 <= 3 ) {
 turnleft(); 

 delay(300);
}
else if(inches2 <= 3 ){ 
  turnright();
 
 delay(300);
}
else if (inches1 > 3|| inches2> 3){
  fwd();
}
}
void bckwd(){//right and left both motors are on
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  analogWrite(speedrm,200);

  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  analogWrite(speedlm,200);
}
void fwd(){//right and left both motors are on
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
  analogWrite(speedrm,200);

digitalWrite(lm1,HIGH);
digitalWrite(lm2,LOW);
analogWrite(speedlm,200);
Serial.println("fwd");
}
void turnright(){// right motor off and left motor on
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  analogWrite(speedrm,0);

  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  analogWrite(speedlm,200);
    Serial.println("turnright");

}
void turnleft(){//right motor on and left motor off
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  analogWrite(speedrm,200);

  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  analogWrite(speedrm,0);
   Serial.println("turnleft");
   }

void stop(){
digitalWrite(rm1,LOW);
digitalWrite(rm2,LOW);

digitalWrite(lm1,LOW);
digitalWrite(lm2,LOW);
Serial.println("stop");}

