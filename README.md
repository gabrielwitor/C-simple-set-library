
# C simple set library

C simple set library é uma biblioteca que implementa a estrutura de dados conjunto na linguagem C.

A biblioteca utiliza árvores binárias de busca e listas encadeadas para alcançar este propósito.


## Requisitos
Para rodar a demo da biblioteca ou para compilá-la em um arquivo .o, é necessário ter instalado em seu computador [make](https://www.gnu.org/software/make/) e [C](https://gcc.gnu.org/).

## Execução

Clone o repositório

     git clone https://github.com/gabrielwitor/C-simple-set-library.git

Compile o código

     make

 Execute a demo

     ./main


## Notas e ponderações

É provável que a árvore binária de busca não seja a estrutura de dados mais eficiente para este trabalho. Mesmo assim, buscando simplicidade preferi utilizar essa estrutura de dados relativamente simples.

Por que não utilizei hashing? 
Hashing seria uma boa alternativa se o conjunto de números que podem ser adicionados fosse relativamente pequeno. Entretanto, neste trabalho o objetivo era criar um conjunto capaz de armazenar números inteiros (-∞ até +∞).
É claro que em C, como qualquer outra linguagem, existe o limite dos tamanhos dos números. Ainda assim, se eu fosse criar uma tabela hash para [números inteiros em C](https://www.ime.usp.br/~pf/algoritmos/aulas/int.html), a tabela seria gigante, ou haveriam muitos conflitos na tabela.


