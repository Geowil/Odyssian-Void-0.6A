#ifndef MINING_H
#define MINING_H

#include <string>
#include <vector>

#include "entity.h"
#include "planet.h"

using std::string;
using std::vector;

class Mining
{
public:

	Mining();

	void mLoop(Player& mPlayer, aBelt* belt); //Mining loop
	void mSCycle(Player& mPlayer, aBelt* belt); //Starts a mining cycle
	void mECycle(Player& mPlayer, aBelt* belt); //Ends mining cycle
	void mSOre(Player& mPlayer, aBelt* belt); //Begins storage process for mined ore

	void mTAsteroid(Player& mPlayer, aBelt* belt); //Pick an asteroid to target
	void mUAsteroid(Player& mPlayer); //Untarget target an asteroid
	void mSAsteroid(aBelt* belt, Player& mPlayer); //Scan asteroids for information - only those within mTRange

	void mPMShip(Player& mPlayer, aBelt* belt); //Move player ship

	vector<int> sAsteroids; //Scanned asteroids, store as an int based on position in belt's vector.  Closets to furtherst order 

private:
	bool bDMining; //bool: done mining?
	bool bMCycle; //bool: are we currently in a mining cycle?
	bool bNChange; //bool: while time has not changed (in seconds)
	bool bContinue;
	float mEOre; //Total extracted ore
	int rand1,i,i2,i3,pChoice;

	int mCTime_new,mCTime_old,mCTime_left; //For keeping track of how much time as passed in a cycle
	int mCLength; //Store the length of the mining cycle for currently loaded mining laser

	float tempDist,tempDist1,tempDist2; //Store distance between player and asteroid for comparison

	int tempRoid1, tempRoid2; //Storage for sorting

	int mPRPoint; //Player reference point for moving the ship

	//Values from Player ship
	int mTDist; //Max target distance
	float mOPCycle; //Ore mined per cycle
	int pPosX, pPosY, pPosZ; //Player position

	bool bPHMLaser; //bool: player has a mining laser installed?

	bool bTarget,bTIsDone;
};

class Cycle
{
public:
	Cycle(int clen, int time_left)
	{
		mlCLen = clen;
		mCTime_left = time_left;
		bIsCompleted = false;
	}

	int getCLen()
	{
		return mlCLen;
	}

	
	void setMCOld(int old)
	{
		mCTime_old = old;
	}

	void mCycle()
	{
		if (!bIsCompleted)
		{
			int mCTime_new = GetTickCount(); //Get current tick count for comparison to mCOld_time

			if (mCTime_old != ((mCTime_new + 500) / 1000)) //Do calculations to see if time has passed since mCTime_old was set
			{
				//If it has then update mCTime_old and remove one second from mCTime_left.
				mCTime_old = ((mCTime_new + 500) / 1000);
				mCTime_left -= 1000;
			}

			cur_time = mCTime_left;
		}

		else
		{
			mCTime_left = 0;
		}
	}

	int getCTime()
	{
		return cur_time;
	}

	int getCTLeft()
	{
		return mCTime_left;
	}

	void mCComp()
	{
		bIsCompleted = true;
	}

	bool getCompleted()
	{
		return bIsCompleted;
	}

private:
	int mlCLen; //Time of a complete mining cycle
	int cur_time; //The current time remaining in the current mining cycle; will be removing this as it is just a copy of mCTime_left that I was going to use for another possiblity to make this code work
	int mCTime_left; //The current time remaining in the current mining cycle
	int mCTime_old; //The last time that mCycle was called

	bool bIsCompleted; //Flag to check if a mining cycle has already been accounted for as completed

};
#endif


