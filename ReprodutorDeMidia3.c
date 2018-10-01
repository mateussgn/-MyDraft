int main(int argc, char *argv[]) {
	int i, num_comands = 0;
	char *command = (char *)malloc(4*sizeof(char))
        , *playlist_name = (char *)malloc(70*sizeof(char))
        , *song1_name = (char *)malloc(70*sizeof(char))
        , *song2_name = (char *)malloc(70*sizeof(char));

    playlist *list_of_playlists = alloc_playlist();
    playlist *in_reproduction = alloc_playlist();
    song *actual_song = alloc_song();

	scanf("%d", &num_comands);

    for(i = 0; i < num_comands; i++){
        printf("Digite o comando:\n");
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
   }
    return 0;
}