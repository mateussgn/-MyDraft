#include <stdio.h>
#include <stdlib.h>

#define CAMINHO1 "C:\\Users\\mateu\\OneDrive\\Códigos de Programação\\Arquivos\\teste.txt"
#define CAMINHO2 "C:\\Users\\mateu\\OneDrive\\Códigos de Programação\\Arquivos\\teste2.txt"

int main()
{
    FILE *arquivo1; //*arquivo2;
    //char ch;
    char Nome[100];
    int Nota;

    arquivo1 = fopen(CAMINHO1, "rt");
    //arquivo2 = fopen(CAMINHO2, "w+b");

    if((arquivo1 == NULL) /*&& (arquivo2 == NULL)*/)
        puts("Arquivos nao foram abertos");
    else
        puts("Arquivos abertos com sucesso");

    fputs("Maria\t7\n"
          "Joao\t9\n"
          "Ze\t2\n"
          "Rute\t3\n", arquivo1);

    //while((ch=fgetc(arquivo1))!= EOF)
    //    fputc(ch, arquivo2);
    fseek(arquivo1, 5*sizeof(char), SEEK_SET);
    while(fscanf(arquivo1, "%s\t%d", Nome, &Nota)!=EOF)
        if(Nota>=5)
            printf("%s\t%d\n", Nome, Nota);

    fclose(arquivo1);
    //fclose(arquivo2);
    return 0;
}
