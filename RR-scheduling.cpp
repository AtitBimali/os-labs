#include <stdio.h>

int main()
{
    int i, n, sum = 0, count = 0, y, quant, wt = 0, tat = 0, arrival_time[10], burst_time[10], temp[10];
    float avg_wt, avg_tat;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Accept burst time and arrival time for each process
    printf("Enter the burst time for\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i]; // store the burst time in a temporary array
    }
    printf("Enter the arrival time for\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &arrival_time[i]);
    }

    // Accept the time quantum
    printf("Enter the Time Quantum : ");
    scanf("%d", &quant);

    // Initialize the process counter
    y = n;

    // Display the process No, burst time, Turn Around Time and the waiting time
    printf("\n Process \t Burst Time \t TAT \t Waiting Time ");

    // Run the Round Robin algorithm
    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= quant && temp[i] > 0) // Check if the process can complete within the given time quantum
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }
        if (temp[i] == 0 && count == 1)
        {
            y--;
            printf("\nP%d \t\t %d\t \t%d\t\t %d", i + 1, burst_time[i], sum - arrival_time[i], sum - arrival_time[i] - burst_time[i]);
            wt = wt + sum - arrival_time[i] - burst_time[i];
            tat = tat + sum - arrival_time[i];
            count = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (arrival_time[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }


    // Calculate average waiting time and Turn Around time
    avg_wt = (float)wt / n;
    avg_tat = (float)tat / n;

    printf("\n Average Turn Around Time: %f", avg_tat);
    printf("\n Average Waiting Time: %f", avg_wt);

    return 0;
}

