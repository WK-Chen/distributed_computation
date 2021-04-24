#include "pch.h"
#include <iostream>
#include "isum.h"
#include "ieo.h"
#include "ipo.h"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	ISum *myisum = CreateObject(3, 5);
	if (myisum)
	{
		int sum = myisum->getSum();
		cout << "sum=" << sum << endl;
		IPO *ipo = dynamic_cast<IPO*>(myisum);
		if (!ipo)
		{
			myisum->Delete();
		}
		else
		{
			cout << "mul=" << ipo->getMul();
		}
	}
	return 0;
}
