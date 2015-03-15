#include "InterestRateObject.h"

using namespace el;


BEGIN_FIELD_DESCRIPTOR(CInterestRateObject)
	ADD_FIELD_DESCRIPTOR(m_nInstrumentID)
	ADD_FIELD_DESCRIPTOR(m_nSecurityID)
	ADD_FIELD_DESCRIPTOR(m_nGLAccountID)
	ADD_FIELD_DESCRIPTOR(m_nProductType)
END_FIELD_DESCRIPTOR()

CInterestRateObject::CInterestRateObject():
m_nInstrumentID(eInstrumentID),
m_nSecurityID(eSecurityID),
m_nGLAccountID(eGLAccountID),
m_nProductType(eProductType)
{
	
}
