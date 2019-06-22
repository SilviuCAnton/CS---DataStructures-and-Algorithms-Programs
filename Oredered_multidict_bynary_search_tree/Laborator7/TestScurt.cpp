#include <assert.h>

#include "MDO.h"
#include "IteratorMDO.h"

#include <exception>
#include <vector>

using namespace std;

bool relatie1(TCheie cheie1, TCheie cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll() {
	MDO dictOrd = MDO(relatie1);
	MDO dict2 = MDO(relatie1);
	assert(dictOrd.dim() == 0);
	assert(dictOrd.vid());

	dictOrd.adauga(5, 5);
	dictOrd.adauga(2, 2);
	dictOrd.adauga(6, 6);
	dictOrd.adauga(8, 8);
	dictOrd.adauga(1, 1);
	dictOrd.adauga(0, 0);
	dictOrd.adauga(4, 4);
	assert(dictOrd.dim() == 7);

	dict2.adauga(5, 5);
	dict2.adauga(2, 2);
	dict2.adauga(6, 6);
	dict2.adauga(8, 8);
	assert(dict2.dim() == 4);
	assert(dict2.adaugaInexistente(dictOrd)==3);
	assert(dict2.dim() == 7);

	IteratorMDO myit = dictOrd.iterator();
	assert(myit.element().first == 0);
	myit.urmator();
	assert(myit.element().first == 1);
	myit.urmator();
	assert(myit.element().first == 2);
	myit.urmator();
	assert(myit.element().first == 4);
	myit.urmator();
	assert(myit.element().first == 5);
	myit.urmator();
	assert(myit.element().first == 6);
	myit.urmator();
	assert(myit.element().first == 8);

	assert(dictOrd.cauta(4).front() == 4);

	dictOrd.sterge(1, 1);
	dictOrd.sterge(8, 8);
	dictOrd.sterge(2, 2);
	dictOrd.sterge(0, 0);
	dictOrd.sterge(4, 4);
	dictOrd.sterge(5, 5);
	dictOrd.sterge(6, 6);
	assert(dictOrd.vid());

	dictOrd.adauga(1, 2);
	dictOrd.adauga(1, 3);
	assert(dictOrd.dim() == 2);
	assert(!dictOrd.vid());
	vector<TValoare> v = dictOrd.cauta(1);
	assert(v.size() == 2);
	v = dictOrd.cauta(3);
	assert(v.size() == 0);
	IteratorMDO it = dictOrd.iterator();
	it.prim();
	while (it.valid()) {
		TElem e = it.element();
		it.urmator();
	}
	assert(dictOrd.sterge(1, 2) == true);
	assert(dictOrd.sterge(1, 3) == true);
	assert(dictOrd.sterge(2, 1) == false);
	assert(dictOrd.vid());
}