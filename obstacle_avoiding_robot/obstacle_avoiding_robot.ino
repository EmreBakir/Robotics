int IN4 = 11;
int IN3 = 10;
int IN2 = 9;
int IN1 = 8;
int ENA = 7;
int ENB = 12;

int trig = 6;
int echo = 5;
long duration;
long mesafe;

void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENA,150);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENB,150);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  
  mesafe = distance();
  if(mesafe < 20 && mesafe != 0){
    geriGit();
    delay(600);
    sagGit();
    delay(600);
  }
  else{
    ileriGit();
  }

 

}

int  distance() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  return  duration*0.0343/2.0;
}
void ileriGit(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}
void geriGit(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN4,HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}
void sagGit(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN4,LOW);
  analogWrite(ENB, 150);
}





