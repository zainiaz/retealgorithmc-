#include "LectorArchivos.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

LectorArchivos::LectorArchivos(string nomArch){
	this->archivo.open(nomArch.c_str(), ios::out | ios::in);
	if(!this->archivo.is_open()){
		string aux = nomArch;
		while(!this->archivo.is_open()){
			cout << "No se pudo localizar el archivo: " << aux  << endl;
			cout << "Ingresa de nuevo el nombre del archivo para leer: ";
			cin >> aux;
			this->archivo.open(aux.c_str(), ios::out | ios::in);
		}

		cout << "El archivo: " << aux << " ";
	}
	else cout << "El archivo: " << nomArch << " ";

	cout << "se ha abierto correctamente!" << endl << endl;
}

string LectorArchivos::leerCadena(){
	string tmp;

	if(getline(archivo, tmp)){
		return tmp;
	}
	else{
		cout << "Ya alcanzaste el fin de archivo. Imposible leer más!" << endl << endl;
		return string("EOF");
	}
}

void LectorArchivos::cierra(){
	this->archivo.close();
}
