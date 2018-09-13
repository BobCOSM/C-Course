#include "fibo.h"

#define RECU_ENABLE 0


#if RECU_ENABLE
//////////////////////////////
//递归方式
int fibo(int n) //n从1开始
{
	int res = 0;
	if(n <= 2)
	{
		res = 1;
	}
	else
	{
		res = fibo(n - 1) + fibo(n - 2);
	}
	printf("------------------> f %d : %d\r\n",n,res);
	return res;
}

int fibo_sum(int n)
{
	if(n <= 2)
	{
		return n;
	}
	return fibo_sum(n - 1) + fibo(n);
}

//
///////////////////////////////

#else
/////////////////////////////////
//

int fibo(int n)
{
	int i = 1;
	int res = 0;
	int res_tmp = 0;
	for(i = 1;i <= n ; i ++)
	{
		if(i <= 2)
		{
			res = 1;
			res_tmp = 1;
		}
		else
		{
			res += res_tmp;	//此时 res 是f(n - 1) res_tmp 是 f(n - 2)，运算完成后 res是 f(n)
			res_tmp = res - res_tmp;	//此时 f(n) - f(n - 2) = f(n - 1),用res_tmp记录f(n-1)的值；用于下一次循环计算;
		}
		printf(" -------------- > %d : %d\r\n",i,res);
	}
	return res;
}

int fibo_sum(int n)
{
	int i = 1;
	int sum = 0;
	int res = 0;
	int res_tmp = 0;
	for(i = 1; i <= n; i++)
	{
		if(i <= 2)
		{
			res = 1;
			res_tmp = 1;
		}
		else
		{
			res += res_tmp;	//此时 res 是f(n - 1) res_tmp 是 f(n - 2)，运算完成后 res是 f(n)
			res_tmp = res - res_tmp;	//此时 f(n) - f(n - 2) = f(n - 1),用res_tmp记录f(n-1)的值；用于下一次循环计算;
		}
		sum += res;
	}
	return sum;
}

//
/////////////////////////////////////
#endif
