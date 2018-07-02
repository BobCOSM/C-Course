#include "loopfor.h"

int nums[] = {9,3,5,1,2,0,4,7,6,8};

int main()
{
    printnnt();
    random_sort_nums(nums,10);
    bubble_sort(nums,10);
    random_sort_nums(nums,10);
    select_sort(nums,10);
    return 0;
}
