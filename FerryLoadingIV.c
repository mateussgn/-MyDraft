#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

    int number_of_tests_cases = 0,
        ferrie_length = 0,
        m_lines = 0,
        mobile_length = 0,
        size_left = 0,
        size_right = 0,
        number_of_travels = 0,
        ocupied_space = 0,
        left_side[100] = {0},
        right_side[100] = {0};
    char river_side[6];

    scanf("%d", &number_of_tests_cases);

    for(int i = 0; i < number_of_tests_cases; i++){
        scanf("%d %d", &ferrie_length, &m_lines);
        ferrie_length *= 100;
        for(int j = 0; j < m_lines; j++){
            scanf("%d %s", &mobile_length, river_side);
            if(j == 0 && river_side[0] == 'r')
                number_of_travels = 1;
            if(river_side[0] == 'l'){
                left_side[size_left] = mobile_length;
                size_left++;
            } else{
                right_side[size_right] = mobile_length;
                size_right++;
            }
        }
        if(number_of_travels == 0){
            ocupied_space = 0;
            for(i = 0; ocupied_space <= ferrie_length && i < size_left;i++){
                ocupied_space += left_side[i];
                for(int j = 0; j < size_left; j++){
                    left_side[j] = left_side[j+1];
                }
            }
            number_of_travels++;
        }else {
            ocupied_space = 0;
            for(i = 0; ocupied_space <= ferrie_length && i < size_right;i++){
                ocupied_space += right_side[i];
                for(int j = 0; j < size_right; j++){
                    left_side[j] = right_side[j+1];
                }
            }
            number_of_travels++;
        }
        printf("%d\n", number_of_travels);
    }
    return 0;
}
