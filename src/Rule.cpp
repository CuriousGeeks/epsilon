#include "Rule.h"

using namespace el;

bool CBalanceBookRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsBalanceBookValid();
}
bool CDateIssueRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsIssueDateValid();
}
bool CDateIssueAndDateDataRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsIssueDateValidForData();
}
bool CDateMaturityRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsMaturityDateValid();
}
bool CDateMaturityAndDateDataRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsMaturityDateValidForData();
}
bool CPaymentFreqRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsPaymentFreqValid();
}
bool CPaymentFreqUnitRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsPaymentFreqUnitValid();
}
bool CResetFreqRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsResetFreqValid();
}
bool CResetFreqUnitRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsResetFreqUnitValid();
}
bool CRateIndexRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsRateIndexValid();
}
bool CAssetLiabilityRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsAssetLiabilityValid();
}
bool CBusinessDayConventionRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsBusinessDayConventionValid();
}
bool CAccrualBasisRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsAccrualBasisValid();
}
bool CFlagPaymentRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsFlagPaymentValid();
}
bool CCalendarPaymentRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsCalendarPaymentValid();
}
bool CCalendarResetRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsCalendarResetValid();
}
bool CRateCustomerRule::Execute(const CCache& cache, const CInterestRateObject& obj)
{
	return obj.IsRateCustomerValid();
}
