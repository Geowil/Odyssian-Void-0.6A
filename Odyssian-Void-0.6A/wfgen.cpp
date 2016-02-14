#include "wfgen.h"
#include "datasystem.h"

dataSystem ds_wfg;


wFGen::wFGen()
{
	eID = 0;
}
		
void wFGen::iWFGen(int eid)
{
	ds_wfg.rData("Warp Field Generator", "select from", eid);

	
	wfgName = ds_wfg.getSEName();
	eID = eid;
	wfgSMax = ds_wfg.getSESMax(); //Max Speed
	wfgPCon = ds_wfg.getSEPCon(); //Initial Power Consumption (powering up cost; different from continuous drain)
	wfgCReq = ds_wfg.getSECReq(); //CPU Requirement
	wfgRReq = ds_wfg.getSERReq(); //RAM Requirement
	wfgPSReq = ds_wfg.getSEPReq(); //Power System Requirement
	wfgCDrain = ds_wfg.getSECDrain(); //Secondry Power System Drain per AU
	wfgDTime = ds_wfg.getSEDTime(); //Delay to warp in ms

}
	
bool wFGen::bIsInstalled()
{
	return eID != 0;
}

string wFGen::getName()
{
	return wfgName;
}

int wFGen::getID()
{
	return eID;
}

float wFGen::getSMax()
{
	return wfgSMax;
}

float wFGen::getCReq()
{
	return wfgCReq;
}

float wFGen::getRReq()
{
	return wfgRReq;
}

float wFGen::getPSReq()
{
	return wfgPSReq;
}

float wFGen::getCDrain()
{
	return wfgCDrain;
}

float wFGen::getPCon()
{
	return wfgPCon;
}

int wFGen::getDTime()
{
	return wfgDTime;
}



