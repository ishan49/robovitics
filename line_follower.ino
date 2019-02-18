#define l1 3 //arduino pin 3 to input pin 1 (IN3) of motor driver (LEFT WHEEL)
#define l2 9 //arduino pin 5 to input pin 2 (IN4) of motor driver (LEFT WHEEL)
#define r1 10 //arduino pin 6 to input pin 3 (IN1) of motor driver (RIGHT WHEEL)
#define r2 11 //arduino pin 9 to input pin 4 (IN2) of motor driver (RIGHT WHEEL)
#define LS 5  
#define RS 6
void setup() 
{
 Serial.begin(9600);
 pinMode(l1,OUTPUT);
 pinMode(l2,OUTPUT);
 pinMode(r1,OUTPUT);
 pinMode(r2,OUTPUT);
 pinMode(LS,INPUT);
 pinMode(RS,INPUT);
}

void loop() 
{
  if(!digitalRead(LS) && !digitalRead(RS))
  {
    forward();
  }
  if((digitalRead(LS)) && !(digitalRead(RS)))
  {
    left();
  }
  if(!digitalRead(LS) && (digitalRead(RS)))
  {
    right();
  }
  if((digitalRead(LS)) && (digitalRead(RS)))
  {
    wait();
  }
}
void backward()
{
  analogWrite(l1,120);
  analogWrite(l2,0);
  analogWrite(r1,120);
  analogWrite(r2,0);
}
void forward()
{
  analogWrite(l1,0);
  analogWrite(l2,120);
  analogWrite(r1,0);
  analogWrite(r2,120);
}
void right()
{
  analogWrite(l1,0);
  analogWrite(l2,120);
  analogWrite(r1,120);
  analogWrite(r2,0);
}
void left()
{
  digitalWrite(l1,120);
  digitalWrite(l2,0);
  digitalWrite(r1,0);
  digitalWrite(r2,120);
}
void wait()
{
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
}
