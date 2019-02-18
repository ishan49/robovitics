int l1=3;
int l2=5;
int r1=6;
int r2=9;
void setup() 
{
 pinMode(l1,OUTPUT);
 pinMode(l2,OUTPUT);
 pinMode(r1,OUTPUT);
 pinMode(r2,OUTPUT);
 Serial.begin(9600);
 digitalWrite(l1,LOW);
 digitalWrite(l2,LOW);
 digitalWrite(r1,LOW);
 digitalWrite(r2,LOW);
}
void loop() 
{
  forward();
  delay(3000);
  backward();
  delay(1000);
  left();
  delay(2000);
  forward();
  delay(3000);
  right();
  delay(2000);
  backward();
  delay(1000);
  wait();
  delay(2000);
}
void forward()
{
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
}
void backward()
{
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
}
void left()
{
  digitalWrite(l1,LOW);
  digitalWrite(l2,HIGH);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
}
void right()
{
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
}
void wait()
{
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
}
