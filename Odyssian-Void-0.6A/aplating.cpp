#include "aplating.h"
#include "datasystem.h"

dataSystem ds_ap;

aPlating::aPlating()
{
	eID = 0;
}

void aPlating::iAPlating(int eid)
{
	ds_ap.rData("Armor Plating","select from",eid);

	apName = ds_ap.getSEName();
	eID = eid;
	apMAP = ds_ap.getSEMAP();
	apRRate = ds_ap.getSERRate();
	apRPConsumption = ds_ap.getSERPCon();
	apPReq = ds_ap.getSEPReq();
	apCReq = ds_ap.getSECReq();
	apRReq = ds_ap.getSERReq();
}

bool aPlating::bIsInstalled()
{
	return eID != 0;

string aPlating::getName()
{
	return apName;
}

int aPlating::getID()
{
	return eID;
}

float aPlating::getMAP()
{
	return apMAP;
}

float aPlating::getRRate()
{
	return apRRate;
}

int aPlating::getRPCon()
{
	return apRPConsumption;
}

float aPlating::getPReq()
{
	return apPReq;
}

float aPlating::getCReq()
{
	return apCReq;
}

float aPlating::getRReq()
{
	return apRReq;
}



