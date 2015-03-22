#include "Cache.h"
#include "RecordSet.h"

#include "ProcessObject.h"
#include "CurrencyObject.h"

#include <iostream>

using namespace el;


	
bool CCache::Load(const std::string& strCSVFile, IntKeyObjectCache& mapObjectCache, CObject::eObjectTypes eObjectType)
{
	el::CRecordSet csv(strCSVFile);
	csv.LoadFromFile();
	
	//Looping the list and Loading in the cache will come here
	auto& lstCSV = csv.GetCSVRowList();
	
	
	//Ignore the first item in the list since it contains column header.
	auto itr = lstCSV.begin();
	for (++itr; itr != lstCSV.end(); ++itr)
	{
			CCSVRow& rowVec = *(*itr);
									
			switch(eObjectType)
			{
				case CObject::eProcessObject:
				{
					shared_ptr<CProcessObject> processObj(new CProcessObject());
					processObj->LoadFromRecord(rowVec);
					
					mapObjectCache.insert(pair<unsigned int, shared_ptr<CObject>> (processObj->GetProcessID(), processObj));
				}
				break;
			}
		
	}
	
	return true;
}
bool CCache::Load(const std::string& strCSVFile, StringKeyObjectCache& mapObjectCache, CObject::eObjectTypes eObjectType)
{
	el::CRecordSet csv(strCSVFile);
	csv.LoadFromFile();
	
	//Looping the list and Loading in the cache will come here
	auto& lstCSV = csv.GetCSVRowList();
	
	
	//Ignore the first item in the list since it contains column header.
	auto itr = lstCSV.begin();
	for (++itr; itr != lstCSV.end(); ++itr)
	{
			CCSVRow& rowVec = *(*itr);
									
			switch(eObjectType)
			{
				case CObject::eCurrencyObject:
				{
					shared_ptr<CCurrencyObject> currencyObj(new CCurrencyObject());
					currencyObj->LoadFromRecord(rowVec);
					
					mapObjectCache.insert(pair<string, shared_ptr<CObject>> (currencyObj->GetCurrencyID(), currencyObj));
				}
				break;
			}
	}
	
	return true;
}

bool CCache::LoadAll()
{
	Load("../../test/Process.csv", GetProcessCache(), CObject::eProcessObject);
	Load("../../test/Currency.csv", GetCurrencyCache(), CObject::eCurrencyObject);
	//Load("Currency.csv" ..)
	//Load("InterestRate.csv" ..)
	return true;
}