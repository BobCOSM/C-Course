#include "fibo.h"

#define RECU_ENABLE 0


#if RECU_ENABLE
//////////////////////////////
//�ݹ鷽ʽ
int fibo(int n) //n��1��ʼ
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
			res += res_tmp;	//��ʱ res ��f(n - 1) res_tmp �� f(n - 2)��������ɺ� res�� f(n)
			res_tmp = res - res_tmp;	//��ʱ f(n) - f(n - 2) = f(n - 1),��res_tmp��¼f(n-1)��ֵ��������һ��ѭ������;
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
			res += res_tmp;	//��ʱ res ��f(n - 1) res_tmp �� f(n - 2)��������ɺ� res�� f(n)
			res_tmp = res - res_tmp;	//��ʱ f(n) - f(n - 2) = f(n - 1),��res_tmp��¼f(n-1)��ֵ��������һ��ѭ������;
		}
		sum += res;
	}
	return sum;
}

//
/////////////////////////////////////
#endif
