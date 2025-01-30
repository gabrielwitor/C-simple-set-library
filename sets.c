#include "include/sets.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct set{
    int data;
    Set* right;
    Set* left;
};

typedef struct linked_list Linked_List;

struct linked_list{
    int data;
    Linked_List* next;
};

Linked_List* toLinkedList(Set* set, Linked_List* list);

Linked_List* insertLinkedList(Linked_List* list, int data);

void printLinkedList(Linked_List* list);

void freeLinkedList(Linked_List* list);

Set* add(Set* set, int elem){
    if(set == NULL){
        set = (Set*) malloc (sizeof(Set));

        set->data = elem;
        set->right = set->left = NULL;
    }

    else if (elem < set->data){
        set->left = add(set->left, elem);
    }

    else if (elem > set->data){
        set->right = add(set->right, elem);
    }

    return set;
}

bool isEmpty(Set* set){
    if (set == NULL){
        return true;
    }

    return false;
}

int len(Set* set){
    if (set == NULL){
        return 0;
    }

    int l = len(set->left);
    int r = len(set->right);

    return 1+l+r;
}

bool isIn(Set* set, int elem){
    if(set == NULL){
        return false;
    }

    if(set->data > elem){
        return isIn(set->left,elem);
    }

    if(set->data < elem){
        return isIn(set->right,elem);
    }

    return true;
}

bool isNotIn(Set* set, int elem){
    return !isIn(set, elem);
}

bool isDisjoint(Set* set1, Set* set2){

    if(set1 == NULL || set2 == NULL){
        return true;
    }

    return isNotIn(set2, set1->data) && isDisjoint(set1->left, set2) && isDisjoint(set1->right, set2);
}

Set* remove_(Set* set, int elem){
    if (set == NULL){
        return NULL;
    }

    else if (set->data > elem){
        set->left = remove_(set->left, elem);
    }

    else if (set->data < elem){
        set->right = remove_(set->right, elem);
    }

    else{
        if(set->left == NULL && set->right == NULL){
            free(set);
            set = NULL;
        }

        else if(set->left == NULL){
            Set* temp = set;
            set = set->right;
            free(temp);
        }

        else if(set->right == NULL){
            Set* temp = set;
            set = set->left;
            free(temp);
        }

        else{
            Set* temp = set->left;
            while(temp->right != NULL){
                temp = temp->right;
            }

            set->data = temp ->data;
            temp->data = elem;
            set->left = remove_(set->left, elem);
        }
    }
    return set;
}

int pop(Set* set){
    if(set == NULL){
        perror("Error. Impossible to remove elements from an empty set.");
    }

    Set* temp = set;
    while(temp->right != NULL){
        temp = temp->right;
    }

    int largest_number = temp->data;

    set = remove_(set, largest_number);
    return largest_number;
}

Set* clear(Set* set){
    if(set != NULL){
        clear(set->left);
        clear(set->right);
        free(set);
    }
    return NULL;
}

Set* union_(Set* set1, Set* set2){
    Linked_List* list = NULL;

    list = toLinkedList(set1, list);
    list = toLinkedList(set2, list);

    Set* set3 = NULL;

    Linked_List* aux = list;

    while(aux != NULL){
        set3 = add(set3, aux->data);
        aux = aux->next;
    }

    freeLinkedList(list);
    return set3;
}

Set* intersection(Set* set1, Set* set2){
    Linked_List* list = NULL;

    list = toLinkedList(set1, list);

    Set* set3 = NULL;

    Linked_List* aux = list;

    while(aux != NULL){
        if(isIn(set2, aux->data)){
            set3 = add(set3,aux->data);
        }
        aux = aux->next;
    }

    free(list);
    return set3;
}

Set* symmetric_difference(Set* set1, Set* set2){
    Linked_List* list = NULL;

    list = toLinkedList(set1, list);

    Set* set3 = NULL;

    Linked_List* aux = list;

    while(aux != NULL){
        if(isNotIn(set2, aux->data)){
            set3 = add(set3,aux->data);
        }
        aux = aux->next;
    }

    free(list);
    return set3;
}

bool isSubSet(Set* set1, Set* set2){

    bool isSubSet = true;

    Linked_List* list = NULL;

    list = toLinkedList(set1, list);

    Linked_List* aux = list;

    while(aux != NULL){
        if(isNotIn(set2, aux->data)){
            isSubSet = false;
            break;
        }
        aux = aux->next;
    }

    free(list);
    return isSubSet;
}

bool isSuperSet(Set* set1, Set* set2){
    return isSubSet(set2, set1);
}

Set* copy(Set* set){
    Linked_List* list = NULL;

    list = toLinkedList(set, list);

    Set* copy = NULL;

    Linked_List* aux = list;

    while(aux != NULL){
        copy = add(copy, aux->data);
        aux = aux->next;
    }

    free(list);
    return copy;

}


void print(Set* set){
    if(set != NULL){
        print(set->left);
        printf("%d\n",set->data);
        print(set->right);
    }
}

Linked_List* toLinkedList(Set* set, Linked_List* list){
    if(set != NULL){
        list = toLinkedList(set->left, list);
        list = insertLinkedList(list, set->data);
        list = toLinkedList(set->right, list);
    }
    return list;
}

Linked_List* insertLinkedList(Linked_List* list, int data){
    if(list == NULL){
        list = (Linked_List*) malloc (sizeof(Linked_List));
        list->data = data;
        list->next = NULL;
        return list;
    }
    list->next = insertLinkedList(list->next, data);
    return list;
}

void printLinkedList(Linked_List* list){
    Linked_List* temp = list;

    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void freeLinkedList(Linked_List* list){
    Linked_List* temp = list;

    while(list != NULL){
        temp = list;
        list = list->next;
        free(temp);
    }
}