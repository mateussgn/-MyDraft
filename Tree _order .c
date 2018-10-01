#include <stdio.h>
#include <stdlib.h>

#define TAM 8000

typedef struct node {
    int key_node;
    struct node *left_node;
    struct node *right_node;
} TREE_NODE;

TREE_NODE *insert_node(TREE_NODE *root, int key){
    TREE_NODE *new_node = NULL;
    if(root == NULL){
        new_node = (TREE_NODE *) malloc (sizeof(TREE_NODE));
        new_node->key_node = key;
        new_node->left_node = NULL;
        new_node->right_node = NULL;
        return new_node;
    }else if(root->left_node == NULL)
        root->left_node = insert_node(root->left_node, key);
    else
        root->right_node = insert_node(root->right_node, key);
    return root;
}

void postOrderThree(TREE_NODE *root, int post[], int i){
    i++;
    if(root != NULL){
        postOrderThree(root->left_node, post, i);
        postOrderThree(root->right_node, post, i);
        post[i] = root->key_node;
    }
}

void inOrderThree(TREE_NODE *root, int in[], int i){
    i++;
    if(root != NULL){
        inOrderThree(root->right_node, in, i);
        in[i] = root->key_node;
        inOrderThree(root->left_node, in, i);
    }
}

int compararArvores(int vetor1[], int vetor2[], int number_of_nodes){
    int i = 0, j = 1;
    for (i = 0; i < number_of_nodes; i++){
        if(vetor1[i] != vetor2[i])
            j = 0;
    }
    return j;
}

int main()
{
    int i = 0, j = 1, number_of_nodes = 0,
            pre_order_nodes[TAM] = {0},
            post_order_nodes[TAM] = {0},
            in_order_nodes[TAM] = {0},
            post_conf[TAM] = {0},
            in_conf[TAM] = {0};
    char space;
    TREE_NODE *root_node = NULL;

    scanf("%d", &number_of_nodes);
    for(i = 0; i < number_of_nodes; i++){
        scanf("%d%c", &pre_order_nodes[i], &space);
    }
    for(i = 0; i < number_of_nodes; i++){
        scanf("%d%c", &post_order_nodes[i], &space);
    }
    for(i = 0; i < number_of_nodes; i++){
        scanf("%d%c", &in_order_nodes[i], &space);
    }
    for(i = 0; i < number_of_nodes; i++){
        insert_node(root_node, pre_order_nodes[i]);
    }
    i = -1;
    postOrderThree(root_node, post_conf, i);
    i = -1;
    inOrderThree(root_node, in_conf, i);
    j = compararArvores(post_order_nodes, post_conf, number_of_nodes);
    if(j!=1) {
        printf("no");
        return 0;
    }
    else{
        j = compararArvores(in_order_nodes, in_conf, number_of_nodes);
        if(j==1)
            printf("yes");
        else
            printf("no");
    }
    return 0;
}
