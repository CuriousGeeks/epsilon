
#include "Object.h"

using namespace el;

void CObject::LoadFromRecord(CCSVRow& rwCSV)
{
	
	for (auto& itr = rwCSV.begin(); itr != rwCSV.end(); ++itr)
	{
		val = (*itr);
	}
}