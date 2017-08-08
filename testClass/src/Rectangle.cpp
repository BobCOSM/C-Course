
#include "../inc/Rectangle.h"
#include <iostream>
using namespace std;

Rectangle* Rectangle::mRect = NULL;

Rectangle::Rectangle(){
	cout<<" Rectangle"<<endl;
}

Rectangle* Rectangle::getInstance(){
	if(mRect == NULL){
		mRect = new Rectangle();
	}
	return mRect;
}

Rectangle::~Rectangle(){
	cout<<" ~Rectangle"<<endl;
}

void Rectangle::show(){
	cout<<" rectangle show"<<endl;
}