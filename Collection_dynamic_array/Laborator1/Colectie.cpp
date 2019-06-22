#include "IteratorColectie.h"
#include "Colectie.h"

Colectie::Colectie() {
	size = 0;
	capacity = 5;
	elems = new ElementPereche[capacity];
}

Colectie::~Colectie() {
	delete elems;
}

void Colectie::resize() {
	capacity *= 2;
	ElementPereche* newArray = new ElementPereche[capacity];
	for (int i = 0; i < size; i++) {
		newArray[i] = elems[i];
	}
	delete elems;
	elems = newArray;
}

void Colectie::adauga(TElem elem) {
	ElementPereche elNou(elem, 1);
	bool gasit = false;

	for (int i = 0; i < size; i++) {
		if (elems[i] == elNou) {
			elems[i].setFrec(elems[i].getFrec() + 1);
			gasit = true;
			break;
		}
	}
	
	if (!gasit) {
		if (size == capacity) {
			resize();
		}
		elems[size] = elNou;
		size++;
	}
}

bool Colectie::sterge(TElem elem) {
	ElementPereche elNou(elem, 1);
	int indiceElem = -1;

	for (int i = 0; i < size; i++) {
		if (elems[i] == elNou) {
			indiceElem = i;
			break;
		}
	}

	if (indiceElem >= 0) {
		if (elems[indiceElem].getFrec() > 1) {
			elems[indiceElem].setFrec(elems[indiceElem].getFrec() - 1);
		}
		else {
			elems[indiceElem] = elems[size - 1];
			size--;
		}
		return true;
	}
	return false;
}

bool Colectie::cauta(TElem elem) const{
	ElementPereche elNou(elem, 1);

	for (int i = 0; i < size; i++) {
		if (elems[i] == elNou) {
			return true;
		}
	}
	return false;
}

int Colectie::nrAparitii(TElem elem) const {
	ElementPereche elNou(elem, 1);

	for (int i = 0; i < size; i++) {
		if (elems[i] == elNou) {
			return elems[i].getFrec();
		}
	}
	return 0;
}

int Colectie::dim() const {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += elems[i].getFrec();
	}
	return sum;
}

bool Colectie::vida() const {
	return size == 0;
}

IteratorColectie Colectie::iterator() const {
	return IteratorColectie(*this);
}