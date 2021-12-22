const int sensor = A0;
float tempe;
float tempf;
float vout;
int LED = 13;

void setup()
{
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  delay(500);
  pinMode(LED,OUTPUT);
}

void loop()
{
  vout = analogRead(sensor);
  vout = (vout*330)/1023;
  tempe = vout;
  tempf = (vout*1.8)+32;
  Serial.print("in degree C = ");
  Serial.print(tempe);
  Serial.print('\n');
  Serial.print("in degree F = ");
  Serial.print(tempf);
  Serial.print('\n');
  if (tempf > 100.0)
  {
    digitalWrite(LED,LOW);
    delay(500);
    digitalWrite(LED,HIGH);
    delay(500);
  }
  delay(1000);
}
