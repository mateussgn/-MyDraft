#include <stdio.h>
#include <stdlib.h>

int passings(int start[], int end[], int array_size) {
    int i = 0, j = 0, swaps = 0, tmp = 0;
    for(i = 0; i < array_size; i++) {
        for(j = i; (start[j] != end[i]);j++);
        while(j > i){
            tmp = start[j-1];
            start[j-1] = start[j];
            start[j] = tmp;
            swaps++;
            j--;
        }
    }
    return swaps;
}
int main() {
    int i = 0, num_competitors = 0, overtaking = 0, grid[24] = {0}, finish[24] = {0};
    char space;
    while(scanf("%d", &num_competitors) != EOF){
        //scanf("%d", &num_competitors);
        for(i = 0; i < num_competitors; i++) {
            scanf("%d%c", &grid[i], &space);
        }
        for(i = 0; i < num_competitors; i++) {
            scanf("%d%c", &finish[i], &space);
        }
        overtaking = passings(grid, finish, num_competitors);
        printf("%d\n", overtaking);
    }
    return 0;
}
