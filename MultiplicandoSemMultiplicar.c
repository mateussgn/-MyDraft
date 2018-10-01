#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x, y, i, mult = 0;

    scanf("%d", &x);
    scanf("%d", &y);

    if (x<0 && y<0){
        x = x-x-x;
        y = y-y-y;
        for(i=0; i<y; i++){
            mult = mult+x;
        }
    } else if (x < 0){
        for(i=0; i<y; i++){
            mult = mult + x;
        }
    } else if (y < 0){
        for(i=0; i<x; i++){
            mult = mult + y;
        }
    } else {
        for(i=0; i<y; i++){
            mult = mult+x;
        }
    }

    printf("%d\n", mult);

    return 0;
}
