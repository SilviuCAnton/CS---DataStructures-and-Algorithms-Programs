#pragma once
class Colectie;
typedef int TElem;

class IteratorColectie {
private:
	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	//Complexitate ϴ(1)
	IteratorColectie(const Colectie& c);

	//contine o referinta catre containerul pe care il itereaza
	const Colectie& c;

	//functie iterator din colectie are acces la constructor
	friend class Colectie;

	/* aici e reprezentarea specifica a iteratorului*/
	int curentPoz;
	int curentFrec;

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
