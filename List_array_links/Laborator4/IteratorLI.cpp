#include "IteratorLI.h"
#include <stdexcept>
#include "LI.h"

IteratorLI::IteratorLI(const LI& li) : li{ li } {
	prim();
}

void IteratorLI::prim() {
	curNode = li.head;
}

bool IteratorLI::valid() const {
	if (curNode != -1)
		return true;
	return false;
}

TElem IteratorLI::element() const {
	if (valid())
		return li.elems[curNode].getValue();
	else
		throw std::invalid_argument("Nu este valid!!");
}

void IteratorLI::urmator() {
	if (valid()) {
		curNode = li.next[curNode];
	}
	else
		throw std::invalid_argument("Nu este valid!!");
}