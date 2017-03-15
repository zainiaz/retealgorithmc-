#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include "Rule.h"
#include "BooleanStack.h"
#include "Atom.h"
#include "WorkingMemory.h"
#include "Negation.h"
#include "Operator.h"
#include "Binary.h"
#include "RulePart.h"
using namespace std;

Rule::Rule(string rule_as_string){
	this->mark = false;
	this->triggered = false;
	this->target = false;

	conditionalElements = new vector<RulePart*>();
	conclusionElements = new vector<RulePart*>();
	analyze(rule_as_string);
}

string Rule::toString() const{
	string ret_string = "IF ";
	itr_rulepart itr;

	itr = conditionalElements->begin();

	while(itr != conditionalElements->end()){
		ret_string += (*itr)->toString() + " ";
		itr++;
	}

	ret_string += "THEN ";

	itr = conclusionElements->begin();

	while(itr != conclusionElements->end()){
		ret_string += (*itr)->toString() + " ";
		itr++;
	}

	return ret_string;
}

//This method tests the conditions. Returns TRUE if it can triggers
bool Rule::testCondition(WorkingMemory &wm){
	BooleanStack *bool_stack = new BooleanStack();
	Atom* memory_atom = NULL;
	bool aux_bool_1 = false, aux_bool_2 = false;

	itr_rulepart it;

	it = conditionalElements->begin();

	while(it != conditionalElements->end()){
		if((*it)->toString().compare(string("!")) == 0){
	
			aux_bool_1 = bool_stack->pop();
			bool_stack->push(!aux_bool_1);
		}
		else if((*it)->toString().compare(string("|")) == 0 ){
			aux_bool_1 = bool_stack->pop();
			aux_bool_2 = bool_stack->pop();
			
			bool_stack->push(aux_bool_1 ||  aux_bool_2);
		}
		else if( (*it)->toString().compare(string("&")) == 0 ){
			aux_bool_1 = bool_stack->pop();
			aux_bool_2 = bool_stack->pop();

			bool_stack->push(aux_bool_1 &&  aux_bool_2);
		}
		else{
			memory_atom = new Atom( *((Atom*)*it) ) ;

			if( wm.verifyPresence(*memory_atom) ){
				bool_stack->push(
					memory_atom->seeTruth((*(Atom*)memory_atom))
					);
			}
		}

		it++;
	}

	return bool_stack->pop();
}

//If testCondition return TRUE, trigger the rule
bool Rule::trigger(WorkingMemory& wm){
	Atom* temp_atom = NULL;
	bool target_arrived = false;
	this->triggered = true;
	vector<Atom> *atoms = new vector<Atom>();

	itr_rulepart it;

	it = conclusionElements->begin();

	while(it != conclusionElements->end()){
		if((*it)->toString().compare(string("!")) == 0){
			temp_atom->setState( !temp_atom->getState() );
		}
		
		else{
			temp_atom = new Atom( *((Atom*)*it) );
			atoms->push_back( *temp_atom );
			if( temp_atom -> getGoal() ) target_arrived = true;
		}

		it++;
	}

	vector<Atom>::iterator itr = atoms->begin();

	while(itr != atoms->end()){
		wm.addAtom( *new Atom( ((Atom)*itr) ) );
		itr++;
	}

	return target_arrived;
}

bool Rule::isTarget(){
	return this->target;
}

void Rule::analyze(string str){
	vector<string> *parts = new vector<string>();
	string token;
	size_t token_pos;

	bool rule = false, condition = false, conclusion = false, atom = false, target = false;
	RulePart * rp = NULL;
	
	vector<string>::iterator itr;

	while( (token_pos = str.find(" ")) != string::npos ){
		token = str.substr( 0 , token_pos );
		parts->push_back(token); 
		str.erase(0, token_pos + 1 );
	}
	parts->push_back(str);

	itr = parts->begin();

	while(itr != parts->end()){
		if((*itr).compare(string("<atom>")) == 0){
			atom = true;
			target = false;
		}
		else if((*itr).compare(string("</atom>")) == 0){
			atom = false;
			target = false;
		}
		else if((*itr).compare(string("<targetAtom>")) == 0){
			atom = true;
			target = true;
			this->target = true;
		}
		else if((*itr).compare(string("</targetAtom>")) == 0){
			atom = false;
			target = false;
		}
		else if((*itr).compare(string("<conditional>")) == 0){
			condition = true;
		}
		else if((*itr).compare(string("</conditional>")) == 0){
			condition = false;
		}
		else if((*itr).compare(string("<conclusion>")) == 0){
			conclusion = true;
		}
		else if((*itr).compare(string("</conclusion>")) == 0){
			conclusion = false;
		}
		else if((*itr).compare(string("<negation/>")) == 0){
			//Negation
			if(condition&&!conclusion) conditionalElements->push_back( new Negation() );
			if(conclusion&&!condition) conclusionElements->push_back( new Negation() );
		}
		else if((*itr).compare(string("<conjunction/>")) == 0){
			//Conjunction
			if(condition&&!conclusion) conditionalElements->push_back( new Binary(true) );
			if(conclusion&&!condition) conclusionElements->push_back( new Binary(true) );
		}
		else if((*itr).compare(string("<disjunction/>")) == 0){
			//Disjunction
			if(condition&&!conclusion) conditionalElements->push_back( new Binary(false) );
		}
		else {
			if(atom){
				//Atom
				if(condition&&!conclusion&&!target) conditionalElements->push_back( new Atom(string(*itr), true, target) );
				if(conclusion&&!condition) conclusionElements->push_back( new Atom(string(*itr), true, target) );
			}
		}

		itr++;
	}
}
