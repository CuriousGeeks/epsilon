#pragma once

#include<map>
#include<memory>

#include "ProcessObject.h"

namespace el{

typedef std::map<std::string , std::shared_ptr<el::CObject>> StringKeyObjectCache;
typedef std::map<unsigned int, std::shared_ptr<el::CObject>> IntKeyObjectCache;
	
class CCache
{
	public:

	inline IntKeyObjectCache& GetProcessCache() { return m_mapProcessCache; }
	inline IntKeyObjectCache& GetInterestRate() { return m_mapInterestRateCache; }
	inline StringKeyObjectCache& GetCurrencyCache() { return m_mapCurrencyCache; }
	
	bool LoadAll();
private:
	bool Load(std::string& strCSVFile, IntKeyObjectCache& mapObjectCache, CObject::eObjectTypes eObjectType, int nKeyColumnId);
	bool Load(std::string& strCSVFile, StringKeyObjectCache& mapObjectCache, CObject::eObjectTypes eObjectType, int nKeyColumnId);
	
	
	StringKeyObjectCache m_mapCurrencyCache;	
	IntKeyObjectCache m_mapProcessCache;
	
	IntKeyObjectCache m_mapInterestRateCache;
};
	
	
};