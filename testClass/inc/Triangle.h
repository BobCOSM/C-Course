#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "../inc/Shape.h"
#include "../inc/common.h"
//class Shape;
//typedef 
struct node ;
typedef node N_NODE;
class Triangle : public Shape{
	public :
		Triangle();
		virtual void show();
		virtual ~Triangle();
		N_NODE* getSNode();
};
#endif