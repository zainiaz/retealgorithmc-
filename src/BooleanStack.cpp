#include "BooleanStack.h"

using namespace std;

BooleanStack::BooleanStack(){
	;
}

void BooleanStack::clear(){
	data.clear();
}

bool BooleanStack::empty(){
	return data.empty();
}

bool BooleanStack::top(){
	if(this->empty()) return false;
	else return data.at(data.size() - 1);
}

bool BooleanStack::pop(){
	if(!this->empty()) {
		bool tmp = data.at(data.size() - 1);
		data.pop_back();
		return tmp;
	}
	
	else return false;
}

void BooleanStack::push(bool value){
	data.push_back(value);
}

int BooleanStack::size(){
	return data.size();
}
