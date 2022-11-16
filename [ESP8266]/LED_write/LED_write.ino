// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, 0);   // turn the LED on (HIGH || 0 is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, 1);    // turn the LED off by making the voltage LOW || 1
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, 0);   
  delay(500);                      
  digitalWrite(LED_BUILTIN, 1);   
  delay(500);         
}

// swap HIGH | LOW for esp8266 wifi