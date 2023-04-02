#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
#include "arvores.h"
#include "listas.h"
#include "arquivos.h"
#define MAX 80

void get(char * string, int n);

int main(void)
{
    setlocale(LC_ALL, "");
    clock_t time;
    pNodoA *a;
    char arq1[MAX], arq2[MAX];
    char stopwords[MAX];

    printf("Digite o nome do primeiro arquivo:\n");
    get(arq1, MAX);

    printf("\nDigite o nome do segundo arquivo:\n");
    get(arq2, MAX);

    printf("\nDigite o nome do arquivo de stopwords:\n");
    get(stopwords, MAX);

    printf("\n----------------------------------------------\n");

    time = clock();


    *a = Abre_Arquivo(arq1, stopwords);


    time = ((clock() - time)/CLOCKS_PER_SEC) *1000;

    printf("O tempo de execução foi de: %f segundos\n", time);

    system("pause");
}

void get(char * string, int n)
{
    fgets(string, n, stdin);     //Explicar stdin mais tarde

    while(*string != '\0'){
        if(*string == '\n'){
            *string = '\0';
            break;
        }

        string++;
    }
}
