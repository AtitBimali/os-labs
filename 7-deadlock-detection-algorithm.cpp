#include<stdio.h>
#include<stdbool.h>

int main() {
    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    int alloc[n][m], max[n][m], avail[m], req[n][m], f[n], ans[n], index = 0;
    for(i=0; i<n; i++) {
        f[i] = 0;
    }
    printf("Enter the allocation matrix:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the max matrix:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the available resources:\n");
    for(i=0; i<m; i++) {
        scanf("%d", &avail[i]);
    }
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            req[i][j] = max[i][j] - alloc[i][j];
        }
    }
    int y=0;
    bool deadlock = true;
    for(k=0; k<5; k++) {
        bool found = false;
        for(i=0; i<n; i++) {
            if(f[i] == 0) {
                bool flag = true;
                for(j=0; j<m; j++) {
                    if(req[i][j] > avail[j]) {
                        flag = false;
                        break;
                    }
                }
                if(flag == true) {
                    found = true;
                    ans[index++] = i;
                    for(y=0; y<m; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
        if (found == false) {
            deadlock = true;
            break;
        }
    }
    if (deadlock == true) {
        printf("Error: Deadlock detected!\n");
    } else {
        printf("Safe sequence is: ");
        for(i=0; i<n-1; i++) {
            printf("P%d -> ", ans[i]);
        }
        printf("P%d\n", ans[n-1]);
    }
    return 0;
}

