#include "pch.h"
#include "sum.h"

Sum::Sum(int a, int b) :m_refcount(1)
{
	this->a = a;
	this->b = b;
	InterlockedIncrement(&m_refcount);
}

Sum::~Sum(void)
{
	InterlockedDecrement(&m_refcount);
}
void Sum::Delete() {
	delete this;
}
void _stdcall Sum::Save()
{
}
int __stdcall Sum::addRef()
{
	return InterlockedIncrement(&m_refcount);
}
int __stdcall Sum::release()
{
	if (0 == InterlockedDecrement(&m_refcount)) {
		delete this;

		return 0;
	}
	return m_refcount;
}
int Sum::getSum(void)
{
	return a + b;
}

int _stdcall Sum::getMul()
{
	return a * b;
}

void Sum::Dynamic(const char *name, void**ppI)
{
	if (strcmp(name, "ISum") == 0)
		*ppI = (ISum*)this;
	else if (strcmp(name, "IPO") == 0)
		*ppI = (IPO*)this;
	else  if (strcmp(name, "IEO") == 0)
		*ppI = (IPO*)this;
}

ISum* CreateObject(int a, int b)
{
	return new Sum(a, b);
}
