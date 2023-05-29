#include <AccelStepper.h>

AccelStepper stepper1 = AccelStepper(8 ,9, 11, 10, 12); 




//Stepper Variables
int max_speed = 4076;
int main_speed = 0;
bool but1_state = true;
bool activate_stepper = true;
int rotating_speed = 665;
int speed_pot = A1;
int STEP = 3;
int DIR = 4;




void set_AC_motor() {

  stepper1.setMaxSpeed(max_speed);
 // stepper1.setSpeed(500);
  }

void motor_AC() {

    rotating_speed = map(analogRead(speed_pot),0,1024,main_speed,max_speed);
    stepper1.setSpeed(rotating_speed);
    //stepper1.setSpeed(650);
   // stepper1.setAcceleration(200);
    stepper1.runSpeed();
}
