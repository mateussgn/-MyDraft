#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PLAY{
char music[10000],playlist[10000];
struct Node *next;
}play;

/*---------- FUNCTIONS ----------*/
void add_playlist_song(play *in_reproduction, char playlist_name[]){
    play *new_song = (play *)malloc(sizeof(play));
    new_song->next = NULL;
    scanf(" %s",new_song->music);
    strcpy(new_song->playlist, playlist_name);
    if(in_reproduction->next == NULL){
        in_reproduction->next = new_song;
    }else{
        play *aux_play = in_reproduction->next;
        while(aux_play->next != NULL){
            aux_play = aux_play->next;
        }
        aux_play->next = new_song;
    }
}
void del_playlist_song(play *in_reproduction, char playlist_name[]){
    char song_name[1000];
    scanf(" %s", song_name);
    play *actual_play = in_reproduction->next;
    play *prev_play = in_reproduction;
    while(1){
        if(strcmp(actual_play->playlist, playlist_name)){
            if(strcmp(actual_play->music, song_name)){
                prev_play->next = actual_play->next;
                break;
            }
        }if(actual_play == NULL){
            break;
        }
        prev_play = actual_play;
        actual_play = actual_play->next;
    }
}
void swp_playlist_song1_song2(play *in_reproduction, char playlist_name[]){
    char song1_name[1000], song2_name[1000], aux[10000];
    scanf(" %s", song1_name);
    scanf(" %s", song2_name);
    int counter = 0;
    play *current = in_reproduction->next;
    play *current2;
    while(1){
        if(strcmp(current->playlist, playlist_name)){
            if(strcmp(current->music, song1_name) && counter == 0){
                current2 = current;
                counter++;
                current = in_reproduction->next;
            }
            if(strcmp(current->music,song2_name) == 0 && counter > 0){
                strcpy(aux, current->music);
                strcpy(current->music, current2->music);
                strcpy(current2->music, aux);
                break;
            }
            if(counter == 0 && current == NULL){
                break;
            }
        }
        current = current->next;
    }
}
void pls_song(play *in_reproduction){
    play *new_song = (play *)malloc(sizeof(play));
    new_song->next = NULL;
    scanf(" %s",new_song->music);
    if(in_reproduction->next == NULL){
        in_reproduction->next = new_song;
    }else{
        play *aux_song = in_reproduction->next;
        while(aux_song->next != NULL){
            aux_song = aux_song->next;
        }
        aux_song->next = new_song;
    }
}
void plp_playlist(play *queue, play *in_reproduction, char playlist_name[]){
    clr(queue);
    play *current = (play *)malloc(sizeof(play));
    current = in_reproduction->next;
    while(1){
        if(strcmp(current->playlist, playlist_name) == 0){
            play *new_song = (play *) malloc(sizeof(play));
            new_song->next = NULL;
            strcpy(new_song->music, current->music);
            if(queue->next == NULL){
                queue->next = new_song;
            }else{
                play *aux = queue->next;
                while(aux->next != NULL){
                    aux = aux->next;
                }
                aux->next = new_song;
            }
        }
        if(current->next == NULL){
            break;
        }
        current = current->next;
    }
}
int nxt(int prox){
    prox++;
    return prox;
}
int prv(int prox){
    prox--;
    return prox;
}
int clr(play *in_reproduction){
    int prox = 1;
    play *actual_play = in_reproduction->next;
    play *next_play;
    while(actual_play != NULL){
        next_play = actual_play->next;
        actual_play = NULL;
        actual_play = next_play;
    }
    in_reproduction->next = NULL;
    return prox;
}
void inf(play *queue, int prox){
    int i;
    play *actual= queue->next;
    if(queue->next == NULL){
        printf("UNKNOWN\n");
    }else{
        for(i = 1; i <= prox; i++){
            if(i == prox && actual != NULL){
                printf("%s\n", actual->music);
            }
            else if(i == prox && actual == NULL){
                printf("UNKNOWN\n");
            }else{
                actual = actual->next;
            }
        }
    }
}
/*---------- END FUNCTIONS ----------*/
/*---------- MAIN ----------*/
int main(int argc, char *argv[]) {
    int num_commands, prox = 1;
    char command[4], playlist_name[1000];
    play *in_reproduction= (play *) malloc(sizeof(play));
    play *queue = (play *) malloc(sizeof(play));
    scanf("%d",&num_commands);
    while(num_commands >= 1){
        scanf("%s",command);
        if(command[0]=='A'){
            scanf("%s",playlist_name);
            add_playlist_song(in_reproduction, playlist_name);
        }else if(command[0]=='D'){
            scanf(" %s",playlist_name);
            del_playlist_song(in_reproduction, playlist_name);
        }else if(command[0]=='N'){
            prox=nxt(prox);
        }else if(command[0]=='S'){
            scanf(" %s",playlist_name);
            swp_playlist_song1_song2(in_reproduction, playlist_name);
        }else if(command[0]=='P' && command[2]=='P'){
            scanf(" %s",playlist_name);
            plp_playlist(queue, in_reproduction, playlist_name);
            prox=1;
        }else if(command[0]=='P' && command[2]=='S'){
            pls_song(in_reproduction);
        }else if(command[0]=='P'&& command[2]=='V'){
            prox=prv(prox);
        }else if(command[0]=='C'){
            prox = clr(queue);
        }else if(command[0]=='I'){
            inf(queue, prox);
        }
        num_commands--;
    }
    return 0;
}
/*---------- END MAIN ----------*/