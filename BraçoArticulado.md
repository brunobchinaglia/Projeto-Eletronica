# Projeto Braço Robótico com Três Articulações

## Apresentação
  Esse projeto é um braço articulado controlado por um sensor de flexão e um potenciômetro. As articulações são servo motores.
  
https://github.com/brunobchinaglia/Projeto-Eletronica/assets/124844938/3338a261-644b-4c6e-9645-561d482f7916

À esquerda do vídeo, está o sensor de flexão e, à direita, está o potenciômetro.

### Sobre o protótipo
* **Material**:
  
  Foram utilizados três servo motores, sendo: um na base para fazer a rotação do eixo principal do braço, rotacionando-o todo à direita ou à esquerda, alèm disso, os dois restantes, serviram como articulações do membro robótico, possibilitando o deslocamento vertical dele. Ademais, papelão, protoboard, peças de plástico e a dobradura da mão, foram usufruídos como suporte e/ou decoração do projeto.
* **Sensores**:
  
  Para o controle do movimento vertical, foi usado um sensor de flexão, que varia a resistência ao ser dobrado, com ele, analisamos os intervalos de ddp máximos e mínimos oferecidos e colocamos na função "map" da biblioteca "servo.h" para conseguirmos controlar os dois servos motores das articulações.
  Para o controle radial do eixo principal, reutilizamos o potenciômetro da fonte de tensão, porém tivemos que realizar a nossa própria função map, pois, devido ao fato da escala do potenciômetro estar em exponenciação, tivemos que utilizar logaritmo e trabalhar com números decimais (que não são suportados na função "map" citada anteriormente).
* **Código**:
  
  A placa escolhida foi a do Arduíno, portanto, o código foi feito nessa linguagem (que basicamente é C).

## Código do Pograma
```INO
// Esse programa controla um braço com três articulações por meio de um sensor de flexão e um potenciômetro.
// O sensor de flexão controla os dois servo motores do corpo, já o potenciometro controla o servo motor da base.

// Autores: Victor Moreli dos Santos, Bruno Basckeira Chinaglia, Giordano Santorum Lorenzetto
// Data: 2023

#include <Servo.h>
#include <math.h>

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
#define value_pot_min 41
#define value_pot_max 1014

// Variaveis de valor do flex sensor e do potenciometro
int value_flex, value_pot;
int servo1vet[10] = {90, 90, 90, 90, 90, 90, 90, 90, 90, 90};
int servo2vet[10];

int tmp1 = 90, tmp2 = 90, tmp3 = 90, cont = 0;

// Variaveis dos servos motores
Servo s1, s2, s3;
int pos1, pos2, pos3;

void setup() {

  // Declarando os três servos motores
  s1.attach(servo1Pin);
  s2.attach(servo2Pin);
  s3.attach(servo3Pin);

  // Setando a posição dos servo motores para 0
  s1.write(90);
  s2.write(90);
  s3.write(90);

  Serial.begin(9600);
}

void loop() {

  // Lendo valor do sensor de flexão
  value_flex = analogRead(flexPin);

  // Lendo valor do potenciômetro
  value_pot = analogRead(potPin);


  // Verificação de máximo e mínimo com o objetivo de proteger o servo motor de giros inválidos
  if(value_flex > value_flex_max){
    value_flex = value_flex_max;
  }

  if(value_flex < value_flex_min){
    value_flex = value_flex_min;
  }

  // Alterando as posições dos servos motores 1 e 2 com o sensor de flexão

  pos1 = (int) (map(value_flex, value_flex_min, value_flex_max, 10, 100)/5) * 5;
  s1.write(pos1);
  
  pos2 = (int) (map(value_flex, value_flex_min, value_flex_max, 10, 100)/5) * 5;
  s2.write(pos2);

  
  pos3 = (int) ((50 * log(value_pot)  - 180)/10) * 10 + 10;

  // Alterando a posição do servo motor 3 (da base) com o potenciômetro

  if(abs(pos3 - tmp3) > 20){
    s3.write(tmp3);
    Serial.print(" tmp posicao 3: ");
    Serial.println(tmp3);
  } else {
    s3.write(pos3);
    Serial.print(" pos posicao 3: ");
    Serial.println(pos3);
    tmp3 = pos3;
  }
  
  delay(100);

}
```

### Medição dos valores:
  Máximos e mínimos registrados para colocar no programa
  
  * Sensor resistivo de flexão:
  
![WhatsApp Image 2023-07-01 at 15 44 47](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/124844938/076b9289-c320-4b6a-bdae-03a9af4d935c)

  * Potenciômetro:
  
![WhatsApp Image 2023-07-01 at 15 48 08](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/124844938/ce55bca2-a3ec-4cbd-acb3-b71f7f0f17d1)

## Circuito para retirar sinal de sensor resistivo

  Tanto o sensor de flexão quanto o potenciômetro foram utilizados como sensores resistivos. O R é um resistor fixo que é calculado para gerar o maior range possível dentro das condições dos sensores. O maior range é cálculado pela diferença entre o sinal de tensão máxima e mínima em função do Rx (variável):

  ![image](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/89356201/ec7d5fde-eb90-4cfe-a880-2448456db769)

  
  Foi utilizado o software geogebra para encontrar o máximo do range. Foi escolhido um resistor de 200Ohms para acompanhar o potenciômetro e um de 33kOhms para acompanhar o sensor de flexão.
  Print das funções e do resultado no geogebra:

  
  ![image](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/89356201/1b29995c-26df-4c02-8865-0bdf6ab8b2ee)
  Potenciômetro.


  
  ![image](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/89356201/5efbb678-d5c9-4bdb-b29a-842301cc898b)
  Sensor de flexão.

  

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
