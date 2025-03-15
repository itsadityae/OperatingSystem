#include <stdio.h>
#include <stdlib.h>

struct Process 
{
    int PID;
    int PAT;
    int PBT; 
    int PCT; 
    int PTAT;
    int PWT; 
    int Priority;
};

int main() 
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process* p = (struct Process*)malloc(n * sizeof(struct Process));
    float Avg_PTAT;
    float Avg_PWT;
    float Total_PTAT = 0;
    float Total_PWT = 0;
    int Com_P[n];
    for (int i = 0; i < n; i++)
    {
        Com_P[i] = 0;
    }

    for(int i = 0; i < n; i++) 
    {
        printf("\nArrival time of the Process %d: ", i+1);
        scanf("%d", &p[i].PAT);
        printf("Burst time of the process %d: ", i+1);
        scanf("%d",&p[i].PBT);
        printf("Priority of the process %d: ", i+1);
        scanf("%d",&p[i].Priority);
        p[i].PID = i + 1;
    }

    int current_time = 0;
    int completed = 0;

    while(completed != n) 
    {
        int idx = -1;
        int mx = 10000000;
        for(int i = 0; i < n; i++) {
            if(p[i].PAT <= current_time && Com_P[i] == 0) 
            {
                if(p[i].Priority < mx) 
                {
                    mx = p[i].Priority;
                    idx = i;
                }
                if(p[i].Priority == mx) 
                {
                    if(p[i].PAT < p[idx].PAT) 
                    {
                        mx = p[i].Priority;
                        idx = i;
                    }
                }
            }
        }
        if(idx != -1) 
        {
            p[idx].PCT = current_time;
            p[idx].PCT += p[idx].PBT;
            p[idx].PTAT = p[idx].PCT - p[idx].PAT;
            p[idx].PWT = p[idx].PTAT - p[idx].PBT;

            Total_PTAT += p[idx].PTAT;
            Total_PWT += p[idx].PWT;

            Com_P[idx] = 1;
            completed++;
            current_time = p[idx].PCT;
        }
        else {
            current_time++;
        }
        
    }

    Avg_PTAT = Total_PTAT / n;
    Avg_PWT = Total_PWT / n;

    printf("PID\tAT\tBT\tCT\tTAT\tWT\tPriority\n");

    for(int i = 0; i < n; i++) 
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].PID, p[i].PAT, p[i].PBT, p[i].PCT, p[i].PTAT, p[i].PWT, p[i].Priority);
    }
    printf("Average Turnaround Time = %f\n", Avg_PTAT);
    printf("Average Waiting Time = %f\n", Avg_PWT);

    free(p); // Don't forget to free the dynamically allocated memory.

    return 0;
}
