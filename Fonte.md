# Projeto Fonte de Tensão
## Objetivo:
Desenvolver uma fonte capaz de transformar a corrente alternada da tensão média de 127V numa corrente de 12V contínua.

## Tabela dos componentes:
| Componentes | Quantidade | Valor unitário R$ |
|-------------|  :---:  |----------|
| Capacitor Eletrolítico (470uF) 35V       | 1 | 0,85 |
| Diodo 1N4004                             | 5 | 0,15 |
| Diodo Zener (13V)                        | 1 | 0,09 |
| Potenciômetro Linear 5k                  | 1 | 2,21 |
| Resistor 2.2K                            | 1 | 0,42 |
| Resistor 3k                              | 1 | 0,36 |
| Transistor NPN-2N2222                    | 1 | 2,00 |
| Led vermelho                             | 1 | 0,50 |
| Resistor 1.5k                            | 2 | 0,70 |
| | Total: | 9,39 |

Obs: A protoboard e o transformador (razão 7.1) foram emprestados a nós.

## Componentes:

* **Transformador**: é o primeiro componente, que transforma os 127v da ddp proveninete da tomada para valores menores desejados para o projeto. O transformador escolhido é capaz de abaixar a tensão alternada de 110 volts para 12 volts com 24v de pico, mas não altera as propriedades da tensão e da corrente, mantendo ambas alternadas.
* **Ponte de diodo**: é o segundo momento do circuito em que faz a corrente deixar de ser alternada, mas mantém a corrente pulsada, pois faz os ciclos da corrente passarem para o circuito sempre de maneira positiva.
* **Capacitor**: é o terceiro componente (em paralelo com todo o restante do circuito), que armazena a carga durante os ciclos da corrente alternada, liberando corrente quando a tensão interna é maior que a tensão vinda da fonte. Descarrega quando ocorre a inversão de ciclo. Como demonstrado nos cálculos da próxima seção, para alcançar o valor de riple de 10% (2,4V pois o pico é de 24V), a capacitância calculada deve ser de 347uF, portanto, optamos por pegar o capacitor de 470uF pela folga e compatibilidade con valores comerciais.
* **Resistores**: estão presentes por todo o circuito para limitar a corrente e evitar a queima dos dispositivos. Os resistores estão associados em série com vários componentes, tais como: o LED, o Diodo Zener, o potenciômetro e na saída final (para fins de medição).
* **LED**: é o próximo item em paralelo ao capacitor, que permite mostrar a passagem da corrente, ou seja, mostrar que a fonte está operante.
*  **Diodo Zener**: é o quarto período do circuito que regula a tensão máxima. Ele mantém a tensão dos seus terminais fixa numa tensão constante, no caso, em 13v, quando a tensão fornecida a ele é maior que a constante. Além disso, se oferecida uma ddp insuficiente para alcançar a constante, o diodo não conduz e não interfere no circuito.
*  **Potenciometro**: é o quinto momento do circuito, que consiste num resistor variável que permitirá o controle do valor da tensão resultante entre 3 e 12 volts.
*  **Transistor**: é a parte final do circuito, que amplifica a corrente pequena que chega na sua base para o desejado de no máximo 100mA. 

## Cálculo do capacitor

![CodeCogsEqn (1)](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/89356201/29496c5c-e417-4be1-b4f2-5546c9cbe771)


![CodeCogsEqn (3)](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/89356201/7a188a64-e19b-4c3a-be06-2f5ae6737534)


## Cálculo do resistor do LED

![CodeCogsEqn (4)](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/89356201/9bf6d8d4-5291-4e64-a36c-125aa9267134)

Os demais resistores foram decididos empiricamente por meio do simulador Falstad.


## Imagem da fonte no simulador
![image](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/89356201/4583e65e-1b09-4c39-90c7-f53b2e2b4452)
  É importante notar que os valores de alguns resistores foram alterados seguindo medições feitas na prática. O resistor de 2k2 Ohms foi substitudo por dois resistores de 1k Ohms em série pegos no lab, para se adequar melhor aos valores de tensão que devem ser disponibilizados pela fonte.
Link da fonte: https://tinyurl.com/23abu5a5

## Esquemático da fonte
![image](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/129186535/a5292c87-7d33-444d-a904-8b300dbed69c)
## PCB da fonte
![image](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/129186535/d0978a1f-b648-433c-9da4-a37cec547c0d)
## Pasta do projeto do EAGLE
[Fonte.zip](https://github.com/brunobchinaglia/Projeto-Eletronica/files/11952782/Fonte.zip)


## Professor Simões medindo a fonte na Protoboard
![krxxtddj](https://github.com/brunobchinaglia/Projeto-Eletronica/assets/124844938/507c9743-61b4-45ac-a99a-6a84604367b4)




## Vídeo no YouTube

### Alunos:
* Bruno Basckeira Chinaglia
* Didrick Chancel Egnina Ndombi
* Giordano Santorum Lorenzetto
* Victor Moreli dos Santos
