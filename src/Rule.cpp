#include "Rule.h"

using namespace el;

bool Execute(const CCache& cache, CInterestRateObject& obj)
{
	return obj.IsBalanceBookValid();
}