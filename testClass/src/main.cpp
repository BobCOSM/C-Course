#include "../inc/Rectangle.h"
#include "../inc/Triangle.h"

int main(int args,char* argv[]){
	Rectangle *r = Rectangle::getInstance();
	r->show();
	delete r;
	Triangle *t = new Triangle();
	t->show();
	delete t;
	return 0;
}

