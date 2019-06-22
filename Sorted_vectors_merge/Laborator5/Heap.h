#pragma once
#include <functional>

template <typename T>
class Heap {
private:
	T* items;
	int size;
	int cap;

	std::function<bool(T, T)> rel;
	void heapifyDown();
	void heapifyUp();
	void resize();
public:
	Heap(std::function<bool(T, T)> relatie) : rel{ relatie }, size{ 0 }, cap{5} {
		items = new T[cap];
	}
	~Heap() {
		delete[] items;
	}

	void add(T elem);
	T remove();
	T first();
	bool empty();
};

//Complexitate O(log2(n))
template<typename T>
inline void Heap<T>::heapifyDown() {
	int index = 0;
	int nextIndex = 2 * index + 1;
	T temp = items[size - 1]; 

	while (nextIndex <= size - 1) {

		//Are fiu drept
		if (nextIndex < size - 1) {
			//Daca fiul drept e superior in relatie
			if (rel(items[nextIndex + 1], items[nextIndex])) {
				nextIndex++;
			}
		}

		//Daca am gasit pozitia potrivita -> break
		if (rel(temp, items[nextIndex])) {
			break;
		}
		else {
			items[index] = items[nextIndex];
			index = nextIndex;
			nextIndex = 2 * index + 1;
		}
	}

	items[index] = temp;
}

//Complexitate O(log2(n))
template<typename T>
inline void Heap<T>::heapifyUp() {
	int index = size - 1;
	T temp = items[index];
	while (!rel(items[(index - 1) / 2], temp) && index!= 0) {
		items[index] = items[(index - 1) / 2];
		index = (index - 1) / 2;
	}
	items[index] = temp;
}

//Complexitate ϴ(n)
template<typename T>
inline void Heap<T>::resize() {
	cap *= 2;
	T* temp = new T[cap];
	for (int i = 0; i < size; i++) {
		temp[i] = items[i];
	}
	delete[] items;
	items = temp;
}

//Complexitate O(log2(n)) amortizat
template<typename T>
inline void Heap<T>::add(T elem) {
	if (size == cap) {
		resize();
	}
	items[size++] = elem;
	heapifyUp();
}

//Complexitate O(log2(n))
template<typename T>
inline T Heap<T>::remove() {
	if (size == 0) {
		return T();
	}
	T first = items[0];
	heapifyDown();
	size--;
	return first;
}

//Complexitate ϴ(1)
template<typename T>
inline T Heap<T>::first() {
	if (size == 0) {
		return T();
	}
	return items[0];
}

//Complexitate ϴ(1)
template<typename T>
inline bool Heap<T>::empty() {
	return size == 0;
}
