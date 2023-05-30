#include <AccelStepper.h>

AccelStepper steppers = AccelStepper(8 ,9, 11, 10, 12); 


//Stepper Variables
int max_speed = 1500;
int main_speed = 0;
bool but1_state = true;
bool activate_stepper = true;
int rotating_speed;
int speed_pot = A1;
int STEP = 3;
int DIR = 4;




void setAccelMotor() {
  steppers.setMaxSpeed(max_speed);
  //steppers.setAcceleration(200);
  }

void motorAccel() {
    rotating_speed = map(analogRead(speed_pot),0,1024,main_speed,max_speed);
    steppers.setSpeed(rotating_speed);
    steppers.runSpeed();
}
