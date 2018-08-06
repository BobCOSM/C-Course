#ifndef __SHAPE_H__
#define __SHAPE_H__
#include <iostream>

using namespace std;

class Shape{
public:
	Shape();
    virtual void show(){ cout << "shape show " <<endl;};
	virtual ~Shape();
};

#endif
