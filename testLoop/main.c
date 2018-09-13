#include "./inc/loopfor.h"

int nums[] = {9,3,5,1,2,0,4,7,6,8};

int main()
{
    int i = 0;
    printnnt();
    random_sort_nums(nums,10);
    bubble_sort(nums,10);
    random_sort_nums(nums,10);
    select_sort(nums,10);
    random_sort_nums(nums,10);
    insert_sort(nums,10);
    random_sort_nums(nums,10);
    merge_sort(nums,0,9);
    printf("merge_sort :");
    for(;i<10;i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");
    return 0;
}
