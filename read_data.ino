#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;

void setup() {
  Serial.begin(9600);

  //Default ADC range set to +/- 6.144 (1 bit = 0.1875mV/ADS1115)

  if (!ads.begin()) {
    Serial.println("Did not initialize ADS.");
    while(1);
  }
}

void loop() {
  int16_t A0, A1, A2, A3;
  float V0, V1, V2, V3;

  A0 = ads.readADC_SingleEnded(0);
  A1 = ads.readADC_SingleEnded(1);
  A2 = ads.readADC_SingleEnded(2);
  A3 = ads.readADC_SingleEnded(3);
  
  V0 = ads.computeVolts(A0);
  V1 = ads.computeVolts(A1);
  V2 = ads.computeVolts(A2);
  V3 = ads.computeVolts(A3);

  Serial.print(V0); Serial.print(", "); Serial.print(V1); Serial.print(", "); Serial.print(V2); Serial.print(", "); Serial.println(V3);

  delay(1000);

}
