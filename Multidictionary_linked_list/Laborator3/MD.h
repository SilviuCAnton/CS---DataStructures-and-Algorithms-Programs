#pragma once
#include <vector>
#include "LDI.h"
using namespace std;

class IteratorMD;
typedef int TCheie;
typedef int TValoare;

typedef pair<TCheie, TValoare> TElem;

class MD {

private:
	/* aici e reprezentarea */
	Node* head;
public:

	friend class IteratorMD;

	// constructorul implicit al MultiDictionarului
	//Complexitate ϴ(1)
	MD();

	// adauga o pereche (cheie, valoare) in MD	
	//Complexitate ϴ(1)
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	//Complexitate ϴ(n)
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	//Complexitate O(n)
	bool sterge(TCheie c, TValoare v);

	//sterge toate valorile pentru o cheie
	//returneaza adevarat daca s-a gasit cheia si valorile s-au stres
	//Complexitate ϴ(n)
	bool sterge_valori(TCheie key);

	//returneaza numarul de perechi (cheie, valoare) din MD 
	//Complexitate ϴ(n)
	int dim() const;

	//verifica daca MultiDictionarul e vid 
	//Complexitate ϴ(1)
	bool vid() const;

	// se returneaza iterator pe MD
	//Complexitate ϴ(1)
	IteratorMD iterator() const;

	// destructorul MultiDictionarului	
	//Complexitate ϴ(n)
	~MD();



};