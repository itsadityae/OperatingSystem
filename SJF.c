#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    int *PAT = malloc(n * sizeof(int));
    int *PBT = malloc(n * sizeof(int));
    int *PCT = malloc(n * sizeof(int));
    int *PTAT = malloc(n * sizeof(int));
    int *PWT = malloc(n * sizeof(int));
    int *PTEMP = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("\nArrival Time of P%d: ", i + 1);
        scanf("%d", &PAT[i]);

        printf("Burst Time of P%d: ", i + 1);
        scanf("%d", &PBT[i]);
        PCT[i] = 0; // Initialize completion time to 0
        PTAT[i] = 0; // Initialize turnaround time to 0
        PWT[i] = 0; // Initialize waiting time to 0
    }
    for(int j=0; j<n;j++)
    {
        PTEMP[j]=PBT[j];
    }
    int curt = 0; // Current time
    int cp = 0; // Completed processes count

    while (cp < n) {
        int sj = -1; // Shortest Job
        int shortestBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (PBT[i] > 0 && PAT[i] <= curt && PBT[i] < shortestBurst) {
                shortestBurst = PBT[i];
                sj = i;
            }
        }

        if (sj == -1) {
            curt++;
        } else {
            PCT[sj] = curt + PBT[sj];
            PTAT[sj] = PCT[sj] - PAT[sj];
            PWT[sj] = PTAT[sj] - PBT[sj];
            curt = PCT[sj];
            PBT[sj] = 0; // Mark the process as completed
            cp++;
        }
    }

    float AvgWT = 0.0f, AvgTAT = 0.0f;
    for (int i = 0; i < n; i++) {
        AvgWT += PWT[i];
        AvgTAT += PTAT[i];
    }
    AvgTAT /= n;
    AvgWT /= n;

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, PAT[i], PTEMP[i], PCT[i], PTAT[i], PWT[i]);
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
