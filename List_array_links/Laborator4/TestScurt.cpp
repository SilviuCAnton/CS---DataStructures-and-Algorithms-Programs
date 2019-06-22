#include <assert.h>
#include <exception>

#include "TestScurt.h"
#include "LI.h"
#include "IteratorLI.h"




void testAll() {
	LI lista = LI();
	LI lista2 = LI();
	
	lista2.adaugaSfarsit(1);
	lista2.adaugaSfarsit(2);
	lista2.adaugaSfarsit(3);
	lista2.adaugaSfarsit(4);
	lista2.adaugaSfarsit(5);

	lista.adaugaSfarsit(1);
	lista.adaugaSfarsit(2);
	lista.adaugaSfarsit(3);
	lista.adaugaSfarsit(4);
	lista.adaugaSfarsit(5);

	assert(lista.eliminaToate(lista2) == 5);
	assert(lista.eliminaToate(lista2) == 0);

	assert(lista.vida());
	lista.adaugaSfarsit(1);
	assert(lista.dim() == 1);
	lista.adauga(0, 2);
	assert(lista.dim() == 2);
	IteratorLI it = lista.iterator();
	assert(it.valid());
	it.urmator();
	assert(it.element() == 1);
	it.prim();
	assert(it.element() == 2);
	assert(lista.cauta(1) == 1);
	assert(lista.modifica(1, 3) == 1);
	assert(lista.element(1) == 3);
	assert(lista.sterge(0) == 2);
	assert(lista.dim() == 1);
}