#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*=================================STRUCTS=================================*/
typedef struct song{ //doubly linked list
    char *name_song;
    struct song *next_song;
    struct song *prev_song;
}song;

typedef struct playlist{ //linked list
    char *name_playlist;
    struct playlist *next_playlist;
    struct song *first_song;
}playlist;
/*=================================STRUCTS=================================*/

/*================================FUNCTIONS================================*/
song *alloc_song(){
    song *new_song = (song *)malloc(sizeof(song)); //allocating space
    if(new_song == NULL){ //verifying if the space was allocated correctly
        printf("Not allocated song!");
        exit(1);
    }else{
        new_song->name_song = (char *)malloc(70*sizeof(char)); //allocating space
        if(new_song->name_song == NULL){ //verifying if the space was allocated correctly
            printf("Not allocated song->name_song!");
            exit(1);
        }else{
            new_song->next_song = (song *)malloc(sizeof(song)); //allocating space
            if(new_song->next_song == NULL){ //verifying if the space was allocated correctly
                printf("Not allocated song->next_song!");
                exit(1);
            }else{
                new_song->prev_song = (song *)malloc(sizeof(song));//allocating space
                if(new_song->prev_song == NULL){ //verifying if the space was allocated correctly
                    printf("Not allocated song->prev_song!");
                    exit(1);
                }else
                    return new_song;
            }
        }
    }
}
playlist *alloc_playlist(){
    playlist *new_playlist = (playlist *)malloc(sizeof(playlist)); //allocating space
    if(new_playlist == NULL){ //verifying if the space was allocated correctly
        printf("Not allocated playlist!");
        exit(1);
    }else{
        new_playlist->name_playlist = (char *)malloc(70*sizeof(char)); //allocating space
        if(new_playlist->name_playlist == NULL){ //verifying if the space was allocated correctly
            printf("Not allocated playlist->name_playlist!");
            exit(1);
        }else{
            new_playlist->next_playlist = (playlist *)malloc(sizeof(playlist));//allocating space
            if(new_playlist->next_playlist == NULL){//verifying if the space was allocated correctly
                printf("Not allocated playlist->next_playlist!");
                exit(1);
            }else{
                new_playlist->first_song = alloc_song();//allocating space
                if(new_playlist->first_song == NULL){//verifying if the space was allocated correctly
                    printf("Not allocated playlist->first_song!");
                    exit(1);
                }else
                    return new_playlist;
            }
        }
    }
}
song *nxt(song *actual_song){
    if(actual_song == NULL)
        return NULL;
    else if(actual_song->next_song == NULL)
        return NULL;
    else{
        actual_song = actual_song->next_song;
        return actual_song;
    }
}
song *prv(song *actual_song){
    if(actual_song == NULL)
        return NULL;
    else if(actual_song->prev_song == NULL)
        return NULL;
    else{
        actual_song = actual_song->prev_song;
        return actual_song;
    }
}
void clr(playlist *in_reproduction){
    in_reproduction->first_song = NULL; //clearing the actual playlist
}
void inf(song *actual_song){
    if(actual_song == NULL)
        printf("UNKNOWN");
    else
        printf(actual_song->name_song);
}
playlist *find_playlist(playlist *list_of_playlists, char *playlist_name){
    playlist *aux_playlist = list_of_playlists->next_playlist; //create an aux_playlist
    while(!strcmp(playlist_name, aux_playlist->name_playlist)){ //verifying if already exist this playlist name
        if(aux_playlist->next_playlist == NULL)
            break;
        else
            aux_playlist = aux_playlist->next_playlist;
    }
    return aux_playlist;
}
song *find_song(song *song_list/*playlist->first_song*/, char *song_name){
    song *aux_song = song_list; //create an aux_song
    while(!strcmp(aux_song->name_song, song_name)){ //finding the song
        if(aux_song->next_song == NULL)
            break;
        else
            aux_song = aux_song->next_song;
    }
    return aux_song;
}
void add_playlist_song(playlist *list_of_playlists, char *playlist_name, char *song_name){
    playlist *aux_playlist = find_playlist(list_of_playlists, playlist_name);
    song *new_song = alloc_song(); //create a song
    new_song->name_song = song_name; //name the song
    new_song->next_song = NULL; //set the new next song
    if(strcmp(playlist_name, aux_playlist->name_playlist)){ //if the playlist already exists
        if(aux_playlist->first_song == NULL){ //if there is no song on the playlist
            aux_playlist->first_song = new_song; //define the new song as the first
            new_song->prev_song = NULL; //as the first song, doesn't have a previous song
        }else{ //if the playlist already has songs
            song *aux_song = aux_playlist->first_song; //create an aux_song
            while(aux_song->next_song != NULL)//finding the last song
                aux_song = aux_song->next_song;
            aux_song->next_song = new_song; //define the new song as the last
            new_song->prev_song = aux_song; //define the song before the new song
        }
    }else{ //if the playlist doesn't exist
        playlist *new_playlist = alloc_playlist(); //create a new playlist
        aux_playlist = list_of_playlists;
        while(aux_playlist->next_playlist != NULL) //verifying if already exist this playlist name
            aux_playlist = aux_playlist->next_playlist;
        aux_playlist->next_playlist = new_playlist; //set the new playlist as the last one
        new_playlist->name_playlist = playlist_name; //define the playlist name
        new_playlist->next_playlist = NULL; //set the next playlist
        new_playlist->first_song = new_song;//set new song as the first playlist song
        new_song->prev_song = NULL; //set no song as first song previous
    }
}
song *del_playlist_song(playlist *list_of_playlists, char *playlist_name, char *song_name){
    playlist *aux_playlist = find_playlist(list_of_playlists, playlist_name);
    if(strcmp(playlist_name, aux_playlist->name_playlist)){ //if the playlist exists
        if(aux_playlist->first_song == NULL)
            return NULL;
        else{
            song *aux_song = find_song(aux_playlist->first_song, song_name); //create an aux_song
            if(strcmp(aux_song->name_song, song_name)){ //if the song exists
                song *tmp1 = aux_song->prev_song; //tmp1 receive previous song
                song *tmp2 = aux_song->next_song; //tmp2 receive next song
                tmp1->next_song = tmp2; //tmp1 next song now is the aux_song next song
                tmp2->prev_song = tmp1; //tmp2 previous song now is the aux_song previous song
                return aux_song; //delete the desired song
            }else
                return NULL;
        }
    }else
        return NULL;
}
void swp_playlist_song1_song2(playlist *list_of_playlists, char *playlist_name, char *song1_name, char *song2_name){
    playlist *aux_playlist = find_playlist(list_of_playlists, playlist_name);
    if(strcmp(playlist_name, aux_playlist->name_playlist)){
        song *aux1_song = find_song(aux_playlist->first_song, song1_name); //finding songs
        song *aux2_song = find_song(aux_playlist->first_song, song2_name);
        if(strcmp(aux1_song->name_song, song1_name) && strcmp(aux2_song->name_song, song2_name)){ //if those song are the same as search for
            song *tmp = alloc_song();
            tmp->name_song = aux1_song->name_song; //swap data
            tmp->next_song = aux1_song->next_song;
            tmp->prev_song = aux1_song->prev_song;
            aux1_song->name_song = aux2_song->name_song;
            aux1_song->next_song = aux2_song->next_song;
            aux1_song->prev_song = aux2_song->prev_song;
            aux2_song->name_song = tmp->name_song;
            aux2_song->next_song = tmp->next_song;
            aux2_song->prev_song = tmp->prev_song;
        }
    }
}
void pls_song(playlist *in_reproduction, char *song_name){
    song *new_song = alloc_song(); //create a song
    new_song->name_song = song_name; //name the song
    new_song->next_song = NULL; //set the next song
    if(in_reproduction->first_song == NULL){
        in_reproduction->first_song = new_song;
        new_song->prev_song = NULL; //set the previous song
    }else{
        song *aux_song = in_reproduction->first_song; //create an aux_song
        while(aux_song->next_song != NULL)//finding the last song
            aux_song = aux_song->next_song;
        aux_song->next_song = new_song; //define the new song as the last
        new_song->prev_song = aux_song; //define the song before the new songg
    }
}
 void plp_playlist(playlist *list_of_playlists, playlist *in_reproduction, char *playlist_name){
    clr(in_reproduction); //free the actual reproduction playlist
    playlist *aux_playlist = find_playlist(list_of_playlists, playlist_name); //find the playlist
    if(strcmp(playlist_name, aux_playlist->name_playlist)) //if the playlist exists
        in_reproduction->first_song = aux_playlist->first_song; //define the reproduction list as the actual playlist
 }

