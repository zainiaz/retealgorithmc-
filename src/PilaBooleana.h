#ifndef PILA_BOOLEANA_H
#define PILA_BOOLEANA_H
#include <vector>

using namespace std;

class PilaBooleana{
	private:
		vector<bool> datos;
	
	public:
		PilaBooleana();
		void anular();
		bool vacia();
		bool top();
		bool pop();
		void push(bool);
		int size();		
};

#endif
