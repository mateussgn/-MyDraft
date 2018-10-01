#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000

typedef struct NODE{
char music[SIZE], playlist[SIZE];
struct NODE *next;
}play;

/*---------- FUNCTIONS ----------*/
/*---------- ADD ----------*/
void add_playlist_song(play *playlist, char playlist_name[], char song_name[]){
    play *new_playlist_song = (play *)malloc(sizeof(play));
    if(playlist->next == NULL){
        strcpy(new_playlist_song->playlist, playlist_name);
        strcpy(new_playlist_song->music, song_name);
        new_playlist_song->next = NULL;
    }else{
        play *aux_playlist = playlist;
        while(aux_playlist->next != NULL)
            aux_playlist = aux_playlist->next;
        aux_playlist->next = new_playlist_song;
        strcpy(new_playlist_song->playlist, playlist_name);
        strcpy(new_playlist_song->music, song_name);
    }
}
/*---------- DEL ----------*/
void del_playlist_song(play *playlist, char playlist_name[], char song_name[]){
    if(playlist->next == NULL);
    else{
        play *aux_playlist = playlist, *prev_aux_playlist;
        while((strcmp(aux_playlist->playlist, playlist_name) == 0) && (strcmp(aux_playlist->music, song_name) == 0)){
            if(aux_playlist->next == NULL)
                break;
            else{
                prev_aux_playlist = aux_playlist;
                aux_playlist = aux_playlist->next;
            }
        }
        prev_aux_playlist->next = aux_playlist->next;
        free(aux_playlist);
    }
}
/*---------- SWP ----------*/
void swp_playlist_song1_song2(play *playlist, char playlist_name[], char song1_name[], char song2_name[]){
    if(playlist->next == NULL);
    else{
        play *aux1_playlist = playlist, *aux2_playlist = playlist, *prev_aux1_playlist, *prev_aux2_playlist, *tmp_playlist;
        while((strcmp(aux1_playlist->playlist, playlist_name) == 0) && (strcmp(aux1_playlist->music, song1_name) == 0)){
            if(aux1_playlist->next == NULL)
                break;
            else{
                prev_aux1_playlist = aux1_playlist;
                aux1_playlist = aux1_playlist->next;
            }
        }
        while((strcmp(aux2_playlist->playlist, playlist_name) == 0) && (strcmp(aux2_playlist->music, song2_name) == 0)){
            if(aux2_playlist->next == NULL)
                break;
            else{
                prev_aux2_playlist = aux2_playlist;
                aux2_playlist = aux2_playlist->next;
            }
        }
        tmp_playlist->next = aux2_playlist->next;
        prev_aux1_playlist->next = aux2_playlist;
        aux2_playlist->next = aux1_playlist->next;
        prev_aux2_playlist->next = aux1_playlist;
        aux1_playlist->next = tmp_playlist->next;
    }

}
/*---------- PLS ----------*/
void pls_song(){

}
/*---------- PLP ----------*/
void plp_playlist(){

}
/*---------- NXT ----------*/
void nxt(){

}
/*---------- PRV ----------*/
void prv(){

}
/*---------- CLR ----------*/
void clr(){

}
/*---------- INF ----------*/
void inf(){

}
/*---------- END FUNCTIONS ----------*/

/*---------- MAIN ----------*/
int main(int argc, char *argv[]) {
	int i, num_comands = 0, prox = 1;
	char command[4], playlist_name[SIZE], song1_name[SIZE], song2_name[SIZE];

    play *in_reproduction = (play *)malloc(sizeof(play));
    play *queue = (play *)malloc(sizeof(play));
    play *actual_song = (play *)malloc(sizeof(play));

	scanf("%d", &num_comands);
    for(i = 0; i < num_comands; i++){
        scanf(" %s", command);

        if(command[0] == 'A'/*ADD*/){
            scanf("%s", playlist_name);
            scanf("%s", song1_name);
            add_playlist_song(in_reproduction, playlist_name, song1_name);
        }else if(command[0] == 'D'/*DEL*/){
            scanf("%s", playlist_name);
            scanf("%s", song1_name);
            del_playlist_song(in_reproduction, playlist_name, song1_name);
        }else if(command[0] == 'S'/*SWP*/){
            scanf("%s", playlist_name);
            scanf("%s", song1_name);
            scanf("%s", song2_name);
            swp_playlist_song1_song2(in_reproduction, playlist_name, song1_name, song2_name);
        }else if(command[0] == 'P' && command[2] == 'S'/*PLS*/){
            scanf("%s", song1_name);
            pls_song(in_reproduction, song1_name);
        }else if(command[0] == 'P' && command[2] == 'P'/*PLP*/){
            scanf("%s", playlist_name);
            plp_playlist(in_reproduction, in_reproduction, playlist_name);
        }else if(command[0] == 'P' && command[2] == 'V'/*PRV*/){
            prox = prv(prox);
        }else if(command[0] == 'N'/*NXT*/){
            prox = nxt(prox);
        }else if(command[0]=='C'/*CLR*/){
            prox = clr(queue);
        }else if(command[0] == 'I'/*INF*/){
            inf(queue, prox);
        }
        else{
            exit(1);
        }
   }
    return 0;
}

/*---------- END MAIN ----------*/