#include "ErrorCodeObject.h"

using namespace el;


BEGIN_FIELD_DESCRIPTOR(CErrorCodeObject)
ADD_FIELD_DESCRIPTOR(m_szErrorCode)
ADD_FIELD_DESCRIPTOR(m_szFieldName)
ADD_FIELD_DESCRIPTOR(m_szDescription)
ADD_FIELD_DESCRIPTOR(m_nAuthID)
END_FIELD_DESCRIPTOR()

CErrorCodeObject::CErrorCodeObject() :
m_szErrorCode(eErrorCode),
m_szFieldName(eFieldName),
m_szDescription(eDescription),
m_nAuthID(eAuthID)
{

}
