
int printCounter;
extern float temperature;
extern int heater;
extern int setTemp;
extern int ref;
extern int rotating_speed;
extern int rpm;
extern int steps;
void print(){

 printCounter+=1;
  if (printCounter%30==0){

            Serial.print("Temp: ");
            Serial.print(temperature);
          if (heater == 0)
            Serial.print(",   Heater OFF");
          else
              Serial.print(",   Heater ON");
          Serial.print(",  Set temp =  ");
          Serial.print(setTemp);
          Serial.print("  stepper RPM: "); 
          Serial.println(rpm);
        
        }
}