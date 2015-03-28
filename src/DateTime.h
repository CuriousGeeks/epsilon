#pragma pack

#include <sstream> 
#include <iomanip>
#include <ctime>
#include <map>
#include <algorithm>

using namespace std;

namespace el
{
	class CDateTime
	{
		std::string m_szTime;
		std::string m_szFormat = "DD-MMM-YY";
		char m_cDelimeter = '-';
		map<std::string, short> m_mapMonths;
		time_t m_time;
	public:
		CDateTime(std::string szTime) :m_szTime(szTime), m_mapMonths({ { "JAN", 0 }, { "FEB", 1 }, { "MAR", 2 }, { "APR", 3 }, { "MAY", 4 }, { "JUN", 5 }, { "JUL", 6 }, { "AUG", 7 }, { "SEP", 8 }, { "OCT", 9 }, { "NOV", 10 }, { "DEC", 11 } })
		{
		}
		const time_t& getTime(){ return m_time; }
		bool ValidateFormat()
		{
			if (m_szTime.length() != 9)
				return false;

			const char* pFormatString = m_szFormat.c_str();
			const char* pString = m_szTime.c_str();
			for (int i = 0; i < m_szFormat.length(); i++)
			{
				if (pFormatString[i] == m_cDelimeter)
					if (pString[i] == m_cDelimeter)
						continue;
					else
						return  false;
			}

			return true;
		}
		bool Check()
		{
			try
			{
				if (!ValidateFormat())
					return false;

				int nDay, nMonth, nYear;
				char sDate[10];
				strcpy_s(sDate, m_szTime.c_str());

				//Day
				char* sToken = strtok(sDate, &m_cDelimeter);
				if (isdigit(sToken[0]) > 0 && isdigit(sToken[1]) > 0)
					nDay = atoi(sToken);
				else
					return false;

				//Month
				std::string sMonth = strtok(nullptr, &m_cDelimeter);
				std::transform(sMonth.begin(), sMonth.end(), sMonth.begin(), ::toupper);
				nMonth = m_mapMonths.at(sMonth);

				//Year
				sToken = strtok(nullptr, &m_cDelimeter);
				if (isdigit(sToken[0]) > 0 && isdigit(sToken[1]) > 0)
					nYear = atoi(sToken);
				else
					return false;

				if (nYear > 0 && nDay > 0)
				{
					tm datetime = { 0 };
					datetime.tm_mon = nMonth;
					datetime.tm_mday = nDay;
					datetime.tm_year = nYear + 2000 - 1900;

					m_time = mktime(&datetime);
					if (m_time == -1)
						return false;
				}
				else
					return false;
				return true;
			}
			catch (...)
			{
				return false;
			}
		}
		bool operator <(CDateTime& timeObj) //Will b used to compare dates..
		{
			double seconds = difftime(m_time, timeObj.getTime());
			if (seconds > 0)
				return false;
			return true;
		}
		bool operator >(CDateTime& timeObj) //Will b used to compare dates..
		{
			double seconds = difftime(m_time, timeObj.getTime());
			if (seconds > 0)
				return true;
			return false;
		}
	};
}