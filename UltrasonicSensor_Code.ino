

const int trigPin = 9;
const int echoPin = 10;
const int buzz = 11;
//const int espSignal = 12;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //--------------------------
  pinMode(buzz, OUTPUT);
  digitalWrite(buzz,0);
  //--------------------------
 // pinMode,(espSignal, OUTPUT);
  //digitalWrite(espSignal, LOW);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
  if(distance<20)
  {
    for(int i = 0; i<=6 ; i++)
    {
      //digitalWrite(espSignal, HIGH);
      sound();
      Serial.println("Object!!!!!!!!!!!!!!!!");
      }
    }
    else
    {
     //digitalWrite(espSignal,LOW);
     Serial.println("No_Object***************");
     digitalWrite(buzz,0);
     delay(500); 
      }
}

void sound()
{
  digitalWrite(buzz, 1);
  delay(500);
  digitalWrite(buzz, 0);
  delay(1000);
  }
