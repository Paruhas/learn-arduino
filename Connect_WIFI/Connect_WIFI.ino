#include <ESP8266WiFi.h>
// const char* ssid     = "Your WiFi SSID";
// const char* password = "Your Password";
const char* ssid     = "MINERTA242789";
const char* password = "Mit242789";

void setup () {
  pinMode(LED_BUILTIN, OUTPUT); // SET UP LED_BUILTIN

  Serial.begin(9600); //
  WiFi.begin(ssid, password); //ทำการ Connect SSID และ Pass
  
  while (WiFi.status() != WL_CONNECTED) { // ถ้าไม่สามารถเชื่อมต่อได้
    // ทำการ Print ทุก 1000ms
    Serial.print("Attempting to connect to Network named: ");  
    Serial.print(ssid);
    Serial.printf(" =>> Connection Status: %d \n", WiFi.status()); 
    // แสดงสถานะการเชื่อมต่อ
    delay(1000);
  }
  // จะหลุดออกจาก while ก็ต่อเมือ Connected เรียบร้อย
  Serial.println(" ========== ");
  Serial.print("Wi-Fi "); 
  Serial.print(ssid); 
  Serial.println(" has been connected."); 
  Serial.print("at IP Address : "); 
  Serial.println(WiFi.localIP());  // ทำการ Print IP ที่ได้รับมาจาก 
  Serial.println(" ========== ");
}

void loop () { 
  if (WiFi.status() == 3) 
  {
    digitalWrite(LED_BUILTIN, 1);
    Serial.printf("> Current connection Status: %d\n", WiFi.status());// แสดงสถานะการเชื่อมต่อ
    
    digitalWrite(LED_BUILTIN, 0);
    delay(1);
    digitalWrite(LED_BUILTIN, 1);
    delay(1);
  } else 
  {
    digitalWrite(LED_BUILTIN, 0);
  }  

  delay(2000);
}