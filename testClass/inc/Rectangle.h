#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "../inc/Shape.h"
#include "../inc/common.h"

typedef struct node{
	int data;
	node* next;
}S_NODE;


class Rectangle : public Shape
{
	private:
		Rectangle();
		static Rectangle* mRect;
	public:
		static Rectangle* getInstance();
		virtual void show();
		virtual ~Rectangle();
};

#endif
