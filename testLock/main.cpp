#include <iostream>
using namespace std;

#include "lock/locktest.h"

int main(int argc, char* argv[]){
	cout<<"hello world"<<endl;
	
//	LockTest *lt = new LockTest();
	LockTest lt;
	lt.startLockTest();
	char ch;
	cin >> ch;
//	delete lt;
	return 0;	
}
