#include <stdio.h>
#include <stdlib.h>

int size;

void CLOOK(int arr[], int head)
{
    int seek_count = 0;
    int distance, cur_track;
    int left[size], right[size];
    int left_count = 0, right_count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < head)
            left[left_count++] = arr[i];
        if (arr[i] > head)
            right[right_count++] = arr[i];
    }

    for (int i = 0; i < left_count - 1; i++)
    {
        for (int j = 0; j < left_count - i - 1; j++)
        {
            if (left[j] > left[j + 1])
            {
                int temp = left[j];
                left[j] = left[j + 1];
                left[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < right_count - 1; i++)
    {
        for (int j = 0; j < right_count - i - 1; j++)
        {
            if (right[j] > right[j + 1])
            {
                int temp = right[j];
                right[j] = right[j + 1];
                right[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < right_count; i++)
    {
        cur_track = right[i];
        distance = abs(cur_track - head);
        seek_count += distance;

        head = cur_track;
    }
    seek_count += abs(head - left[0]);
    head = left[0];

    for (int i = 0; i < left_count; i++)
    {
        cur_track = left[i];
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }

    printf("Total number of seek operations = %d\n", seek_count);
    printf("Seek Sequence is:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    printf("Enter the number of requests: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the request sequence:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int head;
    printf("Enter the initial position of head: ");
    scanf("%d", &head);

    printf("Initial position of head: %d\n",head);

    CLOOK(arr, head);

    return 0;
}
