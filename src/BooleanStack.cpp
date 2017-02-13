#include <iostream>
#include "PilaBooleana.h"

using namespace std;

PilaBooleana::PilaBooleana(){
	;
}

void PilaBooleana::anular(){
	datos.clear();
}

bool PilaBooleana::vacia(){
	return (bool)datos.empty();
}

bool PilaBooleana::top(){
	if(this->vacia()) return false;
	else return (bool)datos.at(datos.size() - 1);
}

bool PilaBooleana::pop(){
	if(!this->vacia()) {
		bool tmp = datos.at(datos.size() - 1);
		datos.pop_back();
		return tmp;
	}
	
	else return false;
}

void PilaBooleana::push(bool valor){
	datos.push_back(valor);
}

int PilaBooleana::size(){
	return datos.size();
}
