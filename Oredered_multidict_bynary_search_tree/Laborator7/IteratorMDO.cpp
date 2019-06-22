#include "IteratorMDO.h"
#include "MDO.h"

IteratorMDO::IteratorMDO(const MDO& mdo) : mdo{ mdo } {
	if (mdo.root != -1) {
		prim();
	}
	else {
		current = mdo.root;
	}
}

void IteratorMDO::prim() {
	while (mdoStack.size() > 0) {
		mdoStack.pop();
	}
	current = mdo.root;
	while (current != -1) {
		mdoStack.push(current);
		current = mdo.leftChild[current];
	}
	if (mdo.root != -1) {
		current = mdoStack.top();
		mdoStack.pop();
	}
}

void IteratorMDO::urmator() {
	current = mdo.rightChild[current];
	while (current != -1) {
		mdoStack.push(current);
		current = mdo.leftChild[current];
	}
	if (mdoStack.size() > 0) {
		current = mdoStack.top();
		mdoStack.pop();
	}
}

bool IteratorMDO::valid() const {
	return current != -1 || mdoStack.size() != 0;
}

TElem IteratorMDO::element() const {
	return mdo.items[current];
}
