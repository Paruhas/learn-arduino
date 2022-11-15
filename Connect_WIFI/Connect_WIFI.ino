#include <Arduino.h>

#include <ESP8266WiFi.h>

// const char* ssid     = "Your WiFi SSID";
// const char* password = "Your Password";
const char* ssid     = "MINERTA242789";
const char* password = "Mit242789";

void setup () {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT); // SET UP LED_BUILTIN
  digitalWrite(LED_BUILTIN, 1); // off LED when start
  
  delay(2000); // delay start

  if (!SPIFFS.begin())  {
    Serial.println("=== An error has occurred whiel mounting SPIFFS!. ===");
    return;
  }
  
  WiFi.disconnect(); // disconnect ก่อน เพื่อความชัว
  delay(100);
  WiFi.begin(ssid, password); // ทำการ Connect SSID และ Pass
  
  while (WiFi.status() != WL_CONNECTED) { // ถ้าไม่สามารถเชื่อมต่อได้
    digitalWrite(LED_BUILTIN, 0);
    delay(250);
    digitalWrite(LED_BUILTIN, 1);
    delay(250);

    Serial.print("Attempting to connect to Network named: ");  
    Serial.print(ssid);
    Serial.printf(" =>> Connection Status: %d \n", WiFi.status()); 

    digitalWrite(LED_BUILTIN, 0);
    delay(250);
    digitalWrite(LED_BUILTIN, 1);
    delay(250);
  }
  // จะหลุดออกจาก while ก็ต่อเมือ Connected เรียบร้อย
  digitalWrite(LED_BUILTIN, 0); // on LED when complete

  Serial.println(" ========== ");
  Serial.print("Wi-Fi "); 
  Serial.print(ssid); 
  Serial.print(" has been connected, "); 
  Serial.print("at IP Address : "); 
  Serial.println(WiFi.localIP());  // ทำการ Print IP ที่ได้รับมาจาก 
  Serial.println(" ========== ");
}

void loop () { 
  if (WiFi.status() != 3) {
    digitalWrite(LED_BUILTIN, 1);
    Serial.printf("WiFi disconnect > connection Status: %d\n", WiFi.status());// แสดงสถานะการเชื่อมต่อ
  } 

  delay(2000);
}