#pragma once

#include "./Object.h"

namespace el{
	

class CInterestRateObject : public CObject
{
public:	
	enum eColumnIds
	{
		eInstrumentID,
		eSecurityID,
		eGLAccountID,
		eProductType
	};
	
	CInterestRateObject();
	
	unsigned int GetInstrumentID() { return m_nInstrumentID.Get(); }
	
	DECLARE_FIELD_DESCRIPTOR();
private:
	CFieldUInt 		m_nInstrumentID;
	CFieldUInt 		m_nSecurityID;
	CFieldUInt 		m_nGLAccountID;
	CFieldUInt 		m_nProductType;

	//Note: When Adding new Fields don't forget to ADD_FIELD_DESCRIPTOR and assign Column Id.
};
	
	
};