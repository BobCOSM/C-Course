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


static void merge(int *nums,int start,int mid,int end)
{
    static int count = 0;
    int n1 = mid - start + 1 + 1;
    int n2 = end - mid + 1;
    int *L = (int *)malloc(sizeof(int) * n1);
    int *R = (int *)malloc(sizeof(int) * n2);
    memcpy(L,nums + start ,sizeof(int) * n1);
    memcpy(R,nums + mid + 1,sizeof(int) * n2);
    
    L[n1 - 1] = 10;
    R[n2 - 1] = 10;
    printf("%d : \n",count);
    print_nums(L,n1);
    printf("\n");
    print_nums(R,n2);
    printf("\n");
    int i = 0 ;
    int j = 0 ;
    int k = start ;
    for(k = start;k <= end;k++)
    {
        if(L[i] <= R[j])
        {
            nums[k] = L[i];
            i += 1;
        }
        else
        {
            nums[k] = R[j];
            j += 1;
        }
    }
    printf("merge_sort %d :\n",count);
    print_nums(nums,10);
    count += 1;
}

void merge_sort(int *nums,int start,int end)
{
    if(start < end)
    {
        int q = (start + end ) /2;
        merge_sort(nums,start,q);
        merge_sort(nums,q+1,end);
        merge(nums,start,q,end);
    }
}








