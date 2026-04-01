#include "DHT.h"

#define DHTPIN 4     
#define DHTTYPE DHT22   
#define LDR_PIN 34   // LDR (simulando pH)
#define RELAY_PIN 5  // Relé Azul (Bomba)

// Definição dos botões
#define BTN_N 25     // Botão Nitrogênio (Cima)
#define BTN_P 26     // Botão Fósforo (Meio)
#define BTN_K 27     // Botão Potássio (Baixo)

DHT dht(DHTPIN, DHTTYPE);

bool vaiChover = false; 

void setup() {
  Serial.begin(115200);
  dht.begin();
  
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BTN_N, INPUT_PULLUP); 
  pinMode(BTN_P, INPUT_PULLUP);
  pinMode(BTN_K, INPUT_PULLUP);
  
  digitalWrite(RELAY_PIN, LOW); // Bomba inicie desligada
  
  Serial.println("Iniciando Sistema FarmTech - Monitoramento de Soja");
}

void loop() {
  // Leitura do DHT22 (Umidade do Solo Simulada)
  float umidadeSolo = dht.readHumidity();

  bool temN = (digitalRead(BTN_N) == LOW);
  bool temP = (digitalRead(BTN_P) == LOW);
  bool temK = (digitalRead(BTN_K) == LOW);

  int valorLDR = analogRead(LDR_PIN);
  float pH = map(valorLDR, 0, 4095, 0, 14);

  // 'C', vai chover. 'S', sem chuva.
  if (Serial.available() > 0) {
    char comando = Serial.read();
    if (comando == 'C') {
      vaiChover = true;
      Serial.println("Python: Alerta de CHUVA recebido!");
    } else if (comando == 'S') {
      vaiChover = false;
      Serial.println("Python: Previsão de TEMPO SECO.");
    }
  }

  // Lógica de Irrigação
  // Liga a bomba se a umidade estiver baixa e não houver previsão de chuva
  if (umidadeSolo < 40.0 && !vaiChover) {
    digitalWrite(RELAY_PIN, HIGH); // Liga
  } else {
    digitalWrite(RELAY_PIN, LOW);  // Desliga 
  }

  // Prints de acompanhamento
  Serial.print("Umidade Solo: "); Serial.print(umidadeSolo); Serial.print("% | ");
  Serial.print("pH (LDR): "); Serial.print(pH); Serial.print(" | ");
  Serial.print("NPK: ["); 
  Serial.print(temN ? "N" : "-"); Serial.print(temP ? "P" : "-"); Serial.print(temK ? "K" : "-"); 
  Serial.print("] | Bomba: ");
  Serial.println(digitalRead(RELAY_PIN) == HIGH ? "LIGADA" : "DESLIGADA");

  delay(2000); // Tempo para a proxima leitura
}