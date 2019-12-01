/* MQ-3 Alcohol Sensor Circuit with Arduino */
/*SHUBHAM GUPTA - EMBEDDED ENGINEER*/
#include <string.h>

const int AOUTpin=A0;//the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
const int ledPin=13;//the anode of the LED connects to digital pin D13 of the arduino
String str;
int i,alco_high,alco_low,mapped,data;
int moistPin = A1;
int moistVal = 0;
int tooDry = 150; //set low parameter for plant
int tooWet = 400; 
void setup() {
Serial.begin(9600);//sets the baud rate
pinMode(AOUTpin, INPUT);//sets the pin as an input to the arduino
for(i=2;i<=5;i++)
{
  pinMode(i,OUTPUT);//sets the pin as an output of the arduino
}
}

void loop()
{
  alco_high=0; // initially alcohol level is zero
  alco_low = 1023; // low threshold is 1023


data= analogRead(AOUTpin);//reads the analaog value from the alcohol sensor's AOUT pi//prints the alcohol value
 moistVal = analogRead(moistPin);
  int percent = 2.718282 * 2.718282 * (.008985 * moistVal + 0.207762); //calculate percent for probes about 1 - 1.5 inches apar
  Serial.print(String(data)+","+String(moistVal)+",");
}
