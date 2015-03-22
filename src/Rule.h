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
		virtual bool Execute(const el::CCache& cache, const CInterestRateObject& obj) = 0;
		virtual string GetErrorCode() = 0;
	};

	class CBalanceBookRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CBalanceBookRule() :m_eRuleId(eBalanceBookRule){}
		
		inline int GetRuleId() { return m_eRuleId; }
		
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		
		inline string GetErrorCode() { return ""; }
	};

	class CDateIssueRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CDateIssueRule() :m_eRuleId(eDateIssueRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		inline string GetErrorCode(){return "";}
	};

	class CDateIssueAndDateDataRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CDateIssueAndDateDataRule() :m_eRuleId(eDateIssueAndDateDataRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

	class CDateMaturityRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CDateMaturityRule() :m_eRuleId(eDateMaturityRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

	class CDateMaturityAndDateDataRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CDateMaturityAndDateDataRule() :m_eRuleId(eDateMaturityAndDateDataRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

	class CPaymentFreqRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CPaymentFreqRule() :m_eRuleId(ePaymentFreqRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

	class CPaymentFreqUnitRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CPaymentFreqUnitRule() :m_eRuleId(ePaymentFreqUnitRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

	class CResetFreqRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CResetFreqRule() :m_eRuleId(eResetFreqRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

	class CResetFreqUnitRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CResetFreqUnitRule() :m_eRuleId(eResetFreqUnitRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

	class CRateIndexRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CRateIndexRule() :m_eRuleId(eRateIndexRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

	class CAssetLiabilityRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CAssetLiabilityRule() :m_eRuleId(eAssetLiabilityRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

	class CBusinessDayConventionRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CBusinessDayConventionRule() :m_eRuleId(eBusinessDayConventionRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

	class CAccrualBasisRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CAccrualBasisRule() :m_eRuleId(eAccrualBasisRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

	class CFlagPaymentRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CFlagPaymentRule() :m_eRuleId(eFlagPaymentRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

	class CCalendarPaymentRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CCalendarPaymentRule() :m_eRuleId(eCalendarPaymentRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

	class CCalendarResetRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CCalendarResetRule() :m_eRuleId(eCalendarResetRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

	class CRateCustomerRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CRateCustomerRule() :m_eRuleId(eRateCustomerRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(const CCache& cache, const CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

}