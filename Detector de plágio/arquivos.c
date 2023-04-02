#include <stdio.h>
#include <string.h>
#include "arquivos.h"

pNodoA Abre_Arquivo(char arq[], char stopword[])
{
    FILE *point_arq;
    FILE *point_stopword;

    point_arq = fopen(arq, "r");
    point_stopword = fopen(arq, "r");

}
