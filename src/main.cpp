#include <Arduino.h>
#include <DHT.h>
#define DHTPIN 12
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int RGBpin[] = {9, 10, 11};
int LDRpin = A0;
int LDRValue = 0;

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
{
  analogWrite(RGBpin[0], red_light_value);
  analogWrite(RGBpin[1], green_light_value);
  analogWrite(RGBpin[2], blue_light_value);
}

void LuxLight(int LDRL){
  if(LDRL > 0){
    RGB_color(255, 255, 255);
  }
  if(LDRL > 100){
    RGB_color(225, 225, 225);
  }
  if(LDRL > 200){
    RGB_color(200, 200, 200);
  }
  if(LDRL > 300){
    RGB_color(180, 180, 180);
  }
  if(LDRL > 400){
    RGB_color(160, 160, 160);
  }
  if(LDRL > 500){
    RGB_color(140, 140, 140);
  }
  if(LDRL > 600){
    RGB_color(120, 120, 120);
  }
  if(LDRL > 700){
    RGB_color(100, 100, 100);
  }
  if(LDRL > 800){
    RGB_color(50, 50, 50);
  }
  if(LDRL > 900){
    RGB_color(0, 0, 0);
  }

}

void setup() {
  Serial.begin(9600);
  dht.begin(); // initialize the sensor
  pinMode(RGBpin[0], OUTPUT);
  pinMode(RGBpin[1], OUTPUT);
  pinMode(RGBpin[2], OUTPUT);
}

void loop() {
  float humi  = dht.readHumidity();       // read temperature as Celsius
  float tempC = dht.readTemperature();    // read temperature as Fahrenheit
  if (isnan(humi) || isnan(tempC)) {      // check if any reads failed
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.print("%");
    Serial.print("  |  "); 
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("°C ~ ");
    Serial.println("");
  }
  for(int i=0; i<5; i++){
    LDRValue = analogRead(LDRpin);
    Serial.print("LDR Value is: ");
    Serial.println(LDRValue);
    LuxLight(LDRValue);
    delay(1000);
  }
  Serial.println("");
}