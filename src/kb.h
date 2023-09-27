#ifndef KB_H_INCLUDED
#define KB_H_INCLUDED 
#include <string>

using namespace std;

class kb {
	public:
		kb(){
            cout << "Worked" << endl;
        };
		~kb(){
            //this will free up memory
        }; 

        string toString();
};

#endif
