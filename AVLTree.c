#include <stdio.h>
#include <stdlib.h>

#define DONT_FIND "Data tidak ada"

//montar avore AVL depois percorrer a partir do menor valor em um nó até achar o nó procurado
//e retornar o indice desse nó caso ele estivesse em uma lista ordenada crescentemente

int main() {
    int i = 0,
        number_of_queries = 0,
        include1_search2 = 0,
        values[] = {0};

    scanf("%d", &number_of_queries);
    for(i = 0; i < number_of_queries; i++){
        scanf("%d %d", &include1_search2, values[i]);
        if(include1_search2 == 1){
            //inserir values[i] na arvore avl
        } else{
            //procurar valor na arvore avl
        }

    }
    return 0;
}