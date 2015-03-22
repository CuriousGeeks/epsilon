#pragma once

#include "Rule.h"

#include <map>


namespace el{

typedef std::map<unsigned int, shared_ptr<CRule>> RuleMap;	

class CRuleCache
{
public:
	inline const RuleMap& GetRuleMap() { return m_mapRule; }
	
	void Initialize();
private:
	RuleMap m_mapRule;
};

typedef std::map<unsigned int, shared_ptr<CRule>> ProductRuleMap;

class CProductRuleCache
{
public:
	inline ProductRuleMap& GetProductRuleMap() { return m_mapProductRule;}
	
	void Initialize();
	
private:
	ProductRuleMap m_mapProductRule;	
};

};