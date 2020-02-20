#include <Wire.h>
#include "rgb_lcd.h"
 
rgb_lcd lcd;
 
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
 
float sensor_volt;
float RS_gas; 
float R0;
float ratio;
float BAC;
int R2 = 2000;
 
void setup() 
{
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
}
 
void loop() 
{
    int sensorValue = analogRead(A0);
    sensor_volt=(float)sensorValue/1024*5.0;
    RS_gas = ((5.0 * R2)/sensor_volt) - R2; 
   /*-Replace the value of R0 with the value of R0 in your test -*/
    R0 = 16000;
    ratio = RS_gas/R0;// ratio = RS/R0
    double x = 0.4*ratio;   
    BAC = pow(x,-1.431);  //BAC in mg/L
    lcd.setCursor(0,0);
    lcd.print("BAC = ");
    lcd.print(BAC*0.0001);  //convert to g/dL
    lcd.print(" g/DL");
    delay(1000);
}
