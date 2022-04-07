#ifndef _STACK_H_
#define _STACK_H_

#include "Library.h"

class Stack
{
private:
    double *data;
    int16_t size;

public:
    Stack(int16_t size);
    Stack(const Stack& object);
    ~Stack();

    void show();

    void operator=(const double value);
    void operator+=(const double value);
    void operator-=(const double value);

    friend std::ostream& operator<<(std::ostream& out, const Stack& object);
    friend Stack operator+(const Stack& object_1, const double value);
    friend Stack operator-(const Stack& object_1, const double value);
    friend Stack operator*(const Stack& object_1, const double value);
    friend Stack operator+(const double value, const Stack& object_2);
    friend Stack operator-(const double value, const Stack& object_2);
    friend Stack operator*(const double value, const Stack& object_2);


};

std::ostream& operator<<(std::ostream& out, const Stack& object);
Stack operator+(const Stack& object_1, const double value);
Stack operator-(const Stack& object_1, const double value);
Stack operator*(const Stack& object_1, const double value);
Stack operator+(const double value, const Stack& object_2);
Stack operator-(const double value, const Stack& object_2);
Stack operator*(const double value, const Stack& object_2);
#endif // !_STACK_H_