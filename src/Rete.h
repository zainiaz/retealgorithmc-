#include "WorkingMemory.h"
#include "KnowledgeBase.h"

class Rete{
private:
	WorkingMemory* wm; //Maybe this could be inside the knowledgeBase
	KnowledgeBase* kb;	
	bool keepInference; //Control flag for main loop  

public:

	Rete(const WorkingMemory&, const KnowledgeBase&);
	~Rete();

	infer(); // Main loop, it starts all rules (threads) and keeps inference working
}