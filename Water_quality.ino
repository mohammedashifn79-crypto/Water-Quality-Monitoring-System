#include <Wire.h>
#include <Liquidcrystal_I2C.h>
#include"gravityTDS.h"
#include <Onewire.h>
#include <DallasTemprature.h>
#define TdsSensorPin A0
#define TurbiditySensorPin A1
#define pHSensorPin A2
#define DS18B20pin 2

LiquidCrystal_I2C lcd(0x27,16,2);
GravityTDS gravityTds;
Onewire Onewire(DS18B20Pin);
DallasTemprature Sensors(&oneWire);
float temprature=25,tdsValue=0,pHValue=0;
unsigned Long int avgValue;
int turbidity,sensorValue,phBuff[10],temp;
float ds18b20temp=0.0;

void setup(){
  Serial.begin(1152200);
lcd.init();
lcd.clear();
lcd.backlight();
gravityTds.setPin(TdsSensorPin);
gravityTds.setAref(5.0);
GravityTds.setAdcrange(1024);
gravityTds.begin();

Sensor.begin();
}
Void loop(){
  sensorvalue=analogRead(TurbiditySensorPin);
turbidity=map(sensorValue,0,1023,0,100);
for(int i=0;i<10;i++){
phBuf[i]=analogRead(pHSensorPin);
delay(10);
}
for (int i=0;i<9;i++){
for(int j=i+1;j<10;j++){
if (phBhuf[i]>phBuf[j]{
temp=phbuf[i];
phBuf[i]=phBuf[j];
phBuf[j]=temp;
}
}
}
avgValue=0;
for(int i=2;i<8;i++){
avgvalue+=phBuf[i];
}
phvalue=(float)avgValue*5.0/1024/6;
phValue=3.5*phValue;
gravityTds.setTemprature(temprature);
gravityTds.update();
tdsValue=gravityTds.getTdsValue();

Sensors.requstTemratures();
ds18b20temp=sensors.getTempCByindex(0);

lcd.setCursor(0,0);
lcd.print("TDS:");
lcd.print(tdsValue,0);
lcd.setCursor(9,0);
lcd.print("pH:");
lcd.print(pH Value,2);

lcd.setCursor(0,1);
lcd.print("Turb:");
lcd.print(Turbidity);
lcd.setCursor(9,1);
lcd.print("Temp");
lcd.print(ds18b20Temp,1);

Serial.print("TDS:");
Serial.print(tdsValue,0);
Serial.print("pH:");
Serial.print(phValue,2);
Serial.print("Turbidity:");
Serial.print(turbidity);
Serial.print("Temp:");
Serial.print(ds18b20Temp,1);
Serial.println("C");

delay(1000);
}
