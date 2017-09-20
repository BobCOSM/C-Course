#include "../inc/Rectangle.h"
#include "../inc/Triangle.h"

#include <iostream>
using namespace std;

int main(int args,char* argv[]){
	Rectangle *r = Rectangle::getInstance();
	r->show();
	delete r;
	Triangle *t = new Triangle();
	t->show();
	delete t;
	if(0){
		#define IST_HELLO "hello"
	}
	#if defined(IST_HELLO)
		cout<<IST_HELLO<<" " << args<<endl;
	#endif
	#if defined(IST_10003_86S)
		cout<< " defined IST_10003_86S "<<endl;
	#else
		cout<<" haven't defined IST_10003_86S "<<endl;
	#endif
	return 0;
}

