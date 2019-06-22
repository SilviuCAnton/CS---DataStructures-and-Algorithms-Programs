#pragma once
#include <vector>
#include "ListNode.h"

class IteratorLI;
//LI.h

typedef int TElem;

class LI {
private:
	friend class IteratorLI;
	/* aici e reprezentarea */
	Node* elems;
	int capacity;
	int* next;
	int* prev;
	int head;
	int tail;
	int firstFreeSpot;

	// Complexitate ϴ(n)
	void initializeSpace(int position);

	// Complexitate ϴ(1)
	int alocatePosition();

	// Complexitate ϴ(1)
	void dealocatePosition(int position);

	// Complexitate ϴ(1)
	int createNode(TElem elem);

	// Complexitate ϴ(n)
	void resize();

public:
	// constructor implicit
	// Complexitate ϴ(n)
	LI();

	// returnare dimensiune
	// Complexitate ϴ(n)
	int dim() const;

	// verifica daca lista e vida
	// Complexitate ϴ(1)
	bool vida() const;

	// returnare element
	//arunca exceptie daca i nu e valid
	// Complexitate O(n)
	TElem element(int i) const;

	// modifica element de pe pozitia i si returneaza vechea valoare
	//arunca exceptie daca i nu e valid
	// Complexitate O(n)
	TElem modifica(int i, TElem e);

	// adaugare element la sfarsit
	// Complexitate ϴ(1)
	void adaugaSfarsit(TElem e);

	// adaugare element pe o pozitie i 
	//arunca exceptie daca i nu e valid
	// Complexitate O(n)
	void adauga(int i, TElem e);

	// sterge element de pe o pozitie i si returneaza elementul sters
	//arunca exceptie daca i nu e valid
	// Complexitate O(n)
	TElem sterge(int i);

	// cauta element si returneaza prima pozitie pe care apare (sau -1)
	// Complexitate O(n)
	int cauta(TElem e)  const;

	// returnare iterator
	// Complexitate ϴ(1)
	IteratorLI iterator() const;

	//sterge toate elementele din lista
	//Complexitate ϴ(n)
	int eliminaToate(const LI& lista);

	//destructor
	// Complexitate ϴ(1)
	~LI();

};