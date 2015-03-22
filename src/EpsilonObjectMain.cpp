#include <stdio.h>
#include <iostream>
#include <map>

#include "RecordSet.h"
#include "ProcessObject.h"
#include "CurrencyObject.h"
#include "Cache.h"

int main(int argc, char **argv)
{
	el::CCache cache;
	
	cache.LoadAll();
	
		
	auto& processCache = cache.GetProcessCache();
	
	auto& interestRateCache = cache.GetInterestRateCache();
	
	for (auto& processKV : processCache)
	{
		for (auto& interestRateKV : interestRateCache)
		{
			//interestRateKV.second
		}
	}
		
	
	printf("hello world\n");
	return 0;
}
