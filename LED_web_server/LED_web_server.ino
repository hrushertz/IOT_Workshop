
#include<ESP8266WiFi.h>

const char* ssid = "OnePlus";
const char* password = "Hrushi2021";

int LED = 13;
// Creating instance of server
WiFiServer server(80);

void setup()
{
  Serial.begin(115200);
  delay(10);

  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);

  // Connecting to wifi Network

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status()!= WL_CONNECTED)
  {
    delay(50);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WIFI connected");

  // Start the server

  server.begin();
  Serial.println("Server started");

  //Printing the IP address

  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop()
{
  // check if a client has connected
  WiFiClient client = server.available();
  if(!client)
  {
    return;
  }

  //wait until the client sends some data

  Serial.println("new client");
  while(!client.available())
  {
    delay(0.5);
  }

  // Read the first line of the request

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Match the request

  int value = LOW;
  if(request.indexOf("/LED=ON")!= -1)
  {
    digitalWrite(LED, LOW);
    value = LOW;
  }
  if(request.indexOf("/LED=OFF")!= -1)
  {
    digitalWrite(LED, HIGH);
    value = HIGH;
  }

  //Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<HTML>");
  client.print("led pin is now: ");
  if(value == LOW)
  {
    client.print("on");
  }
  else
  {
    client.print("off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn On</button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn Off</button></a><br/>");
  client.println("</html>");
  delay(1);
  Serial.println("Client Disconnected");
  Serial.println("");
}
