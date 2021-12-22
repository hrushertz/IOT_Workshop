int i1 = 13;
int i2 = 4;
int i3 = 0;
int i4 = 2;
int Switch1;
int Switch2;
int Switch3;
int Switch4;
void setup()
{
  Serial.begin(9600);
  pinMode(i1, INPUT);
  pinMode(i2, INPUT);
  pinMode(i3, INPUT);
  pinMode(i4, INPUT);
}
void loop()
{
  Switch1 = digitalRead(i1);
  if (Switch1 == LOW)
  {
    Serial.print("key 1 is pressed");
  Serial.print('\n');
  delay(1000);
  }

  Switch2 = digitalRead(i2);
  if (Switch2 == LOW)
  {
    Serial.print("key 2 is pressed");
  Serial.print('\n');
  delay(1000);
  }

  Switch3 = digitalRead(i3);
  if (Switch3 == LOW)
  {
    Serial.print("key 3 is pressed");
  Serial.print('\n');
  delay(1000);
  }

  Switch4 = digitalRead(i4);
  if (Switch4 == LOW)
  {
    Serial.print("key 4 is pressed");
  Serial.print('\n');
  delay(1000);
  }
  
}
