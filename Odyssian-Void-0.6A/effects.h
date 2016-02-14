#ifndef EFFECTS_H
#define EFFECTS_H

#include <string>
#include <vector>

struct Effects
{
public:
	Effects();

	float getModDmg(vector<string> dtyps, float dmg, string targ, int wid); //Calculate modified damage based on damage types

private:
	float	dmgMod; //Damage mod val
	int		gmDur;  //Damage duration in turns
};

#endif;