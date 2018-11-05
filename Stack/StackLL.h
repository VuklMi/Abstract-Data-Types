#ifndef STACKLL_H
#define STACKLL_H

#include "List.h"

template<typename T>
class Stack {
private: 
	List<T> list;
public: 
	bool empty() const;
	T top() const;
	void push(T const &);
	T pop();
	void display() const;
};

//**************** IMPLEMENTATION******************//

template<typename T>
T Stack<T>::top() const {
	return list.front();
}

template<typename T>
T Stack<T>::pop() {
	return list.pop_front();
}

template<typename T>
void Stack<T>::push(T const &n) {
	return list.push_front(n);
}

template<typename T>
bool Stack<T>::empty() const {
	return list.empty();
}

template<typename T>
void Stack<T>::display() const {
	list.displayList();
}
#endif