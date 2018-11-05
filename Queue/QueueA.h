#ifndef QUEUEA_H
#define QUEUEA_H

#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
class QueueA {
private:
	T *array;
	int queue_size;
	int ifront;		// indexof the front entry
	int iback;		// index of the back entry
	int array_capacity;
	class underflow {

	};
	class overflow {

	};
public:
	QueueA(int = 10);
	~QueueA();
	bool empty() const;
	T front() const;
	void push(T const &);
	T pop();
	//void double_capacity();
	void display() const;
};

//************************ IMPLEMENTATION ***************************//

// constructor
template<typename T>
QueueA<T>::QueueA(int n)
	:queue_size(0),
	iback(-1), // index of the first element
	ifront(0), // index of the last element
	array_capacity(std::max(1, n)), // if user sends number less then 1, initialize capacity to 1 (if user sends nothing, capacity = 10)
	array(new T[array_capacity]) {
	// empty constructor
}

// destructor
template<typename T>
QueueA<T>::~QueueA() {
	delete[] array;
}

template<typename T>
bool QueueA<T>::empty() const {
	return (!queue_size); // if queue_size is 0, returns true => means it's empty
}

template<typename T>
T QueueA<T>::front() const {
	if (empty()) {
		throw underflow();
	}
	return array[ifront];
}

template<typename T>
T QueueA<T>::pop() {
	if (empty()) {
		throw underflow();
	}
	--queue_size;
	++ifront;
	return array[ifront-1];
}

template<typename T>
void QueueA<T>::push(T const &obj) {
	if (queue_size == array_capacity) {
		throw overflow();
		//double_capacity();
	}
	iback = ++iback % array_capacity;
	array[iback] = obj;
	++queue_size;
}

/*template<typename T>
void QueueA<T>::double_capacity() {
	T *tmp_array = new T[2 * array_capacity];
	for (int i = 0; i < array_capacity; i++) {
		tmp_array[i] = array[i];
	}
	delete [] array;
	array = tmp_array;
	array_capacity *= 2;
}*/

template<typename T>
void QueueA<T>::display() const {
	for (int i = ifront; i <= queue_size; i++) {
		cout << array[i] << " ";
	}
	cout << endl << "iback: " << iback << endl;
	cout << "queue_size: " << queue_size << endl;
	if(iback != queue_size) {
		for(int i = iback; i > 0; i--) {
			cout << array[i];
		}
	}
}

#endif
