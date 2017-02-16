#ifndef NEGATION_H_INCLUDED
#define NEGATION_H_INCLUDED
#include "Operator.h"
#include <string>

class Negation : public Operator{
	public:
		Negation(){};
		~Negation(){};
		string toString() override;
};

#endif
