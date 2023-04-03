#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "arvores.h"

int Compara_Palavra(TipoPtNo *str1, TipoPtNo *str2)
{
    TipoPtNo *ptaux1, *ptaux2;
    ptaux1 = str1;
    ptaux2 = str2;

    while(ptaux1 != NULL && ptaux2 != NULL){

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

TipoPtNo* Insere_Lista(TipoPtNo *lista, char letra){
    TipoPtNo *ptaux, *novo_no = malloc(sizeof(TipoPtNo));


    if(novo_no){
        novo_no->letra = letra;
        novo_no->prox = NULL;

        if(lista == NULL){
            lista = novo_no;
        }
        else{
            ptaux = lista;
            while(ptaux->prox != NULL){
                ptaux = ptaux->prox;
            }
            ptaux->prox = novo_no;
        }

    }

}

TipoPtNo* Inicializa_Lista(){
    return NULL;
}

