#include "Problema2.h"
#include "Heap.h"

//Complexitate O(nlog2(n))
vector<TElem> interclaseazaVectori(vector<vector<TElem>> vectoriDeIntrare, Relatie rel) {

	Heap<pair<TElem, int>> myHeap{ [&rel](pair<TElem, int> x, pair<TElem, int> y) {return rel(x.first, y.first);} };
	vector<TElem> result;
	vector<int> curPoz;
	curPoz.resize(vectoriDeIntrare.size());
	for (auto& item : curPoz) {
		item = 0;
	}

	//Initializare cu primele elemente de la toti vectorii
	for (unsigned int i = 0; i < vectoriDeIntrare.size(); i++) {
		if (vectoriDeIntrare[i].size() > 0) {
			myHeap.add(std::make_pair(vectoriDeIntrare[i][0], i));
		}
	}
	
	while (!myHeap.empty()) {
		pair<TElem, int> toPush = myHeap.remove();
		if (curPoz[toPush.second] < vectoriDeIntrare[toPush.second].size() - 1) {
			curPoz[toPush.second]++;
			auto toAdd = std::make_pair(vectoriDeIntrare[toPush.second][curPoz[toPush.second]], toPush.second);
			myHeap.add(toAdd);
		}
		result.push_back(toPush.first);
	}
	return result;
}
