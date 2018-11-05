#ifndef DEQUEUE_H
#define DEQUEUE_H

#include "List.h"

template<typename T>
class Dequeue {
private: 
	List<T> list;
	class underflow {

	};
public: 
	bool empty() const;
	T front() const;
	T back() const;
	void push_front(T const &);
	void push_back(T const &);
	T pop_front();
	T pop_back();
	void display() const;
};

//************************ IMPLEMENTATION ***************************//

template<typename T>
bool Dequeue<T>::empty() const {
	return list.empty();
}

template<typename T>
T Dequeue<T>::front() const {
	if (empty()) {
		throw underflow();
	}
	return list.front();
}

template<typename T>
T Dequeue<T>::back() const {
	if (empty()) {
		throw underflow();
	}
	return list.back();
}

template<typename T>
void Dequeue<T>::push_front(T const &obj) {
	list.push_front(obj);
}

template<typename T>
void Dequeue<T>::push_back(T const &obj) {
	list.push_back(obj);
}

template<typename T>
T Dequeue<T>::pop_front() {
	if (empty()) {
		throw underflow();
	}
	return list.pop_front();
}

template<typename T>
T Dequeue<T>::pop_back() {
	if (empty()) {
		throw underflow();
	}
	return list.pop_back();
}

template<typename T>
void Dequeue<T>::display() const {
	list.displayList();
}

#endif
