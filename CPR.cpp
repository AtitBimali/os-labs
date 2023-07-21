#include <stdio.h>

#define MAX_FRAMES 20

int main() {
    int pages[MAX_FRAMES], n, capacity, i, j, faults = 0, hits = 0, pos = 0;
    int use_bit[MAX_FRAMES];
    printf("Enter number of pages for CPR: ");
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
        use_bit[i] = 0;
    }
    for(i=0; i<n; i++) {
        int found = 0;
        for(j=0; j<capacity; j++) {
            if(frames[j] == pages[i]) {
                use_bit[j] = 1;
                found = 1;
                hits++;
                break;
            }
        }
        if(!found) {
            while(use_bit[pos] == 1) {
                use_bit[pos] = 0;
                pos = (pos + 1) % capacity;
            }
            frames[pos] = pages[i];
            use_bit[pos] = 1;
            pos = (pos + 1) % capacity;
            faults++;
        }
    }
    printf("Number of page hits: %d\n", hits);
    printf("Number of page faults: %d\n", faults);
    return 0;
}

