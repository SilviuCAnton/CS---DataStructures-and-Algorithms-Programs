#include <utility>
typedef int TElem;
typedef std::pair<int, TElem> TPereche;

class IteratorMatrice;

#define NULL_TELEMENT 0

class Matrice {
private:
	friend class IteratorMatrice;

	/* aici e reprezentarea */
	int nRows, nCols;
	int capacity;
	int* next;
	TPereche* items;
	int firstOpen;

	// functie hashing - returneaza o valoarea intre 0 si capacity-1
	int hashFunction(int hashCode) const;
	int hashCode(int row, int col) const;

	void renewFirstOpen();
	void resizeAndRehash();
	TElem addElement(int pos, int posCode, TElem e);
	TElem removeElement(int hashCode);

public:
	// constructor
	//arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	Matrice(int rowCount, int colCount);

	// returnare numar linii
	//ϴ(1)
	int nrLinii() const;

	// returnare numar coloane
	//ϴ(1)
	int nrColoane() const;

	// returnare element de pe o linie si o coloana
	//arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii ii consideram de la 0
	//O(1)
	TElem element(int i, int j) const;

	// modifica elementul de pe o linie si o coloana si returneaza vechea valoare
	//arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	//O(1)
	TElem modifica(int i, int j, TElem e);

	//ϴ(1)
	IteratorMatrice iterator() const;

	// destructor
	~Matrice();
};
