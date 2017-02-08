#include "Operador.h"

string Negacion::toString(){
	return "!";
}

Binario::Binario(bool conj){
	this->conj = conj;
}

string Binario::toString(){
	return conj?"&":"|";
}
