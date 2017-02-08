#include "MemoriaTrabajo.h"
#include <algorithm>

MemoriaTrabajo::MemoriaTrabajo(){
	afirmados = new vector<Atomo>();
	negados = new vector<Atomo>();
}

MemoriaTrabajo::~MemoriaTrabajo(){
	delete afirmados;
	delete negados;
}

void MemoriaTrabajo::guardaAtomo(const Atomo& atm){
	if(!fueNegado(atm) && !fueAfirmado(atm))
	{
		if(atm.getEstado())
			afirmados -> push_back(atm);
		else
			negados -> push_back(atm);
	}
}

bool MemoriaTrabajo::presente(const Atomo& atm) const{
	return (fueNegado(atm) || fueAfirmado(atm));
}

iterador MemoriaTrabajo::busca(iterador inicio, iterador fin,const Atomo& atm)const{
	return find(inicio,fin,atm);
}

bool MemoriaTrabajo::fueAfirmado(const Atomo& atm)const{
	return busca(afirmados->begin(),afirmados->end(),atm) != afirmados->end();
}

bool MemoriaTrabajo::fueNegado(const Atomo& atm)const{
	return busca(negados->begin(),negados->end(),atm) != negados->end();
}

Atomo* MemoriaTrabajo::recupera(const Atomo& atm)const{
	iterador itA, itN;
	
	itA = busca(afirmados->begin(),afirmados->end(),atm);
	itN = busca(negados->begin(),negados->end(),atm);
	
	if(itA != afirmados->end()) 
		return new Atomo(*itA);	

	if(itN != negados->end()) 
		return new Atomo(*itN);

	return NULL;
}

/*Atomo* MemoriaTrabajo::recupera(string desc){
	iterador itA, itN;
	Atomo atm(desc,true,true);
	itA = busca(afirmados->begin(),afirmados->end(),atm);
	itN = busca(negados->begin(),negados->end(),atm);
	
	if(itA != afirmados->end()) 
		return *itA;	

	if(itN != negados->end()) 
		return *itN;

	return NULL;
}*/

string MemoriaTrabajo::toString()const{
	string retorno = "\nMemoria de Trabajo\nAfirmados: [ ";
	iterador it;
	
	it = afirmados->begin();
	while(it != afirmados->end()){
		retorno += (*it).toString()+" ";
		it++;
	}

	retorno = retorno+"]\nNegados: [ ";

	it = negados->begin();
	while(it != negados->end()){
		retorno += (*it).toString()+" ";
		it++;
	}
	return retorno+"]";
}