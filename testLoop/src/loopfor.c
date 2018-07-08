#include "loopfor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    for(i = 0;i < size ; i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
}

void random_sort_nums(int *nums,int size)
{
    int i = 0;
    srand((int)time(NULL));
    for(i = 0; i < size - 1; i++)
    {   
        int cur_max_index = size - i -1;
        int rand_num = rand();
        int random_index = (int)(rand_num % (cur_max_index + 1));

//        int tmp = nums[random_index];
//        nums[random_index] = nums[cur_max_index];
//        nums[cur_max_index] = tmp;
        if(random_index == cur_max_index)
        {
            continue;
        }
        nums[random_index] = nums[random_index] + nums[cur_max_index];
        nums[cur_max_index] = nums[random_index] - nums[cur_max_index];
        nums[random_index] = nums[random_index] - nums[cur_max_index];
    }  
    printf("random nums : ");
    print_nums(nums,size);
}

void bubble_sort(int *nums,int size)
{
    int i = 0;
    for(i = 0;i < size; i++)
    {
        int j = 0;
        for(j = 0; j < size - i - 1; j++)
        {
            if(nums[j] > nums[j+1])
            {
                //int tmp_num = nums[j];
                nums[j] = nums[j + 1] + nums[j];
                nums[j+1] = nums[j] - nums[j + 1];
                nums[j] = nums[j] - nums[j + 1];
            }
        }
    }
    printf("bubble_sort : ");
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
            if(nums[key_index] > nums[j])
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
    printf("select_sort : ");
    print_nums(nums,size);
}

void insert_sort(int *nums,int size )
{
//need fix
    int i = 0;
    for(i = 1;i < size; i++)
    {
        int key = nums[i];
        int j = i - 1;
        for(; j >= 0; j--)
        {
            if(nums[j] < key)
            {
                break;
            }
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = key;
    }
    printf("insert_sort : ");
    print_nums(nums,size);
}

