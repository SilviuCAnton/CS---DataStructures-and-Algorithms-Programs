#include <vector>

typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, std::vector<TValoare>> TElem;

typedef bool(*Relatie)(TCheie, TCheie);

class IteratorMDO;

class MDO {

private:
	friend class IteratorMDO;

	/* aici e reprezentarea */
	Relatie rel;
	TElem* items;
	int* leftChild;
	int* rightChild;
	int capacity;
	int firstOpenSpace;
	int root;

	void resize();
	void initializeSpace(int position);
	int recursiveDim(const int root) const;
	int recursiveDel(int root, TCheie key);
	int minimum(int root);

public:

	// constructorul implicit al MultiDictionarului Ordonat
	MDO(Relatie r);

	// adauga o pereche (cheie, valoare) in MDO
	// O(h - inaltimea arborelui binar)
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	// O(h - inaltimea arborelui binar)
	std::vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	// O(n - nr noduri)
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MDO 
	// ϴ(n - nr chei)
	int dim() const;

	//verifica daca MultiDictionarul Ordonat e vid 
	// ϴ(1)
	bool vid() const;

	// se returneaza iterator pe MDO
	// iteratorul va returna perechile ordine dupa relatia de ordine
	// ϴ(1)
	IteratorMDO iterator() const;

	int adaugaInexistente(MDO& mdo);

	// destructorul 	
	~MDO();



};