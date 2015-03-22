
#include "Object.h"
#include "RecordSet.h"

using namespace el;

void CObject::LoadFromRecord(CCSVRow& rwCSV)
{
	
	auto& vecRow = rwCSV.GetVecRow();
	el::TFieldDescriptor *pDesc = this->GetFieldDescriptor();
	
	for (int i = 0; !pDesc[i].IsEnd(); i++)
	{
		el::CField* pField = this->GetFieldPtr(pDesc[i].m_nOffset);
		
		std::string strValue = vecRow[pField->GetColumnId()];
		
		pField->SetValue(strValue);
		
	}
}