#include "effect.h"
#include "datasystem.h"
#include "settings.h"
#include "effect.h"

dataSystem ds_ef;

namespace gS = gSettings; //May not need, will see

Effect::Effect() {
}

int Effect::getEID() {
	return eID;
}

string Effect::getEName() {
	return eName;
}

void Effect::updateIEffect(int pos, int update) {
	Effects.at(pos).updateIVal(update);
}

void Effect::updateFEffect(int pos, float update) {
	Effects.at(pos).updateFVal(update);
}

void Effect::addEffect(int effId) {
	//Get data from database

	//Effects.push_back()
}

//Commintented out because it is no longer needed here but leaving it in case it needs to be used somewhere else
/*float Effects::getModDmg(vector<string> dtyps, float dmg, string targ, int wid)
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
}*/




