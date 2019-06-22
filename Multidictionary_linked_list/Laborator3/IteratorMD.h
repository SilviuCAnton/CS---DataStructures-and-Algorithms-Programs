#pragma once
#include "LDI.h"
class MD;
typedef int TCheie;
typedef int TValoare;

typedef pair<TCheie, TValoare> TElem;

class IteratorMD {
private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	//Complexitate ϴ(1)
	IteratorMD(const MD& md);

	//contine o referinta catre containerul pe care il itereaza
	const MD& md;

	//functie iterator din colectie are acces la constructor
	friend class MD;

	/* aici e reprezentarea specifica a iteratorului*/
	Node* curNode;

public:

	//reseteaza pozitia iteratorului la inceputul containerului
	//Complexitate ϴ(1)
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	//Complexitate ϴ(1)
	void urmator();

	//verifica daca iteratorul e valid (indica un element al containerului)
	//Complexitate ϴ(1)
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	//Complexitate ϴ(1)
	TElem element() const;
};