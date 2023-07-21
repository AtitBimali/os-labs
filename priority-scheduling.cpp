#include <stdio.h>

int main()
{
    int i, n, sum = 0, wt = 0, tat = 0, arrival_time[10], burst_time[10], priority[10], temp[10];
    float avg_wt, avg_tat;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Accept burst time, arrival time, and priority for each process
    printf("Enter the burst time, arrival time, and priority for\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d %d %d", &burst_time[i], &arrival_time[i], &priority[i]);
        temp[i] = burst_time[i]; // store the burst time in a temporary array
    }

    // Display the process No, burst time, arrival time, priority, Turn Around Time, waiting time
    printf("\nProcess 	 Burst Time \t Arrival Time \t Priority \t TAT \t Waiting Time ");

    // Run the Priority Scheduling algorithm
    int completed = 0;
    for (sum = 0; completed < n; sum++)
    {
        int min = 999, index = -1;
        for (int j = 0; j < n; j++)
        {
            if (arrival_time[j] <= sum && priority[j] < min && temp[j] > 0)
            {
                min = priority[j];
                index = j;
            }
        }
        if (index != -1)
        {
            temp[index]--;
            if (temp[index] == 0)
            {
                completed++;
                printf("\nP%d \t\t %d\t\t %d\t\t %d\t\t %d\t\t %d", index + 1, burst_time[index], arrival_time[index], priority[index], sum + 1 - arrival_time[index], sum + 1 - arrival_time[index] - burst_time[index]);
                wt = wt + sum + 1 - arrival_time[index] - burst_time[index];
                tat = tat + sum + 1 - arrival_time[index];
            }
        }
    }

    // Calculate average waiting time and Turn Around time
    avg_wt = (float)wt / n;
    avg_tat = (float)tat / n;

  printf("\n Average Waiting Time: %f", avg_wt);
    printf("\n\n Average Turn Around Time: %f", avg_tat);
  

    return 0;
}

