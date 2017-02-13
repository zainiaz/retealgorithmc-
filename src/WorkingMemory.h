#ifndef WORKING_MEMORY_H
#define WORKING_MEMORY_H

#include <vector>
#include <string>
#include "Atom.h"

using namespace std;
typedef vector<Atom>::iterator iterator_v;

class WorkingMemory{

private:
	vector<Atom> *negated;
	vector<Atom> *affirmed;
	iterator_v search(iterator_v, iterator_v, const Atom&) const;

public:
	WorkingMemory();
	~WorkingMemory();
	void saveAtom(const Atom& atm);
	bool verifyPresence(const Atom& atm) const;
	bool verifyAffirmed(const Atom& atm) const;
	bool verifyNegated(const Atom& atm) const;
	Atom* returnAtom(const Atom& atm) const;
	string toString()const; 
};

#endif
