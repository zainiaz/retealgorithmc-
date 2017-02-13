#ifndef ATOM_H_INCLUDED
#define ATOM_H_INCLUDED
#include <string>
#include <iostream>
#include "RulePart.h"

using namespace std;

class Atom: public RulePart{
	public:
		Atom(string, bool, bool);
		Atom(const Atomo&);

		string toString() override;
		
		bool seeEquality(const Atomo&)const;
		bool seeTruth(const Atomo&)const;
		bool operator == (const Atomo&)const;
		
		string getDesc()const;
		bool getState()const;
		bool getGoal()const;
		
		void setDesc(string);
		void setState(bool);
		void setGoal(bool);

	private:
		bool state; 
		bool goal;
		string desc;
};

#endif
