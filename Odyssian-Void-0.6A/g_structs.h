//Global Structs
#ifndef G_STRUCTS_H
#define G_STRUCTS_H

#include <vector>

#include "range.h"

using std::vector;

//Ships
struct sIDRange
{
	Range vRange;
};

//Weapons
struct wIDRange
{
	Range vRange;
};

//P. Shields
struct psIDRange
{
	Range vRange;
};

//P. Defenses
struct pdIDRange
{
	Range vRange;
};

//P. Types
struct ptRange
{
	Range vRange1; //Planet Size Range
	Range vRange2; //Planet Size Random
	Range vRange3; //Planet Outlier Check Range
	Range vRange4; //Planet Size Check Ranges
	vector<Range> pDChances; //Chances of a certain number of planetary defesnes for this planet
	vector<Range> pSChances; //Chances of a certain number of planetary shields for this planet
};

//Asteroid Data
struct aData
{
	Range vRange1; //Astroid Ore ID Range (int)
	Range vRange2; //Asteroid Size Range (float)
	Range vRange3; //Asteroid Stage Range - for asteroid belt filling
	float aSMulti;	//Asteroid Size Multiplier
};

//Skill Data
struct sData
{
	Range vRange; //Skill ID Range
};

#endif

