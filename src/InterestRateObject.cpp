#include "InterestRateObject.h"

using namespace el;

#define CHECK_UNIT(x) (x == 'D' || x == 'W' || x == 'M' || x == 'Y')
#define CHECK_FREQ(x) (x >= 0 && x <= 365)

BEGIN_FIELD_DESCRIPTOR(CInterestRateObject)
	ADD_FIELD_DESCRIPTOR(m_nInstrumentID)
	ADD_FIELD_DESCRIPTOR(m_szSecurityID)
	ADD_FIELD_DESCRIPTOR(m_szGLAccountID)
	ADD_FIELD_DESCRIPTOR(m_nProductType)
	ADD_FIELD_DESCRIPTOR(m_nAssetLiability)
	ADD_FIELD_DESCRIPTOR(m_dBalanceBook)
	ADD_FIELD_DESCRIPTOR(m_nBuisnessDayConvention)
	ADD_FIELD_DESCRIPTOR(m_nAccrualBasis)
	ADD_FIELD_DESCRIPTOR(m_dtDateData)
	ADD_FIELD_DESCRIPTOR(m_dtDateIssue)
	ADD_FIELD_DESCRIPTOR(m_dtDateMaturity)
	ADD_FIELD_DESCRIPTOR(m_szCalendarPayment)
	ADD_FIELD_DESCRIPTOR(m_szCalendarReset)
	ADD_FIELD_DESCRIPTOR(m_nFlagPayment)
	ADD_FIELD_DESCRIPTOR(m_nPaymentFreq)
	ADD_FIELD_DESCRIPTOR(m_cPaymentFreqUnit)
	ADD_FIELD_DESCRIPTOR(m_szRateIndex)
	ADD_FIELD_DESCRIPTOR(m_nResetFreq)
	ADD_FIELD_DESCRIPTOR(m_cResetFreqUnit)
	ADD_FIELD_DESCRIPTOR(m_dRateCustomer)
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
m_dRateCustomer(eRateCustomer)
{
	
}

bool CInterestRateObject::IsBalanceBookValid() const{ return m_dBalanceBook.Get() > 0; }
bool CInterestRateObject::IsIssueDateValid() const{ return m_dBalanceBook.Get() < 0; }
bool CInterestRateObject::IsIssueDateValidForData() const{ return m_dBalanceBook.Get() < 0; }
bool CInterestRateObject::IsMaturityDateValid() const{ return m_dBalanceBook.Get() < 0; }
bool CInterestRateObject::IsMaturityDateValidForData() const{ return m_dBalanceBook.Get() < 0; }

bool CInterestRateObject::IsPaymentFreqValid() const{ return (CHECK_FREQ(m_nPaymentFreq.Get())); }
bool CInterestRateObject::IsPaymentFreqUnitValid() const{ return (CHECK_UNIT(m_cPaymentFreqUnit.Get())); }
bool CInterestRateObject::IsResetFreqValid() const{ return (CHECK_FREQ(m_nResetFreq.Get())); }
bool CInterestRateObject::IsResetFreqUnitValid() const{ return (CHECK_UNIT(m_cPaymentFreqUnit.Get())); }
bool CInterestRateObject::IsRateIndexValid() const
{
	std::string szRateIndex = "";
	m_szRateIndex.GetValue(szRateIndex);
	int nRateIndex = atoi(szRateIndex.c_str());
	return (nRateIndex>0 && nRateIndex < 1000);
}
bool CInterestRateObject::IsAssetLiabilityValid() const{ return (m_nAssetLiability.Get() == 1 || m_nAssetLiability.Get() == -1); }
bool CInterestRateObject::IsBusinessDayConventionValid() const{ return (m_nBuisnessDayConvention.Get() >= 0 && m_nBuisnessDayConvention.Get() <= 9); }
bool CInterestRateObject::IsAccrualBasisValid() const{ return (m_nAccrualBasis.Get() >= 0 && m_nAccrualBasis.Get() <= 9); }
bool CInterestRateObject::IsFlagPaymentValid() const{ return (m_nFlagPayment.Get() == 1 || m_nFlagPayment.Get() == 2); }
bool CInterestRateObject::IsCalendarPaymentValid() const{ return m_dBalanceBook.Get() < 0; }
bool CInterestRateObject::IsCalendarResetValid() const{ return m_dBalanceBook.Get() < 0; }
bool CInterestRateObject::IsRateCustomerValid() const{ return m_dRateCustomer.Get() != 0; }

