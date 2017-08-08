#include <stdio.h>
#include <pthread.h>

void funthread1(char* msg);
void funthread2(char* msg);

pthread_mutex_t mutext;
int flag = 2;
int g_value = 0;
int main(int argc,char* argv[]){
	pthread_t pthread1;
	pthread_t pthread2;
	
	int val = 0;
	if(pthread_mutex_init(&mutext,NULL) != 0){
		printf(" init mutext error \n");
	}
	if(pthread_create(&pthread1,NULL,(void*)funthread1,NULL)!=0){
		printf(" create pthread1 error \n ");
	}
	if(pthread_create(&pthread2,NULL,(void*)funthread2,NULL)!=0){
		printf(" create pthread2 error \n ");
	}
	sleep(1);
	printf("the end g_value = %d \n",g_value);
	return 0;
}

void funthread1(char* msg){
	
//	g_value = 0;
//	printf(" funthread1 locked init g_value = 0 and add 5 \n");
//	g_value += 5;
//	printf(" current g_value = %d \n",g_value);
//	pthread_mutex_unlock(&mutext);
//	printf(" funthread1 unlocked \n");
	
	int val;
	val = pthread_mutex_lock(&mutext);
	do{
		if(val != 0){
			printf(" locked error \n");
		}
		if(g_value < 500){
			printf("g_value = %d \n",g_value);
			g_value ++;
		} else {
			flag -= 1;
		}
	}while(flag!=0);
	pthread_mutex_unlock(&mutext);
}

void funthread2(char* msg){
	int val;
	val = pthread_mutex_lock(&mutext);
	do{
		if(val != 0){
			printf(" locked error \n");
		}
		if(g_value >= 500 && g_value < 1000){
			printf("g_value = %d \n",g_value);
			g_value ++;
		}else {
			flag -= 1;
		}
	}while(flag!=0);
	pthread_mutex_unlock(&mutext);
}