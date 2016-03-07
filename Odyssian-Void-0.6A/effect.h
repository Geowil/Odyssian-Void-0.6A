/*FILE HEADER

File Name:
Effect

File Description:
This class will be used to create vectors in other classes to hold any and all data related to effects that will be applied through that object (eg: weapons)

Created On:  Sunday, March 06, 2016 (file header added on this date)

Version:
1.0 - 03/06/2016


Changes:
1.0:
-Renamed from Effects to Effect, see next update point
-Refocused this class to providing abstraction/instancing to other classes to store one effect name and related data per instance.
-Added several new functions and class variables
-Added using statements for string and vector


End File Header*/

#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <vector>

#include "key_value.h"

using std::string;
using std::vector;

struct Effect
{
public:
	Effect();

	//float getModDmg(vector<string> dtyps, float dmg, string targ, int wid); //Calculate modified damage based on damage types //Left in but commented out in case I need this later to add somewhere else
	int getEID(); //Return effect id
	string getEName(); //Return effect name

	void updateIEffect(int pos, int update); //Update an int effect
	void updateFEffect(int pos, float update); //Update a float effect
	
	//Used in only specific situations, most of time these will be setup with the creation of the weapon but may have some times where an effect is granted by a skill or something
	void addEffect(int effId); //Add an effect to the vector


private:
	int eID; //Effect ID
	string eName; //Effect Name

	vector<keyVal> Effects; //Vector of effects and the modifier values; either int or float right now
};

#endif;