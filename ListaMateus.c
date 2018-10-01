#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**LIST STRUCTURE**/
typedef struct l_node{
    char *name;
    struct l_node *next_node;
}list_node;
/******************/

/**FUNCTION'S PROTOTYPES**/
list_node *alloc_list();
void start_list(list_node *first_element);
void insert_node(list_node *list);
list_node *remove_node(list_node *list);
/*************************/

/**STACK'S FUNCTIONS**/
list_node *alloc_list(){ //allocating space for a new node
    list_node *new = (list_node *)malloc(sizeof(list_node));
    if(!new){ //verifying id the space was allocated correctly
        printf("Not allocated!");
        exit(1);
    }
    else{
        new->name = (char *)malloc(26*sizeof(char));//allocating space for node name
        if(!new->name){//verifying if the space was allocated correctly
            printf("Not allocated!");
            exit(1);
        }else
            return new;
    }
}
void start_list(list_node *first_element){ //starting a list
    first_element->name = NULL;
    first_element->next_node = NULL;
}

void insert_node(list_node *list){ //inserting node in list
    list_node *new = alloc_list(); //allocating a new space
    new->next_node = NULL; //setting the next node
    if(list->next_node == NULL) // if the list is empty
        list->next_node = new;  //this new node will be the first node
    else{ //if the list is not empty
        list_node *auxiliar = list->next_node; //setting auxiliar node
        while(auxiliar->next_node != NULL) //while isn't the end of the list
            auxiliar = auxiliar->next_node; //pass to the next node, until find the last node
        auxiliar->next_node = new; //when finds yhe last node, set the new node next to the last node
    }
}
list_node *remove_node(list_node *list){
    if(list->next_node == NULL) //if the list is empty
        return NULL; //do nothing
    else{
        list_node *auxiliar = list->next_node; //setting auxiliar node
        list->next_node = auxiliar->next_node; //the first node of the list is removed, and the second node now is the new first node
        return auxiliar; //return de removed node
    }
}
/********************/