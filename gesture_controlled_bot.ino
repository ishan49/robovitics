int av1=A3;
int av2=A4;
int pin1=3;
int pin2=5;
int pin3=6;
int pin4=9;
int a,b,x,y;
void setup() {
 pinMode(pin1,OUTPUT);
 pinMode(pin2,OUTPUT);
 pinMode(pin3,OUTPUT);
 pinMode(pin4,OUTPUT);
 pinMode(av1,INPUT);
 pinMode(av2,INPUT);

 a=analogRead(av1);
 b=analogRead(av2);

 Serial.begin(9600);
}
void loop() 
{
x=analogRead(av1);
y=analogRead(av2); 
 if(x<a-30)
{
  Serial.println("left");
  left();
}
else if(x>a+30)
{
  Serial.println("right");
  right();
}
else if(y>b+30)
{
  Serial.println("backward");
  backward();
}
else if(y<b-30)
{
  Serial.println("forward");
  forward();
}
else if(x>a-30&&x<a+30&&y>b-30&&y<b+30)
{
  Serial.print("stop");
  wait();
}
}
void forward()
{
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
}
void backward()
{
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,HIGH);
}
void left()
{
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
}
void right()
{
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,HIGH);
}
void wait()
{
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
}
