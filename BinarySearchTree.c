#include <stdio.h>
#include <stdlib.h>

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
    }else if(key < root->key_node)
        root->left_node = insert_node(root->left_node, key);
    else
        root->right_node = insert_node(root->right_node, key);
    return root;
}

void postOrderThree(TREE_NODE *root){
    if(root != NULL){
        postOrderThree(root->left_node);
        postOrderThree(root->right_node);
        printf("%d\n", root->key_node);
    }
}

void inOrderThree(TREE_NODE *root){
    if(root != NULL){
        inOrderThree(root->right_node);
        printf("%d\n", root->key_node);
        inOrderThree(root->left_node);
    }
}

int main() {
    int key = 0, i = 0;
    TREE_NODE *root_node = NULL;

    /*while(scanf("%d", &key) != EOF) {
        root_node = insert_node(root_node, key);
    }*/

    for(i = 0; i < 9; i++){
        scanf("%d", &key);
        root_node = insert_node(root_node, key);
    }
    printf("\n------post order-------\n");
    postOrderThree(root_node);
    printf("\n------in order-------\n");
    inOrderThree(root_node);
    return 0;
}