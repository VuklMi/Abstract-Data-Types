#ifndef QUEUELL_H
#define QUEUELL_H

#include "List.h"

template<typename T>
class Queue {
private: 
	List<T> list;
	class underflow {

	};
public: 
	bool empty() const;
	T front() const;
	void push(T const &);
	T pop();
	void display() const;
};

//************************ IMPLEMENTATION ***************************//

template<typename T>
bool Queue<T>::empty() const {
	return list.empty();
}

template<typename T>
T Queue<T>::front() const {
	if (empty()) {
		throw underflow();
	}
	return list.front();
}

template<typename T>
void Queue<T>::push(T const &obj) {
	list.push_back(obj);
}

template<typename T>
T Queue<T>::pop() {
	if (empty()) {
		throw underflow();
	}
	return list.pop_front();
}

template<typename T>
void Queue<T>::display() const {
	list.displayList();
}

#endif