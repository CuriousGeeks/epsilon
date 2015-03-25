#include <stdio.h>
#include <iostream>
#include <map>

#include "RecordSet.h"
#include "ProcessObject.h"
#include "CurrencyObject.h"
#include "InterestRateObject.h"
#include "Cache.h"

int main(int argc, char **argv)
{
	el::CCache cache;
	
	cache.LoadAll();
	
		
	auto& processCache = cache.GetProcessCache();
	
	auto& interestRateCache = cache.GetInterestRateCache();
	
	auto& productRuleCache = cache.GetProductRuleCache();
	
	for (auto& processKV : processCache)
	{
		for (auto& interestRateKV : interestRateCache)
		{
			shared_ptr<el::CObject> obj = interestRateKV.second;
			
			el::CInterestRateObject *pInterestRateObj = (el::CInterestRateObject *)obj.get();
			
			//Fetch Rule to be run
			auto& lstRule = productRuleCache[ pInterestRateObj->GetProductType() ];
			
			for(auto& rule : lstRule)
			{
				if (!rule->Execute(cache, *pInterestRateObj))
				{
					//capture error code and write in csv.
				}
			}
		}
	}
		
	
	printf("hello world\n");
	return 0;
}
