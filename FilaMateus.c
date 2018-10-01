#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**START**QUEUE STRUCTURE**/
typedef struct q_node{
    char *name;
    struct q_node *next_node;
}queue_node;
/**END***********************/

/**START**FUNCTION'S PROTOTYPES**/
queue_node *alloc_queue();
void start_queue(queue_node *first_element);
void insert_node(queue_node *line);
queue_node *remove_node(queue_node *line);
/**END***************************/

/**START**STACK'S FUNCTIONS**/
queue_node *alloc_queue(){ //allocating space for a new node
    queue_node *new = (queue_node *)malloc(sizeof(queue_node));
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
void start_queue(queue_node *first_element){ //starting a queue
    first_element->name = NULL;
    first_element->next_node = NULL;
}

void insert_node(queue_node *line){ //inserting node in queue
    queue_node *new = alloc_queue();
    new->next_node = NULL;
    if(line->next_node == NULL)
        line->next_node = new;
    else{
        queue_node *auxiliar = line->next_node;
        while(auxiliar->next_node != NULL)
            auxiliar = auxiliar->next_node;
        auxiliar->next_node = new;
    }
}
queue_node *remove_node(queue_node *line){
    if(line->next_node == NULL)
        return NULL;
    else{
        queue_node *auxiliar = line->next_node;
        return line->next_node;
        line->next_node = auxiliar->next_node;
    }
}
/**END***********************/
