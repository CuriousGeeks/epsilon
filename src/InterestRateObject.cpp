#include "InterestRateObject.h"

using namespace el;

#define CHECK_UNIT(x) (x == 'D' || x == 'W' || x == 'M' || x == 'Y')
#define CHECK_FREQ(x) (x >= 0 && x <= 365)

BEGIN_FIELD_DESCRIPTOR(CInterestRateObject)
	ADD_FIELD_DESCRIPTOR(m_nInstrumentID)
	ADD_FIELD_DESCRIPTOR(m_szSecurityID)
	ADD_FIELD_DESCRIPTOR(m_szGLAccountID)
	ADD_FIELD_DESCRIPTOR(m_nProductType)
	ADD_FIELD_DESCRIPTOR(m_nAccrualBasis)
	ADD_FIELD_DESCRIPTOR(m_nAssetLiability)
	ADD_FIELD_DESCRIPTOR(m_dBalanceBook)
	ADD_FIELD_DESCRIPTOR(m_nBuisnessDayConvention)
	ADD_FIELD_DESCRIPTOR(m_szCurrency)
	ADD_FIELD_DESCRIPTOR(m_dtDateData)
	ADD_FIELD_DESCRIPTOR(m_dtDateIssue)
	ADD_FIELD_DESCRIPTOR(m_dtDateMaturity)
	ADD_FIELD_DESCRIPTOR(m_szCalendarPayment)
	ADD_FIELD_DESCRIPTOR(m_szCalendarReset)
	ADD_FIELD_DESCRIPTOR(m_nFlagPayment)
	ADD_FIELD_DESCRIPTOR(m_nPaymentFreq)
	ADD_FIELD_DESCRIPTOR(m_cPaymentFreqUnit)
	ADD_FIELD_DESCRIPTOR(m_dRateCustomer)
	ADD_FIELD_DESCRIPTOR(m_szRateIndex)
	ADD_FIELD_DESCRIPTOR(m_nResetFreq)
	ADD_FIELD_DESCRIPTOR(m_cResetFreqUnit)
	ADD_FIELD_DESCRIPTOR(m_nChartOfAccountId)
END_FIELD_DESCRIPTOR()

CInterestRateObject::CInterestRateObject():
m_nInstrumentID(eInstrumentID),
m_szSecurityID(eSecurityID),
m_szGLAccountID(eGLAccountID),
m_nProductType(eProductType),
m_nAssetLiability(eAssetLiability),
m_dBalanceBook(eBalanceBook),
m_nBuisnessDayConvention(eBuisnessDayConvention),
m_nAccrualBasis(eAccrualBasis),
m_szCurrency(eCurrency),
m_dtDateData(eDateData),
m_dtDateIssue(eDateIssue),
m_dtDateMaturity(eDateMaturity),
m_szCalendarPayment(eCalendarPayment),
m_szCalendarReset(eCalendarReset),
m_nFlagPayment(eFlagPayment),
m_nPaymentFreq(ePaymentFreq),
m_cPaymentFreqUnit(ePaymentFreqUnit),
m_szRateIndex(eRateIndex),
m_nResetFreq(eResetFreq),
m_cResetFreqUnit(eResetFreqUnit),
m_dRateCustomer(eRateCustomer),
m_nChartOfAccountId(eChartOfAccountID)
{
	
}

