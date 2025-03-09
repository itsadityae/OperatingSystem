#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, AvgWT = 0, AvgTAT = 0;
    printf("\nEnter The Number of Processes: ");
    scanf("%d", &n);

    int *PAT = malloc(n * sizeof(int));
    int *PBT = malloc(n * sizeof(int));
    int *PCT = malloc(n * sizeof(int));
    int *PTAT = malloc(n * sizeof(int));
    int *PWT = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("\nArrival time of the Process %d: ", i+1);
        scanf("%d", &PAT[i]);

        printf("Burst time of the process %d: ", i+1);
        scanf("%d", &PBT[i]);
    }

    PCT[0] = PAT[0] + PBT[0];
    for (int i = 1; i < n; i++)
    {
        if (PCT[i - 1] < PAT[i])
        {
            PCT[i] = PAT[i] + PBT[i];
        }
        else
        {
            PCT[i] = PCT[i - 1] + PBT[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        PTAT[i] = PCT[i] - PAT[i];
        PWT[i] = PTAT[i] - PBT[i];
        AvgTAT += PTAT[i];
        AvgWT += PWT[i];
    }

    AvgTAT /= n;
    AvgWT /= n;

    printf("Process\tArrival-Time\tBurst-Time\tCompletion-Time\tTurnaround-Time\tWaiting-Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("p%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, PAT[i], PBT[i], PCT[i], PTAT[i], PWT[i]);
    }

    printf("Average Turnaround Time: %d\n", AvgTAT);
    printf("Average Waiting Time: %d\n", AvgWT);
    free(PAT);
    free(PBT);
    free(PCT);
    free(PTAT);
    free(PWT);

    return 0;
}

