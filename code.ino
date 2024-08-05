#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>

#define DHTPIN D4
#define DHTTYPE DHT11
#define WIFI_SSID "wifi_name"  //enter your wifi name here
#define WIFI_PASSWORD "wifi_password"  //enter your wifi password here
#define THINGSPEAK_CHANNEL_ID "channel_id"  //write channel ID on thingspeak
#define THINGSPEAK_API_KEY "API_key"  //Write API key here

const int ledPin=15;
const int ldrPin=5;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  delay(10);
  dht.begin();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to Wi-Fi");
  
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);

}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    
    return;
  }
  //ldr();
int ldrStatus= digitalRead(ldrPin);

  if(ldrStatus==1){
    digitalWrite(ledPin, HIGH);
    Serial.print("It's Dark, Turn on the LED: ");
    Serial.println(ldrStatus);
}
else
{ 
  digitalWrite(ledPin, LOW);
  Serial.print("It's Bright, Turn off the LED: ");
  Serial.println(ldrStatus);
}
  WiFiClient client;
  HTTPClient http;
  String url = "http://api.thingspeak.com/update?api_key=" + String(THINGSPEAK_API_KEY) +
               "&field1=" + String(temperature) + "&field2=" + String(humidity);

  Serial.println(url);

  http.begin(client, url);
  int httpCode = http.GET();
  if (httpCode > 0) {
    String payload = http.getString();
    Serial.println(payload);
  } else {
    Serial.println("Error sending data to Thingspeak");
  }

  http.end();
  delay(100); // Send data every 15 seconds
}
