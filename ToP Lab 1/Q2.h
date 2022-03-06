#pragma once
#include "Q.h"
class Q2 :
	protected Q
{
public:
	void push(int data);
	int pop();
	void show();
	Q* copy();
	int GetSize();
	static Q* merge(Q* first, Q* second);
	int fun();
};

