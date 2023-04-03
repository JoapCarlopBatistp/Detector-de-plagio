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
    pNodoA *a, *b;
    char arq1[MAX], arq2[MAX];
    char stopwords[MAX];

    int total_a, total_b;
    int iguais;
    int diferentes_a, diferentes_b, diferentes_a_b;
    int Similaridade_Jaccard;

    printf("Digite o nome do primeiro arquivo:\n");
    get(arq1, MAX);

    printf("\nDigite o nome do segundo arquivo:\n");
    get(arq2, MAX);

    printf("\nDigite o nome do arquivo de stopwords:\n");
    get(stopwords, MAX);

    printf("\n----------------------------------------------\n");

    time = clock();

    a = Abre_Arquivo(arq1, stopwords);
    printf("\n\n");
    b = Abre_Arquivo(arq2, stopwords);


    total_a = Contagem_Palavras(a);
    printf("\n%d\n", total_a);
    total_b = Contagem_Palavras(b);
    printf("\n%d\n", total_b);

    if(total_a >= total_b){
        iguais = Compara_Arvores(b, a);
    }
    else{
        iguais = Compara_Arvores(a, b);
    }

    diferentes_a = total_a - iguais;
    diferentes_b = total_b - iguais;

    printf("\n\n%d\n\n", iguais);

    diferentes_a_b = 1;

    Similaridade_Jaccard = (diferentes_a + diferentes_b)/(((diferentes_a + diferentes_b))- (diferentes_a + diferentes_b));






    time = ((clock() - time)/CLOCKS_PER_SEC);

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
