#ifndef RULEPART_H
#define RULEPART_H

#include <string>

class RulePart{
public:
	std::string virtual toString()const =0;
};

#endif
