# Projeto Braço Robótico com Três Articulações

## Apresentação
  Esse projeto é um braço articulado controlado por um sensor de flexão e um potenciômetro. As articulações são servo motores.

## Medição dos valores:
  Máximos e mínimos registrados para colocar no programa
  
  * Sensor resistivo de flexão:
  
![WhatsApp Image 2023-07-01 at 15 44 47](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/124844938/076b9289-c320-4b6a-bdae-03a9af4d935c)

  * Potenciômetro:
  
![WhatsApp Image 2023-07-01 at 15 48 08](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/124844938/ce55bca2-a3ec-4cbd-acb3-b71f7f0f17d1)

## Código do Programa
```INO
// Esse programa define valores de máximo e mínimo obitos por meio do sensor de flexão e do potenciômetro.
// Essa informação é importante para controlar os servos motores do braço articulado.
// Autores: Bruno Basckeira Chinaglia, Didrick Chancel Egnina Ndombi, Giordano Santorum Lorenzetto, Victor Moreli dos Santos
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
```

### Alunos:
* Bruno Basckeira Chinaglia
* Didrick Chancel Egnina Ndombi
* Giordano Santorum Lorenzetto
* Victor Moreli dos Santos
