#include <stack>
#include <vector>
typedef int TValoare;
typedef int TCheie;
typedef std::pair<TCheie, std::vector<TValoare>> TElem;
class MDO;

class IteratorMDO {
private:
	friend class MDO;

	IteratorMDO(const MDO& mdo);

	const MDO& mdo;

	/* aici e reprezentarea specifica a iteratorului*/
	int current;
	std::stack<int> mdoStack;

public:

	//O(h - inaltimea arborelui binar)
	void prim();

	//O(h - inaltimea arborelui binar)
	void urmator();

	//ϴ(1)
	bool valid() const;

	//ϴ(1)
	TElem element() const;

};
