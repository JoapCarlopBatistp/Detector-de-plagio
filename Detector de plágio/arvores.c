#include <stdio.h>
#include <stdlib.h>
#include "arvores.h"



pNodoA* InsereAVL (pNodoA *a, TipoPtNo *str, int *ok){



    int comparacao;


    if (a == NULL) {
        a = (pNodoA*) malloc(sizeof(pNodoA));
        a->palavra = str;
        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0;
        ok = 1;
    }
    else{
        comparacao = Compara_Palavra(str, a->palavra);
        if (comparacao == -1) {
            a->esq = InsereAVL(a->esq,str,ok);
            if (*ok) {
                switch (a->FB) {
                    case -1: a->FB = 0; *ok = 0; break;
                    case 0: a->FB = 1; break;
                    case 1: a=Caso1(a,ok); break;
                }
            }
            }
        else {
            a->dir = InsereAVL(a->dir,str,ok);
            if (*ok) {
                switch (a->FB) {
                    case 1: a->FB = 0; *ok = 0; break;
                    case 0: a->FB = -1; break;
                    case -1: a = Caso2(a,ok); break;
                }
            }
        }
    }

return a;
}

pNodoA* Caso1 (pNodoA *a , int *ok)
{

    pNodoA *z;
    z = a->esq;

    if (z->FB == 1)
        a = rotacao_direita(a);
    else
        a = rotacao_dupla_direita(a);

    a->FB = 0;
    *ok = 0;

    return a;
}

pNodoA* Caso2 (pNodoA *a , int *ok)
{
    pNodoA *z;
    z = a->dir;

    if (z->FB == -1)
        a = rotacao_esquerda(a);
    else
        a = rotacao_dupla_esquerda(a);

    a->FB = 0;
    *ok = 0;

    return a;
}

pNodoA* rotacao_direita(pNodoA* p)
{
    pNodoA *u;
    u = p->esq;
    p->esq = u->dir;
    u->dir = p;
    p->FB = 0;
    p = u;
    return p;
}

pNodoA* rotacao_esquerda(pNodoA *p)
{
    pNodoA *z;
    z = p->dir;
    p->dir = z->esq;
    z->esq = p;
    p->FB = 0;
    p = z;
    return p;
}

pNodoA* rotacao_dupla_direita (pNodoA* p)
{
    pNodoA *u, *v;
    u = p->esq;
    v = u->dir;
    u->dir = v->esq;
    v->esq = u;
    p->esq = v->dir;
    v->dir = p;

    if (v->FB == 1) p->FB = -1;
    else p->FB = 0;

    if (v->FB == -1) u->FB = 1;
    else u->FB = 0;

    p = v;
    return p;
}

pNodoA* rotacao_dupla_esquerda (pNodoA *p)
{
    pNodoA *z, *y;
    z = p->dir;
    y = z->esq;
    z->esq = y->dir;
    y->dir = z;
    p->dir = y->esq;
    y->esq = p;

    if (y->FB == -1) p->FB = 1;
    else p->FB = 0;

    if (y->FB == 1) z->FB = -1;
    else z->FB = 0;


    p = y;
    return p;
}

int Contagem_Palavras(pNodoA *a)
{

    if(a == NULL){
        return 0;
    }
    else{
        return 1 + Contagem_Palavras(a->esq) + Contagem_Palavras(a->dir);
    }
}

int Ja_Existe(pNodoA *a, TipoPtNo *str)
{
    int flag;
    pNodoA *aux;

    aux = a;


    while(aux != NULL){
        flag = Compara_Palavra(aux->palavra, str);

        switch(flag)
        {
            case 0: return 1; break;         //Achou igual
            case -1: aux = aux->dir; break;  //Se a string for maior
            case 1: aux = aux->esq; break;  //Se a string for menor
        }
    }

    return 0;     //Não achou igual

}

pNodoA* Insere_Palavra(pNodoA *a, char word[], int i)  //i sempre começa em 0
{
    TipoPtNo *str = Inicializa_Lista();
    char c;
    int ok = 0;
    int j;


    while(word[i] != '\0'){

        if(word[i] >= 65 && word[i] <= 90){   //Transforma letras maíusculas em minúsculas
            word[i] = word[i] + 32;
        }

        c = word[i];
        str = Insere_Lista(str, c);
        i++;
    }

    j = Ja_Existe(a, str);


    if(j == 0){
        a = InsereAVL(a, str, &ok);
    }


    return a;

}

pNodoA* Inicializa_Arvore(void){
    return NULL;
}

int Compara_Arvores(pNodoA *a, pNodoA *b){

    int resultado = 0;

    if(Compara_Palavra(a->palavra, b->palavra) == 0){
        return resultado + 1;
    }
    else
        return resultado;

}

pNodoA* Caminhamento(pNodoA *a, pNodoA *b){
    int total;

    a = Caminhamento(a->dir, b);
    a = Caminhamento(a->esq, b);

    if(a == NULL){
        return 0;
    }
    else{
        while(b != NULL){
        total += Compara_Arvores(a, b);
        total += Compara_Arvores(a, b->esq);
        total += Compara_Arvores(a, b->dir);
        }
    }
}
