// EpsilonDQProcess.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include <map>

#include "RecordSet.h"
#include "ProcessObject.h"
#include "CurrencyObject.h"
#include "ErrorCodeObject.h"
#include "Cache.h"

int main()
{
	el::CCache cache;

	cache.LoadAll();


	auto& processCache = cache.GetProcessCache();

	auto& interestRateCache = cache.GetInterestRateCache();

	auto& productRuleCache = cache.GetProductRuleCache();

	auto& errorCodeCache = cache.GetErrorCodeCache();

	el::CRecordSet Report("../test/Report.csv");

	for (auto& processKV : processCache)
	{
		for (auto& interestRateKV : interestRateCache)
		{
			shared_ptr<el::CObject> obj = interestRateKV.second;

			el::CInterestRateObject *pInterestRateObj = (el::CInterestRateObject *)obj.get();

			//Fetch Rule to be run
			auto& lstRule = productRuleCache[pInterestRateObj->GetProductType()];

			for (auto& rule : lstRule)
			{
				if (!rule->Execute(cache, *pInterestRateObj))
				{
					std::string szErrorCode = rule->GetErrorCode();
					auto ItrErrCode = errorCodeCache.find(szErrorCode);
					if (ItrErrCode != errorCodeCache.end())
					{
						std::shared_ptr<el::CObject >ErrorCodeObj = (*ItrErrCode).second;
						el::CErrorCodeObject* pErrorCode = (el::CErrorCodeObject*)ErrorCodeObj.get();
						
						ostringstream os;
						os << pInterestRateObj->GetTableName() << "," << pInterestRateObj->GetProductType() << "," << pInterestRateObj->GetInstrumentID() << "," << szErrorCode
							<< "," << pErrorCode->GetFieldName() << "," << pErrorCode->GetDescription();
						Report.AddRow(os.str());
						cout << os.str() << endl;
					}
				}
			}
		}
	}

	Report.WriteToFile();
	//printf("hello world\n");
	char ch;
	cin >> ch;
	return 0;
}

