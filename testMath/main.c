#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define HEART_SIZE 64
#if 0
void drawHeart()
{
    char y[128][128];
    int j = 0;
    for(j = 0;j < 128;j++)
    {
        int i = 0;
        for(i = 0; i<128;i++)
        {
            y[j][i] = '0';
        }
    }
    int tmp_y = 0;
    int x = 0;

    int i = -30;
    for(;i < HEART_SIZE; i++)
    {
        double a_1 = 0;
        if(i == 0)
        {
            a_1 = 1;
        }
        else
        {
            a_1 = sqrt(i*i -1);
        }
        double p_1 = pow(i*i,1/3.0);

        //printf("%d  sqrt: %f,pow: %f\n",i,a_1,p_1);
        if(i == 0)
        {
            tmp_y = a_1 + p_1 + 30;
        }
        else
        {
            tmp_y = a_1*(-1) + p_1 + 30;
        }
        printf("%d %d \n",i + 30 ,tmp_y);
        y[i + 30][tmp_y] = '*';
    }
    
    int m = 0;
    for(m = 0;m<128;m++)
    {
        int n = 0;
        for(n = 0;n<128;n++)
        {
            printf("%c",y[m][n]);
        }
        printf("\n");
    }
    
}

#endif

void drawHeart()
{
    char pic[128][128];
    int j = 0;
    for(j = 0;j < 128;j++)
    {
        int i = 0;
        for(i = 0; i<128;i++)
        {
            pic[j][i] = ' ';
        }
    }
    double theta = 0;
    int t_x = 100;
    int t_y = 100;
    for(theta = 0;theta <= 360; theta += 1)
    {
        double d;
        if(theta == 0)
        {
            d = 0;
        }
        else
        {
            d =  360 * 3.14/theta;
        }
        double row = 1 + cos(d);
        double x = row * cos(d);
        double y = row * sin(d);
        if(theta == 360)
        {
            row = 1;
            x = 1;
            y = 0;
        }
        t_x = x * 15;
        t_y = y * 30;
        pic[t_x + 20][t_y + 64] = '*';
        printf("%f %f %f\r\n",row,x,y);
        printf("%f %d %d\r\n",row,t_x + 64,t_y + 64);
    }
    int m = 0;
    for(m = 0;m < 128;m++)
    {
        int n = 0;
        for(n = 0;n < 128;n ++)
        {
            printf("%c",pic[m][n]);
        }
        printf("\n");
    }
}
int main()
{
    drawHeart();
}
