#include "smatrix.h"
#include "datasystem.h"

dataSystem ds_sm;

sMatrix::sMatrix()
{
	eID = 0;
}

void sMatrix::iSMatrix(int eid)
{
	ds_sm.rData("Shield Matrix","select from",eid);

	smName = ds_sm.getSEName();
	eID = eid;
	smMSP = ds_sm.getSEMSP();
	smRRate = ds_sm.getSERRate();
	smRPConsumption = ds_sm.getSERPCon();
	smPReq = ds_sm.getSEPReq();
	smCReq = ds_sm.getSECReq();
	smRReq = ds_sm.getSERReq();
}

bool sMatrix::bIsInstalled()
{
	return eID != 0;

string sMatrix::getName()
{
	return smName;
}

int sMatrix::getID()
{
	return eID;
}

float sMatrix::getMSP()
{
	return smMSP;
}

float sMatrix::getRRate()
{
	return smRRate;
}

int sMatrix::getRPCon()
{
	return smRPConsumption;
}

float sMatrix::getPReq()
{
	return smPReq;
}

float sMatrix::getCReq()
{
	return smCReq;
}

float sMatrix::getRReq()
{
	return smRReq;
}



