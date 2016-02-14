#include "wtsystem.h"
#include "datasystem.h"

dataSystem ds_wts;

wTSystem::wTSystem()
{
	eID = 0;
}

void wTSystem::iWTS(int eid)
{
	ds_wts.rData("Weapon Targeting System","select from",eid);

	wtsName = ds_wts.getSEName();
	eID = eid;
	wtsTTime = ds_wts.getSETTime();
	wtsMTargets = ds_wts.getSEMTargs();
	wtsPReq = ds_wts.getSEPReq();
	wtsCReq = ds_wts.getSECReq();
	wtsRReq = ds_wts.getSERReq();
}

bool wTSystem::bIsInstalled()
{
	return eID != 0;

string wTSystem::getName()
{
	return wtsName;
}

int wTSystem::getID()
{
	return eID;
}

float wTSystem::getTTime()
{
	return wtsNTMax;
}

float wTSystem::getMTargs()
{
	return wtsNSMax;
}

float wTSystem::getPReq()
{
	return wtsPReq;
}

float wTSystm::getCReq()
{
	return wtsCReq;
}

float wTSystem::getRReq()
{
	return wtsRReq;
}



