#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100000

int lomutoPartition(long long int line[], long int inicial, int long length) {
    int left = inicial, right = length, pivot = line[left], split = left, tmp = 0;
    for(int i = left+1; i < right; i++) {
        if(line[i] < pivot) {
            split = split+1;
            tmp = line[split];
            line[split] = line[i];
            line[i] = tmp;
        }
    }
    tmp = line[left];
    line[left] = line[split];
    line[split] = tmp;
    return split;
}
void quickSort(long long int line[], long int inicial, long int length) {
    int left = inicial, right = length, split = 0;
    if(left < right) {
        split = lomutoPartition(line, left, right);
        quickSort(line, left, split-1);
        quickSort(line, split+1, right);

    }
}
int check(long long int line[], long int length) {
    long long int total_time = 0, desapointed_people = 0, tmp = 0;
    for(int i = 1; i < length; i++) {
        total_time += line[i-1];
        if(line[i] < total_time) {
            desapointed_people++;
            for(int j = i+1; (line[j] >= total_time) && (j < length); j++) {
                tmp = line[i];
                line[i] = line[j];
                line[j] = tmp;
                desapointed_people--;
            }
        }
    }
    return desapointed_people;
}
int main() {
    long int number_of_people = 0;
    long long int waiting[MAX_LENGTH] = {0}, not_desapointed_people = 0;
    char s;
    while(scanf("%ld", &number_of_people) != EOF) {
        for(int i = 0; i < number_of_people; i++) {
            scanf("%lld%c", &waiting[i], &s);
        }
        quickSort(waiting, 0, number_of_people);
        not_desapointed_people = check(waiting, number_of_people);
        printf("%lld\n", number_of_people - not_desapointed_people);
    }
    return 0;
}
