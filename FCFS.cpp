
#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[20], n, head, i, seek_time = 0;
    printf("\tEnter number of requests for FCFS: ");
    scanf("%d", &n);
    printf("\tEnter the queue: ");
    for(i=0; i<n; i++) {
        scanf("%d", &queue[i]);
    }
    printf("\tEnter initial head position: ");
    scanf("%d", &head);
    // calculate seek time
     printf("\tDisk movement\n");
    for(i=0; i<n; i++) {
        seek_time += abs(head - queue[i]);
        printf("%d - >%d\t", head, queue[i]);
        head = queue[i];
    }
    printf("\n\tTotal seek time: %d\n", seek_time);
    return 0;
}


