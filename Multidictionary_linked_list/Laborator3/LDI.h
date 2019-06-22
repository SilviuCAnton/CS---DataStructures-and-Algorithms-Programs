#pragma once
#include <vector>
using namespace std;
typedef int TCheie;
typedef int TValoare;

typedef pair<TCheie, TValoare> TElem;

class Node {
private:
	TElem value;
	Node* prev;
	Node* next;

public:
	//Constructor nod
	//Complexitate ϴ(1)
	Node(TElem, Node*, Node*);

	//returneaza perechea cheieValoare
	//Complexitate ϴ(1)
	TElem getValue() const;

	//seteaza perechea cheieValoare
	//Complexitate ϴ(1)
	void setValue(TElem);

	//returneaza adresa nodului anterior
	//Complexitate ϴ(1)
	Node* getPrev() const;

	//returneaza adresa nodului urmator
	//Complexitate ϴ(1)
	Node* getNext() const;

	//seteaza adresa nodului anterior
	//Complexitate ϴ(1)
	void setPrev(Node*);

	//seteaza adresa nodului urmator
	//Complexitate ϴ(1)
	void setNext(Node*);
};