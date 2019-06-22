#include "Matrice.h"
#include <exception>
#include <random>
#include <iostream>
#include "IteratorMatrice.h"

int Matrice::hashFunction(int hashCode) const{
	return hashCode % capacity;
}

int Matrice::hashCode(int row, int col) const {
	return ((row + col) * (row + col + 1)) / 2 + col;
}

void Matrice::renewFirstOpen() {
	firstOpen++;
	while (firstOpen < capacity && items[firstOpen].first != -1) {
		firstOpen++;
	}
}

void Matrice::resizeAndRehash() {
	//throw std::exception("Depasire tabela");
	capacity *= 2;

	int* hashCodes = new int[capacity / 2];
	TElem* values = new TElem[capacity / 2];

	int* tempNext = new int[capacity];
	TPereche* tempItems = new TPereche[capacity];

	for (int i = 0; i < capacity/2; i++) {
		hashCodes[i] = items[i].first;
		values[i] = items[i].second;
		tempItems[i] = std::make_pair(-1, NULL_TELEMENT);
		tempNext[i] = -1;
	}

	for (int i = capacity / 2; i < capacity; i++) {
		tempItems[i] = std::make_pair(-1, NULL_TELEMENT);
		tempNext[i] = -1;
	}

	delete[] items;
	delete[] next;
	items = tempItems;
	next = tempNext;

	for (int i = 0; i < capacity/2; i++) {
		if (hashCodes[i] != -1) {
			addElement(hashFunction(hashCodes[i]), hashCodes[i], values[i]);
		}
	}
}

TElem Matrice::addElement(int pos, int posCode, TElem e)
{
	if (e == NULL_TELEMENT) {
		return NULL_TELEMENT;
	}
	if (firstOpen >= capacity) {
		resizeAndRehash();
	}
	pos = hashFunction(posCode);
	int prev;
	if (items[pos].first == -1) {
		items[pos].first = posCode;
		items[pos].second = e;

		if (pos == firstOpen) {
			renewFirstOpen();
		}
	}
	else {
		while (pos != -1 && posCode != items[pos].first) {
			prev = pos;
			pos = next[pos];
		}
		if (pos != -1) {
			throw std::exception("Cod deja existent!!!");
		}

		items[firstOpen].first = posCode;
		items[firstOpen].second = e;
		next[prev] = firstOpen;
		renewFirstOpen();
	}

	return NULL_TELEMENT;
}

TElem Matrice::removeElement(int hashCode) {
	int pos = hashFunction(hashCode);
	int prev = -1;
	while (items[pos].first != hashCode) {
		prev = pos;
		pos = next[pos];
	}
	TElem e = items[pos].second;
	if (prev == -1) {
		while (next[pos] != -1 && hashFunction(items[pos].first) == hashFunction(hashCode)) {
			prev = pos;
			items[pos].first = items[next[pos]].first;
			items[pos].second = items[next[pos]].second;
			pos = next[pos];
		}
		if (next[pos] != -1) {
			next[prev] = next[pos];
		}
		else {
			next[prev] = -1;
		}
	}
	else {
		if (next[pos] != -1) {
			next[prev] = next[pos];
		}
		else {
			next[prev] = -1;
		}
	}
	items[pos].first = -1;
	items[pos].second = NULL_TELEMENT;
	return e;
}

Matrice::Matrice(int rowCount, int colCount) : capacity{ 8 }, nRows{ rowCount }, nCols{ colCount } {
	if (rowCount <= 0 || colCount <= 0) {
		throw std::exception("Matricea nu poate avea mai putin de o linie si o colana");
	}
	items = new TPereche[capacity];
	next = new int[capacity];
	for (int i = 0; i < capacity; i++) {
		items[i] = std::make_pair(-1, NULL_TELEMENT);
		next[i] = -1;
	}
}

int Matrice::nrLinii() const {
	return nRows;
}

int Matrice::nrColoane() const {
	return nCols;
}

TElem Matrice::element(int i, int j) const {
	if (i >= nrLinii() || j >= nrColoane() || i < 0 || j < 0) {
		throw std::exception("Pozitie nevalida");
	}
	int posCode = hashCode(i, j);
	int pos = hashFunction(posCode);
	while (pos != -1 && items[pos].first != -1) {
		if (items[pos].first == posCode) {
			return items[pos].second;
		}
		pos = next[pos];
	}
	return NULL_TELEMENT;
}

TElem Matrice::modifica(int i, int j, TElem e) {
	//Verificare pozitie valida in matrice
	if (i >= nrLinii() || j >= nrColoane() || i < 0 || j < 0) {
		throw std::exception("Pozitie nevalida");
	}

	TElem el = NULL_TELEMENT;
	bool found = false;
	int posCode = hashCode(i, j);
	int pos = hashFunction(posCode);
	int k = pos;

	//Modificare element (utilizatorul modifica o pozitie ocupata de o valoare diferita de 0 intr-o valoare diferita de 0)
	while (k != -1 && items[k].first != -1) {
		if (items[k].first == posCode) {
			found = true;
			el = items[k].second;
			items[k].second = e;
			if (e != NULL_TELEMENT) {
				return el;
			}
			break;
		}
		k = next[k];
	}

	//Stergere element (utilizatorul modifica o pozitie ocupata de o valoare diferita de 0 in 0)
	if (found) {
		return removeElement(posCode);
	}

	//Adaugare element (utilizatorul modifica o pozitie ocupata de 0 intr-o valoare diferita de 0)
	return addElement(pos, posCode, e);
}

IteratorMatrice Matrice::iterator() const {
	return IteratorMatrice(*this);
}

Matrice::~Matrice() {
	delete[] items;
	delete[] next;
}
