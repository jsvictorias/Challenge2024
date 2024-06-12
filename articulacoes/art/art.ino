#include <Servo.h>

// Definição dos pinos dos servos
#define SERVO1_PIN 6
#define SERVO2_PIN 7
#define SERVO3_PIN 8
#define SERVO4_PIN 9
#define SERVO5_PIN 10

// Definição dos pinos dos potenciômetros
#define POT1_PIN A0
#define POT2_PIN A1
#define POT3_PIN A2
#define POT4_PIN A3
#define POT5_PIN A4

// Criação dos objetos Servo
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// Variáveis para armazenar os ângulos atuais dos servos
int angle1 = 0;
int angle2 = 0;
int angle3 = 0;
int angle4 = 0;
int angle5 = 0;

// Variável para armazenar o valor de mudança significativa
const int threshold = 5;

void setup() {
  // Conecta os servos aos pinos digitais
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  servo3.attach(SERVO3_PIN);
  servo4.attach(SERVO4_PIN);
  servo5.attach(SERVO5_PIN);

  // Move os servos para a posição inicial
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(angle4);
  servo5.write(angle5);
}

void loop() {
  // Lê os valores dos potenciômetros (0 a 1023)
  int pot1Val = analogRead(POT1_PIN);
  int pot2Val = analogRead(POT2_PIN);
  int pot3Val = analogRead(POT3_PIN);
  int pot4Val = analogRead(POT4_PIN);
  int pot5Val = analogRead(POT5_PIN);

  // Mapeia os valores dos potenciômetros para ângulos de 0 a 180
  int newAngle1 = map(pot1Val, 0, 1023, 0, 180);
  int newAngle2 = map(pot2Val, 0, 1023, 0, 180);
  int newAngle3 = map(pot3Val, 0, 1023, 0, 180);
  int newAngle4 = map(pot4Val, 0, 1023, 0, 180);
  int newAngle5 = map(pot5Val, 0, 1023, 0, 180);

  // Verifica se a mudança é significativa para mover os servos
  if (abs(newAngle1 - angle1) > threshold) {
    angle1 = newAngle1;
    servo1.write(angle1);
  }

  if (abs(newAngle2 - angle2) > threshold) {
    angle2 = newAngle2;
    servo2.write(angle2);
  }

  if (abs(newAngle3 - angle3) > threshold) {
    angle3 = newAngle3;
    servo3.write(angle3);
  }

  if (abs(newAngle4 - angle4) > threshold) {
    angle4 = newAngle4;
    servo4.write(angle4);
  }

  if (abs(newAngle5 - angle5) > threshold) {
    angle5 = newAngle5;
    servo5.write(angle5);
  }

  // Pequeno atraso para suavizar o movimento
  delay(15);
}
