#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    
    int p;
    printf("Enter the initial head position: ");
    scanf("%d", &p);
    
    int r[n];
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }

    int total_head_moves = 0;
    
    for (int i = 0; i < n; i++) {
        total_head_moves += abs(p - r[i]);
        p = r[i];
    }

    printf("Total head moves using FCFS: %d\n", total_head_moves);

    return 0;
}
