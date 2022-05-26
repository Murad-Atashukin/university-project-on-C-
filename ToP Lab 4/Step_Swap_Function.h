#ifndef _SWAP_H_
#define _SWAP_H_

#include "Library.h"

template<typename T>
void swap_elem_of_array(T* arr, int16_t size, int16_t step)
{
	T buf;

	for (int16_t i = 0; i < size - step; i++)
	{
		buf = arr[i];
		arr[i] = arr[i + step];
		arr[i + step] = buf;
	}
}

#endif // !_SWAP_H_

