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

