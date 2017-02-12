#ifndef OPERADOR_H
#define OPERADOR_H

#include "ParteRegla.h"
#include <string>

using namespace std;

class Operador : ParteRegla{
public:
	virtual string toString()=0;
};

class Negacion : public Operador{
public:
	string toString() override;
};

class Binario : public Operador{
private:
	bool conj;
	
public:
	Binario(bool conj);
	string toString() override;
};

#endif
