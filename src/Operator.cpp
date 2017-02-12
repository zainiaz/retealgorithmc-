#include "Operator.h"

string Not::toString(){
	return "!";
}

Binary::Binary(bool conj){
	this->conj = conj;
}

string Binary::toString(){
	return conj?"&":"|";
}
