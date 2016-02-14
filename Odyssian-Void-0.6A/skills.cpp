#include "skills.h";
#include "datasystem.h"

dataSystem sk_ds;

Skill::Skill()
{

}

void Skill::newSkill(int id)
{
	sk_ds.rData("Skills","select from",id);
	
	sID = id;
	//sName = sk_ds.getSkName();
	//sDesc = sk_ds.getSkDesc();
	//sEffect = sk_ds.getSkEffect();
	//sGroup = sk_ds.getSkGroup();
	//sTTime = sk_ds.getSkTTime();
	//sTDiff = sk_ds.getSkTDiff();
	sRank = 0;
}



void Skill::rankUp()
{
	sRank += 1;
}

void Skill::checkTTime()
{
	if (sCTTime >= sTTime)
	{
		rankUp();
		sCTTime = 0;
		sTTime = (sRank * 2.0f) * 21.2f * sRank / (((/*(*/sTDiff /*+ getSkMods())*/ * (sRank * 20.1f)) / 2.0f) / 1.4f); //getSkMods would be a function that would return any bonuses applied to skill training times by training skills.  Note that the larger the value of sTDiff the shorter the training time.
	}	
}

string Skill::getSName()
{
	return sName;
}

string Skill::getSDesc()
{
	return sDesc;
}

string Skill::getSEffect()
{
	return sEffect;
}

int Skill::getTTime()
{
	return sTTime;
}

int Skill::getSRank()
{
	return sRank;
}

void Skill::aTraining(int i)
{
	sCTTime += i;
}

int Skill::getSID()
{
	return sID;
}