#ifndef WORKING_MEMORY_H
#define WORKING_MEMORY_H

#include <vector>
#include <string>
#include "Atom.h"

using namespace std;
typedef vector<Atom>::iterator itr_vector;

class WorkingMemory{

private:
	vector<Atom> *negated;
	vector<Atom> *affirmed;
	itr_vector search(itr_vector, itr_vector, const Atom&) const;

public:
	WorkingMemory();
	~WorkingMemory();
	void addAtom(const Atom& atm);
	bool verifyPresence(const Atom& atm) const;
	bool verifyAffirmed(const Atom& atm) const;
	bool verifyNegated(const Atom& atm) const;
	Atom* returnAtom(const Atom& atm) const;
	string toString()const; 
};

#endif
