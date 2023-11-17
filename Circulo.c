#include <stdio.h>
#include <stdlib.h>

void imprimeCirculo(char *RA, int raio, int lado)
{
    int i = 1, j = 1, k = 0, limite = 0;
    FILE *arquivo = NULL;

    limite = raio*2 + 4;

    arquivo = fopen("circulo.txt", "w");

    if(arquivo == NULL)
    {
        printf("Erro na leitura do arquivo.\n");
        exit(2);
    }

    while(i <= raio+2)
    {
        for(j = 1; j <= raio+2; j++)
        {
            if(i*j < limite)
            {
                fprintf(arquivo, "%c", RA[k]);
                k++;
                if(k == 7)
                {
                    k = 0;
                }
            }

            else
            {
                fprintf(arquivo, " ");
            }
        }

        for(j = raio+3; j <= lado; j++)
        {
            if(i*(lado-j+1) < limite)
            {
                fprintf(arquivo, "%c", RA[k]);
                k++;
                if(k == 7)
                {
                    k = 0;
                }
            }

            else
            {
                fprintf(arquivo, " ");
            }
        }

        i++;
        fprintf(arquivo, "\n");
    }
    
    while(i <= lado)
    {
        for(j = 1; j <= raio+2; j++)
        {
            if((lado-i+1)*j < limite)
            {
                fprintf(arquivo, "%c", RA[k]);
                k++;
                if(k == 7)
                {
                    k = 0;
                }
            }

            else
            {
                fprintf(arquivo, " ");
            }
        }

        for(j = raio+3; j <= lado; j++)
        {
            if((lado-i+1)*(lado-j+1) < limite)
            {
                fprintf(arquivo, "%c", RA[k]);
                k++;
                if(k == 7)
                {
                    k = 0;
                }
            }

            else
            {
                fprintf(arquivo, " ");
            }
        }

        i++;
        fprintf(arquivo, "\n");
    }

    
}


int main(int args, char *argv[])
{
    char ra[7]= {'2','2','6','4','9','5','1'};
    int raio = 0, lado = 0;

    if(args != 2)
    {
        printf("Erro! Entre com o raio por linha de comando!\n");
        exit(1);
    }

    raio = atoi(argv[1]);

    lado = raio*2 + 3;

    imprimeCirculo(ra, raio, lado);


    return 0;
}
