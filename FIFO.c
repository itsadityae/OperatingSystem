#include <stdio.h>
#include <stdlib.h>

int main() {
    int frames = 3;
    int faults = 0;
    int m, n, s, num_pages;

    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    int *pages = (int *)malloc(num_pages * sizeof(int));

    printf("Enter page references: ");
    for (m = 0; m < num_pages; m++) {
        scanf("%d", &pages[m]);
    }

    printf("Page References\t\tFrame 1\t\t\tFrame 2\t\tFrame 3");

    int *temp = (int *)malloc(frames * sizeof(int));
    if (temp == NULL) {
        free(pages);
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    for (m = 0; m < frames; m++) {
        temp[m] = -1;
    }

    for (m = 0; m < num_pages; m++) {
        s = 0;
        for (n = 0; n < frames; n++) {
            if (pages[m] == temp[n]) {
                s++;
                faults--;
            }
        }
        faults++;
        if ((faults <= frames) && (s == 0)) {
            temp[m] = pages[m];
        } else if (s == 0) {
            temp[(faults - 1) % frames] = pages[m];
        }
        printf("\n");
        printf("%d\t\t\t", pages[m]);
        for (n = 0; n < frames; n++) {
            if (temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf("-\t\t\t");
        }
    }
    printf("\n\nTotal Page Faults:\t%d\n", faults);

    free(pages);
    free(temp);
    return 0;
}
