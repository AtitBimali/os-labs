#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[20], n, head, i, j, min, seek_time = 0, visited[20] = {0};
    printf("\tEnter number of requests for SSTF: ");
    scanf("%d", &n);
    printf("\tEnter the queue : ");
    for(i=0; i<n; i++) {
        scanf("%d", &queue[i]);
    }
    printf("\tEnter initial head position : ");
    scanf("%d", &head);
    // calculate seek time
     printf("\tDisk movement\n");
    for(i=0; i<n; i++) {
        min = 9999;
        int index = -1;
        for(j=0; j<n; j++) {
            if(abs(head-queue[j]) < min && !visited[j]) {
                min = abs(head-queue[j]);
                // save the index with the minimum distance
                // from the current head position
                index = j;
            }
        }
        visited[index] = 1;
        seek_time += min;
        printf("%d - >%d   ", head, queue[index]);
        head = queue[index];
    }
    printf("\n\tTotal seek time: %d\n", seek_time);
    return 0;
}

