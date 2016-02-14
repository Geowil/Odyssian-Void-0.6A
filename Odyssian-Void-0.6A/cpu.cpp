#include "cpu.h"
#include "datasystem.h"

dataSystem ds_cpu;

CPU::CPU()
{
	eID = 0;
}

void CPU::iCPU(int eid)
{
	ds_cpu.rData("CPU","select from",eid);

	cName = ds_cpu.getSEName();
	eID = eid;
	cPMax = ds_cpu.getSEPMax();
	cPReq = ds_cpu.getSEPReq();
}

bool CPU::bIsInstalled()
{
	return eID != 0;
}

string CPU::getName()
{
	return cName;
}

int CPU::getID()
{
	return eID;
}

float CPU::getPMax()
{
	return cPMax;
}

float Engine::getPReq()
{
	return cPReq;
}



