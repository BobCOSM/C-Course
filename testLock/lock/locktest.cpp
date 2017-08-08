#include "locktest.h"

pthread_mutex_t LockTest::mutex;
int LockTest::g_value = 0;
LockTest::LockTest(){
	if(pthread_mutex_init(&mutex,NULL) != 0){
		cout<<" init mutext error \n"<<endl;
	}
}

LockTest::~LockTest(){
	cout<<" ~LockTest "<<endl;
}

void LockTest::startLockTest(){
	if(pthread_create(&pthread_1,NULL,(void* (*)(void*))&funthread1,NULL) != 0){
		cout<<" create pthread_1 error ! "<<endl;
	}
	
	if(pthread_create(&pthread_2,NULL,(void* (*)(void*))&funthread2,NULL) != 0){
		cout<<" create pthread_2 error ! "<<endl;
	}
}
void LockTest::funthread1(void* msg){
	cout<< "funthread1 is running" <<endl;
	pthread_mutex_lock(&mutex);
	while(g_value < 500){
		cout<<"funthread1 g_value = "<<g_value++<<endl;
	}
	pthread_mutex_unlock(&mutex);
}

void LockTest::funthread2(void* msg){
	cout<< "funthread2 is running" <<endl;
	pthread_mutex_lock(&mutex);
	while(g_value < 1000){
		cout<<"funthread2 g_value = "<<g_value++<<endl;
	}
	pthread_mutex_unlock(&mutex);
}