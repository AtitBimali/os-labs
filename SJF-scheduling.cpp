#include <stdio.h>

int main()
{
    int n, burst_time[20], arrival_time[20], waiting_time[20], turnaround_time[20], i, j, smallest, temp;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times and arrival times for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i+1);
        scanf("%d %d", &burst_time[i], &arrival_time[i]);
    }

    // Sort the processes by arrival time in ascending order using selection sort algorithm
    for (i = 0; i < n-1; i++)
    {
        smallest = i;
        for (j = i+1; j < n; j++)
        {
            if (arrival_time[j] < arrival_time[smallest])
            {
                smallest = j;
            }
        }
        temp = arrival_time[i];
        arrival_time[i] = arrival_time[smallest];
        arrival_time[smallest] = temp;

        temp = burst_time[i];
        burst_time[i] = burst_time[smallest];
        burst_time[smallest] = temp;
    }

    waiting_time[0] = 0;
    for (i = 1; i < n; i++)
    {
        waiting_time[i] = 0;
        for (j = 0; j < i; j++)
        {
            waiting_time[i] += burst_time[j];
        }
        waiting_time[i] -= arrival_time[i];
    }


    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], arrival_time[i], waiting_time[i], turnaround_time[i]);
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}

