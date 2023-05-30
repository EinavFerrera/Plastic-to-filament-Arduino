#define TEMP_CONTROL_PIN 2
#define ANALOG_TEMP A2
#define TEMP_MIN 30

int heater;
int analogTemp;
int setTemp;

void temp_control() {
analogTemp = analogRead(ANALOG_TEMP);
//setTemp = map(analogTemp, 0, 1023, 25, 320); // convert A2 to a percentage
setTemp = 270;
if (setTemp < TEMP_MIN){
  digitalWrite(TEMP_CONTROL_PIN,LOW);
  heater = 0;
}
if (temperature > setTemp-5){
  digitalWrite(TEMP_CONTROL_PIN,LOW);
  heater = 0;
}
else{
  digitalWrite(TEMP_CONTROL_PIN,HIGH);
  heater = 1;
}
}
