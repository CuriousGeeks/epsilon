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
		
		if (szRow.size() > 0)
		{
			m_lstTable.push_back(new CCSVRow(szRow));
		}
	}
	return true;
}

void CRecordSet::AddRow(std::string szRow)
{
	m_lstTable.push_back(new CCSVRow(szRow));
}

bool CRecordSet::WriteToFile()
{
	ofstream file(m_szCSVFileName);
	if (!file) return false;
	for (CCSVRow* Row : m_lstTable)
	{
		ostringstream os;
		for (auto Cell : Row->GetVecRow())
		{
			os << Cell<<",";
		}
		file << os.str() <<std::endl;
	}
}