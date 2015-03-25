#pragma pack
using namespace std;
namespace el
{
	//need to revisit this class.. 
	class CDateTime
	{
		std::string m_szTime;
		std::string m_szFormat = "DD-MMM-YY";
		char m_cDelimeter = '-';
		short m_nNoOfDelimeters = 0;
		short m_nArrDelimeterIndex[10];
	public:
		CDateTime(std::string szTime) :m_szTime(szTime)
		{
			int ArrIndex = 0;
			for (int idx = 0; idx < m_szFormat.length(); idx++)
			{
				const char* p = m_szFormat.c_str();
				if (p[idx] == m_cDelimeter)
				{
					m_nArrDelimeterIndex[ArrIndex++] = idx;
					m_nNoOfDelimeters++;
				}
			}
		}
		bool ValidateFormat()
		{
			if (m_szFormat.length() != 9)
				return false;
			const char* pFormatString = m_szFormat.c_str();
			const char* pString = m_szTime.c_str();

			for (int i = 0; i < m_nNoOfDelimeters; i++)
			{
				if (pFormatString[m_nArrDelimeterIndex[i]] != pString[m_nArrDelimeterIndex[i]])
					return false;
			}
			return true;
		}
		bool Test()
		{
			try
			{
				if (!ValidateFormat())
					return false;
				int iDelimter = m_szTime.find(m_cDelimeter);
				int nDate = atoi(m_szTime.substr(0, iDelimter).c_str());
				string szTime = m_szTime.substr(iDelimter + 1).c_str();
				iDelimter = szTime.find(m_cDelimeter);
				string sMonth = szTime.substr(0, iDelimter).c_str();
				int nYear = atoi(szTime.substr(iDelimter + 1).c_str());

				if (nDate > 0 && nDate <= 31 && nYear != 0)
					return true;
				return false;
			}
			catch (...)
			{
				return false;
			}
		}
		bool operator <(const CDateTime& timeObj) //Will b used to compare dates..
		{

		}
	};
}