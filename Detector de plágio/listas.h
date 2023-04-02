#ifndef LISTAS_H
#define LISTAS_H

struct S_PtNo{
    char letra;
    struct S_PtNo * prox;
};
typedef struct S_PtNo TipoPtNo;

TipoPtNo Insere_Palavra(TipoPtNo *str, char word[], int i);

int Compara_Palavra(TipoPtNo *str1, TipoPtNo *str2);

#endif // LISTAS_H
