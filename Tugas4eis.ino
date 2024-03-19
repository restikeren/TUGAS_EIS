int pirPin = 4; // PIR sensor input pin
int ledPin = 5; // Output pin to indicate motion detection
int PIRstatus = 0;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  PIRstatus = digitalRead(pirPin);

  if (PIRstatus == HIGH) {
    Serial.println("Motion Detected");
    digitalWrite(ledPin, HIGH); // Turn on the LED
    delay(2000); // Adjust delay as needed
  } 
  else {
    Serial.println("No Motion");
    digitalWrite(ledPin, LOW); // Turn off the LED
  }
  
  delay(100); // Delay between readings
}
