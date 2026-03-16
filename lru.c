#include <stdio.h>

int main()
{
    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int frames[3];
    int time[3];
    int i,j,k,pos;

    int hits = 0;
    int faults = 0;
    int counter = 0;

    for(i=0;i<3;i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nLRU Page Replacement\n");
    printf("Number of Frames = 3\n");

    for(i=0;i<12;i++)
    {
        int found = 0;

        for(j=0;j<3;j++)
        {
            if(frames[j] == pages[i])
            {
                hits++;
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            int min = time[0];
            pos = 0;

            for(j=1;j<3;j++)
            {
                if(time[j] < min)
                {
                    min = time[j];
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            counter++;
            time[pos] = counter;
            faults++;
        }

        printf("\nPage %d\n",pages[i]);

        printf("Frame1 : ");
        if(frames[0] == -1) printf("-");
        else printf("%d",frames[0]);

        printf("\nFrame2 : ");
        if(frames[1] == -1) printf("-");
        else printf("%d",frames[1]);

        printf("\nFrame3 : ");
        if(frames[2] == -1) printf("-");
        else printf("%d",frames[2]);

        if(found)
            printf("\nResult : Hit\n");
        else
            printf("\nResult : Fault\n");
    }

    float hitPer = (hits/12.0)*100;
    float faultPer = (faults/12.0)*100;

    printf("\n\nTotal Hits = %d",hits);
    printf("\nTotal Faults = %d",faults);
    printf("\nHit Percentage = %.2f%%",hitPer);
    printf("\nFault Percentage = %.2f%%\n",faultPer);

    return 0;
}
