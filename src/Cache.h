#pragma once

#include<map>
#include<memory>

#include "Object.h"
#include "ProductRuleCache.h"


namespace el{

typedef std::map<std::string , std::shared_ptr<el::CObject>> StringKeyObjectCache;
typedef std::map<unsigned int, std::shared_ptr<el::CObject>> IntKeyObjectCache;

//class CProductRuleCache;
//class ProductRuleMap;
	
class CCache
{
	public:

	inline IntKeyObjectCache& GetProcessCache() { return m_mapProcessCache; }
	inline IntKeyObjectCache& GetInterestRateCache() { return m_mapInterestRateCache; }
	inline StringKeyObjectCache& GetCurrencyCache() { return m_mapCurrencyCache; }
	inline StringKeyObjectCache& GetErrorCodeCache() { return m_mapErrorCodeCache; }

	ProductRuleMap& GetProductRuleCache();
		
	bool LoadAll();
	
private:
	bool Load(const std::string& strCSVFile, IntKeyObjectCache& mapObjectCache, CObject::eObjectTypes eObjectType);
	bool Load(const std::string& strCSVFile, StringKeyObjectCache& mapObjectCache, CObject::eObjectTypes eObjectType);
	
	
	StringKeyObjectCache m_mapCurrencyCache;	
	StringKeyObjectCache m_mapErrorCodeCache;
	IntKeyObjectCache m_mapProcessCache;
	IntKeyObjectCache m_mapInterestRateCache;
	
	CProductRuleCache m_ProductRuleCache;
};
	
	
};