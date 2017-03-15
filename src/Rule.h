#ifndef RULE_INCLUDED
#define RULE_INCLUDED

#include <vector>
#include <string>
#include <algorithm>
#include "WorkingMemory.h"
#include "RulePart.h"
#include "Atom.h"
#include "Operator.h"

using namespace std;

typedef vector<RulePart*>::iterator itr_rulepart;

class Rule{
	private:
		vector<RulePart*> *conditionalElements;
		vector<RulePart*> *conclusionElements;

		bool mark;
		bool triggered;
		bool target;
		bool isTarget();


	public:
		Rule(string);
		string toString() const;
		void analyze(string);
		bool testCondition(WorkingMemory&);
		bool trigger(WorkingMemory&);

};


#endif
