#include "Q3.h"
int Q3::fun()
{
	int size = GetSize();	// получение размера очереди
	int* arr = new int[size];	// выделение памяти под массив
	int i = 0;
	for (i = 0; i < size; i++) {
		int save = pop();	// вытаскивание элемента из очереди
		arr[i] = save;		// запись элемента в массив
		this->push(save);	// запись элемента в конец очереди
	}

	int max = arr[0], min = arr[0], result;	// инициализация переменных подсчета
	for (i = 0; i < size; i++) {	// цикл поиска максимального элемента массива
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	for (i = 0; i < size; i++) {	// цикл поиска минимального элемента массива
		if (min > arr[i]) {
			min = arr[i];
		}
	}

	result = max - min;				// подсчет результата
	delete[] arr;					// удаление выделенной памяти
	return result;
}

void Q3::push(int data) {
	Q::push(data);
}

int Q3::pop() {
	return Q::pop();
}

void Q3::show() {
	Q::Qprint();
}

Q* Q3::copy() {
	return Q::copy();
}

int Q3::GetSize() {
	return Q::GetSize();
}

Q* Q3::merge(Q* first, Q* second) {
	return Q::merge(first, second);
}