#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SCAN(int req[], int n, int head, char* dir) {
    int sc = 0, d, cur, left[n], right[n], ls = 0, rs = 0;

    if (!strcmp(dir, "left")) left[ls++] = 0;
    else if (!strcmp(dir, "right")) right[rs++] = 199;

    for (int i = 0; i < n; i++) {
        if (req[i] < head) left[ls++] = req[i];
        if (req[i] > head) right[rs++] = req[i];
    }

    for (int i = 0; i < ls - 1; i++)
        for (int j = 0; j < ls - i - 1; j++)
            if (left[j] > left[j + 1]) {
                int t = left[j];
                left[j] = left[j + 1];
                left[j + 1] = t;
            }

    for (int i = 0; i < rs - 1; i++)
        for (int j = 0; j < rs - i - 1; j++)
            if (right[j] > right[j + 1]) {
                int t = right[j];
                right[j] = right[j + 1];
                right[j + 1] = t;
            }

    int r = 2;
    while (r--) {
        if (!strcmp(dir, "left")) {
            for (int i = ls - 1; i >= 0; i--) {
                cur = left[i];
                printf("%d ", cur);
                d = abs(cur - head);
                sc += d;
                head = cur;
            }
            dir = "right";
        } else if (!strcmp(dir, "right")) {
            for (int i = 0; i < rs; i++) {
                cur = right[i];
                printf("%d ", cur);
                d = abs(cur - head);
                sc += d;
                head = cur;
            }
            dir = "left";
        }
    }

    printf("\nTotal seeks = %d\n", sc);
}

int main() {
    int n, h;
    char dir[10];

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter requests: ");
    for (int i = 0; i < n; i++) scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &h);

    printf("Enter direction (left/right): ");
    scanf("%s", dir);

    SCAN(req, n, h, dir);

    return 0;
}
