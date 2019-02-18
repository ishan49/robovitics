int l1=3;
int l2=5;
int r1=6;
int r2=9;
int ls=7;
int cs=8;
int rs=10;
int vls;
int vrs;
int vcs;
void setup() 
{
 Serial.begin(9600);
 pinMode(l1,OUTPUT);
 pinMode(l2,OUTPUT);
 pinMode(r1,OUTPUT);
 pinMode(r2,OUTPUT);
 pinMode(ls,INPUT);
 pinMode(rs,INPUT);
 pinMode(cs,INPUT); 
}
void loop() 
{
  vls=digitalRead(ls);
  vrs=digitalRead(rs);
  vcs=digitalRead(cs);
  if(vls==1 && vcs==1 && vrs==1)
  {
    right();
    delay(1000);
  }
  if(vls==1 && vcs==1 && vrs==0)
  {
    left();
  }
  if(vls==0 && vcs==1 && vrs==1)
  {
    right();
  }
  if(vls=1 && vcs==0 && vrs==1)
  {
    forward();
  }
  if(vls==0 && vcs==0 && vrs==0)
  {
    right();
  }
  if(vls==0 && vcs==066 && vrs==1)
  {
  right();
  }
}
void forward()
{
  analogWrite(l1,200);
  analogWrite(l2,0);
  analogWrite(r1,200);
  analogWrite(r2,0);
}
void right()
{
  analogWrite(l1,200);
  analogWrite(l2,0);
  analogWrite(r1,0);
  analogWrite(r2,200);
}
void left()
{
  analogWrite(l1,0);
  analogWrite(l2,200);
  analogWrite(r1,200);
  analogWrite(r2,0);
}
