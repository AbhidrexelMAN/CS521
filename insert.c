#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    /*initialising input data*/
    
    int t,i,j,k;
    int r,count=9000,upper=10000,lower=1;
    int length, input_stream[count];
    length = sizeof(input_stream) / sizeof(int);
    
    srand(time(0));
    
    for (r = 0; r < count; r++)
    {
        int num = (rand() % (upper - lower + 1)) + lower;
        input_stream[r]=num;
    }
    
    
    printf("intial array is:\n");
    for(k=0;k<length;k++)
    {
        printf("%d\t",input_stream[k]);
    }
    printf("\n\n");
    
    clock_t begin = clock();
    
    for(j=1;j<length;j++)
    {
        i = j;
        
        while ( i > 0 && input_stream[i-1] > input_stream[i])
        {
            t = input_stream[i];
            input_stream[i]  = input_stream[i-1];
            input_stream[i-1] = t;
            
            i--;
        }
        
    }
    
    clock_t end = clock();
    
    printf("sorted array is:\n");
    for(k=0;k<length;k++)
    {
        printf("%d\t",input_stream[k]);
    }
    
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    printf("\n\ntime spent is %f seconds",time_spent);
}

