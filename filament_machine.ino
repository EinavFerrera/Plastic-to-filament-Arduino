 #include <max6675.h>
 #include "temp_read.h"
 #include "stepper_move.h"
 #include "temp_cont.h"
 #include "print.h"
 #include "stepper_Accel.h"
 #include"stepper_28Byj.h"

int actionCounter = 1; // 1 == temp read, 2 == temp cont ,3== speed, 4 == print 

void setup(void) {
  analogReference(EXTERNAL);
  set_temp();
  setMotor();
  Serial.begin(1000000);   //initialize serial communication at a baud rate of 9600
}

void loop(void) {
switch (actionCounter%4){
case 0:
  if (actionCounter%40 == 0){
    actionCounter = 0;
    print();
  }
  break;
case 1:
  temp_read();
  break;
case 2:
  temp_control();
  break;
case 3:
  moveMotor();
  break;
}
actionCounter+=1;
}