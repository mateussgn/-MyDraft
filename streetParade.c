#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int number_of_cars,
        car_number[1000],
        side_street[1000];

    scanf("%d", &number_of_cars);
    for(int i = 0; i < number_of_cars; i++){
        scanf("%d", &car_number[i]);
    }

    for(int i = 0, j = 0; i < number_of_cars; i++){
        if(car_number[i] != i){
            side_street[j] = car_number[i];
            j++;
        }
    }
    return 0;
}

void stack_push(int vector[], int element){

}
