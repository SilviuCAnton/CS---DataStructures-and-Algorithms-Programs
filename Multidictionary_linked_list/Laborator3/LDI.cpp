#include "LDI.h"

Node::Node(TElem keyValuePair, Node* prev, Node* next) {
	this->prev = prev;
	this->next = next;
	value = keyValuePair;
}

TElem Node::getValue() const {
	return value;
}

Node* Node::getPrev() const {
	return prev;
}

Node* Node::getNext() const {
	return next;
}

void Node::setValue(TElem keyValuePair) {
	value = keyValuePair;
}

void Node::setNext(Node* next) {
	this->next = next;
}

void Node::setPrev(Node* prev) {
	this->prev = prev;
}