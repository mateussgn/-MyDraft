#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**START**STACK STRUCTURE**/
typedef struct s_node{
    char *name;
    struct s_node *next_node;
}stack_node;
/**END***********************/

/**START**FUNCTION'S PROTOTYPES**/
stack_node *alloc_stack();
void start_stack(stack_node *first_element);
void stack_push(stack_node *pile);
stack_node *stack_pop(stack_node *pile);
/**END***************************/

/**START**STACK'S FUNCTIONS**/
stack_node *alloc_stack(){
    stack_node *new = (stack_node *)malloc(sizeof(stack_node));
    if(!new){
        printf("Not allocated!");
        exit(1);
    }
    else{
        new->name = (char *)malloc(26*sizeof(char));
        if(!new->name){
            printf("Not allocated!");
            exit(1);
        }
    }
    return new;
}
void start_stack(stack_node *first_element){
    first_element->name = NULL;
    first_element->next_node = NULL;
}
void stack_push(stack_node *pile){
    stack_node *new = alloc_stack();
    new->next_node = NULL;
    if(pile->next_node == NULL)
        pile->next_node = new;
    else{
        stack_node *auxiliar = pile->next_node;
        while(auxiliar->next_node != NULL)
            auxiliar = auxiliar->next_node;
        auxiliar->next_node = new;
    }
}
stack_node *stack_pop(stack_node *pile){
    if(pile->next_node == NULL)
        return NULL;//already is an empty stack
    else{
        stack_node *last = pile->next_node, *before_last = pile;
        while(last->next_node != NULL){
            before_last = last;
            last = last->next_node;
        }
        before_last->next_node = NULL;
        return last;
    }
}
/**END***********************/