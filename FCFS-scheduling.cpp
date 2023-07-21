#include<stdio.h>

int main()
{
  int n, burst_time[20], arrival_time[20], waiting_time[20], turnaround_time[20], i, j;
  float avg_waiting_time = 0, avg_turnaround_time = 0;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  printf("Enter the burst time and arrival time for each process:\n");
  for(i = 0; i < n; i++)
  {
    printf("P%d: ", i+1);
    scanf("%d%d", &burst_time[i], &arrival_time[i]);
  }

  waiting_time[0] = 0;
  for(i = 1; i < n; i++)
  {
    waiting_time[i] = 0;
    for(j = 0; j < i; j++)
    {
      if(arrival_time[j] <= arrival_time[i]){
          waiting_time[i] += burst_time[j];
      } else {
          waiting_time[i] += burst_time[i];
      }
    }
  }

  printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for(i = 0; i < n; i++)
  {
    turnaround_time[i] = burst_time[i] + waiting_time[i];
    avg_waiting_time += waiting_time[i];
    avg_turnaround_time += turnaround_time[i];
    printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
  }


  avg_waiting_time /= n;
  avg_turnaround_time /= n;
  printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
  printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

  return 0;
}

