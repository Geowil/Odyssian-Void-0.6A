#include "abelt.h"
#include "random.h"
#include "datasystem.h"
#include "globalvars.h"

dataSystem ds_a;

using std::uniform_real_distribution;
using std::uniform_int_distribution;
namespace gv = gVars;

aBelt::aBelt()
{

}

aBelt::aBelt(string name, float size, bool full)
{
	aBName = name;
	aBSize = size;
	bIsABFull = full;
}

aBelt::aBelt(string name, float size, int ramount, bool full)
{
	aBName = name;
	aBSize = size;
	numOfAsteroids = ramount;
	bIsABFull = full;
}

void aBelt::createAsteroids()
{
	bIsABFull = false;
	tempSize1 = 0.0f;
	tempSize2 = 0.0f;
	tempSize3 = 0.0f;

	asteroid_id = 0; //Reset aid

	while (!bIsABFull)
	{
		/*
		non-testing ranges:
		small: 75% of random max 1-37.5
		medium: 15% of random max 37.6-45.0
		large: 5% of random max 45.1-50.0

		*/



		rand5 = getFRange(gv::aSRRange.fLow, gv::aSRRange.fHigh);

		for (i1 = 0; i1 < gv::aStages; i1++) //Cycle through the stages
		{
			if ((rand5 >= gv::gPAData.at(i1).vRange3.fLow) && (rand5 <= gv::gPAData.at(i1).vRange3.fHigh)) //Until a match is found here (TODO: handle exception if no match is found)
			{
				aID = getIRange(gv::gPAData.at(i1).vRange1.iLow, gv::gPAData.at(i1).vRange1.iHigh);

				ds_a.rData("Ore", "select from", aID);

				tempSize1 = ds_a.getOBSize();

				//asteroid size calcualtion
				tempSize1 = tempSize1 * getFRange(gv::gPAData.at(i1).vRange2.fLow, gv::gPAData.at(i1).vRange2.fHigh);
				tempSize2 = (((tempSize1 * 10) / 4) * gv::gPAData.at(i1).aSMulti);
				tempSize3 += tempSize2;

				//TODO: In version 1.0 this function will need to change for positioning to include consideration for asteroid object bounds so asteroids are not stuck inside, fully or partially, other asteroids.
				addAsteroid(asteroid_id, ds_a.getOName(), ds_a.getOOre(), aID, ds_a.getODesc(), tempSize2, (tempSize2 / ds_a.getOSG2()), getIRange(-10, 30), getIRange(-8, 21), getIRange(-13, 32));
				asteroid_id += 1;
				break;
			}
		}

		//Check to see if tempSize2 is greater thean aBSize
		if (tempSize3 > aBSize)
		{
			//If it is then remove last asteroid
			tempSize3 -= tempSize2; //Remove the asteroid's size from the size total
			roids.erase(roids.begin()+roids.size()-1);
		}

		else if (tempSize3 <= aBSize)
		{
			if (numOfAsteroids == roids.size())
			{
				bIsABFull = true;
			}

			else if (tempSize3 == aBSize)
			{
				bIsABFull = true;
			}
		}

		//Check to make sure no other asteroid has the same coords
		if (roids.size() > 1)
		{
			for(i2 = 0; i2 < roids.size(); i2++)
			{
				for (i3 = 0; i3 < roids.size()-1; i3++)
				{
					if ((roids.at(i3).getXPos() == roids.at(i3+1).getXPos()) && (roids.at(i3).getYPos() == roids.at(i3+1).getYPos()) && (roids.at(i3).getZPos() == roids.at(i3+1).getZPos())) //If asteroid is at same coords then
					{
						tempSize3 -= roids.at(i3+1).getASize(); //Remove from total size
						roids.erase(roids.begin()+i3+1); //And then from the vector
						asteroid_id -= 1;
					}
				}
			}
		}
	}
}

void aBelt::addAsteroid(int aid, string aName, string aOName, int aOID, string aDesc, float aSize, float aOAmount, int x, int y, int z)
{
	roids.push_back(Asteroid(aid, aName, aOName, aOID, aDesc, aSize, aOAmount, x, y, z));
}

string aBelt::getABName()
{
	return aBName;
}

float aBelt::getABSize()
{
	return aBSize;
}

void aBelt::removeAsteroid(int i)
{
	roids.erase(roids.begin()+i);
}

bool aBelt::isFull()
{
	return bIsABFull;
}