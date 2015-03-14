#pragma once

#include "./Object.h"

namespace el{
	

class CProcessObject : public CObject
{
public:	
	enum eColumnIds
	{
		eProcessID,
		eProcessDesc,
		eProcessType,
		eProcessSubCategory,
		eReportingCurrency,
		eDateStart
	};
	
	CProcessObject();
	
	unsigned int GetProcessId() { return m_nProcessId.Get(); }
	
	DECLARE_FIELD_DESCRIPTOR();
private:
	CFieldUInt 		m_nProcessId;
	CFieldString 	m_szProcessDesc;
	CFieldUInt 		m_nProcessType;
	CFieldUInt 		m_nProcessSubCategory;
	CFieldString 	m_szReportingCurrency;
	CFieldDate		m_dtStart;
	//When Adding new Fields don't forget to ADD_FIELD_DESCRIPTOR and assign Column Id.
};
	
	
};