
const int PINO_TRIG = 27; 
const int PINO_ECHO = 14; 
void setup() {
  Serial.begin(115200);
  pinMode(PINO_TRIG, OUTPUT);
  pinMode(PINO_ECHO, INPUT);
}

void loop() {
  digitalWrite(PINO_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PINO_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIG, LOW);  
  long duracao = pulseIn(PINO_ECHO, HIGH); // Mede o tempo de resposta do ECHO  
  float distancia = (duracao * 0.034029) / 2;// Calcula a distância usando a velocidade do som (aproximadamente 343 m/s)
  Serial.print(distancia);
  Serial.println();
  append(distancia);  
  delay(50);
}

//long -> A variável "long" é utilizada para armazenar números inteiros longos, ou seja, números inteiros maiores do que os que podem ser armazenados em uma variável "int"
//delayMicroseconds -> A função delayMicroseconds() lida com microssegundos (10 elevado a -6 segundos), enquanto a função delay() lida com milissegundos (10 elevado a -3 segundos).

const int num_valores = 10;  // Número de valores a serem armazenados
float valores[num_valores];
int i = 0;  // Array para armazenar os valores
void append(float distancia){
  if(i <= num_valores){
    valores[i] = distancia;
  }else{
    i = 0;
    media();
  };
}

void media(){
  float soma = 0;
  
  for(int j = 0; j < num_valores; j++) {
    soma += valores[j];
  }

  float media = soma / num_valores;
  Serial.println(media);

};