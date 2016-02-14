#include "target.h";

target::target()
{

}

target::target(string tid)
{
	tID = tid;
}

void target::setTID(string tid)
{
	tID = tid;
}

void target::addSIDS(vector<string> sids)
{
	for (i1 = 0; i1 < sids.size(); i1++)
	{
		tSource = sids.at(i1);
		sID.push_back(tSource);
	}
}

vector<string> target::getTSources()
{
	return sID;
}

string target::getTID()
{
	return tID;
}
