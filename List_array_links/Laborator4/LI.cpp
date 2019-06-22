#include "LI.h"
#include "IteratorLI.h"
#include <exception>

int LI::alocatePosition() {
	int position{ firstFreeSpot };
	if (position != -1) {
		firstFreeSpot = next[firstFreeSpot];
	}
	return position;
}

void LI::dealocatePosition(int position) {
	next[position] = firstFreeSpot;
	firstFreeSpot = position;
}

void LI::resize() {
	Node* newElems = new Node[capacity * 2];
	int* newNext = new int[capacity * 2];
	int* newPrev = new int[capacity * 2];
	for (int i = 0; i < capacity; i++) {
		newElems[i] = elems[i];
		newNext[i] = next[i];
		newPrev[i] = prev[i];
	}
	capacity *= 2;
	delete[] elems;
	delete[] next;
	delete[] prev;
	elems = newElems;
	next = newNext;
	prev = newPrev;
	initializeSpace(capacity/2);
}

int LI::createNode(TElem elem) {
	int position;
	if (firstFreeSpot == -1) {
		resize();
	}
	position = alocatePosition();
	elems[position].setValue(elem);
	next[position] = -1;
	prev[position] = -1;
	return position;
}

void LI::initializeSpace(int position) {
	for (int i = position; i < capacity - 1; i++) {
		next[i] = i + 1;
		prev[i + 1] = i;
	}
	next[capacity - 1] = -1;
	prev[position] = position - 1;
	firstFreeSpot = position;
}

LI::LI() : capacity{ 5 }, firstFreeSpot{ 0 } {
	elems = new Node[capacity];
	next = new int[capacity];
	prev = new int[capacity];
	initializeSpace(0);
	head = -1;
	tail = -1;
}

LI::~LI() {
	delete[] elems;
	delete[] next;
	delete[] prev;
}

void LI::adauga(int i, TElem elem) {
	if (i != 0 && tail == -1) 
		throw std::invalid_argument("Indicele este invalid!");
	
	if (i > elems[tail].getIndex() + 1)
		throw std::invalid_argument("Indicele este invalid!");

	if (i < 0) {
		throw std::invalid_argument("Indicele este invalid!");
	}

	if (i == elems[tail].getIndex() + 1)
		adaugaSfarsit(elem);

	else {

		if (head == -1) {
			head = createNode(elem);
			elems[head].setIndex(i);
			tail = head;
		}

		else {
			int position = head;
			while (position != -1 && elems[position].getIndex() != i) {
				position = next[position];
			}

			int newNodePosition = createNode(elem);
			elems[newNodePosition].setIndex(i);

			if (prev[position] != -1) {
				prev[newNodePosition] = prev[position];
				next[newNodePosition] = position;
				next[prev[position]] = newNodePosition;
			}

			else {
				head = newNodePosition;
				prev[newNodePosition] = -1;
				next[newNodePosition] = position;
			}

			prev[position] = newNodePosition;

			while (position != -1) {
				elems[position].setIndex(elems[position].getIndex() + 1);
				position = next[position];
			}
		}
	}
}

TElem LI::modifica(int i, TElem e)
{
	if (tail == -1)
		throw std::invalid_argument("Lista este vida!");

	if (i > elems[tail].getIndex() + 1)
		throw std::invalid_argument("Indicele este invalid!");

	if (i < 0) {
		throw std::invalid_argument("Indicele este invalid!");
	}

	int position = head;
	while (position != -1 && elems[position].getIndex() < i) {
		position = next[position];
	}

	TElem value = elems[position].getValue();
	elems[position].setValue(e);
	return value;
}

void LI::adaugaSfarsit(TElem elem) {
	int positionToAddTo = createNode(elem);;
	if (head == -1) {
		head = positionToAddTo;
		tail = head;
		elems[head].setIndex(0);
	}
	else {
		prev[positionToAddTo] = tail;
		next[tail] = positionToAddTo;
		elems[positionToAddTo].setIndex(elems[tail].getIndex() + 1);
		tail = positionToAddTo;
	}
}

int LI::cauta(TElem elem) const {
	int position = head;
	while (position != -1) {
		if (elems[position].getValue() == elem) {
			return elems[position].getIndex();
		}
		position = next[position];
	}
	return -1;
}

 TElem LI::sterge(int index) {
	TElem elem;
	int position = head;
	bool isHead = false;
	while (position != -1) {
		if (elems[position].getIndex() == index) {
			elem = elems[position].getValue();

			if (prev[position] != -1) {
				next[prev[position]] = next[position];
			}

			if (next[position] != -1) {
				prev[next[position]] = prev[position];
			}

			if (position == head)
			{
				if (next[position] != -1)
					head = next[position];
				else
					isHead = true;
			}

			if (position == tail) {
				tail = prev[position];
			}

			dealocatePosition(position);

			if (isHead) {
				head = -1;
			}

			return elem;
		}
		position = next[position];
	}
	throw std::invalid_argument("Index invalid!!!");
}

 int LI::eliminaToate(const LI& lista) {
	 int numarElemente{ 0 };
	 int position = head;
	 while (position != -1) {
		 int nextPoz = next[position];
		 if (lista.cauta(elems[position].getValue()) > -1) {
			 sterge(elems[position].getIndex());
			 numarElemente++;
		 }
		 position = nextPoz;
	 }
	 return numarElemente;
 }

int LI::dim() const {
	int len{ 0 };
	int position = head;
	while (position != -1) {
		len++;
		position = next[position];
	}
	return len;
}

bool LI::vida() const {
	return head == -1;
}

TElem LI::element(int i) const
{
	if (tail == -1)
		throw std::invalid_argument("Lista este vida!");

	if (i > elems[tail].getIndex() + 1)
		throw std::invalid_argument("Indicele este invalid!");

	if (i < 0) {
		throw std::invalid_argument("Indicele este invalid!");
	}

	int position = head;
	while (position != -1 && elems[position].getIndex() < i) {
		position = next[position];
	}

	return elems[position].getValue();
}

IteratorLI LI::iterator() const {
	return IteratorLI(*this);
}