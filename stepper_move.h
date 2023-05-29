#include <Stepper.h>
// ------------------stepper----------
//Set how many steps it takes to make a full revolution
//Divide the degrees per step by 360 to get the steps
const int stepsPerRevolution = 2048;
int turn = stepsPerRevolution;
int speed;
int maxSpeed = 13;

//Use pin 10-13 to IN1-IN4
Stepper wheelMotor = Stepper(stepsPerRevolution, 10, 12, 11, 13);

int potPin = A1; // potentiometer is connected to analog 0 pin
int potValue; // variable used to store the value coming from the sensor
float percent; // variable used to store the percentage value

void set_motor() {

  //Set the RPM of the stepper motor
  wheelMotor.setSpeed(maxSpeed);  

  }

void motor_speed() {
    potValue = analogRead(potPin); // get a reading from the potentiometer, assign the name potValue
    speed = map(potValue, 0, 1023, 0, 15); // convert reading to a percentage
    speed = 15;
    wheelMotor.setSpeed(speed);
      if (speed>1)
        wheelMotor.step(10);
      }


