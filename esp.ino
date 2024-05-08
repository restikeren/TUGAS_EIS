#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define BLYNK_TEMPLATE_ID "TMPL6SRvG_JCx"
#define BLYNK_TEMPLATE_NAME "rere"
#define BLYNK_AUTH_TOKEN "Hiskm1ku8R-eKN87LDiuTu6n8c68TRQG"
#define BLYNK_PRINT Serial

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wokwi-GUEST"; //nama hotspot yang digunakan
char pass[] = ""; //password hotspot yang digunakan

#define triggerPin 4
#define echoPin 2
#define LED1 25
#define LED2 26
#define LED3 27

long durasi;
int jarak;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
  Serial.println("Setup done!");
}

void loop() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  durasi = pulseIn(echoPin, HIGH);
  jarak = durasi * 0.034 / 2;

  if (jarak > 80) {
    Serial.println("Jarak lebih dari 80cm");
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  } else if (jarak <= 80 && jarak >= 40) {
    Serial.println("Jarak berada diantara 40cm hingga 80cm");
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
    digitalWrite(LED3, LOW);
  } else if (jarak < 40) {
    Serial.println("Jarak kurang dari 40cm");
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, LOW);
  }

  delay(1000); // 
}
