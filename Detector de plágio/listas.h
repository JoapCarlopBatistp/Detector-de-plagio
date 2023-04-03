#ifndef LISTAS_H
#define LISTAS_H


struct S_PtNo{
    char letra;
    struct S_PtNo * prox;
};
typedef struct S_PtNo TipoPtNo;

int Compara_Palavra(TipoPtNo *str1, TipoPtNo *str2);

TipoPtNo* Insere_Lista(TipoPtNo *lista, char letra);

TipoPtNo* Inicializa_Lista();

#endif // LISTAS_H
