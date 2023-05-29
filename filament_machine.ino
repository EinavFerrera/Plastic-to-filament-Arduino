 #include <max6675.h>
 #include "temp_read.h"
 #include "stepper_move.h"
 #include "temp_cont.h"
 //#include "print.h"
 #include "stepper_Accel.h"

int printCounter;

void setup(void) {
  analogReference(EXTERNAL);
  set_temp();
  set_motor();
 //set_AC_motor();
  Serial.begin(9600);   //initialize serial communication at a baud rate of 9600

}

void loop(void) {
  
 temp_read();
 motor_speed();
 //motor_AC();
 temp_control();

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
          Serial.print(",   Speed: ");
          //Serial.println(speed);
           Serial.println(rotating_speed);
        }

}