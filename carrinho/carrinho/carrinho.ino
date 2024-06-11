#include <AccelStepper.h>
#include <MultiStepper.h>

#include <AccelStepper.h>

// Definições dos pinos dos motores de passo
#define MOTOR1_STEP_PIN 3
#define MOTOR1_DIR_PIN 4
#define MOTOR2_STEP_PIN 5
#define MOTOR2_DIR_PIN 6

// Definição do pino do interruptor
#define SWITCH_PIN 2

// Criação dos objetos AccelStepper para cada motor
AccelStepper motor1(AccelStepper::DRIVER, MOTOR1_STEP_PIN, MOTOR1_DIR_PIN);
AccelStepper motor2(AccelStepper::DRIVER, MOTOR2_STEP_PIN, MOTOR2_DIR_PIN);

void setup() {
  // Configuração do pino do interruptor
  pinMode(SWITCH_PIN, INPUT_PULLUP);

  // Configuração inicial dos motores
  motor1.setMaxSpeed(1000); // Ajuste conforme necessário
  motor1.setAcceleration(500); // Ajuste conforme necessário
  motor2.setMaxSpeed(1000); // Ajuste conforme necessário
  motor2.setAcceleration(500); // Ajuste conforme necessário
}

void loop() {
  // Verifica o estado do interruptor
  if (digitalRead(SWITCH_PIN) == LOW) {
    // Gira os motores se o interruptor estiver pressionado
    motor1.move(1000);  // Número de passos para mover
    motor2.move(1000);  // Número de passos para mover
  } else {
    // Para os motores se o interruptor não estiver pressionado
    motor1.stop();
    motor2.stop();
  }

  // Executa os movimentos dos motores
  motor1.run();
  motor2.run();
}
