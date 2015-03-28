#pragma once

#include "./Object.h"
#include "DateTime.h"

namespace el{
	

class CInterestRateObject : public CObject
{
public:	
	enum eColumnIds
	{
		eInstrumentID = 0,
		eSecurityID,
		eGLAccountID,
		eProductType,
		eAccrualBasis = 11,
		eAssetLiability = 13,
		eBalanceBook = 14,
		eBuisnessDayConvention = 19,
		eCurrency = 28,
		eDateData = 29,
		eDateIssue = 31,
		eDateMaturity = 34,
		eCalendarPayment = 44,
		eCalendarReset = 45,
		eFlagPayment = 54,
		ePaymentFreq = 55,
		ePaymentFreqUnit = 56,
		eRateCustomer = 66,
		eRateIndex = 69,
		eResetFreq = 77,
		eResetFreqUnit = 78,
		eChartOfAccountID = 190
	};
	
	CInterestRateObject();
	
	std::string GetTableName(){ return "Interest_Rate"; }
	unsigned int GetInstrumentID() { return m_nInstrumentID.Get(); }
	unsigned int GetProductType() { return m_nProductType.Get(); }
	
	std::string& GetCalendarPayment() { return m_szCalendarPayment.Get(); }
	std::string& GetCalendarReset() { return m_szCalendarReset.Get(); }
	std::string& GetCurrency() { return m_szCurrency.Get(); }
			
	bool IsInstrumentIDValid() const;
	bool IsChartOfAccountIdValid() const;
	bool IsGLAccountIDValid() const;
	bool IsCurrencyValid() const;

	bool IsBalanceBookValid() const;
	bool IsIssueDateValid() const;
	bool IsDataDateValid() const;
	bool IsIssueDateValidForData() const;
	bool IsMaturityDateValid() const;
	bool IsMaturityDateValidForData() const;

	bool IsPaymentFreqValid() const;
	bool IsPaymentFreqUnitValid() const;
	bool IsResetFreqValid() const;
	bool IsResetFreqUnitValid() const;
	bool IsRateIndexValid() const;
	
	bool IsAssetLiabilityValid() const;
	bool IsBusinessDayConventionValid() const;
	bool IsAccrualBasisValid() const;
	bool IsFlagPaymentValid() const;
	bool IsRateCustomerValid() const;
	
	DECLARE_FIELD_DESCRIPTOR();
private:
	mutable CFieldUInt		m_nInstrumentID;
	mutable CFieldString	m_szSecurityID;
	mutable CFieldString	m_szGLAccountID;
	mutable CFieldUInt 		m_nProductType;
	//Fields to perform Validations on.
	mutable CFieldInt		m_nAccrualBasis;
	mutable CFieldInt		m_nAssetLiability;
	mutable CFieldDouble	m_dBalanceBook;
	mutable CFieldInt		m_nBuisnessDayConvention;
	mutable CFieldString    m_szCurrency;
	mutable CFieldString	m_dtDateData;
	mutable CFieldString	m_dtDateIssue;
	mutable CFieldString	m_dtDateMaturity;
	mutable CFieldString	m_szCalendarPayment;
	mutable CFieldString	m_szCalendarReset;
	mutable CFieldInt		m_nFlagPayment;
	mutable CFieldInt		m_nPaymentFreq;
	mutable CFieldChar		m_cPaymentFreqUnit;
	mutable CFieldDouble	m_dRateCustomer;
	mutable CFieldString	m_szRateIndex;
	mutable CFieldInt		m_nResetFreq;
	mutable CFieldChar		m_cResetFreqUnit;
	mutable CFieldInt		m_nChartOfAccountId;
	//Note: When Adding new Fields don't forget to ADD_FIELD_DESCRIPTOR and assign Column Id.
};
	
	
};