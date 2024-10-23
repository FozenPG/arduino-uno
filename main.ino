#include <Servo.h>

// Definições de pinos
const int pirPin = 2;        // Sensor PIR conectado ao pino 2
const int ledPin = 3;        // LED conectado ao pino 3
const int relayPin = 4;      // Relé conectado ao pino 4
const int buttonPin = 5;     // Botão de controle remoto conectado ao pino 5

Servo servoMotor;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  servoMotor.attach(6);     // Servo conectado ao pino 6

  // Inicializar estados
  digitalWrite(ledPin, LOW);
  digitalWrite(relayPin, LOW);

  Serial.begin(9600);
}

void loop() {
  int pirState = digitalRead(pirPin);
  int buttonState = digitalRead(buttonPin);

  // Detecção de movimento com PIR
  if (pirState == HIGH) {
    digitalWrite(ledPin, HIGH);      // Liga o LED
    digitalWrite(relayPin, HIGH);    // Aciona o relé para ligar a luz
    servoMotor.write(90);            // Move o servo motor (se necessário)
    Serial.println("Movimento detectado: Luzes ligadas");
  } else {
    digitalWrite(ledPin, LOW);       // Desliga o LED
    digitalWrite(relayPin, LOW);     // Desliga o relé para apagar a luz
    servoMotor.write(0);             // Retorna o servo motor à posição original
    Serial.println("Nenhum movimento: Luzes apagadas");
  }

  // Controle remoto manual
  if (buttonState == HIGH) {
    digitalWrite(ledPin, !digitalRead(ledPin));   // Inverte o estado do LED
    digitalWrite(relayPin, !digitalRead(relayPin)); // Inverte o estado do relé
    delay(500); // Debounce
  }

  delay(200); // Pequeno atraso para evitar flutuações
}
