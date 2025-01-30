#include <stdbool.h>

/* Tipo que define o conjunto (Árvore binária). */
typedef struct set Set;

/* Insere elem no conjunto set. */ 
Set* add(Set* set, int elem);

/* Retorna T se o conjunto estiver vazio, F caso contrário. */ 
bool isEmpty(Set* set);

/* Retorna o número de elementos do conjunto */ 
int len(Set* set); 

/* Retorna T se o elemento estiver no conjunto, retorna F caso cobtrário. */ 
bool isIn(Set* set, int elem);

/* Bool. Retorna T se o elemento não estiver contido, F caso contrário. */ 
bool isNotIn(Set* set, int elem);

/* Retorna T se a intersecção entre os conjuntos for vazia, F caso contrário. */ 
bool isDisjoint(Set* set1, Set* set2); 

/* Remove elem do conjunto. */ 
Set* remove_(Set* set, int elem); 

/* Remove e retorna um elemento arbitrário (aleatório) do conjunto. */ 
int pop(Set* set);

/* Remove todos os elementos do conjunto. */ 
Set* clear(Set* set);

/* Retorna a união dos conjuntos. */ 
Set* union_(Set* set1, Set* set2);

/* Retorna a interseção dos conjuntos. */ 
Set* intersection(Set* set1, Set* set2);

/* Retorna um conjunto com os elementos que estão no 1 e não estão no 2. */
Set* symmetric_difference(Set* set1, Set* set2);

/* Verifica se o conjunto 1 é um subconjunto de 2. */
bool isSubSet(Set* set1, Set* set2);

/* Verifica se o conjunto 1 é um superconjunto de 2. */
bool isSuperSet(Set* set1, Set* set2);

/* Retorna uma cópia física do conjunto. */
Set* copy(Set* set);

/* Imprime o conjunto no terminal. */
void print(Set* set);

