#include "effects.h"
#include "datasystem.h"
#include "globalvars.h"

dataSystem ds_ef;

namespace gv = gVars;

Effects::Effects()
{

}

float Effects::getModDmg(vector<string> dtyps, float dmg, string targ, int wid)
{
	/*
	for (int i = 0; i < dtyps.size(); i++)
	{
		for (int i2 = 0; i2 < gVars.dmgTypes.size(); i2++)
		{
			if (dtyps.at(i) == gVarms.dmgTypes.at(i2))
			{
				ds_ef.rData("Weapon", "select from", wid);
				dtVal = ds_ef.getDTVal();
				dtDur = ds_ef.getDTLng();

				break;
			}
		}
	}

	if (dtVal > 0.0f)
	{
		//do stuff
	}

	if ((dtDur > 0) && (dtyps.at(i) != "EMP#") && (dtyps.at(i) == "Virus#")
	{
		//do stuff
	}

	if (dtyps.at(i) == "EMP#")
	{
		//disable ship for turns
	}
	
	*/
}