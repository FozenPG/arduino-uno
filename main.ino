int inputPin = 7;               // Escolhe o pino de entrada(para o sensor PIR)
int pirState = LOW;             // Inicia o PIR, assumindo que não há movimento detectado
int val = 0;                    // Variável que lê o estado do PIR
int RELE_PIN = 6;               // Escolhe o pino onde esta o relé

void setup() {
  pinMode(RELE_PIN, OUTPUT);      // Declara que o relé é um dispositivo de saida
  pinMode(inputPin, INPUT);       // Declara que o sensor PIR é um dispositivo de entrada
  Serial.begin(9600);
}
void loop(){
  val = digitalRead(inputPin);  
  if (val == HIGH) {            
    digitalWrite(RELE_PIN, LOW);  
    delay(15000);
if (pirState == LOW) {
    Serial.println("Motion detected!");
    pirState = HIGH;
    }
  } else {
      digitalWrite(RELE_PIN, HIGH); 
      delay(30);    
      if (pirState == HIGH){
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}