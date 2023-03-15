int verde = 12;
int vermelho = 13;
int botao = 2;

void setup() {
  pinMode(verde, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  
  while(digitalRead(botao) == HIGH){
    delay(1);
  }
  
  digitalWrite(vermelho, HIGH);
  
  int intervalo = random(1000, 3000);
  delay(intervalo);
  
  digitalWrite(vermelho,LOW);
  digitalWrite(verde, HIGH);
  
  long tempoInicial = millis();
  long tempoLimite = millis();
  long tempoDecorrido = 0;
  
  while (digitalRead(botao) == HIGH && tempoDecorrido < tempoLimite) {
    delay(1);
    tempoDecorrido++;
  }
  if (digitalRead(botao) == LOW) {
    long tempoDeReacao = millis() - tempoInicial;
    Serial.print("Tempo de reacao: ");
    Serial.print(tempoDeReacao);
    Serial.println("ms");
    digitalWrite(verde, LOW);
  }
  delay(150);
}
