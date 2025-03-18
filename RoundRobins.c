#include <stdio.h>

struct Process
{
    int burst_time;
    int remaining_time;
};

int main()
{
    int n, tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &tq);
    struct Process processes[n];
    int arrival[n], wait[n], turn[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrival[i]);
    }

    int timer = 0;

    while (1)
    {
        int done = 1;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].remaining_time > 0)
            {
                done = 0;
                if (processes[i].remaining_time > tq)
                {
                    timer += tq;
                    processes[i].remaining_time -= tq;
                }
                else
                {
                    timer += processes[i].remaining_time;
                    wait[i] = timer - arrival[i] - processes[i].burst_time;
                    processes[i].remaining_time = 0;
                }
            }
        }

        if (done == 1)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        turn[i] = processes[i].burst_time + wait[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, processes[i].burst_time, wait[i], turn[i]);
    }

    float avg_wait = 0, avg_turn = 0;

    for (int i = 0; i < n; i++)
    {
        avg_wait += wait[i];
        avg_turn += turn[i];
    }

    avg_wait /= n;
    avg_turn /= n;

    printf("\nAverage Waiting Time: %.2f\n", avg_wait);
    printf("Average Turnaround Time: %.2f\n", avg_turn);

    return 0;
}
