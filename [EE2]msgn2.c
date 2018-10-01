#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 9
#define CAMINHO "C:\\Users\\mateu\\Desktop\\[EE2]msgn2\\registro_De_Jogadas.bin"


void inicializando_Tabuleiro(int tabuleiro[TAMANHO][TAMANHO]);
void mostrando_Tabuleiro(int tabuleiro[TAMANHO][TAMANHO]);

int main()
{
    int tabuleiro[TAMANHO][TAMANHO];
    char *movimento_Brancas, *movimento_Pretas;
    FILE * registro_De_Jogadas;

    movimento_Brancas = (char *)malloc(7*sizeof(char));
    movimento_Pretas = (char *)malloc(7*sizeof(char));

    inicializando_Tabuleiro(tabuleiro);
    mostrando_Tabuleiro(tabuleiro);

    puts("Digite seu movimento (letras MAIUSCULAS):");
    scanf("%s", movimento_Brancas);
    //validando_movimento();
    mostrando_Tabuleiro(tabuleiro);

    puts("Digite seu movimento (letras minusculas):");
    scanf("%s", movimento_Pretas);
    //validando_movimento();
    mostrando_Tabuleiro(tabuleiro);

    registro_De_Jogadas = fopen(CAMINHO, "w+b");
    if(registro_De_Jogadas==NULL)
        puts("Abertura de arquivo sem sucesso!");
    else
        puts("Abertura de arquivo feita com sucesso!");

    fclose(registro_De_Jogadas);

    free(movimento_Brancas);
    free(movimento_Pretas);
    return 0;
}
//INICIALIZANDO TABULEIRO. Colocam-se as pecas nas posicoes iniciais.
void inicializando_Tabuleiro(int tabuleiro[TAMANHO][TAMANHO])
{
    char posicao_Linha='a', posicao_Coluna='1';
    int i, j;
    for(i=0; i<TAMANHO; i++)
    {
        for(j=0; j<TAMANHO; j++)
        {
            if(i==0)
            {
                tabuleiro[i][j]=posicao_Linha-1;
                posicao_Linha++;
            }
            else if(j==0)
            {
                tabuleiro[i][j]=posicao_Coluna;
                posicao_Coluna++;
            }
            else if(i==2)
                tabuleiro[i][j]='p';
            else if(i==7)
                tabuleiro[i][j]='P';
            else if(((i==1)&&(j==1)) || ((i==1)&&(j==8)))
                tabuleiro[i][j]='t';
            else if(((i==8)&&(j==1)) || ((i==8)&&(j==8)))
                tabuleiro[i][j]='T';
            else if(((i==1)&&(j==2)) || ((i==1)&&(j==7)))
                tabuleiro[i][j]='c';
            else if(((i==8)&&(j==2)) || ((i==8)&&(j==7)))
                tabuleiro[i][j]='C';
            else if(((i==1)&&(j==3)) || ((i==1)&&(j==6)))
                tabuleiro[i][j]='b';
            else if(((i==8)&&(j==3)) || ((i==8)&&(j==6)))
                tabuleiro[i][j]='B';
            else if((i==1)&&(j==4))
                tabuleiro[i][j]='d';
            else if((i==8)&&(j==4))
                tabuleiro[i][j]='D';
            else if((i==1)&&(j==5))
                tabuleiro[i][j]='r';
            else if((i==8)&&(j==5))
                tabuleiro[i][j]='R';
            else
                tabuleiro[i][j]='-';
        }
    }
}

//MOSTRANDO TABULEIRO
void mostrando_Tabuleiro(int tabuleiro[TAMANHO][TAMANHO])
{
    int i, j;
    for(i=0; i<TAMANHO; i++)
    {
        for(j=0; j<TAMANHO; j++)
        {
            printf("%c| ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}
