// Esse programa define valores de máximo e mínimo obitos por meio do sensor de flexão e do potenciômetro.
// Essa informação é importante para controlar os servos motores do braço articulado.
// Autores: Bruno Basckeira Chinaglia, Giordano Santorum Lorenzetto, Victor Moreli dos Santos
// Data: 2023


// Declarando variáveis de leitura, máximo e mínimo
int value_flex, value_max = 0, value_min = -1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Lê valor do sensor de flexão
  value_flex = analogRead(A1);

  // Coloca valor inicial no valor mínimo
  if(value_min == -1){
    value_min = value_flex;
  }

  // Checa se o valor lido é maior que o máximo ou menor que o mínimo, para fazer as atribuições
  if(value_flex > value_max){
    value_max = value_flex;
  } else if(value_flex < value_min){
    value_min = value_flex;
  }

  // Printa na serial os valores máximo e mínimo obtidos com o sensor de flexão
  Serial.print("Max: ");
  Serial.print(value_max);
  Serial.print(" Min: ");
  Serial.println(value_min);

}
