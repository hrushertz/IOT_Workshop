int IN1 = 12;
int IN2 = 13;
int buzzer = 4;
int led = 15;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  delay(2000);
  
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  delay(2000);
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  delay(1000);

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,HIGH);
  delay(2000);
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  delay(2000);
  digitalWrite(led,LOW);
  delay(500);
  digitalWrite(led,HIGH);
  delay(500);
  

}
