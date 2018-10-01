#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000

typedef struct PLAY{
char playlist_name[SIZE];
struct PLAYLIST *next_playlist;
struct SONG *first_song;
}play;

/*---------- FUNCTIONS ----------*/
/*---------- FIND PLAYLIST ----------*/
play *find_playlist(play *list_of_playlists, char playlist_name[]){
    play *aux_playlist = list_of_playlists->next_playlist; //create an aux_playlist
    while(strcmp(aux_playlist->playlist_name, playlist_name) != 0){ //verifying if already exist this playlist name
        if(aux_playlist->next_playlist == NULL)
            return aux_playlist;
        else
            aux_playlist = aux_playlist->next_playlist;
    }
    return aux_playlist;
}
/*---------- FIND SONG ----------*/
song *find_song(song *song_list/*playlist->first_song*/, char song_name[]){
    song *aux_song = song_list; //create an aux_song
    while(strcmp(aux_song->music_name, song_name) != 0){ //finding the song
        if(aux_song->next_music == NULL)
            return aux_song;
        else
            aux_song = aux_song->next_music;
    }
    return aux_song;
}
/*---------- ADD ----------*/
void add_playlist_song(play *list_of_playlists, char playlist_name[], char song_name[]){
    play *aux_playlist = find_playlist(list_of_playlists, playlist_name);
    song *new_song  = (song *)malloc(sizeof(song));
    new_song->next_music = NULL;
    strcpy(new_song->music_name, song_name);
    if(aux_playlist->next_playlist == NULL){
        play *new_playlist = (play *)malloc(sizeof(play));
        aux_playlist->next_playlist = new_playlist;
        strcpy(new_playlist->playlist_name, playlist_name);
        new_playlist->next_playlist = NULL;
        new_playlist->first_song = new_song;
        new_song->prev_music = NULL;
    }else{
        if(aux_playlist->first_song == NULL){
            aux_playlist->first_song = new_song;
            new_song->prev_music = NULL;
        }
        else{
            song *aux_song = aux_playlist->first_song;
            while(aux_song->next_music != NULL)
                aux_song = aux_song->next_music;
            aux_song->next_music = new_song;
            new_song->prev_music = aux_song;
        }
    }
}
/*---------- DEL ----------*/
void del_playlist_song(play *list_of_playlists, char playlist_name[], char song_name[]){
    play *aux_playlist = find_playlist(list_of_playlists, playlist_name);
    if(aux_playlist->next_playlist == NULL);
    else{
        song *aux_song = find_song(aux_playlist->first_song, song_name);
        if(aux_song->next_music == NULL);
        else{
            song *prev_aux_song = aux_song->prev_music;
            prev_aux_song->next_music = NULL;
            free(aux_song);
        }
    }
}
/*---------- SWP ----------*/
void swp_playlist_song1_song2(play *list_of_playlists, char playlist_name[], char song1_name[], char song2_name[]){
    play *aux_playlist = find_playlist(list_of_playlists, playlist_name);
    if(aux_playlist->next_playlist == NULL);
    else{
        song *aux1_song = find_song(aux_playlist->first_song, song1_name);
        song *aux2_song = find_song(aux_playlist->first_song, song2_name);
        if((aux1_song->next_music == NULL) || (aux2_song->next_music == NULL));
        else{
            song *tmp_song = (song *)malloc(sizeof(song));
            tmp_song->next_music = aux1_song->next_music;
            tmp_song->prev_music = aux1_song->prev_music;
            aux1_song->next_music = aux2_song->next_music;
            aux1_song->prev_music = aux2_song->prev_music;
            aux2_song->next_music = tmp_song->next_music;
            aux2_song->prev_music = tmp_song->prev_music;
            free(tmp_song);
        }
    }
}
/*---------- PLS ----------*/
void pls_song(play *in_reproduction, song *actual_song, char song_name[]){
    song *new_song  = (song *)malloc(sizeof(song));
    new_song->next_music = NULL;
    strcpy(new_song->music_name, song_name);
    if(in_reproduction->first_song == NULL){
        in_reproduction->first_song = new_song;
        *actual_song = *new_song;
    }
    else if(strcmp(actual_song->music_name, "actual_song")){
        *actual_song = *new_song;
    }else{
        song *aux_actual_song = actual_song;
        if(aux_actual_song->next_music != NULL){
            while(actual_song->next_music != NULL)
                actual_song = actual_song->next_music;
            actual_song->next_music = new_song;
        }
    }
}
/*---------- CLR ----------*/
void clr(play *in_reproduction){
    song *aux_song = in_reproduction->first_song;
    song *next_aux_song = aux_song->next_music;
    while(next_aux_song != NULL){
        free(aux_song);
        aux_song = next_aux_song;
        next_aux_song = aux_song->next_music;
    }
    in_reproduction->first_song = NULL;
}
/*---------- PLP ----------*/
void plp_playlist(play *in_reproduction, play *list_of_playlists, song *actual_song, char playlist_name[]){
    clr(in_reproduction);
    in_reproduction = find_playlist(list_of_playlists, playlist_name);
    *actual_song = *in_reproduction->first_song;
}
/*---------- NXT ----------*/
void nxt(song *actual_song){
    *actual_song = *actual_song->next_music;
}
/*---------- PRV ----------*/
void prv(song *actual_song){
    *actual_song = *actual_song->prev_music;
}
/*---------- END FUNCTIONS ----------*/

/*---------- MAIN ----------*/
int main(int argc, char *argv[]) {
	int i, num_comands = 0;
	char command[4], playlist_name[SIZE], song1_name[SIZE], song2_name[SIZE];

    play *list_of_playlists = (play *)malloc(sizeof(play));
    *list_of_playlists->playlist_name = "list_of_playlists";
    list_of_playlists->next_playlist = NULL;
    list_of_playlists->first_song = NULL;

    play *in_reproduction = (play *)malloc(sizeof(play));
    *in_reproduction->playlist_name = "in_reproduction";
    in_reproduction->first_song = NULL;
    in_reproduction->next_playlist = NULL;

    song *actual_song = (song *)malloc(sizeof(song));
    *actual_song->music_name = "actual_song";
    actual_song->next_music = NULL;
    actual_song->prev_music = NULL;

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
            pls_song(in_reproduction,actual_song, song1_name);
        }else if(command[0] == 'P' && command[2] == 'P'/*PLP*/){
            scanf("%s", playlist_name);
            plp_playlist(in_reproduction, list_of_playlists, actual_song, playlist_name);
        }else if(command[0] == 'P' && command[2] == 'V'/*PRV*/){
            prv(actual_song);
        }else if(command[0] == 'N'/*NXT*/){
            nxt(actual_song);
        }else if(command[0]=='C'/*CLR*/){
            clr(in_reproduction);
        }else if(command[0] == 'I'/*INF*/){
            printf(actual_song->music_name);
        }
        else{
            exit(1);
        }
    }
    return 0;
}
/*---------- END MAIN ----------*/
