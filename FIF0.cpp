#include <stdio.h>

int main()
{
    int frames, ref_len, count = 0;
    int pages[100], frame[100];
    int n, m, page_faults = 0, page_hits = 0;
    
    printf("Enter number of frames for FIFO:");
    scanf("%d", &frames);
    printf("Enter length of reference string:");
    scanf("%d", &ref_len);
    printf("Enter the reference string:");
    
    for(m = 0; m < ref_len; m++)
        scanf("%d", &pages[m]);
    
    for(m = 0; m < frames; m++)
        frame[m] = -1;
    
    for(m = 0; m < ref_len; m++)
    {
        int flag = 0;
        
        for(n = 0; n < frames; n++)
        {
            if(frame[n] == pages[m])
            {
                flag = 1;
                page_hits++;
                
                for(int i=0; i<frames; i++){
                    if(frame[i] != -1)
                        printf("%d ", frame[i]);
                }
                printf("\n");
                break;
            }
        }
        
        if(flag == 0)
        {
            frame[count % frames] = pages[m];
            count++;
            page_faults++;
            for(int i=0; i<frames; i++){
                if(frame[i] != -1)
                    printf("%d ", frame[i]);
            }
            printf("\n");
        }
    }
    
    printf("Number of page faults: %d\n", page_faults);
    printf("Number of page hits: %d\n", page_hits);
    return 0;
}

