#include "Rule.h"

using namespace el;

bool CBalanceBookRule::Execute(const CCache& cache, CInterestRateObject& obj)
{
	return obj.IsBalanceBookValid();
}