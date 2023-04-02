#include "listas.h"

#ifndef ARVORES_H
#define ARVORES_H

struct TNodoA{
TipoPtNo *palavra;
int FB;
struct TNodoA *esq;
struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;

pNodoA* InsereAVL (pNodoA *a, TipoPtNo *str, int *ok);

pNodoA* Caso1 (pNodoA *a , int *ok);

pNodoA* Caso2 (pNodoA *a , int *ok);

pNodoA* rotacao_direita(pNodoA* p);

pNodoA* rotacao_esquerda(pNodoA *p);

pNodoA* rotacao_dupla_direita (pNodoA* p);

pNodoA* rotacao_dupla_esquerda (pNodoA *p);

int Contagem_Palavras(pNodoA *a);         //Caminhamento pré-fixado à esquerda

int Ja_Existe(pNodoA *a, TipoPtNo *str);

pNodoA* Insere_Palavra(TipoPtNo *str, pNodoA *a, char word[], int i);

#endif //ARVORES_H
