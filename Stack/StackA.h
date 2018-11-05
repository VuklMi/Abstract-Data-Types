#ifndef STACKA_H
#define STACKA_H

#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class StackA {
private:
	int stack_size;
	int array_capacity;
	T *array;
	class underflow {

	};
public:
	StackA(int = 10);
	~StackA();
	bool empty() const;
	T top() const;
	void push(T const &);
	T pop();
	void double_capacity();
	void display() const;
	int capacity() const;
	int size() const;
};

//************************ IMPLEMENTATION ***************************//

// constructor
template<typename T>
StackA<T>::StackA(int n)
	:stack_size(0),
	array_capacity(std::max(1, n)), // if user sends number less then 1, initialize capacity to 1
	array(new T[array_capacity]) {
	// empty constructor
}

// destructor
template<typename T>
StackA<T>::~StackA() {
	delete[] array;
}

template<typename T>
bool StackA<T>::empty() const {
	return (!stack_size); // if stack_size is 0, returns true => means it's empty
}

template<typename T>
T StackA<T>::top() const {
	if (empty()) {
		throw underflow();
	}
	return array[stack_size - 1];
}

template<typename T>
T StackA<T>::pop() {
	if (empty()) {
		throw underflow();
}
	--stack_size;
	return array[stack_size];
}

template<typename T>
void StackA<T>::push(T const &obj) {
	if (stack_size == array_capacity) {
		double_capacity();
	}
	array[stack_size] = obj;
	++stack_size;
}

template<typename T>
void StackA<T>::double_capacity() {
	T *tmp_array = new T[2 * array_capacity];
	for (int i = 0; i < array_capacity; i++) {
		tmp_array[i] = array[i];
	}
	delete [] array;
	array = tmp_array;
	array_capacity *= 2;
}

template<typename T>
void StackA<T>::display() const {
	for (int i = 0; i < stack_size; i++) {
		cout << array[i] << " ";
	}
}

template<typename T>
int StackA<T>::capacity() const {
	return array_capacity;
}

template<typename T>
int StackA<T>::size() const {
	return stack_size;
}

#endif
