#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int i,j,k,n,m,sum=0,x,y,h;
    printf("\tEnter the max range of disk for LOOK: ");
    scanf("%d",&m);
    printf("\tEnter the initial head position : ");
    scanf("%d",&h);
    printf("\tEnter number of requests : ");
    scanf("%d",&n);
    printf("\tEnter the queue : ");
    int a[MAX],b[MAX];
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    for(i=0;i<n;i++){
        if(a[i]>m){
            printf("Error, Unknown position %d\n", a[i]);
            return 0;
        }
    }
    int temp=h;
    a[n]=h;
    a[n+1]=m;
    n+=2;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
    for(i=0;i<n;i++){
        if(h==a[i])
            break;
    }
    k=i;
    if(k<n/2){
        for(i=k;i<n-1;i++){
            b[i-k]=a[i];
        }
        for(i=k-1,j=n-k-1;i>=0;i--,j++){
            b[j]=a[i];
        }
    }
    else{    
        for(i=k,j=0;i<n;i++,j++){
            b[j]=a[i];
        }
        for(i=k-1,j=n-k-2;i>=0;i--,j++){
            b[j]=a[i];
        }
    }
    temp=b[0];
    printf("\tDisk movement\n");
    printf("%d",temp);
    for(i=1;i<n-1;i++){
        printf(" -> %d",b[i]);
        sum+=abs(b[i]-temp);
        temp=b[i];
    }
    printf("\n\tTotal seek time is %d\n", sum);
    return 0;
}

