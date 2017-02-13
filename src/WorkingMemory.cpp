#include "WorkingMemory.h"
#include <algorithm>

WorkingMemory::WorkingMemory(){
	affirmed = new vector<Atom>();
	negated = new vector<Atom>();
}

WorkingMemory::~WorkingMemory(){
	delete affirmed;
	delete negated;
}

void WorkingMemory::saveAtom(const Atom& atm){
	if(!verifyNegated(atm) && !verifyAffirmed(atm))
	{
		if(atm.getState())
			affirmed -> push_back(atm);
		else
			negated -> push_back(atm);
	}
}

bool WorkingMemory::verifyPresence(const Atom& atm) const{
	return (verifyNegated(atm) || verifyAffirmed(atm));
}

iterator_vector WorkingMemory::search(iterator_vector begin, iterator_vector end,const Atom& atm)const{
	return find(begin,end,atm);
}

bool WorkingMemory::verifyAffirmed(const Atom& atm)const{
	return search(affirmed->begin(),affirmed->end(),atm) != affirmed->end();
}

bool WorkingMemory::verifyNegated(const Atom& atm)const{
	return search(negated->begin(),negated->end(),atm) != negated->end();
}

Atom* WorkingMemory::returnAtom(const Atom& atm)const{
	iterator_vector itA, itN;
	
	itA = search(affirmed->begin(),affirmed->end(),atm);
	itN = search(negated->begin(),negated->end(),atm);
	
	if(itA != affirmed->end()) 
		return new Atom(*itA);	

	if(itN != negated->end()) 
		return new Atom(*itN);

	return NULL;
}

string WorkingMemory::toString()const{
	string ret_var = "\nWorking memory\nAffirmed: [ ";
	iterator_vector it;
	
	it = affirmed->begin();
	while(it != affirmed->end()){
		ret_var += (*it).toString()+" ";
		it++;
	}

	ret_var = ret_var+"]\nNegated: [ ";

	it = negated->begin();
	while(it != negated->end()){
		ret_var += (*it).toString()+" ";
		it++;
	}
	return ret_var+"]";
}
