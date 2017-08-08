#ifndef __LOCKTEST_H__
#define __LOCKTEST_H__

#include <iostream>
using namespace std;

#include <pthread.h>
class LockTest{
private:
	pthread_t pthread_1;
	pthread_t pthread_2;
	static pthread_mutex_t mutex;
	static int g_value;
private:
	static void funthread1(void* msg);
	static void funthread2(void* msg);
public:
	LockTest();
	void startLockTest();
	virtual ~LockTest();
};

#endif