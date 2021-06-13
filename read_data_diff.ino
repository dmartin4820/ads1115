#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;

void setup() {
  Serial.begin(9600);

  if (!ads.begin()) {
    Serial.println("Did not initialize ADS.");
    while(1);
  }
}

void loop() {
  int16_t A0A1;
  float diffV;
  
  A0A1 = ads.readADC_Differential_0_1();
  diffV = ads.computeVolts(A0A1);
  
  Serial.println(diffV);
  delay(1000);
}

