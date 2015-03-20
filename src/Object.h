#pragma once

#include <stddef.h>
#include "Field.h"


namespace el{
	
struct TFieldDescriptor
{
	int* m_nOffset;
	bool IsEnd() { return (reinterpret_cast<int *>(-1) == m_nOffset);}
};

#define DECLARE_FIELD_DESCRIPTOR() 	 TFieldDescriptor* GetFieldDescriptor(); 
#define BEGIN_FIELD_DESCRIPTOR(C)  typedef C __type; TFieldDescriptor* __type::GetFieldDescriptor() { static TFieldDescriptor m_fieldDescriptor[] = {
#define ADD_FIELD_DESCRIPTOR(field)		 { reinterpret_cast<int *>(offsetof(__type,field)) },
#define END_FIELD_DESCRIPTOR()			 { reinterpret_cast<int *>(-1) } }; 	return m_fieldDescriptor;}


class CCSVRow;

class CObject
{
public:
	enum eObjectTypes
	{
		eInvalidObject,
		eProcessObject,
		eInterestRateObject,
		eCurrencyObject
	};
	
	CObject()
	{
		
	}
	
	virtual int GetObjectType() { return eInvalidObject;}
	
	//For Field Descriptor.
	virtual TFieldDescriptor* GetFieldDescriptor() = 0;
	inline CField* GetFieldPtr(int *pOffset) { return (CField *)(reinterpret_cast<char *>(this) + reinterpret_cast<size_t>(pOffset)); }
	
	void LoadFromRecord(CCSVRow& rwCSV);
	//
};
	
	
};