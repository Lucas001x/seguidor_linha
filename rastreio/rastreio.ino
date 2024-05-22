#include <Ultrasonic.h>// Inicia a biblioteca do sensor ultrassônico

//Define os pinos trigger, echo e o pino do botão
#define pino_trigger 27
#define pino_echo 14
#define pino_botao 17
Ultrasonic ultrasonic(pino_trigger, pino_echo); // Inicializa o sensor ultrassônico

const int num_valores = 250; // Número de valores a serem armazenados
float valores[num_valores]; // Array para armazenar os valores
int indice = 0; // Índice para o array
bool armazenando = false; // Flag para verificar se está armazenando

void setup() {
  Serial.begin(115200);
  pinMode(pino_botao, INPUT_PULLUP); // Configura o pino do botão como entrada com pull-up interno
  // Inicializa o array com zeros
  for (int i = 0; i < num_valores; i++) {
    valores[i] = 0;
  }
}

void armazenarValor(float novoValor) {
  // Armazena o novo valor no array
  if (indice < num_valores) {
    valores[indice] = novoValor;
    indice++;
  }
}

void imprimirValores() {
  // Imprime os valores armazenados
  Serial.print("Valores armazenados: ");
  for (int i = 0; i < num_valores; i++) {
    Serial.print(valores[i]);
    if (i < num_valores - 1) {
      Serial.print(", ");
    }
  }
  Serial.println();
}

void loop() {
  // Verifica se o botão foi pressionado
  if (digitalRead(pino_botao) == LOW) {
    armazenando = true;
    indice = 0; // Reinicia o índice
    delay(50); // Debounce para evitar leituras múltiplas
  }

  if (armazenando) {
    float cmMsec = ultrasonic.distanceRead(CM);
    delay(5);
    // Armazena o valor atual no array
    armazenarValor(cmMsec);
    // Verifica se a quantidade de valores armazenados atingiu o número desejado
    if (indice >= num_valores) {
      armazenando = false;
      imprimirValores();
    }
  }
}
