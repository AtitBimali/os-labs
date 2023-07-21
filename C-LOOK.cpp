#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int i, j, k, n, m, sum = 0, x, y, h;
    printf("Enter the max range of disk for C-LOOK: ");
    scanf("%d", &m);
    printf("Enter the initial head position: ");
    scanf("%d", &h);
    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter the queue: ");
    int a[MAX], b[MAX];
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++) {
        if(a[i] > m) {
            printf("Error, Unknown position %d\n", a[i]);
            return 0;
        }
    }
    a[n] = h;
    n++;
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    for(i = 0; i < n; i++) {
        if(h == a[i])
            break;
    }
    k = i;
    j = 0;
    for(i = k; i < n; i++) {
        b[j] = a[i];
        j++;
    }
    for(i = 0; i < k; i++) {
        b[j] = a[i];
        j++;
    }
    printf("Disk movement\n");
    int temp = h;
    printf("%d",temp);
    for(i=1;i<n;i++){
        printf(" -> %d",b[i]);
        sum+=abs(b[i]-temp);
        temp=b[i];
    }
    printf("\n\tTotal seek time is %d\n", sum);
    return 0;
}

