#include "loopfor.h"
#include <stdio.h>

void printnnt() //9x9 mul table
{
    int i = 0;
    for(i = 1;i <= 9; i ++)
    {
        int j = 0;
        for(j = 1; j <= i; j++)
        {
            printf("%d * %d = %-2d ", j, i, j*i);
        }
        printf("\n");
    }
}
