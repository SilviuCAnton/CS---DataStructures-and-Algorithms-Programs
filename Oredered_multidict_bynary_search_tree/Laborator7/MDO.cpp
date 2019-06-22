#include "MDO.h"
#include "IteratorMDO.h"
#include <algorithm>

void MDO::resize() {
	capacity *= 2;
	TElem* tempItems = new TElem[capacity];
	int* tempLeft = new int[capacity];
	int* tempRight = new int[capacity];
	for (int i = 0; i < capacity/2; i++) {
		tempItems[i] = items[i];
		tempLeft[i] = leftChild[i];
		tempRight[i] = rightChild[i];
	}
	delete[] items;
	delete[] rightChild;
	delete[] leftChild;
	items = tempItems;
	rightChild = tempRight;
	leftChild = tempLeft;
	initializeSpace(capacity / 2);
}

void MDO::initializeSpace(int position) {
	for (int i = position; i < capacity - 1; i++) {
		leftChild[i] = i + 1;
		rightChild[i] = -1;
	}
	leftChild[capacity - 1] = -1;
	rightChild[capacity - 1] = -1;
	firstOpenSpace = position;
}

int MDO::recursiveDim(const int root) const {
	if (root == -1) {
		return 0;
	}
	return items[root].second.size() + recursiveDim(leftChild[root]) + recursiveDim(rightChild[root]);
}

int MDO::recursiveDel(int root, TCheie key) {
	if (root == -1) {
		return -1;
	}

	//Stergem din subarborele stang
	if (rel(key, items[root].first) && items[root].first != key) {
		leftChild[root] = recursiveDel(leftChild[root], key);
		return root;
	}

	//Stergem din subarborele drept
	else if (!rel(key, items[root].first) && items[root].first != key) {
		rightChild[root] = recursiveDel(rightChild[root], key);
		return root;
	}

	//Am ajuns la nodul de sters
	else {
		int temp, repl;
		//Daca avem atat subarbore stang cat si drept
		if (leftChild[root] != -1 && rightChild[root] != -1) {
			temp = minimum(rightChild[root]);
			items[root] = items[temp];

			rightChild[root] = recursiveDel(rightChild[root], items[root].first);
			return root;
		}
		else {
			temp = root;
			if (leftChild[root] == -1) {
				repl = rightChild[root];
			}
			else {
				repl = leftChild[root];
			}
			leftChild[temp] = firstOpenSpace;
			rightChild[temp] = -1;
			firstOpenSpace = temp;
			return repl;
		}
	}
}

int MDO::minimum(int root) {
	while (leftChild[root] != -1) {
		root = leftChild[root];
	}
	return root;
}

MDO::MDO(Relatie r) : rel{ r }, capacity{ 10 }, root{ -1 } {
	items = new TElem[capacity];
	leftChild = new int[capacity];
	rightChild = new int[capacity];
	initializeSpace(0);
}

void MDO::adauga(TCheie c, TValoare v) {
	//Cautam in dictionar cheia
	int pos{ root };
	bool gasit{ false };
	bool nextLeft;
	if (pos > -1) {
		while (true) {
			if (items[pos].first == c) {
				gasit = true;
				items[pos].second.push_back(v);
				break;
			}
			if (rel(c, items[pos].first)) {
				if (leftChild[pos] == -1) {
					nextLeft = true;
					break;
				}
				else {
					pos = leftChild[pos];
				}
			}
			else {
				if (rightChild[pos] == -1) {
					nextLeft = false;
					break;
				}
				else {
					pos = rightChild[pos];
				}
			}
		}
	}
	
	//Daca nu exista deja cheia in dictionar, atunci adaugam un nou nod in arbore
	if (root == -1) {
		std::vector<TValoare> values;

		if (firstOpenSpace == -1) {
			resize();
		}
		root = firstOpenSpace;
		firstOpenSpace = leftChild[firstOpenSpace];

		values.push_back(v);
		items[root] = std::make_pair(c, values);
		leftChild[root] = -1;
		rightChild[root] = -1;
	}
	else if (!gasit) {
		std::vector<TValoare> values;

		if (firstOpenSpace == -1) {
			resize();
		}
		int open{ firstOpenSpace };
		firstOpenSpace = leftChild[firstOpenSpace];

		values.push_back(v);
		items[open] = std::make_pair(c, values);
		leftChild[open] = -1;
		rightChild[open] = -1;

		if (nextLeft == true) {
			leftChild[pos] = open;
		}
		else {
			rightChild[pos] = open;
		}
	}
}

std::vector<TValoare> MDO::cauta(TCheie c) const {
	int pos{ root };
	while (pos != -1) {
		if (items[pos].first == c) {
			return items[pos].second;
		}
		if (rel(c, items[pos].first)) {
			pos = leftChild[pos];
		}
		else {
			pos = rightChild[pos];
		}
	}
	return std::vector<TValoare>();
}

bool MDO::sterge(TCheie c, TValoare v) {
	//Cautam cheia in dictionar
	int pos{ root };
	bool gasit{ false };
	while (pos != -1) {
		if (items[pos].first == c) {
			gasit = true;
			break;
		}
		if (rel(c, items[pos].first)) {
			pos = leftChild[pos];
		}
		else {
			pos = rightChild[pos];
		}
	}

	//Daca nu a fost gasita -> returnam false
	if (!gasit) {
		return false;
	}

	//Daca gasim valoarea o stergem, altfel returnam false
	auto it = std::find(items[pos].second.begin(), items[pos].second.end(), v);
	if (it == items[pos].second.end()) {
		return false;
	}

	//Daca dimensiunea vectorului de valori este mai mare decat 1, atunci putem sterge doar valoarea
	if (items[pos].second.size() > 1) {
		items[pos].second.erase(it);
	}

	//Altfel, trebuie sa stergem nodul din arbore
	else {
		root = recursiveDel(root, c);
	}

	return true;
}

int MDO::dim() const {
	return recursiveDim(root);
}

bool MDO::vid() const {
	return root == -1;
}

IteratorMDO MDO::iterator() const
{
	return IteratorMDO(*this);
}

int MDO::adaugaInexistente(MDO & mdo) {
	int nr = 0;
	IteratorMDO it = mdo.iterator();
	while (it.valid()) {
		TElem elem = it.element();
		std::vector<TValoare> values = cauta(elem.first);
		for (const auto& valoare : elem.second) {
			if (std::find(values.begin(), values.end(), valoare) == values.end()) {
				adauga(elem.first, valoare);
				nr++;
			}
		}
		it.urmator();
	}
	return nr;
}

MDO::~MDO() {
	delete[] items;
	delete[] leftChild;
	delete[] rightChild;
}
