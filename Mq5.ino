#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int valorsensorgas;
int Buzzer_Pin = 7;

const int gasThresholdLow = 300;
const int gasThresholdHigh = 1000;

void setup() {
  pinMode(Buzzer_Pin, OUTPUT);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  // Tampilan inisialisasi
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("MQ-5 DETEKSI");
  lcd.setCursor(0, 1);
  lcd.print("By : xxxxxx ");
  delay(5000);
}


void loop() {
  valorsensorgas = analogRead(A1);
  delay(1000);

  lcd.setCursor(11, 0); // Pindahkan kursor ke kolom 11 baris 0
  lcd.print(valorsensorgas); // Tampilkan nilai sensor gas

  // Cek apakah nilai sensor gas berada dalam rentang tertentu
  if (valorsensorgas >= gasThresholdLow && valorsensorgas <= gasThresholdHigh) {
      lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gas Terdeteksi!!!");
  lcd.setCursor(0, 1);
  lcd.print("Sensor Gas: "); 
  lcd.print(valorsensorgas); 
  digitalWrite(Buzzer_Pin, HIGH); // Nyalakan Buzzer_Pin
  } else {
     lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Situasi Aman");
  lcd.setCursor(0, 1);
  lcd.print("Sensor Gas: "); 
  lcd.print(valorsensorgas); 
    digitalWrite(Buzzer_Pin, LOW); // Matikan Buzzer_Pin
  }

  delay(1000);
}