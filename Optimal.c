#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool find(int key, int fr[], int fr_size) {
    for (int i = 0; i < fr_size; i++) {
        if (fr[i] == key) {
            return true;  // Page found in a frame: HIT
        }
    }
    return false;  // Page not found in a frame: MISS
}

int predict(int pg[], int fr[], int pn, int fr_size, int index) {
    int res = -1, farthest = index;
    for (int i = 0; i < fr_size; i++) {
        int j;
        for (j = index; j < pn; j++) {
            if (fr[i] == pg[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pn) {
            return i;  // Page is never referenced in the future
        }
    }
    return (res == -1) ? 0 : res;  // Return the frame to replace
}

void opPage(int pg[], int pn, int fn) {
    int fr[fn];
    int fr_size = 0;
    int hit = 0;

    for (int i = 0; i < pn; i++) {
        if (find(pg[i], fr, fr_size)) {
            hit++;
        } else {
            if (fr_size < fn) {
                fr[fr_size++] = pg[i];
            } else {
                int j = predict(pg, fr, pn, fr_size, i + 1);
                fr[j] = pg[i];
            }
        }
    }

    printf("Hits = %d\n", hit);
    printf("Misses = %d\n", pn - hit);
}

int main() {
    int pn, fn;

    printf("Enter the number of pages: ");
    scanf("%d", &pn);

    int* pg = (int*)malloc(pn * sizeof(int));
    if (pg == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    printf("Enter the page references:\n");
    for (int i = 0; i < pn; i++) {
        scanf("%d", &pg[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &fn);

    opPage(pg, pn, fn);

    free(pg);  // Free the dynamically allocated memory
    return 0;
}
