#include "Rule.h"
#include "Cache.h"

using namespace el;

bool CBalanceBookRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	return obj.IsBalanceBookValid();
}
bool CDateIssueRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	return obj.IsIssueDateValid();
}
bool CDateIssueAndDateDataRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	return obj.IsIssueDateValidForData();
}
bool CDateMaturityRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	return obj.IsMaturityDateValid();
}
bool CDateMaturityAndDateDataRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	return obj.IsMaturityDateValidForData();
}
bool CPaymentFreqRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	return obj.IsPaymentFreqValid();
}
bool CPaymentFreqUnitRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	return obj.IsPaymentFreqUnitValid();
}
bool CResetFreqRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	return obj.IsResetFreqValid();
}
bool CResetFreqUnitRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	return obj.IsResetFreqUnitValid();
}
bool CRateIndexRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	return obj.IsRateIndexValid();
}
bool CAssetLiabilityRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	return obj.IsAssetLiabilityValid();
}
bool CBusinessDayConventionRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	return obj.IsBusinessDayConventionValid();
}
bool CAccrualBasisRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	return obj.IsAccrualBasisValid();
}
bool CFlagPaymentRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	return obj.IsFlagPaymentValid();
}
bool CCalendarPaymentRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	auto& currencyCache = cache.GetCurrencyCache();
	return currencyCache.find(obj.GetCalendarPayment()) != currencyCache.end();
}
bool CCalendarResetRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	auto& currencyCache = cache.GetCurrencyCache();
	return currencyCache.find(obj.GetCalendarPayment()) != currencyCache.end();
}
bool CRateCustomerRule::Execute(CCache& cache, CInterestRateObject& obj)
{
	return obj.IsRateCustomerValid();
}
