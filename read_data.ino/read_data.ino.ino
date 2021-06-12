#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;

void setup() {
  Serial.begin(9600);

  //Default ADC range set to +/- 6.144 (1 bit = 0.1875mV/ADS1115)

}

void loop() {
  int16_t A0, A1, A2, A3;

  A0 = ads.computeVolts(A0);
  A1 = ads.computeVolts(A1);
  A2 = ads.computeVolts(A2);
  A3 =ads.computeVolts(A3);

  Serial.print(A0); Serial.print(", "); Serial.print(A1); Serial.print(", "); Serial.print(A2); Serial.print(", "); Serial.println(A3);

  delay(1160); //Max sample rate of ADC

}
