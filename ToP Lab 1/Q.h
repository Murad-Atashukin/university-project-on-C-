#pragma once /*препроцессорна€ директива, 
разработанна€ дл€ контрол€ за тем, 
чтобы конкретный исходный файл при компил€ции подключалс€ строго один раз.*/
#include <iostream>
class Q {
public:
	void push(int data);
	int pop();
	Q();
	Q(int data);
	void Qprint();
	Q* copy();
	int GetSize();
	static Q*merge(Q* first, Q* second);
	~Q();
private:
	struct Element {
		int data;
		Element* pNext;
	};
	Element *tail = nullptr;
	int size = 0;
};