#include "TestScurt.h"
#include "TestExtins.h"
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

int main() {
	testAll();
	testAllExtins();
	_CrtDumpMemoryLeaks();
	return 0;
}