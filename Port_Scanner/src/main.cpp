#include <Arduino.h>
#include <WiFi.h>
// put function declarations here:
const char *ssid = "DIGI-24-221847";
const char *password = "1849005563";
IPAddress targetIP(192, 168, 1, 100);
int startPort = 20, endPort = 1024;
void scanPorts(IPAddress targetIP, int startPort, int endPort)
{
  WiFiClient client;
  for (int port = startPort; port < endPort; port++)
  {
    Serial.println("Scanning port:");
    Serial.println(port);
    Serial.println("...");
    if (client.connect(targetIP, port))
    {
      Serial.println("Open");
      client.stop();
    }
    else
    {
      Serial.println("Closed");
    }
    delay(50);
  }
}
void scanNetworks()
{
  int networks = WiFi.scanNetworks();
  for (int i = 0; i < networks; i++)
  {
    Serial.print("Network ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(WiFi.SSID(i));
  }
}
void setup()
{
  Serial.begin(115200);
  delay(1000);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println(".");
    delay(500);
  }
  Serial.println("Connected to WiFi");
  Serial.println("Starting port scan...");
  scanPorts(targetIP, startPort, endPort);
}

void loop()
{
  // put your main code here, to run repeatedly:
}
