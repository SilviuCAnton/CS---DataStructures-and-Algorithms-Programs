#include "MD.h"
#include "IteratorMD.h"

MD::MD() {
	head = nullptr;
}

MD::~MD() {
	Node* p = head;
	Node* s;
	while (p != nullptr) {
		s = p->getNext();
		delete p;
		p = s;
	}
}

void MD::adauga(TCheie key, TValoare value) {
	TElem elem(key, value);
	if (head == nullptr) {
		head = new Node(elem, nullptr, nullptr);
	}
	else {
		Node* newNode = new Node(elem, nullptr, head);
		head->setPrev(newNode);
		head = newNode;
	}
}

vector<TValoare> MD::cauta(TCheie key) const {
	vector<TValoare> values;
	Node* p = head;
	while (p != nullptr) {
		if (p->getValue().first == key) {
			values.push_back(p->getValue().second);
		}
		p = p->getNext();
	}
	return values;
}

bool MD::sterge(TCheie key, TValoare value) {
	TElem elem(key, value);
	Node* p = head;
	bool isHead = false;
	while (p != nullptr) {
		if (p->getValue() == elem) {

			if (p->getPrev() != nullptr) {
				p->getPrev()->setNext(p->getNext());
			}

			if (p->getNext() != nullptr) {
				p->getNext()->setPrev(p->getPrev());
			}

			if (p == head)
			{
				if (p->getNext() != nullptr)
					head = p->getNext();
				else
					isHead = true;
			}
				
			delete p;

			if (isHead) {
				head = nullptr;
			}

			p = nullptr;
			return true;
		}
		p = p->getNext();
	}
	return false;
}

bool MD::sterge_valori(TCheie key) {
	Node* p = head;
	Node* next = nullptr;
	bool amSters = false;
	bool isHead = false;
	while (p != nullptr) {
		next = p->getNext();
		if (p->getValue().first == key) {

			if (p->getPrev() != nullptr) {
				p->getPrev()->setNext(p->getNext());
			}

			if (next != nullptr) {
				next->setPrev(p->getPrev());
			}

			if (p == head)
			{
				if (next != nullptr)
					head = next;
				else
					isHead = true;
			}

			delete p;
			p = nullptr;

			if (isHead) {
				head = nullptr;
			}

			amSters = true;
		}
		p = next;
	}
	return amSters;
}

int MD::dim() const {
	Node* p = head;
	int size = 0;
	while (p != nullptr) {
		size++;
		p = p->getNext();
	}
	return size;
}

bool MD::vid() const {
	return head == nullptr;
}

IteratorMD MD::iterator() const {
	return IteratorMD(*this);
}
