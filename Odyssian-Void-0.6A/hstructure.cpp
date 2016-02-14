#include "hstructure.h"
#include "datasystem.h"

dataSystem ds_hs;

hStructure::hStructure()
{
	eID = 0;
}

void hStructure::iHS(int eid)
{
	ds_hs.rData("Hull Structure","select from",eid);

	hsName = ds_hs.getSEName();
	eID = eid;
	hsMHP = ds_hs.getSEMHP();
	hsRRate = ds_hs.getSERRate();
	hsRPConsumption = ds_hs.getSERPCon();
	hsPReq = ds_hs.getSEPReq();
	hsCReq = ds_hs.getSECReq();
	hsRReq = ds_hs.getSERReq();
}

bool hStructure::bIsInstalled()
{
	return eID != 0;

string hStructure::getName()
{
	return hsName;
}

int hStructure::getID()
{
	return eID;
}

float hStructure::getMHP()
{
	return hsMHP;
}

float hStructure::getRRate()
{
	return hsRRate;
}

int hStructure::getRPCon()
{
	return hsRPConsumption;
}

float hStructure::getPReq()
{
	return hsPReq;
}

float hStructure::getCReq()
{
	return hsCReq;
}

float hStructure::getRReq()
{
	return hsRReq;
}



