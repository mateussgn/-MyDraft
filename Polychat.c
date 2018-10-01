/*
POLYCHAT
ALUNO: MATEUS SANTANA GOMES NASCIMENTO
UNVERSIDADE FEDERAL DE PERNAMBUCO
ENGENHARIA DA COMPUTAÇÃO 2017.2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char commands[100];
    int chaters_counter = 0, caracters_counter = 0, message_size = 0;

    for(int i = 0; i < 100; i++){
        scanf(" %[^\n]s", commands);

        if (commands[0] == '+'){
            chaters_counter++;

        }else if (commands[0] == '-'){
            if(chaters_counter > 0)
                chaters_counter--;

        }else {
            for(int i = 0, j = 0; i < 100; i++){
                if(commands[i] == ':')
                    j = 1;
                if(j == 1)
                    message_size++;
                if(commands[i] == '\0'){
                    break;
                }
            }
            caracters_counter += (message_size*chaters_counter);
        }
    }
    printf("%d", caracters_counter);
    return 0;
}

