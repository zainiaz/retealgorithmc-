#ifndef LECTOR_ARCHIVOS_H
#define LECTOR_ARCHIVOS_H

#include <string>
#include <fstream>

using namespace std;

class LectorArchivos{
	private:
		fstream archivo;		
	public:
		LectorArchivos(string);
		string leerCadena();
		void cierra();
};

#endif
