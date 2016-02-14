#include "psystem.h"
#include "datasystem.h"

dataSystem ds_psys;

pSystem::pSystem()
{
	eID = 0;
}

void pSystem::iPS(int eid)
{
	ds_psys.rData("Power Systems","select from",eid);

	psName = ds_psys.getSEName();
	eID = eid;
	psCMax = ds_psys.getSECMax();
	spsRRate = ds_psys.getSESRRate();
	psCReq = ds_psys.getSECReq();
	psRReq = ds_psys.getSERReq();
}

bool pSystem::bIsInstalled()
{
	return eID != 0;
}

string pSystem::getName()
{
	return psName;
}

int pSystem::getID()
{
	return eID;
}

float pSystem::getCMax()
{
	return psCMax;
}

float pSystem::getSRRate()
{
	return spsRRate;
}

float pSystem::getCReq()
{
	return psCReq;
}

float pSystem::getRReq()
{
	return psRReq;
}



