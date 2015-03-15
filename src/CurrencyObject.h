#pragma once

#include "./Object.h"

namespace el{
	

class CCurrencyObject : public CObject
{
public:	
	enum eColumnIds
	{
		eCurrencyID,
		eCurrencyNumber,
		eCurrencyName,
		eAuthID,
		eCurrencyDayCount
	};
	
	CCurrencyObject();
	
	std::string& GetCurrencyID() { return m_szCurrencyID.Get(); }
	
	DECLARE_FIELD_DESCRIPTOR();
private:
	CFieldString 	m_szCurrencyID;
	CFieldUInt 		m_nCurrencyNumber;
	CFieldString 	m_szCurrencyName;
	CFieldUInt 		m_nAuthID;
	CFieldUInt 		m_nCurrencyDayCount;
	//Note: When Adding new Fields don't forget to ADD_FIELD_DESCRIPTOR and assign Column Id.
};
	
	
};