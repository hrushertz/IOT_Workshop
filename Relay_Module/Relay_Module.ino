 int relay = 12;
 int buzzer = 
 void setup() 
{
  pinMode(relay,OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() 
{
  digitalWrite(relay, HIGH);
  delay(2000);
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(relay, LOW);
  delay(2000);
  digitalWrite(buzzer,LOW);
  delay(1000);
}
