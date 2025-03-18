#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

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
        int min_dist = INT_MAX;
        int nearest = -1;

        for (int j = 0; j < n; j++) {
            if (r[j] != -1) {
                int dist = abs(p - r[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    nearest = j;
                }
            }
        }

        if (nearest != -1) {
            total_head_moves += min_dist;
            p = r[nearest];
            r[nearest] = -1;
        }
    }

    printf("Total head moves using SSTF: %d\n", total_head_moves);

    return 0;
}
