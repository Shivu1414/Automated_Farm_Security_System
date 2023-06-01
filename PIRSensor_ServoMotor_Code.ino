#include <Servo.h>

Servo myservo;
int pos = 0; 
int buzzer=10;
int buzz=7;
#define trigPin 12
#define echoPin 11

//PIR
int Pirpin=4;
int led=3;
int Pirstate=0;

void setup()
{ Serial.begin (9600);
  myservo.attach(9);
 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   pinMode(buzzer,OUTPUT);
   pinMode(buzz,OUTPUT);

// PIR
 pinMode(Pirpin,INPUT);
  pinMode(led, OUTPUT);
}


void loop()
{ long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2;

  Pirstate=digitalRead(Pirpin);

  if (distance < 20)
  { 
      for(int i=0;i<=10;i++){
      digitalWrite(buzzer,HIGH);
      delay(500);
      digitalWrite(buzzer,LOW);
       delay(500);
      }
      digitalWrite(buzzer,HIGH);
      delay(5000);
      digitalWrite(buzzer,HIGH);
  }

  
      if(Pirstate==HIGH){
          digitalWrite(buzzer,LOW);
          digitalWrite(3,HIGH);
          for(int i=0;i<=5;i++){
               digitalWrite(buzz,HIGH);
               delay(500);
               digitalWrite(buzz,LOW);
               delay(500);
           }
           digitalWrite(buzz,HIGH);
          for (pos = 0; pos <= 180; pos += 1) { 
               myservo.write(pos);              
               delay(60);                     
          }
          for (pos = 180; pos >= 0; pos -= 1) { 
               myservo.write(pos);              
                delay(60);                   
          } 
          digitalWrite(3,LOW);
          digitalWrite(buzz,LOW);
          
       } 
       else{
        digitalWrite(3,LOW);
       }
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
  }


//}
