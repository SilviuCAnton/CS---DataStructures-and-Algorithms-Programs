#include "IteratorMatrice.h"
#include "Matrice.h"
#include <exception>


IteratorMatrice::IteratorMatrice(const Matrice & m) : m{ m } {
	prim();
}

void IteratorMatrice::prim() {
	linie = 0;
	coloana = 0;
	while (valid() && m.element(linie, coloana) == NULL_TELEMENT) {
		if (linie < m.nrLinii() - 1) {
			linie++;
		}
		else {
			coloana++;
			linie = 0;
		}
	}
}

void IteratorMatrice::urmator() {
	if (!valid()) {
		throw std::exception();
	}
	if (linie < m.nrLinii() - 1) {
		linie++;
	}
	else {
		coloana++;
		linie = 0;
	}
	while (valid() && m.element(linie, coloana) == NULL_TELEMENT) {
		if (linie < m.nrLinii() - 1) {
			linie++;
		}
		else {
			coloana++;
			linie = 0;
		}
	}
}

bool IteratorMatrice::valid() const {
	return linie < m.nrLinii() && coloana < m.nrColoane();
}

TElem IteratorMatrice::element() const {
	if (!valid()) {
		throw std::exception();
	}
	return m.element(linie, coloana);
}


