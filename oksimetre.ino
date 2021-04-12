#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <LiquidCrystal.h>
#define signal_time_ms     1000
#define rs 9 
#define en 8 
#define d4 7 
#define d5 6  
#define d6 5 
#define d7 4 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
PulseOximeter pox;
uint32_t last_signal = 0;
void setup()
{
  lcd.begin(16, 2);
  lcd.print("Oximeter");    
     pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);    
}
void loop()
{
  pox.update();
    if (millis() - last_signal > signal_time_ms) {
 
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("BPM: ");
        lcd.print(pox.getHeartRate()) 
        lcd.setCursor(0,1);
        lcd.print("SpO2: ");
        lcd.print(pox.getSpO2());
        lcd.print("%");
        last_signal = millis();
    }
}
