#include <stdio.h>
#include <stdlib.h>

#define MAX_DISTANCE 1000000

int main() {
    int i = 0,
        j = 0,
        number_of_test_cases = 0,
        number_of_stops = 0,
        distance_from_stop_town[MAX_DISTANCE] = {0},
        supply_amount_of_fuel[MAX_DISTANCE] = {0},
        distance_from_truck_town = 0,
        truck_amount_of_fuel = 0;

    scanf("%d", &number_of_test_cases);

    for(i = 0; i < number_of_test_cases; i++){
        scanf("%d", &number_of_stops);
        for(j = 0; j < number_of_stops; j++){
            scanf("%d %d", &distance_from_stop_town[i], supply_amount_of_fuel[i]);
        }
        scanf("%d %d", &distance_from_truck_town, &truck_amount_of_fuel);
        //LER L e P
    }
    return 0;
}