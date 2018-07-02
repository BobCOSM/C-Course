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

static void print_nums(int *nums,int size)
{
    int i = 0;
    for(i = 0;i < size; i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
}

void bubble_sort(int *nums,int size)
{
    int i = 0;
    for(i = 0;i < size; i++)
    {
        int j = 0;
        for(j = 0; j < size - i - 1; j++)
        {
            if(nums[j] < nums[j+1])
            {
                //int tmp_num = nums[j];
                nums[j] = nums[j + 1] + nums[j];
                nums[j+1] = nums[j] - nums[j + 1];
                nums[j] = nums[j] - nums[j + 1];
            }
        }
    }
    print_nums(nums,size);
}

void select_sort(int *nums,int size)
{
    int i = 0;
    for(i = 0; i < size; i++)
    {
        int key_index = i;
        int j = 0;
        for(j = i + 1; j < size; j++)
        {
            if(nums[key_index] < nums[j])
            {
                key_index = j;
            }
        }
        //printf("%d ",nums[key_index]);
        if(key_index != i)
        {
            nums[key_index] = nums[key_index] + nums[i];
            nums[i] = nums[key_index] - nums[i];
            nums[key_index] = nums[key_index] - nums[i];
        }
    }
    print_nums(nums,size);
}

