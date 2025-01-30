#include "include/sets.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    // Seja bem vindo(a) à demo da C-simple-set-library 
    /*
    A biblioteca implementa conjuntos na linguagem C utilizando
    árvores binárias de busca e listas lincadas.    
    Gabriel Witor, 2025.
    */

    // Para executar esta demo, basta digitar em seu terminal ./make (É necessário ter o make instalado).

    // Para inicializar o conjunto crie um ponteiro apontando para vazio.
    Set* set1 = NULL;
    Set* set2 = NULL;

    // Para adicionar basta usar a função add.

    set1 = add(set1, 10);
    set1 = add(set1, 20);
    set1 = add(set1, 30);

    set2 = add(set2, 40);
    set2 = add(set2, 50);

    printf("\nImprimindo os conjuntos:\n");

    print(set1);
    printf("\n");
    print(set2);

    // Removendo elementos.

    printf("\nRemovendo elementos do conjunto 1\n");
    set1 = remove_(set1, 10);
    set1 = remove_(set1, 20);

    print(set1);

    // Limpar os conjuntos.

    set1 = clear(set1);
    set2 = clear(set2);

    printf("\nUnião entre conjuntos\n");

    set1 = add(set1, 10);
    set1 = add(set1, 20);

    set2 = add(set2, 30);
    set2 = add(set2, 40);

    print(union_(set1, set2));

    printf("\nIntersecção entre conjuntos\n");

    set2 = add(set2, 10);

    print(intersection(set1, set2));

    //Há mais funções no arquivo sets.h.

    return 0;
}

