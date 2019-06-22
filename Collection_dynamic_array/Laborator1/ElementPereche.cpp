#include "ElementPereche.h"

ElementPereche::ElementPereche() {
	this->elem = 0;
	this->frec = 1;
}

ElementPereche::ElementPereche(TElem elem, int frec) {
	this->elem = elem;
	this->frec = frec;
}

void ElementPereche::setElem(TElem elem) {
	this->elem = elem;
}

void ElementPereche::setFrec(int frec) {
	this->frec = frec;
}

TElem ElementPereche::getElem() const {
	return this->elem;
}

int ElementPereche::getFrec() const {
	return this->frec;
}

bool ElementPereche::operator==(const ElementPereche &other) const{
	return elem == other.getElem();
}