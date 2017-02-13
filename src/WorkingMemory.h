#ifndef MEMORIATRABAJO_H
#define MEMORIATRABAJO_H

#include <vector>
#include <string>

#include "Atomo.h"

using namespace std;
typedef vector<Atomo>::iterator iterador;

class MemoriaTrabajo{

private:
	vector<Atomo> *negados;
	vector<Atomo> *afirmados;
	iterador busca(iterador, iterador, const Atomo&) const;

public:
	MemoriaTrabajo();
	~MemoriaTrabajo();
	void guardaAtomo(const Atomo& atm);
	bool presente(const Atomo& atm) const;
	bool fueAfirmado(const Atomo& atm) const;
	bool fueNegado(const Atomo& atm) const;
	Atomo* recupera(const Atomo& atm) const;
	string toString()const; 
};

#endif
