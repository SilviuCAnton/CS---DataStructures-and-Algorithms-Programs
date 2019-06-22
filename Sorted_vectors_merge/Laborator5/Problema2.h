#pragma once
#include <vector>

using namespace std;

typedef int TElem;
typedef bool(*Relatie) (TElem e1, TElem e2);

vector<TElem> interclaseazaVectori(vector<vector<TElem>> vectoriDeIntrare, Relatie rel);