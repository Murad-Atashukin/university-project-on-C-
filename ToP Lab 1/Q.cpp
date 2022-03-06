#include "Q.h"

using namespace std;
Q::Q() { // Конструктор по умолчанию
	size = 0;
	tail = nullptr;
}


Q::Q(int data) { //Конструктор с параметром
	size = 1;
	tail = nullptr;
	tail = new Element{ data, tail };
}


void Q::push(int data) {	// Добавление в конец списка
	tail = new Element{ data, tail };
	size++;
}

int Q::GetSize() {
	return size;
}


int Q::pop() {	// Удаление элемента
	try {
		Element *iterator = tail;
		Element *prevElement = iterator;
		if (tail == nullptr) {
			throw (404);
		}
		while (iterator->pNext != nullptr) {
			prevElement = iterator;
			iterator = iterator->pNext;
		}
		prevElement->pNext = nullptr;
		int save = iterator->data;
		delete iterator;
		size--;
		if (size == 0)
			tail = nullptr;
		return save;
	}
	catch (int val) { cout << "Ошибка! Очередь пуста." << endl; }
}


void Q::Qprint() // Вывод очереди
{
	int i = size;
	int save = 0;
	while (i != 0) {
		save = this->pop();
		cout << save << " ";
		this->push(save);
		i--;
	}
	cout << endl;
}


Q*Q::copy()
{
	Q*queue = new Q();
	int i = this->size;
	int save = 0;
	while (i != 0) {
		save = this->pop();
		queue->push(save);
		this->push(save);
		i--;
	}
	return queue;
}


Q*Q::merge(Q *first, Q *second)
{
	Q* FirstQueue = first;
	Q*SecondQueue = second;
	int i = SecondQueue->size;
	while (i > 0) {
		int save = SecondQueue->pop();
		FirstQueue->push(save);
		i--;
	}
	FirstQueue->Qprint();
	delete SecondQueue;
	return FirstQueue;
}


Q::~Q() {	// Деструктор
	this->tail = nullptr;
	size = 0;
}