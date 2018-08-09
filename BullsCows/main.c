#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

void random_answer(char *dest,int size)
{
    srand((int)time(NULL));
    int i = 0;
    for(i = 0;i < size; i++)
    {
        int rand_num = rand();
        dest[i] = '0' + rand_num %10;
    }
//    dest[0] = '4';
//    dest[1] = '6';
//    dest[2] = '3';
//    dest[3] = '3';
//    printf("dest : %s\n",dest);
}

BOOL get_option(char *dest,char *src,int size)
{
    int count_a = 0;
    int count_b = 0;
    int i = 0;
    int compar_flag = 0;
    for(i= 0 ;i < size;i++)
    {
        if(dest[i] == src[i])
        {
            if(compar_flag & (0x01<<i))
            {
                count_b -= 1;
            }
            count_a += 1;
            compar_flag |= 0x01 << i;
        }
        else
        {
            int j = 0;
            for(j = 0; j<size; j++)
            {
                if(src[i] == dest[j] && src[j] != dest[j])
                {
                    if(compar_flag & (0x01 << j))
                    {
                        continue;
                    }
                    count_b += 1;
                    compar_flag |= 0x01 << j;
                    break;
                }
            }
        }
    }
    printf("A%dB%d\n",count_a,count_b);
    if(count_a == 4)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int main()
{
    char dest[5] = {0};
    char src[5] = {0};
    random_answer(dest,4);
    BOOL res = FALSE;
    do{
        printf("please input your answer :");
        int i = 0;
        for(i = 0;i<4;i++)
        {
            src[i] = getchar();
        }
        getchar();
        printf("src : %s\n",src);
        res = get_option(dest,src,4);
    }while(!res);
    printf("YOU WIN !!!!\n");
    return 0;
}
