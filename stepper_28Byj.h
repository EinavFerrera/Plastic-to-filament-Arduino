#include <CheapStepper.h>
#define ANALOG_STEPPER_SPEED A1

CheapStepper stepper (9,10,11,12);  

bool moveClockwise = true;
int rpm;
int steps;


void setMotor() {
  stepper.setRpm(20);
  stepper.newMove(moveClockwise, 3000); // move 180 degrees from current position

}

void moveMotor() {

  stepper.run();
    steps = stepper.getStepsLeft();
    if (steps<=1600)
      stepper.resetSteps(0);

  if (steps == 0){
    rpm = map(analogRead(A1),0,1023,0,25);
    stepper.setRpm(rpm);
    if (rpm<5)
      stepper.stop();
    else
      stepper.newMove(moveClockwise, 1800); // move 180 degrees from current position
  }

}