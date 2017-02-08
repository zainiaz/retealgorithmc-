#ifndef ATOMO_H_INCLUDED
#define ATOMO_H_INCLUDED
#include <string>
#include <iostream>
#include "ParteRegla.h"

using namespace std;

class Atomo: public ParteRegla{
	public:
		Atomo(string, bool, bool);
		Atomo(Atomo&);
		string ToString();
		int GetHashCode();
		bool Equals(Atomo&);
		bool verIgualdad(Atomo&);
		bool verVerdad(Atomo&);

	public:
		bool estado;
		bool objetivo;
		string desc;

		string getDesc();
		bool getEstado();
		bool getObjetivo();

		void setDesc(string);
		void setEstado(bool);
		void setObjetivo(bool);
};

#endif
