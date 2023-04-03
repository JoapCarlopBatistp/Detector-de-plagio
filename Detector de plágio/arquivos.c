#include <stdio.h>
#include <string.h>
#include "arquivos.h"
#define NUMERO 100
#define TAMANHO 40
#define MAX_PALAVRA 100
#define MAX_SEPARADORES ",.&*%\\ ?!;/-'@\"$#=><()][}{:\n\t"


pNodoA* Abre_Arquivo(char *arq, char *stopword)
{

    pNodoA *a = Inicializa_Arvore();
    char stop[NUMERO][TAMANHO];
    char copia[TAMANHO];
    int i = 0, j = 0;
    int num_stop;
    int tam;

    for(i=0;i<NUMERO; i++){
        for(j=0;j<TAMANHO;j++){
            stop[i][j] = NULL;
        }
    }

    //////////////////////////////////////////////////////
    FILE* stopwords = fopen(stopword, "r");
    if (stopwords == NULL) {
        printf("Erro ao abrir arquivo %s\n", stopword);
        return;
    }

    i = 0;
    j = 0;
    char linha[TAMANHO];
    while (i < NUMERO && fgets(linha, TAMANHO, stopwords) != NULL) {
        int len = strlen(linha);
        if (len > 0 && linha[len-1] == '\n') {
            linha[len-1] = '\0';
        }
        strncpy(stop[i], linha, TAMANHO);
        i++;
    }


    fclose(stopwords);

    for(i=0; stop[i][0] != NULL; i++){
    }
    num_stop = i;

    /////////////////////////////////////////////////////
    FILE* point_arq = fopen(arq, "r");
    if (point_arq == NULL) {
        printf("Erro ao abrir arquivo %s\n", arq);
        return;
    }

    char palavra[MAX_PALAVRA];
    char copiado[TAMANHO];

    while (fscanf(point_arq, "%s", palavra) != -1 && palavra[0] != EOF) {
        char* sep = strpbrk(palavra, MAX_SEPARADORES);
        if (sep != NULL) {
            *sep = '\0';
        }
//////////////////////////////////////////////////////
        int z=0;
        tam = strlen(palavra);
        while(strcmp(palavra, copiado) != 0 && z != num_stop){
            for(i=0; stop[z][i] != NULL; i++){
                copiado[i] = stop[z][i];
            }
            copiado[tam] = '\0';

            z++;
        }
        if(z == num_stop){
                printf("%s\n", palavra);
            a = Insere_Palavra(a, palavra, 0);
    }
//////////////////////////////////////////////////////
    }


    fclose(point_arq);

    return a;

}

