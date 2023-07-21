#include <stdio.h>

int main()
{
    int n, burst_time[20], remaining_time[20], waiting_time[20], turnaround_time[20], arrival_time[20], i, j, smallest, time = 0, count = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time and arrival time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d %d", &burst_time[i], &arrival_time[i]);
        remaining_time[i] = burst_time[i];
    }

    while (count != n)
    {
        smallest = -1;
        for (i = 0; i < n; i++)
        {
            if (remaining_time[i] > 0 && arrival_time[i] <= time && (smallest == -1 || remaining_time[i] < remaining_time[smallest]))
            {
                smallest = i;
            }
        }
        remaining_time[smallest]--;

        if (remaining_time[smallest] == 0)
        {
            count++;
            waiting_time[smallest] = time - burst_time[smallest] - arrival_time[smallest];
            turnaround_time[smallest] = time - arrival_time[smallest];
        }

        time++;
    }

    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], arrival_time[i], waiting_time[i], turnaround_time[i]);
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}

