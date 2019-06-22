#include "IteratorMD.h"
#include "MD.h"
#include <stdexcept>

IteratorMD::IteratorMD(const MD& md) : md(md) {
	prim();
}

void IteratorMD::prim() {
	curNode = md.head;
}

bool IteratorMD::valid() const {
	if (curNode != nullptr)
		return true;
	return false;
}

TElem IteratorMD::element() const {
	if (valid())
		return curNode->getValue();
	else
		throw std::invalid_argument("Nu este valid!!");
}

void IteratorMD::urmator() {
	if (valid()) {
		curNode = curNode->getNext();
	}
	else
		throw std::invalid_argument("Nu este valid!!");
}