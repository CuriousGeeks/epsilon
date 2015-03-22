#pragma once

#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

namespace el
{
	class CCSVRow
	{
	public:
		CCSVRow(const string& szRow)
		{
			stringstream   lineStream(szRow);
			string         szCell;

			while (getline(lineStream, szCell, ','))
			{
				m_vecRow.push_back(szCell);
			}
		}
		
		inline const vector<string>& GetVecRow() {return m_vecRow;}
	private:	
		vector<string> m_vecRow;
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

