#include <stdio.h>
#include <iostream>
#include <map>

#include "ProcessObject.h"
#include "CurrencyObject.h"

int main(int argc, char **argv)
{
	//el::CDatabase epsilonDB("Process.csv");
	//epsilonDB.LoadFromFile();
	
	el::CProcessObject processObj;
	
	el::TFieldDescriptor *pDesc = processObj.GetFieldDescriptor();
	
	std::cout << pDesc << std::endl;
	
	el::CProcessObject processObj1;
	
	pDesc = processObj1.GetFieldDescriptor();
	
	std::cout << pDesc << std::endl;
		
	for (int i = 0; !pDesc[i].IsEnd(); i++)
	{
		el::CField* pField = processObj.GetFieldPtr(pDesc[i].m_nOffset);
		
		std::cout << pDesc[i].m_nOffset << " " 
				  << pField->GetColumnId()  << " "
				  << pField->GetTypeId() << " "
				  << std::endl;
				  
	}
	
	std::cout << sizeof(el::CProcessObject) << std::endl;
	
	typedef std::map<unsigned int, el::CProcessObject*> ProcessObjectMap;
	typedef std::map<std::string, el::CCurrencyObject*> CurrencyObjectMap;
	
	
	ProcessObjectMap mapProcess;
	
	CurrencyObjectMap mapCurrency;
	
	el::CCurrencyObject dummyCurrObj;
	//mapProcess.insert(pair<unsigned int, el::CProcessObject> (processObj.GetProcessId(),&processObj));
	mapProcess[ processObj.GetProcessID() ] = &processObj;
	
	mapCurrency[ dummyCurrObj.GetCurrencyID() ] = &dummyCurrObj;
	
	
	printf("hello world\n");
	return 0;
}
