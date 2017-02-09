#include <iostream>
#include "src/Atomo.h"
#include "src/Operador.h"
#include "src/PilaBooleana.h"
#include "src/LectorArchivos.h"

using namespace std;

int main(){
	ParteRegla *at1 = new Atomo(string("Holi"), true, false);
	ParteRegla *at2 = new Atomo(string("Holi"), true, false);

	cout << "Comparación: " << ((Atomo*)*at1).Equals((Atomo*)*at2) << endl;
	
	LectorArchivos *l = new LectorArchivos(string("ejemp.txt"));

	cout << "CADENA: " << l->leerCadena() << endl;
	cout << "CADENA: " << l->leerCadena() << endl;
	cout << "CADENA: " << l->leerCadena() << endl;
	cout << "CADENA: " << l->leerCadena() << endl;

	l->cierra();
	
	PilaBooleana *pl = new PilaBooleana();

	cout << "Vacia (1): " << pl->vacia() << "  Size: " << pl->size() << endl;

	pl->push(false);

	cout << "Vacia (0): " << pl->vacia() << "  Size: " << pl->size() << endl;
	cout << "Top: (0)" << pl->top() << endl;
	pl->push(true);
	cout << "Top: (1)" << pl->top() << "  Size: " << pl->size() << endl;
	cout << "Pop: (1)" << pl->pop() << endl;
	pl->anular();
	cout << "Vacia (1): " << pl->vacia() << "  Size: " << pl->size() << endl; 
	
	Atomo *atm4 = new Atomo(string("Hola"), true, false);
	

	Atomo atm3 (std::string("Hola"), true, false);
	Atomo atm2 (std::string("Adios"), false, true);
	Atomo atm1 (atm3);
	cout << "Atomo A - Estado: " << atm1.getEstado();
	cout << "   Desc: " << atm1.getDesc();
	cout << "   Objetivo: " << atm1.getObjetivo() << endl;

	cout << "Atomo B - Estado: " << atm2.getEstado();
	cout << "   Desc: " << atm2.getDesc();
	cout << "   Objetivo: " << atm2.getObjetivo() << endl;

	cout << endl << atm2.ToString() << endl;
	cout << atm1.GetHashCode() << endl;
	cout << "(1 VS 3) Igualdad " << atm1.verIgualdad(atm3) << endl;
	cout << "(1 VS 2) Verdad " << atm1.verVerdad(atm2) << endl;
	cout << "(1 VS 2 DEBE SER FALSO) Equal " << atm1.Equals(atm2) << endl;

	cout << "(1 VS 4 DEBE SER VERDADERO) Equals: " << atm1.Equals(*atm4) << endl;

	cout << "(2 VS 4 DEBE DER FALSO) Equals: " << atm2.Equals(*atm4) << endl;

        Operador* neg = new Negacion();
	Operador* con = new Binario(true);
	Operador* dis = new Binario(false);
	
	cout << "Negación: " << neg->toString() << endl;
	cout << "Conjunción: "<< con->toString() << endl;
	//cout << "Disyunción: "<< dis->toString() << endl;

	return 0;
}
