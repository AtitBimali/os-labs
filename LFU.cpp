#include <stdio.h>
#include <limits.h>

#define MAX_FRAMES 20

int main() {
    int pages[MAX_FRAMES], n, capacity, i, j, faults = 0, hits = 0;
    int counts[MAX_FRAMES], ages[MAX_FRAMES], frames[MAX_FRAMES];
    printf("Enter number of pages for LFU: ");
    scanf("%d", &n);
    printf("Enter page sequence: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter capacity of page frames: ");
    scanf("%d", &capacity);
    for (i = 0; i < capacity; i++) {
        frames[i] = -1;
        counts[i] = 0;
        ages[i] = INT_MAX;
    }
    printf("\nReference String\tPage Frames\n");
    printf("----------------\t-----------\n");
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                hits++;
                counts[j]++;
                break;
            }
        }
        if (!found) {
            int victim = 0;
            for (j = 1; j < capacity; j++) {
                if (counts[j] < counts[victim] || (counts[j] == counts[victim] && ages[j] < ages[victim])) {
                    victim = j;
                }
            }
            frames[victim] = pages[i];
            counts[victim] = 1;
            ages[victim] = i;
            faults++;
        }
        printf("%d\t\t\t", pages[i]);
        for (j = 0; j < capacity; j++) {
            if (frames[j] == -1) {
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

