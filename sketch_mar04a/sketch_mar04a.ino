#include <math.h>
int led0 = 0;
int led1 = 1;
float KtoC(float in){
  return in-273.15;
}
float CtoF(float in){
  return in*1.8+32.0;
 }
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

const float R0 = 10000;
const float R1 = 47000;
const float B = 4100;
const float T0 = 25.0+273.15;
void loop() {// put your main code here, to run repeatedly:
  float A = analogRead(A0); //reads count (0 to 1023) on analog input 
  A*=5.0;A/=1023.0;
  float tR=5.0*R1/A-R1;//Serial.println(tV);
  float temperature = 1.0/((log(tR/R0)/B) + 1.0/T0);
  Serial.println(CtoF(KtoC(temperature)));
  if(temperature>273.15){
    digitalWrite(led0,HIGH);
    digitalWrite(led1, LOW);
      return;
    }
    digitalWrite(led0,LOW);
    digitalWrite(led1, HIGH);
    return;
}
