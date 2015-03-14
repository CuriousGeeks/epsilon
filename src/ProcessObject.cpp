#include "ProcessObject.h"

using namespace el;


BEGIN_FIELD_DESCRIPTOR(CProcessObject)
	ADD_FIELD_DESCRIPTOR(m_nProcessId)
	ADD_FIELD_DESCRIPTOR(m_szProcessDesc)
	ADD_FIELD_DESCRIPTOR(m_nProcessType)
	ADD_FIELD_DESCRIPTOR(m_nProcessSubCategory)
	ADD_FIELD_DESCRIPTOR(m_szReportingCurrency)
	ADD_FIELD_DESCRIPTOR(m_dtStart)
END_FIELD_DESCRIPTOR()

CProcessObject::CProcessObject():
m_nProcessId(eProcessID),
m_szProcessDesc(eProcessDesc),
m_nProcessType(eProcessType),
m_nProcessSubCategory(eProcessSubCategory),
m_szReportingCurrency(eReportingCurrency),
m_dtStart(eDateStart)
{
	
}