/*================================FUNCTIONS================================*/
int main(int argc, char *argv[]) {
	int num_comands = 0;
	char *command = (char *)malloc(4*sizeof(char))
        , *playlist_name = (char *)malloc(70*sizeof(char))
        , *song1_name = (char *)malloc(70*sizeof(char))
        , *song2_name = (char *)malloc(70*sizeof(char));

    playlist *list_of_playlists = alloc_playlist();
    playlist *in_reproduction = alloc_playlist();
    song *actual_song = alloc_song();

	scanf("%d", &num_comands);

    while(num_comands <= 1){
        scanf(" %s", command);

        if(command[0] == 'A'/*ADD*/){
            scanf("%s", playlist_name);
            scanf("%s", song1_name);
            add_playlist_song(list_of_playlists, playlist_name, song1_name);
        }else if(command[0] == 'D'/*DEL*/){
            scanf("%s", playlist_name);
            scanf("%s", song1_name);
            del_playlist_song(list_of_playlists, playlist_name, song1_name);
        }else if(command[0] == 'S'/*SWP*/){
            scanf("%s", playlist_name);
            scanf("%s", song1_name);
            scanf("%s", song2_name);
            swp_playlist_song1_song2(list_of_playlists, playlist_name, song1_name, song2_name);
        }else if(command[0] == 'P' && command[2] == 'S'/*PLS*/){
            scanf("%s", song1_name);
            pls_song(in_reproduction, song1_name);
        }else if(command[0] == 'P' && command[2] == 'P'/*PLP*/){
            scanf("%s", playlist_name);
            plp_playlist(list_of_playlists, in_reproduction, playlist_name);
        }else if(command[0] == 'P' && command[2] == 'V'/*PRV*/){
            actual_song = prv(actual_song);
        }else if(command[0] == 'N'/*NXT*/){
            actual_song = nxt(actual_song);
        }else if(command[0] == 'I'/*INF*/){
            inf(actual_song);
        }
        else{
            exit(1);
        }
    num_comands--;
   }
    return 0;
}