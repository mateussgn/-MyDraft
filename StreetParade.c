#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    int number_of_cars = 0,
        queue_size = 0,
        stack_size = 0,
        yes_or_no = 0,
        car_number[1001] = {0},
        side_street[1001] = {0};
    char space = '0';
    while(1){
        scanf("%d", &number_of_cars);
        if(number_of_cars == 0)
            break;
        for(int i = 1; i <= number_of_cars ; i++){
            scanf("%d%c", &car_number[i], &space);
        }
        for(int i = 1; i <= number_of_cars;){
            if(car_number[i] == 0){
                break;
            } else if(car_number[i] == i){
                i++;
                queue_size = i;
            } else if (stack_size == 0){
                stack_size++;
                side_street[stack_size] = car_number[i];
                for(int k = i; k <= number_of_cars; k++){
                    car_number[k] = car_number[k+1];
                }
            } else if (side_street[stack_size] < car_number[i]){
                for(int k = queue_size; k < number_of_cars; k++){
                    car_number[k+1] = car_number[k];
                }
                car_number[i] = side_street[stack_size];
                stack_size--;
            } else {
                stack_size++;
                side_street[stack_size] = car_number[i];
                for(int k = i; k <= number_of_cars; k++){
                    car_number[k] = car_number[k+1];
                }
            }
        }
        if (stack_size > 0){
            for(int i = queue_size, j = stack_size; i <= number_of_cars; i++, j--){
                car_number[i] = side_street[j];
            }
        }
        for (int i = 1; i <= number_of_cars; i++){
            if(car_number[i] != i){
                yes_or_no = 1;
                break;
            }
        }
        if(yes_or_no == 1)
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}
