#include <iostream>
#include <string>
#include "Atom.h"

using namespace std;

Atom::Atom(const Atom &other){
	desc = other.desc;
	state = other.state;
	goal = other.goal;
}

Atom::Atom(string desc, bool state, bool goal){
	this->desc = desc;
	this->state = state;
	this->goal = goal;
}

string Atom::getDesc()const{
	return desc;
}

void Atom::setDesc(string desc){
	this->desc = desc;
}

bool Atom::getState()const{
	return state;
}

void Atom::setState(bool state){
	this->state = state;
}

bool Atom::getGoal()const{
	return goal;
}

void Atom::setGoal(bool goal){
	this->goal = goal;
}

string Atom::toString(){
	return string(state?"":"!") + string(goal?"*":"") + desc;
} 

bool Atom::seeEquality(const Atom& atm)const{
	return !desc.compare(atm.getDesc());
}

bool Atom::seeTruth(const Atom& atm)const{
	return state && atm.getState();
}

bool Atom::operator == (const Atom& atm)const{
	return !desc.compare(atm.desc) && (state == atm.state);
}
