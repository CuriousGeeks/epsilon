#include "Database.h"


using namespace el;

CDatabase::CDatabase(string szCSVFileName) :m_szCSVFileName(szCSVFileName)
{
}

bool CDatabase::LoadFromFile()
{
	ifstream file(m_szCSVFileName);
	if (!file) return false;
	while (file)
	{
		string szRow;
		getline(file, szRow);
		m_lstProcessTable.push_back(new CCSVRow(szRow));
	}
	return true;
}