
#include "Object.h"

using namespace el;

void CObject::LoadFromRecord(CCSVRow& rwCSV)
{
	
	/*for (auto& itr = rwCSV.begin(); itr != rwCSV.end(); ++itr)
	{
		val = (*itr);
	}*/
	el::TFieldDescriptor *pDesc = this->GetFieldDescriptor();
	
	for (int i = 0; !pDesc[i].IsEnd(); i++)
	{
		el::CField* pField = this->GetFieldPtr(pDesc[i].m_nOffset);
		
		std::string strValue; // = rwCSV[pField->GetColumnId()];
		
		pField->SetValue(strValue);
		
		/*std::cout << pDesc[i].m_nOffset << " " 
				  << pField->GetColumnId()  << " "
				  << pField->GetTypeId() << " "
				  << std::endl;*/
				  
		
	}
}