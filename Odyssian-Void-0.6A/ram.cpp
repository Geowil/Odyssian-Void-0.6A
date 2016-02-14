#include "ram.h"
#include "datasystem.h"

dataSystem ds_ram;

RAM::RAM()
{
	eID = 0;
}

void RAM::iRAM(int eid)
{
	ds_ram.rData("RAM","select from",eid);

	rName = ds_ram.getSEName();
	eID = eid;
	rCMax = ds_ram.getSECMax();
	rPReq = ds_ram.getSEPReq();
}

bool RAM::bIsInstalled()
{
	return eID != 0;
}

string RAM::getName()
{
	return rName;
}

int RAM::getID()
{
	return eID;
}

float RAM::getCMax()
{
	return rCMax;
}

float Engine::getPReq()
{
	return rPReq;
}
