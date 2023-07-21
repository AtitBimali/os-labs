#include <stdio.h>
#include <limits.h>

#define MAX_FRAMES 20

int main() {
    int pages[MAX_FRAMES], n, capacity, i, j, faults = 0, hits = 0, pos = 0;
    int future[MAX_FRAMES], dist[MAX_FRAMES];
    printf("Enter number of pages for OPR: ");
    scanf("%d", &n); 
    printf("Enter page sequence: ");
    for(i=0; i<n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter capacity of page frames: ");
    scanf("%d", &capacity);
    int frames[capacity];
    for(i=0; i<capacity; i++) {
        frames[i] = -1;
        future[i] = -1;
        dist[i] = INT_MAX;
    }
    printf("\nReference String\tPage Frames\n");
    printf("----------------\t-----------\n");
    for(i=0; i<n; i++) {
        int found = 0;
        for(j=0; j<capacity; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                hits++;
                break;
            }
        }
        if(!found) {
            int max_dist = -1;
            int victim = -1;
            for(j=0; j<capacity; j++) {
                int k;
                for(k=i+1; k<n; k++) {
                    if(frames[j] == pages[k]) {
                        dist[j] = k-i;
                        break;
                    }
                }
                if(k == n) {
                    dist[j] = INT_MAX;
                }
                if(dist[j] > max_dist) {
                    max_dist = dist[j];
                    victim = j;
                }
            }
            frames[victim] = pages[i];
            faults++;
        }
        printf("%d\t\t\t", pages[i]);
        for(j=0; j<capacity; j++) {
            if(frames[j] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }
    printf("----------------\t-----------\n");
    printf("Number of page hits: %d\n", hits);
    printf("Number of page faults: %d\n", faults);
    return 0;
}

