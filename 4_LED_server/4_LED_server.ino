
#include<ESP8266WiFi.h>

const char* ssid = "OnePlus";
const char* password = "Hrushi2021";

int LED = 13;
int LED2 = 14;
int LED3 = 12;
int LED4 = 15;

// Creating instance of server
WiFiServer server(80);

void setup()
{
  Serial.begin(115200);
  delay(10);

  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);

  pinMode(LED2,OUTPUT);
  digitalWrite(LED2,LOW);

  pinMode(LED3,OUTPUT);
  digitalWrite(LED3,LOW);

  pinMode(LED4,OUTPUT);
  digitalWrite(LED4,LOW);

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

  int value2 = LOW;
  if(request.indexOf("/LED2=ON")!= -1)
  {
    digitalWrite(LED2, LOW);
    value2 = LOW;
  }
  if(request.indexOf("/LED2=OFF")!= -1)
  {
    digitalWrite(LED2, HIGH);
    value2 = HIGH;
  }

  int value3 = LOW;
  if(request.indexOf("/LED3=ON")!= -1)
  {
    digitalWrite(LED3, LOW);
    value3 = LOW;
  }
  if(request.indexOf("/LED3=OFF")!= -1)
  {
    digitalWrite(LED3, HIGH);
    value3 = HIGH;
  }

  int value4 = LOW;
  if(request.indexOf("/LED4=ON")!= -1)
  {
    digitalWrite(LED4, LOW);
    value4 = LOW;
  }
  if(request.indexOf("/LED4=OFF")!= -1)
  {
    digitalWrite(LED4, HIGH);
    value4 = HIGH;
  }

  //Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<HTML>");
  client.print("led 1 pin is now: ");
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

  client.print("led 2 pin is now: ");
  if(value2 == LOW)
  {
    client.print("on");
  }
  else
  {
    client.print("off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED2=ON\"\"><button>Turn On</button></a>");
  client.println("<a href=\"/LED2=OFF\"\"><button>Turn Off</button></a><br/>");

  client.print("led 3 pin is now: ");
  if(value3 == LOW)
  {
    client.print("on");
  }
  else
  {
    client.print("off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED3=ON\"\"><button>Turn On</button></a>");
  client.println("<a href=\"/LED3=OFF\"\"><button>Turn Off</button></a><br/>");

  client.print("led 4 pin is now: ");
  if(value4 == LOW)
  {
    client.print("on");
  }
  else
  {
    client.print("off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED4=ON\"\"><button>Turn On</button></a>");
  client.println("<a href=\"/LED4=OFF\"\"><button>Turn Off</button></a><br/>");
  client.println("</html>");
  delay(1);
  Serial.println("Client Disconnected");
  Serial.println("");
}
