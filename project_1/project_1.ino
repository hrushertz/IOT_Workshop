#include<ESP8266WiFi.h>
const char*ssid="OnePlus";
const char*password="Hrushi2021";
int sensorPin=A0;
int LED = 13;
int LED2 = 12;
int LED3 = 15;
int i1 = 4;
int i2 = 0;
int i3 = 2;
int button1;
int button2;
int button3;
WiFiServer server (80);

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(i1, INPUT);
  pinMode(i2, INPUT);
  pinMode(i3, INPUT);
  
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(50);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
  server.begin();
  Serial.println("Server started");
  Serial.print("Use this url to connect:");
  Serial.print("HTTP://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop()
{
  int analogValue = analogRead(sensorPin);
  float milivolts=(analogValue/1024.0)*3300;
  float celsius=milivolts /10;
  Serial.print("in Degree C= ");
  Serial.println(celsius);
  delay(1000);

  WiFiClient client = server.available();
  if(!client)
  {
    return;
  }
  Serial.println("new client");
  while(!client.available())

  {
    delay(0.5);   
  }
String request=client.readStringUntil('\r');
Serial.println(request);
client.flush();
int value=HIGH;
button1 = digitalRead(i1);
  if (button1 == HIGH)
  digitalWrite(LED, HIGH);
  else
  digitalWrite(LED,LOW);

   button2 = digitalRead(i2);
  if (button2 == HIGH)
  digitalWrite(LED2, HIGH);
  else
  digitalWrite(LED2,LOW);

   button3 = digitalRead(i3);
  if (button3 == HIGH)
  digitalWrite(LED3, HIGH);
  else
  digitalWrite(LED3,LOW);
client.println("HTTP/1.1 200 OK");
client.println("cuntent-Type:text/html");
client.println("");
client.println("<!DOCTYPE HTML>");
client.println("<html>");
//client.println("<br><br>");
client.println("<center>");client.println("<h4>Temperature in C </h4>");client.println(celsius);client.println("</center>");
client.println("<meta http-equiv='refresh' content='1'>");
client.println("<br><hr><hr><br>");
client.println("<center>");
client.println("<align=left|right|center|justify>");
client.println("<h3>HIGH</h3>");
client.println("<a href=\"/button1=HIGH\"\"><button style=background-color:Red;><h1>PRESS</h1> </button></a>");
client.println("</center>");
client.println("<br><hr><br>");
client.println("<center>");
client.println("<h3>MEDIUM</h3>");
client.println("<a href=\"/button2=HIGH\"\"><button style=background-color:Yellow;><h1>PRESS</h1></button></a>");
client.println("</center>");
client.println("<br><hr><br>");
client.println("<center>");
client.println("<h3>LOW</h3>");
client.println("<a href=\"/button3=HIGH\"\"><button style=background-color:Green;><h1>PRESS</h1> </button></a>");
client.println("</center>");
client.println("<br><hr><br>");
client.println("</html>");
delay(1);
Serial.println("client disconnected");
Serial.println("");
}
