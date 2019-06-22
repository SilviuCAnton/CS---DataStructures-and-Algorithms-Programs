#pragma once
#include <vector>
using namespace std;
typedef int TElem;

class Node {
private:
	int index;
	TElem value;

public:
	static int nextIndex;
	//Constructor nod
	//Complexitate ϴ(1)
	Node(TElem, Node*, Node*, int index);

	Node() = default;

	Node(const Node& otherNode);

	//returneaza perechea cheieValoare
	//Complexitate ϴ(1)
	TElem getValue() const;

	//seteaza perechea cheieValoare
	//Complexitate ϴ(1)
	void setValue(TElem);

	//returneaza indexul nodului curent
	//Complexitate ϴ(1)
	int getIndex() const;

	//seteaza indexul nodului curent
	//Complexitate ϴ(1)
	void setIndex(int index);
};