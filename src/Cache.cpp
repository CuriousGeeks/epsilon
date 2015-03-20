#include "Cache.h"
#include "Database.h"
using namespace el;


	
bool CCache::Load(std::string& strCSVFile, IntKeyObjectCache& mapObjectCache, CObject::eObjectTypes eObjectType, int nKeyColumnId)
{
	el::CDatabase csv(strCSVFile);
	csv.LoadFromFile();
	
	//Looping the list and Loading in the cache will come here
	auto& lstCSV = csv.GetCSVRowList()
	
	for (auto& itr = lstCSV.begin(); itr != lstCSV.end(); ++itr)
	{
			CCSVRow& rowVec = *(*itr);
			
			switch(eObjectType)
			{
				case CObject::eProcessObject:
				{
					CProcessObject* pProcessObj = new CProcessObject();
					
					pProcessObj->
				}
			}
			new
	}
	
	return true;
}
bool CCache::Load(std::string& strCSVFile, StringKeyObjectCache& mapObjectCache, CObject::eObjectTypes eObjectType, int nKeyColumnId)
{
	el::CDatabase epsilonProcessCSV(strCSVFile);
	epsilonProcessCSV.LoadFromFile();
	
	//Looping the list and Loading in the cache will come here
	
	return true;
}

bool CCache::LoadAll()
{
	//Load("Process.csv" ..)
	//Load("Currency.csv" ..)
	//Load("InterestRate.csv" ..)
	return true;
}