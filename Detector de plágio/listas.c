#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "arvores.h"

int Compara_Palavra(TipoPtNo *str1, TipoPtNo *str2)
{
    TipoPtNo *ptaux1, *ptaux2;
    ptaux1 = str1;
    ptaux2 = str2;

    while(str1 != NULL && str2 != NULL){

        if(ptaux1->letra > ptaux2->letra){
            return 1;
        }
        if(ptaux1->letra < ptaux2->letra){
            return -1;
        }
        ptaux1 = ptaux1->prox;
        ptaux2 = ptaux2->prox;
    }

    if(ptaux1 == NULL && ptaux2 == NULL){
        return 0;
    }
    else
        return -1;
}



TipoPtNo Insere_Palavra(TipoPtNo *str, char word[], int i)  //i sempre começa em 0
{

    while(word[i] != NULL){

        if(word[i] >= 65 && word[i] <= 90){   //Transforma letras maíusculas em minúsculas
            word[i] = word[i] + 32;
        }

        if(str == NULL){
            str = (TipoPtNo*) malloc(sizeof(TipoPtNo));
            str->letra = word[i];
            str->prox = NULL;
            i++;
        }

        Insere_Palavra(str->prox, word, i);
    }

    return *str;

}
