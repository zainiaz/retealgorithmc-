#include "Binary.h"

Binary::Binary(bool conj){
	this->conj = conj;
}

string Binary::toString() {
	return conj?"&":"|";
}
