#include "ProductRuleCache.h"
#include <memory.h>

using namespace el;

void CRuleCache::Initialize()
{
	m_mapRule[CRule::eBalanceBookRule] = shared_ptr<CRule>(new CBalanceBookRule);
	m_mapRule[CRule::eDateIssueRule] = shared_ptr<CRule>(new CDateIssueRule);
	m_mapRule[CRule::eDateIssueAndDateDataRule] = shared_ptr<CRule>(new CDateIssueAndDateDataRule);
	m_mapRule[CRule::eDateMaturityRule] = shared_ptr<CRule>(new CDateMaturityRule);
	m_mapRule[CRule::eDateMaturityAndDateDataRule] = shared_ptr<CRule>(new CDateMaturityAndDateDataRule);
	m_mapRule[CRule::ePaymentFreqRule] = shared_ptr<CRule>(new CPaymentFreqRule);
	m_mapRule[CRule::ePaymentFreqUnitRule] = shared_ptr<CRule>(new CPaymentFreqUnitRule);		
	m_mapRule[CRule::eResetFreqRule] = shared_ptr<CRule>(new CResetFreqRule);
	m_mapRule[CRule::eResetFreqUnitRule] = shared_ptr<CRule>(new CResetFreqUnitRule);			
	m_mapRule[CRule::eRateIndexRule] = shared_ptr<CRule>(new CRateIndexRule);			
	m_mapRule[CRule::eAssetLiabilityRule] = shared_ptr<CRule>(new CAssetLiabilityRule);
	m_mapRule[CRule::eBusinessDayConventionRule] = shared_ptr<CRule>(new CBusinessDayConventionRule);
	m_mapRule[CRule::eAccrualBasisRule] = shared_ptr<CRule>(new CAccrualBasisRule);
	m_mapRule[CRule::eFlagPaymentRule] = shared_ptr<CRule>(new CFlagPaymentRule);		
	m_mapRule[CRule::eCalendarPaymentRule] = shared_ptr<CRule>(new CCalendarPaymentRule);	
	m_mapRule[CRule::eCalendarResetRule] = shared_ptr<CRule>(new CCalendarResetRule);	
	m_mapRule[CRule::eRateCustomerRule] = shared_ptr<CRule>(new CRateCustomerRule);	
}




void CProductRuleCache::Initialize()
{
	m_RuleCache.Initialize();
	auto& ruleMap = m_RuleCache.GetRuleMap();
	
	
	//Credit Cards Product
	list<shared_ptr<CRule>> lstCreditCardsRules;
	lstCreditCardsRules.push_back(ruleMap[CRule::eBalanceBookRule]);
	lstCreditCardsRules.push_back(ruleMap[CRule::eDateIssueRule]);
	lstCreditCardsRules.push_back(ruleMap[CRule::eDateIssueAndDateDataRule]);
	lstCreditCardsRules.push_back(ruleMap[CRule::eDateMaturityRule]);
	lstCreditCardsRules.push_back(ruleMap[CRule::eDateMaturityAndDateDataRule]);
	lstCreditCardsRules.push_back(ruleMap[CRule::ePaymentFreqRule]);
	lstCreditCardsRules.push_back(ruleMap[CRule::ePaymentFreqUnitRule]);
	lstCreditCardsRules.push_back(ruleMap[CRule::eResetFreqRule]);
	lstCreditCardsRules.push_back(ruleMap[CRule::eResetFreqUnitRule]);
	lstCreditCardsRules.push_back(ruleMap[CRule::eRateIndexRule]);
	lstCreditCardsRules.push_back(ruleMap[CRule::eAssetLiabilityRule]);
	lstCreditCardsRules.push_back(ruleMap[CRule::eBusinessDayConventionRule]);
	lstCreditCardsRules.push_back(ruleMap[CRule::eAccrualBasisRule]);
	lstCreditCardsRules.push_back(ruleMap[CRule::eFlagPaymentRule]);
	lstCreditCardsRules.push_back(ruleMap[CRule::eCalendarPaymentRule]);
	lstCreditCardsRules.push_back(ruleMap[CRule::eCalendarResetRule]);
	lstCreditCardsRules.push_back(ruleMap[CRule::eRateCustomerRule]);
	
	m_mapProductRule[eCreditCards] = lstCreditCardsRules;
	
	

	
}

void CProductRuleCache::Execute(int nProductType)
{
	
}
