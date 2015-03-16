#pragma once
#include <string>
using namespace std;

namespace el
{
	class CCache
	{};
	class CObject
	{};

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
			AccrualBasisRule,
			FlagPaymentRule,
			CalendarPaymentRule,
			CalendarResetRule,
			RateCustomerRule
		};
		virtual bool Execute(const CCache& cache,const CObject& obj) = 0;
		virtual string GetErrorCode() = 0;
	};

	class CBalanceBookRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CBalanceBookRule() :m_eRuleId(eBalanceBookRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CObject& obj)
		{
			//validate
			return true;
		}
		string GetErrorCode()
		{
			return "";
		}
	};
}