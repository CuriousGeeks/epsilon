#pragma once
#include <string>
using namespace std;

//#include "Cache.h"
#include "InterestRateObject.h"


namespace el
{
	class CCache;
	
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
		virtual bool Execute(CCache& cache, CInterestRateObject& obj) = 0;
		virtual string GetErrorCode() = 0;
	};

	class CBalanceBookRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CBalanceBookRule() :m_eRuleId(eBalanceBookRule){}
		
		inline int GetRuleId() { return m_eRuleId; }
		
		bool Execute(CCache& cache, CInterestRateObject& obj);
		
		inline string GetErrorCode() { return "B001"; }
	};

	class CDateIssueRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CDateIssueRule() :m_eRuleId(eDateIssueRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(CCache& cache, CInterestRateObject& obj);
		inline string GetErrorCode(){return "D001";}
	};

	class CDateIssueAndDateDataRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CDateIssueAndDateDataRule() :m_eRuleId(eDateIssueAndDateDataRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(CCache& cache, CInterestRateObject& obj);
		inline string GetErrorCode(){ return "D002"; }
	};

	class CDateMaturityRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CDateMaturityRule() :m_eRuleId(eDateMaturityRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(CCache& cache, CInterestRateObject& obj);
		inline string GetErrorCode(){ return "D003"; }
	};

	class CDateMaturityAndDateDataRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CDateMaturityAndDateDataRule() :m_eRuleId(eDateMaturityAndDateDataRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(CCache& cache, CInterestRateObject& obj);
		inline string GetErrorCode(){ return "D004"; }
	};

	class CPaymentFreqRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CPaymentFreqRule() :m_eRuleId(ePaymentFreqRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(CCache& cache, CInterestRateObject& obj);
		inline string GetErrorCode(){ return "F001"; }
	};

	class CPaymentFreqUnitRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CPaymentFreqUnitRule() :m_eRuleId(ePaymentFreqUnitRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(CCache& cache, CInterestRateObject& obj);
		inline string GetErrorCode(){ return "F002"; }
	};

	class CResetFreqRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CResetFreqRule() :m_eRuleId(eResetFreqRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(CCache& cache, CInterestRateObject& obj);
		inline string GetErrorCode(){ return "F003"; }
	};

	class CResetFreqUnitRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CResetFreqUnitRule() :m_eRuleId(eResetFreqUnitRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(CCache& cache, CInterestRateObject& obj);
		inline string GetErrorCode(){ return "F004"; }
	};

	class CRateIndexRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CRateIndexRule() :m_eRuleId(eRateIndexRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(CCache& cache, CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

	class CAssetLiabilityRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CAssetLiabilityRule() :m_eRuleId(eAssetLiabilityRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(CCache& cache, CInterestRateObject& obj);
		inline string GetErrorCode(){ return "O006"; }
	};

	class CBusinessDayConventionRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CBusinessDayConventionRule() :m_eRuleId(eBusinessDayConventionRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(CCache& cache, CInterestRateObject& obj);
		inline string GetErrorCode(){ return "O007"; }
	};

	class CAccrualBasisRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CAccrualBasisRule() :m_eRuleId(eAccrualBasisRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(CCache& cache, CInterestRateObject& obj);
		inline string GetErrorCode(){ return "O008"; }
	};

	class CFlagPaymentRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CFlagPaymentRule() :m_eRuleId(eFlagPaymentRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(CCache& cache, CInterestRateObject& obj);
		inline string GetErrorCode(){ return ""; }
	};

	class CCalendarPaymentRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CCalendarPaymentRule() :m_eRuleId(eCalendarPaymentRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(CCache& cache, CInterestRateObject& obj);
		inline string GetErrorCode(){ return "O009"; }
	};

	class CCalendarResetRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CCalendarResetRule() :m_eRuleId(eCalendarResetRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(CCache& cache, CInterestRateObject& obj);
		inline string GetErrorCode(){ return "O010"; }
	};

	class CRateCustomerRule : public CRule
	{
		enmRuleId m_eRuleId;
	public:
		CRateCustomerRule() :m_eRuleId(eRateCustomerRule){}
		inline int GetRuleId() { return m_eRuleId; }
		bool Execute(CCache& cache, CInterestRateObject& obj);
		inline string GetErrorCode(){ return "R001"; }
	};

}