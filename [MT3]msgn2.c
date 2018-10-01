#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAMINHO "C:\\Users\\mateu\\Desktop\\[MT3]msgn2\\CADASTRO_DE_ALUNOS.bin"

int menu();
void adcionando_Aluno();
void removendo_Aluno();
void editando_Aluno();
void calculando_Media_Geral();

typedef struct ALUNO
{
    char nome[100];
    char nota_MD[5];//nota de matematica discreta
    char nota_IC[5];//nota de introducao a computacao
    char nota_IP[5];//nota de introducao a programacao
    char nota_CALC[5];//nota de calculo 1
    char nota_AVLC[5];//nota de algebra vetorial e linear para computacao
} ALUNO;

int main()
{
    int escolha;
    FILE *cadastro_de_alunos = fopen(CAMINHO, "a+b");
    /*
    if(cadastro_de_alunos == NULL)
        printf("Abertura de aquivo sem sucesso!\n");
    else
        printf("Abertura de aqrquivo feita com sucesso!!\n");
    */
    escolha = menu();
    while(escolha!=0)
    {
        switch(escolha)
        {
        case 1:
            adcionando_Aluno(cadastro_de_alunos);
            fclose(cadastro_de_alunos);
            break;
        case 2:
            //removendo_Aluno(cadastro_de_alunos);
            fclose(cadastro_de_alunos);
            break;
        case 3:
            //editando_Aluno(cadastro_de_alunos);
            fclose(cadastro_de_alunos);
            break;
        case 4:
            //calculando_Media_Geral(cadastro_de_alunos);
            fclose(cadastro_de_alunos);
            break;
        default:
            printf("Opcao invalida!\n"
                   "Digite apenas um dos numeros que representam cada opcao: ");
            scanf("%d", &escolha);
        }
    }
    return 0;
}

int menu() //O MENU RETORNA UM INTEIRO COMO NUMERO DA ESCOLHA
{
    int escolha;
    printf("SISTEMA DE GESTAO ACADEMICA\n\n"
           "1.\tIncluir aluno e notas\n"
           "2.\tExcluir aluno e notas\n"
           "3.\tEditar aluno e notas\n"
           "4.\tCalcular e apresentar média geral dos alunos (por disciplina)\n"
           "0.\t Sair\n");
    return scanf("%d", &escolha);
}

void adcionando_Aluno(FILE *arquivo)
{
    ALUNO adcionar_aluno;
    puts("Digite o nome do novo aluno: ");
    scanf("%s", adcionar_aluno.nome);

    puts("Digite sua nota de Matematica Discreta: ");
    scanf("%s", adcionar_aluno.nota_MD);

    puts("Digite sua nota de Introducao a Computacao: ");
    scanf("%s", adcionar_aluno.nota_IC);

    puts("Digite sua nota de Introducao a Programacao: ");
    scanf("%s", adcionar_aluno.nota_IP);

    puts("Digite sua nota de Calculo 1: ");
    scanf("%s", adcionar_aluno.nota_CALC);

    puts("Digite sua nota de Algebra Vetorial e Linear para Computacao: ");
    scanf("%s", adcionar_aluno.nota_AVLC);

    fwrite(adcionar_aluno.nome, 100*sizeof(char), 1, arquivo);
    fwrite(adcionar_aluno.nota_MD, 5*sizeof(char), 1, arquivo);
    fwrite(adcionar_aluno.nota_IC, 5*sizeof(char), 1, arquivo);
    fwrite(adcionar_aluno.nota_IP, 5*sizeof(char), 1, arquivo);
    fwrite(adcionar_aluno.nota_CALC, 5*sizeof(char), 1, arquivo);
    fwrite(adcionar_aluno.nota_AVLC, 5*sizeof(char), 1, arquivo);
}

/*void removendo_Aluno(cadastro_de_alunos)
{
}*/

void editando_Aluno(FILE *arquivo)
{
    ALUNO editar_aluno;
    printf("Digite o nome do aluno que voce quer editar:\n");
    scanf("%s", editar_aluno.nome);
    fread(editar_aluno.nome, sizeof(ALUNO), 1, arquivo);
}

/*void calculando_Media_Geral(cadastro_de_alunos)
{
}*/
