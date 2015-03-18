#pragma once

#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

namespace el
{
	class CCSVRow: public vector<string>
	{
	public:
		CCSVRow(const string& szRow)
		{
			stringstream   lineStream(szRow);
			string         szCell;

			while (getline(lineStream, szCell, ','))
			{
				push_back(szCell);
			}
		}
	};

	class CRecordSet
	{
		string m_szCSVFileName;
		list<CCSVRow*> m_lstTable;
	public:
		CRecordSet(string szCSVFileName);
		~CRecordSet();				
		bool LoadFromFile();
		
		inline list<CCSVRow*>& GetCSVRowList() { return m_lstTable; }
		//LoadIntoMap()
	};

}

