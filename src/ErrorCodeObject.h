#pragma once

#include "./Object.h"

namespace el{


	class CErrorCodeObject : public CObject
	{
	public:
		enum eColumnIds
		{
			eErrorCode,
			eFieldName,
			eDescription,
			eAuthID
		};

		CErrorCodeObject();

		std::string& GetErrorCode() { return m_szErrorCode.Get(); }
		std::string& GetFieldName()	{ return m_szFieldName.Get(); }
		std::string& GetDescription() { return m_szDescription.Get(); }

		DECLARE_FIELD_DESCRIPTOR();
	private:
		CFieldString 	m_szErrorCode;
		CFieldString 	m_szFieldName;
		CFieldString 	m_szDescription;
		CFieldUInt 		m_nAuthID;
		//Note: When Adding new Fields don't forget to ADD_FIELD_DESCRIPTOR and assign Column Id.
	};


};