#include "CurrencyObject.h"

using namespace el;


BEGIN_FIELD_DESCRIPTOR(CCurrencyObject)
	ADD_FIELD_DESCRIPTOR(m_szCurrencyID)
	ADD_FIELD_DESCRIPTOR(m_nCurrencyNumber)
	ADD_FIELD_DESCRIPTOR(m_szCurrencyName)
	ADD_FIELD_DESCRIPTOR(m_nAuthID)
	ADD_FIELD_DESCRIPTOR(m_nCurrencyDayCount)
END_FIELD_DESCRIPTOR()

CCurrencyObject::CCurrencyObject():
m_szCurrencyID(eCurrencyID),
m_nCurrencyNumber(eCurrencyNumber),
m_szCurrencyName(eCurrencyName),
m_nAuthID(eAuthID),
m_nCurrencyDayCount(eCurrencyDayCount)
{
	
}
