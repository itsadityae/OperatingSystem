#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8
#define DISK_SIZE 200

void LOOK(int arr[], int head, char* direction) {
    int seek_count = 0;
    int cur_track;
    int left[SIZE], right[SIZE];
    int left_count = 0, right_count = 0;
    int seek_seq[SIZE * 2];

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < head)
            left[left_count++] = arr[i];
        if (arr[i] > head)
            right[right_count++] = arr[i];
    }

    for (int i = 0; i < left_count - 1; i++) {
        for (int j = 0; j < left_count - i - 1; j++) {
            if (left[j] > left[j + 1]) {
                int temp = left[j];
                left[j] = left[j + 1];
                left[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < right_count - 1; i++) {
        for (int j = 0; j < right_count - i - 1; j++) {
            if (right[j] > right[j + 1]) {
                int temp = right[j];
                right[j] = right[j + 1];
                right[j + 1] = temp;
            }
        }
    }

    int run = 2;
    int seek_seq_index = 0;
    while (run--) {
        if (strcmp(direction, "left") == 0) {
            for (int i = left_count - 1; i >= 0; i--) {
                cur_track = left[i];
                seek_seq[seek_seq_index++] = cur_track;
                seek_count += abs(cur_track - head);
                head = cur_track;
            }
            direction = "right";
        } else if (strcmp(direction, "right") == 0) {
            for (int i = 0; i < right_count; i++) {
                cur_track = right[i];
                seek_seq[seek_seq_index++] = cur_track;
                seek_count += abs(cur_track - head);
                head = cur_track;
            }
            direction = "left";
        }
    }

    printf("Seek operations = %d\n", seek_count);
    printf("Seek Sequence:\n");

    for (int i = 0; i < seek_seq_index; i++) {
        printf("%d\n", seek_seq[i]);
    }
}

int main() {
    int arr[SIZE];
    int head;
    char direction[10];

    printf("Enter array elements:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter initial direction (left or right): ");
    scanf("%s", direction);

    printf("Initial head position: %d\n",head);

    LOOK(arr, head, direction);

    return 0;
}
