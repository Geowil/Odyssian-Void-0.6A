#include "engine.h"
#include "datasystem.h"

dataSystem ds_eng;

Engine::Engine()
{
	eID = 0;
}

void Engine::iEngine(int eid)
{
	ds_eng.rData("Engines","select from",eid);

	eName = ds_eng.getSEName();
	eID = eid;
	eMThrust = ds_eng.getSEMThrust();
	eSMax = ds_eng.getSENSMax();
	eTRCWgt = ds_eng.getSETRCWgt();
	ePReq = ds_eng.getSEPReq();
	eCReq = ds_eng.getSECReq();
	eRReq = ds_eng.getSERReq();
}

bool Engine::bIsInstalled()
{
	return eID != 0;

string Engine::getName()
{
	return eName;
}

int Engine::getID()
{
	return eID;
}

float Engine::getMThrust()
{
	return eMThrust;
}

float Engine::getSMax()
{
	return eSMax;
}

float Engine::getTRCWgt()
{
	return eTRCWgt;
}

float Engine::getPReq()
{
	return ePReq;
}

float Engine::getCReq()
{
	return eCReq;
}

float Engine::getRReq()
{
	return eRReq;
}



