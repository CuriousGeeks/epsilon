// RuleProc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Rule.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	el::CRule* bPtr;
	el::CBalanceBookRule checkBalanceBook;
	bPtr = &checkBalanceBook;

	el::CCache cache;
	el::CObject obj;

	if (bPtr->Execute(cache, obj))
		cout << "Rule passed" << endl;
	else
		cout << "Rule failed" << endl;
	return 0;
}

