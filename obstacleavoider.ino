int l1 = 3; 
int l2 = 5; 
int r1 = 6; 
int r2 = 9; 
int echo = A2;
int trig = A1;
int duration;
int distance;
void setup() 
{
 Serial.begin(9600);
 pinMode(l1,OUTPUT);
 pinMode(l2,OUTPUT);
 pinMode(r1,OUTPUT);
 pinMode(r2,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(trig,OUTPUT);
}

void loop() 
{
  digitalWrite(trig, LOW);    
  delayMicroseconds(2);       
  digitalWrite(trig, HIGH);   
  delayMicroseconds(10);      
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);        
  distance = duration*0.034/2;
  if (distance < 15)  
           { Serial.println(" right");
              right();                           
              delay(500);
           } 
           else 
           { Serial.println(" Forward"); 
              forward();                              
           }       
}
void forward()
{
  digitalWrite(l1,HIGH);
  digitalWrite(l2,LOW);
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
