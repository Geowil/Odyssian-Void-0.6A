#include "spsystem.h"
#include "datasystem.h"

dataSystem ds_sps;

sPSystem::sPSystem()
{
	eID = 0;
}

void sPSystem::iSPS(int eid)
{
	ds_sps.rData("Capacitors","select from",eid);

	spsName = ds_sps.getSEName();
	eID = eid;
	spsCMax = ds_sps.getSECMax();
	spsCReq = ds_sps.getSECReq();
	spsRReq = ds_sps.getSERReq();
}

bool sPSystem::bIsInstalled()
{
	return eID != 0;

string sPSystem::getName()
{
	return spsName;
}

int sPSystem::getID()
{
	return eID;
}

float sPSystem::getCMax()
{
	return spsCMax;
}

float sPSystem::getCReq()
{
	return spsCReq;
}

float sPSystem::getRReq()
{
	return spsRReq;
}



