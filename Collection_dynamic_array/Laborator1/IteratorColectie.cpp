#include "IteratorColectie.h"
#include "Colectie.h"
#include <stdexcept>

IteratorColectie::IteratorColectie(const Colectie& c) : c(c) {
	prim();
}

void IteratorColectie::prim() {
	curentPoz = 0;
	curentFrec = 1;
}

bool IteratorColectie::valid() const{
	if (curentPoz < c.size && curentFrec <= c.elems[curentPoz].getFrec())
		return true;
	return false;
}

TElem IteratorColectie::element() const {
	if (valid())
		return c.elems[curentPoz].getElem();
	else
		throw std::invalid_argument("Nu este valid!!");
}

void IteratorColectie::urmator() {
	if (valid()) {
		if (curentFrec < c.elems[curentPoz].getFrec()) {
			curentFrec += 1;
		}
		else {
			curentPoz += 1;
			curentFrec = 1;
		}
	}
	else
		throw std::invalid_argument("Nu este valid!!");
}