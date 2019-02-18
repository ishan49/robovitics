int ch1=8;

int ch2=9;
int ch3=10;
int ch4=13;
int chan1,chan2,chan3,chan4;
int RightMotor1T1 = 11; // Right Motor
int RightMotor2T1 =6; // Right Motor 
int RightMotor1T2 =12; // Right Motor
int RightMotor2T2 = 7; // Right Moto 
int LeftMotor1T1 = 3;  // Left Motor 
int LeftMotor2T1 = 5; // Left Motor  
int LeftMotor1T2 = 2;// Left Motor   
int LeftMotor2T2 = 4;// Left Motor  
int ThresholdForLeft = 1480; //Move Left if Less than 1200            
int ThresholdForRight = 1580; // Move Right If greater than 1800
int ThresholdForStraight = 1580; // Move Front if Greater Than 1750
int ThresholdForBackWards = 1480; // Move Back if Less than 1200
unsigned long timer[4];
byte last_channel[3];
int input[3];

void setup()
{
  PCICR |= (1 << PCIE0);
  PCMSK0 |= (1 << PCINT0);  // Pin 8 on Uno Board
  PCMSK0 |= (1 << PCINT1);  // Pin 9 on Uno Board
  PCMSK0 |= (1 << PCINT2);
 
  pinMode(RightMotor1T1,OUTPUT); 
  pinMode(RightMotor2T1,OUTPUT);
  pinMode(RightMotor1T2,OUTPUT); 
  pinMode(RightMotor2T2,OUTPUT);
  pinMode(LeftMotor1T1,OUTPUT);
  pinMode(LeftMotor2T1,OUTPUT);
  pinMode(LeftMotor1T2,OUTPUT);
  pinMode(LeftMotor2T2,OUTPUT);
  pinMode(ch2,INPUT);
  pinMode(ch4,INPUT);


  // ************************* Setting the Motion of the Motors to Low *********************************//
  digitalWrite(RightMotor1T1,LOW);
  digitalWrite(RightMotor2T1,LOW);
  digitalWrite(RightMotor1T2,LOW);
  digitalWrite(RightMotor2T2,LOW);
  digitalWrite(LeftMotor1T1,LOW);
  digitalWrite(LeftMotor2T1,LOW);
  digitalWrite(LeftMotor1T2,LOW);
  digitalWrite(LeftMotor2T2,LOW);
  // Begining Of The Serial Communication // 
  Serial.begin(9600);
  
}
ISR(PCINT0_vect)
{
  timer[0] = micros();
  
  // Channel 1 Reading
 if(last_channel[0] == 0 && PINB & B00000001)
 {
  last_channel[0] = 1;
  timer[1]= timer[0];
  }
  else if(last_channel[0] == 1 && !(PINB & B00000001))
  {
    last_channel[0] = 0;
    input[0] = timer[0] - timer[1];
  }

  // Channel 2 Reading

  if(last_channel[1] == 0 && PINB & B00000010)
 {
  last_channel[1] = 1;
  timer[2]= timer[0];
  }
  else if(last_channel[1] == 1 && !(PINB & B00000010))
  {
    last_channel[1] = 0;
    input[1] = timer[0] - timer[2];
  }
  // channel 3 Reading
 if(last_channel[2] == 0 && PINB & B00000100)
 {
  last_channel[2] = 1;
  timer[3]= timer[0];
  }
  else if(last_channel[2] == 1 && !(PINB & B00000100))
  {
    last_channel[2] = 0;
    input[2] = timer[0] - timer[3];
  }
   // channel 4 Reading
 if(last_channel[3] == 0 && PINB & B00001000)
 {
  last_channel[3] = 1;
  timer[4]= timer[0];
  }
  else if(last_channel[3] == 1 && !(PINB & B00001000))
  {
    last_channel[3] = 0;
    input[3] = timer[0] - timer[4];
  }
}

 void loop()
{
  chan1=pulseIn(ch1,HIGH);
  chan2=pulseIn(ch2,HIGH);
  chan3=pulseIn(ch3,HIGH);
  chan4=pulseIn(ch4,HIGH);
  delay(500);
  
  // Going Left
  if( chan4 < ThresholdForLeft && chan4 >1000)
  {
    left();
    Serial.println(" BHOSDIKE We are Going Left");
    Serial.println(chan3);
  }

  // Going Right
  else if(chan4 > ThresholdForRight)
  {
    right();
    Serial.println("AREY LODA We are Going Right");
    Serial.println(chan4);
  }

  // Going  Straight
  else if(chan2 > ThresholdForStraight)
  {
    straight();
    Serial.println("oh FUCK !!We are going Straight ");
    Serial.println(chan2);
  }

  // Going Back
  else if(chan2 < ThresholdForBackWards && chan2 >1000)
  {
    back();
    Serial.println("We are Going Backwards madarchod");
    Serial.println(chan2);
  }
  else
  {
    wait();
    Serial.println("We are waiting bhenchod");
  }
}  
void left()
{
    digitalWrite(RightMotor1T1,HIGH);
    digitalWrite(RightMotor2T1,HIGH);
    digitalWrite(RightMotor1T2,HIGH);
    digitalWrite(RightMotor2T2,HIGH);
    digitalWrite(LeftMotor1T1,HIGH); 
    digitalWrite(LeftMotor2T1,HIGH);
    digitalWrite(LeftMotor1T2,HIGH); 
    digitalWrite(LeftMotor2T2,HIGH); 
}

void straight()
{
    digitalWrite(RightMotor1T1,HIGH);
    digitalWrite(RightMotor2T1,HIGH);
    digitalWrite(RightMotor1T2,HIGH);
    digitalWrite(RightMotor2T2,HIGH);
    digitalWrite(LeftMotor1T1,HIGH); 
    digitalWrite(LeftMotor2T1,HIGH);
    digitalWrite(LeftMotor1T2,LOW); 
    digitalWrite(LeftMotor2T2,LOW);
}

void right()
{
    digitalWrite(RightMotor1T1,HIGH);
    digitalWrite(RightMotor2T1,HIGH);
    digitalWrite(RightMotor1T2,LOW);
    digitalWrite(RightMotor2T2,LOW);
    digitalWrite(LeftMotor1T1,HIGH); 
    digitalWrite(LeftMotor2T1,HIGH);
    digitalWrite(LeftMotor1T2,LOW); 
    digitalWrite(LeftMotor2T2,LOW); 
}

void back()
{
    digitalWrite(RightMotor1T1,HIGH);
    digitalWrite(RightMotor2T1,HIGH);
    digitalWrite(RightMotor1T2,LOW);
    digitalWrite(RightMotor2T2,LOW);
    digitalWrite(LeftMotor1T1,HIGH); 
    digitalWrite(LeftMotor2T1,HIGH);
    digitalWrite(LeftMotor1T2,HIGH); 
    digitalWrite(LeftMotor2T2,HIGH);
}
void wait()
{
    digitalWrite(RightMotor1T1,LOW);
    digitalWrite(RightMotor2T1,LOW);
    digitalWrite(RightMotor1T2,LOW);
    digitalWrite(RightMotor2T2,LOW);
    digitalWrite(LeftMotor1T1,LOW); 
    digitalWrite(LeftMotor2T1,LOW);
    digitalWrite(LeftMotor1T2,LOW); 
    digitalWrite(LeftMotor2T2,LOW); 
}
