#include "Heap.h"
#include "TestProblema2.h"
#include <iostream>
#include <assert.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


int main() {
	{	
		Heap<int> myHeap([](int x, int y) {
			return x <= y; });

		myHeap.add(0);
		myHeap.add(2);
		myHeap.add(3);
		myHeap.add(1);
		myHeap.add(8);
		assert(myHeap.first() == 0);
		assert(myHeap.remove() == 0);
		assert(myHeap.first() == 1);
		assert(myHeap.remove() == 1);
		assert(myHeap.first() == 2);
		assert(myHeap.remove() == 2);
		assert(myHeap.first() == 3);
		assert(myHeap.remove() == 3);
		assert(myHeap.first() == 8);
		assert(myHeap.remove() == 8);
		assert(myHeap.first() == int());
		assert(myHeap.remove() == int());

		testProblema2();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}