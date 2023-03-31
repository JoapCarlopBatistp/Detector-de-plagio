//LISTAS

struct S_PtNo{
    char letra;
    struct S_PtNo * prox;
};
typedef struct S_PtNo TipoPtNo;

void Insere_Palavra();
int Compara_Palavra();

//ARVORES AVL

struct TNodoA{
TipoPtNo palavra;
int FB;
struct TNodoA *esq;
struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;

pNodoA* InsereAVL (pNodoA *a, int x, int *ok);

pNodoA* Caso1 (pNodoA *a , int *ok);

pNodoA* Caso2 (pNodoA *a , int *ok);

pNodoA* rotacao_direita(pNodoA* p);

pNodoA* rotacao_esquerda(pNodoA *p);

pNodoA* rotacao_dupla_direita (pNodoA* p);

pNodoA* rotacao_dupla_esquerda (pNodoA *p);

//ARQUIVOS

int Abertura();
void Copia_p_avl();
