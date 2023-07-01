# Projeto Braço Robótico com Três Articulações

## Apresentação
  Esse projeto é um braço articulado controlado por um sensor de flexão e um potenciômetro. As articulações são servo motores.

## Código do Pograma
```INO
// Esse programa controla um braço com três articulações por meio de um sensor de flexão e um potenciômetro.
// O sensor de flexão controla os dois servo motores do corpo, já o potenciometro controla o servo motor da base.

// Autores: Victor Moreli dos Santos, Bruno Basckeira Chinaglia, Giordano Santorum Lorenzetto
// Data: 2023

#include <Servo.h>

// Definindo pinos de entrada analógica para o flex sensor e para o potenciômetro
#define flexPin A0
#define potPin A1

// Definindo pinos de saída dos servos
#define servo1Pin 3
#define servo2Pin 5
#define servo3Pin 6

// Definindo valores máximos e mínimos do sensor flexor e do potenciometro
#define value_flex_min 250
#define value_flex_max 650
#define value_pot_min 1014
#define value_pot_max 41

// Variaveis de valor do flex sensor e do potenciometro
int value_flex, value_pot;

// Variaveis dos servos motores
Servo s1, s2, s3;
int pos1, pos2, pos3;

void setup() {

  // Declarando os três servos motores
  s1.attach(servo1Pin);
  s2.attach(servo2Pin);
  s3.attach(servo3Pin);

  // Setando a posição dos servo motores para 0
  s1.write(0);
  s2.write(0);
  s3.write(0);

  Serial.begin(9600);
}

void loop() {

  // Lendo valor do sensor de flexão
  value_flex = analogRead(flexPin);

  // Lendo valor do potenciômetro
  value_pot = analogRead(potPin);

  // Alterando as posições dos servos motores 1 e 2 com o sensor de flexão
  pos_1 = map(value_flex, value_flex_min, value_flex_max, 0, 90);
  pos_2 = map(value_flex, value_flex_min, value_flex_max, 0, 90);
  s.write(pos_1);
  s.write(pos_2);

  // Alterando a posição do servo motor 3 (da base) com o potenciômetro
  pos_3 = map(value_pot, value_pot_min, value_pot_max, 0, 360);
  s.write(pos_3);
  
  delay(100);

}
```

### Medição dos valores:
  Máximos e mínimos registrados para colocar no programa
  
  * Sensor resistivo de flexão:
  
![WhatsApp Image 2023-07-01 at 15 44 47](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/124844938/076b9289-c320-4b6a-bdae-03a9af4d935c)

  * Potenciômetro:
  
![WhatsApp Image 2023-07-01 at 15 48 08](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/124844938/ce55bca2-a3ec-4cbd-acb3-b71f7f0f17d1)

## Código de Medição de valores
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
## Imagem do processo de construção
![essa](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/124844938/72832283-ee4b-4a3f-aa52-edd4d09aecaf)





### Alunos:
* Bruno Basckeira Chinaglia
* Didrick Chancel Egnina Ndombi
* Giordano Santorum Lorenzetto
* Victor Moreli dos Santos
