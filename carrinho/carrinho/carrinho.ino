#include <AccelStepper.h>
#include <MultiStepper.h>

#include <AccelStepper.h>


#define MOTOR1_STEP_PIN 3
#define MOTOR1_DIR_PIN 4
#define MOTOR2_STEP_PIN 5
#define MOTOR2_DIR_PIN 6


#define SWITCH_PIN 2


AccelStepper motor1(AccelStepper::DRIVER, MOTOR1_STEP_PIN, MOTOR1_DIR_PIN);
AccelStepper motor2(AccelStepper::DRIVER, MOTOR2_STEP_PIN, MOTOR2_DIR_PIN);

void setup() {
  
  pinMode(SWITCH_PIN, INPUT_PULLUP);

  motor1.setMaxSpeed(1000); 
  motor1.setAcceleration(500); 
  motor2.setMaxSpeed(1000); 
  motor2.setAcceleration(500); 
}

void loop() {
  
  if (digitalRead(SWITCH_PIN) == LOW) {
    
    motor1.move(1000);  
    motor2.move(1000); 
  } else {
    
    motor1.stop();
    motor2.stop();
  }

  
  motor1.run();
  motor2.run();
}
