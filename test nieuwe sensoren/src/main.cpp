#include <Arduino.h>      //dit is een test project om dingen te testen voordat ze in het grooteproject komen
//dit is een concept wat we gaan gebruken voor de grond meter
int Groundpin = A1;       //gebruik A1 omdat in A0 al de temperatuur meter zit
int GroundValue = 0;
const int GroundWet = 0;  // vul hier in wat de sensor meet zodra hij nat is
const int Grounddry = 0;  // vul hier in wat de sensor meet zodra hij droog is

void setup() {
  Serial.begin(9600);
}

void loop() {
  GroundValue = analogRead(Groundpin);
  Serial.println(GroundValue);
  int PercentageWet = map(GroundValue, GroundWet, Grounddry, 100, 0);     
  //moet checken hoe dit werkt, waarschijnlijk is eerste de sensor, daarna check de min en max en vertaal naar berijk tussen 0 en 100
  Serial.print(PercentageWet);    //het percentage en de value zullen langzaam hoger worden, het duurd even voordat de sensor het aanpast
  Serial.println("%");
  delay(1000);



}