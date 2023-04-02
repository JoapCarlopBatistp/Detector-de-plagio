#ifndef LISTAS_H
#define LISTAS_H


struct S_PtNo{
    char letra;
    struct S_PtNo * prox;
};
typedef struct S_PtNo TipoPtNo;

int Compara_Palavra(TipoPtNo *str1, TipoPtNo *str2);

#endif // LISTAS_H
