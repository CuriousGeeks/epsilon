#include "RecordSet.h"

using namespace el;

CRecordSet::CRecordSet(string szCSVFileName) :m_szCSVFileName(szCSVFileName)
{
}

CRecordSet::~CRecordSet()
{
	for (auto Row : m_lstTable)
		delete Row;
}

bool CRecordSet::LoadFromFile()
{
	ifstream file(m_szCSVFileName);
	if (!file) return false;
	while (file)
	{
		string szRow;
		getline(file, szRow);
		m_lstTable.push_back(new CCSVRow(szRow));
	}
	return true;
}