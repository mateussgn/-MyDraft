#include <stdio.h>
#include <stdlib.h>

int f91(int n){
    if(n <= 100){
        n = f91(f91(n+11));
    }else {
        n = n - 10;
    }
    return n;
}
int main()
{
    int num[250000];
    for(int i = 0; i < 250000; i++){
        do{
            scanf("%d", &num[i]);
        }while (num[i] > 1000000);
        if(num == 0)
            break;
    }
    for(int i = 0; i < 250000; i++){
        if(num[i] == 0)
            break;
        else
            printf("f91(%d) = %d", num[i], f91(num[i]));
    }
    return 0;
}
