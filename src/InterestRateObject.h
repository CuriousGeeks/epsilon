#pragma once

#include "./Object.h"

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
		
		eBalanceBook
	};
	
	CInterestRateObject();
	
	unsigned int GetInstrumentID() { return m_nInstrumentID.Get(); }
			
	bool IsBalanceBookValid() {	return m_nBalanceBook.Get() < 0; }
	
	DECLARE_FIELD_DESCRIPTOR();
private:
	CFieldUInt 		m_nInstrumentID;
	CFieldUInt 		m_nSecurityID;
	CFieldUInt 		m_nGLAccountID;
	CFieldUInt 		m_nProductType;

	CFieldUInt 		m_nBalanceBook;
	//Note: When Adding new Fields don't forget to ADD_FIELD_DESCRIPTOR and assign Column Id.
};
	
	
};