#pragma once
#include <string>
using namespace std;

#include "Cache.h"
#include "InterestRateObject.h"


namespace el
{
	class CRule
	{
	public:
		enum enmRuleId
		{
			eBalanceBookRule = 0,
			eDateIssueRule,
			eDateIssueAndDateDataRule,
			eDateMaturityRule,
			eDateMaturityAndDateDataRule,
			ePaymentFreqRule,
			ePaymentFreqUnitRule,
			eResetFreqRule,
			eResetFreqUnitRule,
			eRateIndexRule,
			eAssetLiabilityRule,
			eBusinessDayConventionRule,
			eAccrualBasisRule,
			eFlagPaymentRule,
			eCalendarPaymentRule,
			eCalendarResetRule,
			eRateCustomerRule
		};
		virtual bool Execute(const el::CCache& cache, CInterestRateObject& obj) = 0;
		virtual string GetErrorCode() = 0;
	};

	class CBalanceBookRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CBalanceBookRule() :m_eRuleId(eBalanceBookRule){}
		
		inline int GetRuleId() { return m_eRuleId; }
		
		bool Execute(const CCache& cache, const CObject& obj);
		
		inline string GetErrorCode() { return ""; }
	};
}