#ifndef BINARY_H_INCLUDED
#define BINARY_H_INCLUDED
#include "Binary.h"
#include "Operator.h"
#include <string>

class Binary : public Operator {
	private:
		bool conj;
	
	public:
		Binary(bool conj);
		~Binary(){};
		string toString() override;
		bool isConjuction();
};

#endif
