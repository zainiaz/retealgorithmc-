#include <iostream>
#include <string>
#include "Atomo.h"

using namespace std;

Atomo::Atomo(Atomo &otro){
	desc = otro.getDesc();
	estado = otro.getEstado() & true;
	objetivo = otro.objetivo & true;
}

Atomo::Atomo(string desc, bool estado, bool objetivo){
	this->desc = desc;
	this->estado = estado & true;
	this->objetivo = objetivo & true;
}

string Atomo::getDesc(){
	return desc;
}

void Atomo::setDesc(string desc){
	this->desc = desc;
}

bool Atomo::getEstado(){
	return estado;
}

void Atomo::setEstado(bool estado){
	this->estado = estado;
}

bool Atomo::getObjetivo(){
	return objetivo;
}

void Atomo::setObjetivo(bool obj){
	objetivo = obj;
}

string Atomo::ToString() {
	return string(estado?"":"!") + string(objetivo?"*":"") + desc;
} 

int Atomo::GetHashCode() {
	return 10;
}

bool Atomo::Equals(Atomo &obj) {
	return (obj.getEstado() == estado) && !(desc.compare(obj.getDesc()));
}

bool Atomo::verIgualdad(Atomo &aTmp){
	return !desc.compare(aTmp.getDesc());
}

bool Atomo::verVerdad(Atomo &aTmp){
	return estado && aTmp.getEstado();
}
