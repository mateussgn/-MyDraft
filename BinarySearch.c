#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100000 //10^5
#define MAX_QUERIES 500000 //5*10^5

int binarySearch(long long int numbers_array[], long long int array_size, long long int element_to_search) {
    long long int left = 0, middle = 0, right = array_size - 1;

    while(left <= right) {
        middle = (left + right)/2;
        if(element_to_search == numbers_array[middle]){
            while(numbers_array[middle] == numbers_array[middle - 1] && middle > 0)
                middle--;
            return middle;
        }
        else if (element_to_search <= numbers_array[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}

int main() {

    long long int number_of_elements = 0,
                           number_of_queries = 0;
    long long int searched_element = 0,
                  numbers[MAX_NUMBERS] = {0},
                  queries[MAX_QUERIES] = {0};
    char space;

    scanf("%lld %lld", &number_of_elements, &number_of_queries);

    for(int i = 0; i < number_of_elements; i++) {
        scanf("%lld%c", &numbers[i], &space);
    }

    for(int i = 0; i < number_of_queries; i++) {
        scanf("%lld", &queries[i]);
    }
    for(int i = 0; i < number_of_queries; i++) {
        searched_element = binarySearch(numbers, number_of_elements, queries[i]);
        printf("%lld\n", searched_element);
    }
return 0;
}
