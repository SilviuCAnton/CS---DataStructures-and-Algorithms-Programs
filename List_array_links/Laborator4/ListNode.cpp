#include "ListNode.h"

int Node::nextIndex{ 0 };

Node::Node(TElem value, Node* prev, Node* next, int index) : value{ value }, index{ index } {
}

Node::Node(const Node& otherNode) : value{ otherNode.value }, index{ otherNode.index } {
}

TElem Node::getValue() const {
	return value;
}

void Node::setValue(TElem keyValuePair) {
	value = keyValuePair;
}

int Node::getIndex() const {
	return index;
}

void Node::setIndex(int index) {
	this->index = index;
}