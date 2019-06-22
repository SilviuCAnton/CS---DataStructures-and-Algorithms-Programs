#include "TestScurt.h"
#include <assert.h>
#include "Matrice.h"
#include <iostream>
#include "IteratorMatrice.h"

using namespace std;

void testAll() { //apelam fiecare functie sa vedem daca exista
	Matrice m(4, 4);
	assert(m.nrLinii() == 4);
	assert(m.nrColoane() == 4);
	//adaug niste elemente
	m.modifica(1, 1, 5);
	assert(m.element(1, 1) == 5);
	m.modifica(1, 1, 6);
	assert(m.element(1, 2) == NULL_TELEMENT);
	m.modifica(1, 2, 5);
	IteratorMatrice it = m.iterator();
	assert(it.element() == 6);
	it.urmator();
	assert(it.element() == 5);
	it.urmator();
	try {
		it.element();
		assert(false);
	}
	catch (std::exception) {
		assert(true);
	}
}