#pragma once

#include "Rule.h"

#include <map>
#include <list>

namespace el{

typedef std::map<unsigned int, shared_ptr<CRule>> RuleMap;	

class CRuleCache
{
public:
	inline RuleMap& GetRuleMap() { return m_mapRule; }
	
	void Initialize();
private:
	RuleMap m_mapRule;
};

typedef std::map<unsigned int, list<shared_ptr<CRule>>> ProductRuleMap;

class CProductRuleCache
{
public:
	enum eProductTypes
	{
		eCommitments = 100,
		eLetterOfCredits,
		eLoanGuarantees,
		eCreditCards,
		eReceivables,
		ePayables,
		eFixedRateBullet
	};
	inline ProductRuleMap& GetProductRuleMap() { return m_mapProductRule;}
	
	void Initialize();
	
	void Execute(int nProductType);
	
private:
	ProductRuleMap m_mapProductRule;
	CRuleCache m_RuleCache;
};

};