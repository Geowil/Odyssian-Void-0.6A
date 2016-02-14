#include "res.h"

Resource::Resource(string name, int val)
{
	rName = name;
	rVal = val;
}

int Resource::getRes()
{
	return rVal;
}

void Resource::updateRes(string op, int val)
{
	if (op == "add")
	{
		rVal += val;
	}

	else if (op == "sub")
	{
		rVal -= val;
	}

	else if (op == "set")
	{
		rVal = val;
	}
}