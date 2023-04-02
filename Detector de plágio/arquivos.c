#include <stdio.h>
#include <string.h>
#include "arquivos.h"
#define NUMERO 100
#define TAMANHO 40

pNodoA Abre_Arquivo(char *arq, char *stopword)
{
    int i, j;
    TipoPtNo str;
    FILE *point_arq;
    FILE *point_stopword;
    char separadores[]= {" ,.&*%\?!;/-'@\"$#=><()][}{:\n\t"};
    char stop[NUMERO][TAMANHO];
    char arquivo[TAMANHO];
    char c;
    pNodoA *a;

    point_arq = fopen(arq, "r");
    point_stopword = fopen(stopword, "r");

    for(i=0; i<NUMERO; i++){
        for(j=0; j<TAMANHO; j++){
            stop[i][j] = NULL;
        }
    }

    i=0;
    j=0;

    while((c = fgetc(stopword))!=EOF){
        if(c != '\n'){
            stop[i][j] = c;
            j++;
        }
        else{
            i++;
            j=0;
        }
    }

    for(i=0;i<TAMANHO;i++){
        arquivo[i] = NULL;
    }


    while((c = fgetc(arq))!=EOF){
        for(i=0; i<30; i++){
            if(c == separadores[i] && arquivo[0] != NULL){
                a = Insere_Palavra(str, a, arquivo, 0);
            }
        }

    }



}
