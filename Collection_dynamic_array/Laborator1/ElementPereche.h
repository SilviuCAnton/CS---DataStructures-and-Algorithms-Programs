#pragma once

typedef int TElem;

class ElementPereche {
private:
	TElem elem;
	int frec;

public:
	//Constructor
	//Complexitate ϴ(1)
	ElementPereche();

	//Constructor2
	//Complexitate ϴ(1)
	ElementPereche(TElem, int);

	//setter element
	//Complexitate ϴ(1)
	void setElem(TElem);

	//setter frecventa
	//Complexitate ϴ(1)
	void setFrec(int);

	//getter element
	//Complexitate ϴ(1)
	TElem getElem() const;

	//getter frecventa
	//Complexitate ϴ(1)
	int getFrec() const;

	//operator ==
	//Complexitate ϴ(1)
	bool operator==(const ElementPereche&) const;
};