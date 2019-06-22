#pragma once
#include "ElementPereche.h"
class IteratorColectie;
typedef int TElem;

class Colectie {
private:
	/* aici e reprezentarea */
	ElementPereche* elems;
	int size;
	int capacity;
	void resize();
	friend class IteratorColectie;
public:
	//constructorul implicit
	//Complexitate ϴ(1)
	Colectie();

	//adauga un element in colectie
	//Complexitate O(n) amortizat
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	//Complexitate O(n)
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	//Complexitate O(n)
	bool cauta(TElem elem) const;

	//returneaza numar de aparitii ale unui element in colectie
	//Complexitate O(n)
	int nrAparitii(TElem elem) const;


	//intoarce numarul de elemente din colectie;
	//Complexitate ϴ(1)
	int dim() const;

	//verifica daca colectia e vida;
	//Complexitate ϴ(1)
	bool vida() const;

	//returneaza un iterator pe colectie
	//Complexitate ϴ(1)
	IteratorColectie iterator() const;

	// destructorul colectiei
	//Complexitate ϴ(1)
	~Colectie();

};