#include <stdio.h>
#include <time.h>
#include "arvores.h"
#include "listas.h"
#include "arquivos.h"
#define MAX 100

int main(void)
{
    clock_t time;
    char arq1[MAX], arq2[MAX];
    char stopwords[MAX];
    char separadores[]= {" ,.&*%\?!;/-'@\"$#=><()][}{:\n\t"};

    printf("Digite o nome do primeiro arquivo:\n");
    scanf("%s", &arq1);

    printf("\nDigite o nome do segundo arquivo:\n");
    scanf("%s", &arq2);

    printf("\nDigite o nome do arquivo de stopwords:\n");
    scanf("%s", &stopwords);

    printf("\n----------------------------------------------\n");

    time = clock();


    time = ((clock() - time)/CLOCKS_PER_SEC) *1000;

    printf("O tempo de execução foi de: %f\n", time);

    system("pause");
}
