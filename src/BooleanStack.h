#ifndef BOOLEAN_STACK_H
#define BOOLEAN_STACK_H
#include <vector>

class BooleanStack{
	private:
		std::vector<bool> data;
	
	public:
		BooleanStack();
		void clear();
		bool empty();
		bool top();
		bool pop();
		void push(bool);
		int size();		
};

#endif
