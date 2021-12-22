int i1 = 4;
int i2 = 0;
int i3 = 2;
int LED = 13;
int LED2 = 12;
int LED3 = 15;
int Switch1;
int Switch2;
int Switch3;

void setup() {
  pinMode(i1, INPUT);
  pinMode(i2, INPUT);
  pinMode(i3, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.begin(96000);

}

void loop() {
  Switch1 = digitalRead(i1);
  if (Switch1 == LOW)
  digitalWrite(LED, HIGH);
  else
  digitalWrite(LED,LOW);

 Serial.print(i1);
  

   Switch2 = digitalRead(i2);
  if (Switch2 == HIGH)
  digitalWrite(LED2, HIGH);
  else
  digitalWrite(LED2,LOW);

   Switch3 = digitalRead(i3);
  if (Switch3 == HIGH)
  digitalWrite(LED3, HIGH);
  else
  digitalWrite(LED3,LOW);

}
