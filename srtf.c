#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int n;
    float AvgWT = 0.0f, AvgTAT = 0.0f;
    printf("\nEnter The Number of Processes: ");
    scanf("%d", &n);

    int *PAT = malloc(n * sizeof(int));
    int *PBT = malloc(n * sizeof(int));
    int *PCT = malloc(n * sizeof(int));
    int *PTAT = malloc(n * sizeof(int));
    int *PWT = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("\nArrival Time of P%d: ", i + 1);
        scanf("%d", &PAT[i]);

        printf("Burst Time of P%d: ", i + 1);
        scanf("%d", &PBT[i]);
    }

    int remainingTime[n];
    for (int i = 0; i < n; i++)
    {
        remainingTime[i] = PBT[i];
    }

    int currentTime = 0;
    int completed = 0;

    while (completed < n)
    {
        int shortestIndex = -1;
        int shortestTime = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (PAT[i] <= currentTime && remainingTime[i] < shortestTime && remainingTime[i] > 0)
            {
                shortestTime = remainingTime[i];
                shortestIndex = i;
            }
        }

        if (shortestIndex == -1)
        {
            currentTime++;
        }
        else
        {
            PCT[shortestIndex] = currentTime + 1;
            remainingTime[shortestIndex]--;
            currentTime++;

            if (remainingTime[shortestIndex] == 0)
            {
                completed++;
                PTAT[shortestIndex] = PCT[shortestIndex] - PAT[shortestIndex];
                PWT[shortestIndex] = PTAT[shortestIndex] - PBT[shortestIndex];
                AvgTAT += PTAT[shortestIndex];
                AvgWT += PWT[shortestIndex];
            }
        }
    }

    AvgTAT /= n;
    AvgWT /= n;

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, PAT[i], PBT[i], PCT[i], PTAT[i], PWT[i]);
    }

    printf("Average Turnaround Time: %.2f\n", AvgTAT);
    printf("Average Waiting Time: %.2f\n", AvgWT);

    // Don't forget to free the allocated memory
    free(PAT);
    free(PBT);
    free(PCT);
    free(PTAT);
    free(PWT);
    return 0;
}
