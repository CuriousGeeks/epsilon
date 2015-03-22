#include "Field.h"

using namespace el;

void CFieldInt::SetValue(const std::string& sValue)
{
	m_iVal = atoi(sValue.c_str());
}

void CFieldUInt::SetValue(const std::string& sValue)
{
	m_nVal = atoll(sValue.c_str());
}

void CFieldBool::SetValue(const std::string& sValue)
{
	if (sValue.compare("true") == 0 ||
	    sValue.compare("Y") == 0 ||
		sValue.compare("1") == 0)
		{
			m_bVal = true;
		}
	else
	{
		 m_bVal = false;
	}
}

void CFieldChar::SetValue(const std::string& sValue)
{
	m_chVal = *(sValue.c_str());
}

void CFieldDate::SetValue(const std::string& sValue)
{
	//m_iVal = atoi(sValue.c_str());
}

void CFieldString::SetValue(const std::string& sValue)
{
	m_strVal = sValue;
}

void CFieldDouble::SetValue(const std::string& sValue)
{
	m_dVal = std::stod(sValue.c_str());
}

void CFieldFloat::SetValue(const std::string& sValue)
{
	m_fVal = std::stof(sValue.c_str());
}