bool CInterestRateObject::IsInstrumentIDValid() const
{
	if (m_nInstrumentID.IsNull())
		return false;
	else
		return m_nInstrumentID.Get() > 0; 
}
bool CInterestRateObject::IsChartOfAccountIdValid() const 
{
	if (m_nChartOfAccountId.IsNull())
		return false;
	else
		return m_nChartOfAccountId.Get() > 0; 
}
bool CInterestRateObject::IsGLAccountIDValid() const 
{
	if (m_szGLAccountID.IsNull())
		return false;
	else
		return m_szGLAccountID.Get() != ""; 
}
bool CInterestRateObject::IsBalanceBookValid() const
{
	if (m_dBalanceBook.IsNull())
		return false;
	else
		return m_dBalanceBook.Get() > 0; 
}
bool CInterestRateObject::IsIssueDateValid() const
{	
	if (m_dtDateIssue.IsNull())
		return false;
	else
	{
		el::CDateTime IssueDate(m_dtDateIssue.Get());
		return IssueDate.Check();
	}
}
bool CInterestRateObject::IsDataDateValid() const
{
	if (m_dtDateData.IsNull())
		return false;
	else
	{
		el::CDateTime DataDate(m_dtDateData.Get());
		return DataDate.Check();
	}
}
bool CInterestRateObject::IsIssueDateValidForData() const
{
	if (m_dtDateIssue.IsNull())
		return false;
	else
	{
		el::CDateTime IssueDate(m_dtDateIssue.Get());
		el::CDateTime DataDate(m_dtDateData.Get());
		if (IssueDate.Check() && DataDate.Check())
		{
			return (IssueDate < DataDate);
		}
		return false;
	}
} 
bool CInterestRateObject::IsMaturityDateValid() const
{	
	if (m_dtDateMaturity.IsNull())
		return false;
	else
	{
		el::CDateTime MaturityDate(m_dtDateMaturity.Get()); return MaturityDate.Check();
	}
}
bool CInterestRateObject::IsMaturityDateValidForData() const
{ 
	if (m_dtDateMaturity.IsNull())
		return false;
	else
	{
		el::CDateTime MaturityDate(m_dtDateMaturity.Get());
		el::CDateTime DataDate(m_dtDateData.Get());
		if (MaturityDate.Check() && DataDate.Check())
		{
			return (DataDate < MaturityDate);
		}
		return false;
	}
} 
bool CInterestRateObject::IsPaymentFreqValid() const
{
	if (m_nPaymentFreq.IsNull())
		return false;
	else
		return (CHECK_FREQ(m_nPaymentFreq.Get()));
}
bool CInterestRateObject::IsPaymentFreqUnitValid() const
{ 
	if (m_cPaymentFreqUnit.IsNull())
		return false;
	else
	return (CHECK_UNIT(m_cPaymentFreqUnit.Get())); 
}
bool CInterestRateObject::IsResetFreqValid() const
{ 
	if (m_nResetFreq.IsNull())
		return false;
	else
	return (CHECK_FREQ(m_nResetFreq.Get())); 
}
bool CInterestRateObject::IsResetFreqUnitValid() const
{ 
	if (m_cPaymentFreqUnit.IsNull())
		return false;
	else
	return (CHECK_UNIT(m_cPaymentFreqUnit.Get())); 
}
bool CInterestRateObject::IsRateIndexValid() const
{
	if (m_szRateIndex.IsNull())
		return false;
	else
	{
		std::string szRateIndex = "";
		m_szRateIndex.GetValue(szRateIndex);
		int nRateIndex = atoi(szRateIndex.c_str());
		return (nRateIndex > 0 && nRateIndex < 1000);
	}
}
bool CInterestRateObject::IsAssetLiabilityValid() const
{
	if (m_nAssetLiability.IsNull())
		return false;
	else
	{
		return (m_nAssetLiability.Get() == 1 || m_nAssetLiability.Get() == -1);
	}
}
bool CInterestRateObject::IsBusinessDayConventionValid() const
{ 
	if (m_nBuisnessDayConvention.IsNull())
		return false;
	else
		return(m_nBuisnessDayConvention.Get() >= 0 && m_nBuisnessDayConvention.Get() <= 9);
}
bool CInterestRateObject::IsAccrualBasisValid() const
{ 
	if (m_nAccrualBasis.IsNull())
		return false;
	else
	return (m_nAccrualBasis.Get() >= 0 && m_nAccrualBasis.Get() <= 9); 
}
bool CInterestRateObject::IsFlagPaymentValid() const
{
	if (m_nFlagPayment.IsNull())
		return false;
	else
	return (m_nFlagPayment.Get() == 1 || m_nFlagPayment.Get() == 2); 
}
bool CInterestRateObject::IsRateCustomerValid() const
{ 
	if (m_dRateCustomer.IsNull())
		return false;
	else
	return m_dRateCustomer.Get() != 0; 
}

