#ifndef OPERATOR_H
#define OPERATOR_H

#include "RulePart.h"
#include <string>

using namespace std;

class Operator : public RulePart{
	public:
		virtual string toString() = 0;
};

#endif
