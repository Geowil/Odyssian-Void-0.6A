#include "mining.h"
#include "msgproc.h"
#include "map.h"
#include <thread>
#include <Windows.h>

msgProc mp_mn;
Map	m_mn;

using std::cout;
using std::cin;
using std::thread;
using std::endl;




Mining::Mining()
{

}

void Mining::mLoop(Player& mPlayer, aBelt* belt)
{
	bDMining = false;
	bTIsDone = false;

	//Get some basic values from player ship
	//bPHMLaser = mPlayer.ship.getMLInfo(&mCLength, &mTDist, &mOPCycle);

	if (bPHMLaser)
	{
		//Temp for now, only one mining laser can be used so call this
		//mp_mn.mMLInfo(mCLength, mTDist, mOPCycle);

		while (!bDMining)
		{
			if (sAsteroids.size() == 0) //If no asteroids have been scanned
			{
				pChoice = mp_mn.mMenu1A();

				switch (pChoice)
				{
				case 1:
					mSAsteroid(belt, mPlayer);
					break;

				case 2:
					mPMShip(mPlayer, belt);
					break;

				case 3: //quit
					bDMining = true;
					break;

				default:
					mSAsteroid(belt, mPlayer);
					break;
				}
			}

			else if ((sAsteroids.size() > 0) && (mPlayer.ship.sTargets.size() == 0) && (!bTIsDone)) //If asteroids have been scanned, the player has 0 targets, and bTIsDone is false
			{
				pChoice = mp_mn.mMenu1B();

				switch (pChoice)
				{
				case 1:
					mSAsteroid(belt, mPlayer);
					break;

				case 2:
					mTAsteroid(mPlayer, belt);
					break;

				case 3:
					mPMShip(mPlayer, belt);
					break;

				case 4:
					bTIsDone = true;
					break;

				case 5:
					bDMining = true;
					break;

				default:
					mSAsteroid(belt, mPlayer);
					break;
				}
			}

			else if ((sAsteroids.size() > 0) && (mPlayer.ship.sTargets.size() >= 1) && (bTIsDone) && (!bMCycle)) //If asteroids have been scanned, the player has 1 or more targets, bTIsDone is true, and not in mining cycle
			{
				pChoice = mp_mn.mMenu1C();

				switch (pChoice)
				{
				case 1:

					mSCycle(mPlayer, belt);
					break;
					
				case 2:
					mCTargets();
					break;

				case 3:
					bDMining = true;
					break;

				default:
					mSAsteroid(belt, mPlayer);
					break;
				}
			}

			else if ((sAsteroids.size() > 0) && (mPlayer.ship.sTargets.size() >= 1) && (bTIsDone) && (bMCycle)) //If asteroids have been scanned, the player has 1 or more targets, bTIsDone is true, and in mining cycle
			{
				pChoice = mp_mn.mMenu1D();

				switch (pChoice)
				{
				case 1:
					mSCycle(mPlayer, belt);
					break;

				case 2:
					mSTCycle(mPlayer, belt);
					break;

				case 3:
					mCTargets();
					break;

				case 4:
					bDMining = true;
					break;

				default:
					mSTCycle(mPlayer, belt);
					break;
				}
			}
		}
	}

	else
	{
		cout << mp_mn.mRMessage(2049) << endl;
	}
}

void Mining::mSAsteroid(aBelt* belt, Player& mPlayer)
{
	pPosX = mPlayer.ship.getXPos();
	pPosY = mPlayer.ship.getYPos();
	pPosZ = mPlayer.ship.getZPos();

	//Clear sAsteroids before using it again if it is not empty
	if (sAsteroids.size() > 0)
	{
		sAsteroids.clear();
	}

	//TODO: Only scan asteroids within scanning range (based on ship stat)
	//TODO 0.7+: Only scan if an asteroid scanner is present on the ship
	for (i2 = 0; i2 < belt->roids.size(); i2++)
	{
		sAsteroids.push_back(i2);
	}

	//Arrange based on distance from player; closest to furthest
	for (i2 = 0; i2 < sAsteroids.size(); i2++)
	{
		for (i3 = 0; i3 < sAsteroids.size() - 1; i3++)
		{
			tempDist1 = m_mn.getDistance(mPlayer.ship.getXPos(), belt->roids.at(sAsteroids.at(i3)).getXPos(), mPlayer.ship.getYPos(), belt->roids.at(sAsteroids.at(i3)).getYPos(), mPlayer.ship.getZPos(), belt->roids.at(sAsteroids.at(i3)).getZPos());
			tempDist2 = m_mn.getDistance(mPlayer.ship.getXPos(), belt->roids.at(sAsteroids.at(i3 + 1)).getXPos(), mPlayer.ship.getYPos(), belt->roids.at(sAsteroids.at(i3 + 1)).getYPos(), mPlayer.ship.getZPos(), belt->roids.at(sAsteroids.at(i3 + 1)).getZPos());

			if (tempDist2 < tempDist1)
			{
				tempRoid1 = sAsteroids.at(i3 + 1);
				tempRoid2 = sAsteroids.at(i3);

				sAsteroids.at(i3) = tempRoid1;
				sAsteroids.at(i3 + 1) = tempRoid2;
			}
		}
	}

	cout << mp_mn.mRMessage(2032) << endl;
	mp_mn.mCScreen(true);
}

void Mining::mTAsteroid(Player& mPlayer, aBelt* belt)
{
	bContinue = true;

	while (bContinue)
	{		
		if (sAsteroids.size() > 0) //If there are scanned asteroids then continue
		{
			if (mPlayer.ship.sTargets.size() < 0) //If the player has no targets, start targeting system
			{				
				pChoice = mp_mn.mTMenuA();

				switch (pChoice)
				{
				case 1:
					tempRoid1 = mp_mn.mCTarget(belt->roids, sAsteroids, mPlayer, mTDist);
					
					tempRoid2 = sAsteroids.at(tempRoid1); //Get the asteroid id in belt from sAsteroids and save in tempRoid2 for easier calling in the below function

					//Send aID and target distance to addTarget
					mPlayer.ship.addTarget(belt->roids.at(tempRoid2).getAID(), m_mn.getDistance(mPlayer.ship.getXPos(), belt->roids.at(tempRoid2).getXPos(), mPlayer.ship.getYPos(), belt->roids.at(tempRoid2).getYPos(), mPlayer.ship.getZPos(), belt->roids.at(tempRoid2).getZPos()));
					
					break;

				case -2:
					//no targets in range; move ship
					break;

				default:
					bContinue = false;
					break;
				}			 	
			}

			else //If the player does have targets, ask if they want to lock another laser on a current target or lock on another target
			{
				pChoice = mp_mn.mTMenuB();

				switch (pChoice)
				{
				case 1:
					tempRoid1 = mp_mn.mCTarget(belt->roids, sAsteroids, mPlayer, mTDist);
					break;
					
				case 2:
					//add a new source to current target
					break;

				default:
					bContinue = false;
					break;
				}
			}
		}

		else // If not then try scanning for asteroids and loop
		{		
			cout << mp_mn.mRMessage(2028) << endl;
			mSAsteroid(belt, mPlayer);
		}
	}
}

void Mining::mSCycle(Player& mPlayer, aBelt* belt)
{
	mp_mn.mCScreen(false);

	cout << mp_mn.mRMessage(2029) << endl;

	/*
		This will have to be multi-threaded with one thread for each mining laser; do this in 0.6A, for now only use the higher quality laser
		*/

	bMCycle = true;

	mCTime_left = mCLength * 1000; //Since we get the time from database in seconds we need to multiply by 1000 for miliseconds; resets mCTime_left on each cycle
	mCTime_new = GetTickCount(); //Get cycle start time
	mCTime_old = ((mCTime_new + 500) / 1000);

	cout << mp_mn.mRMessage(2030) << endl;

	while (bMCycle)
	{
		cout << ((mCTime_left + 500) / 1000) << " seconds";

		bNChange = true;

		while (bNChange)
		{
			mCTime_new = GetTickCount();

			if (mCTime_old != ((mCTime_new + 500) / 1000))
			{
				mCTime_old = ((mCTime_new + 500) / 1000);
				mCTime_left -= 1000;
				bNChange = false;
			}
		}

		cout << " \r" << flush;

		
	}

	cout << mp_mn.mRMessage(2031) << endl;

	mECycle(mPlayer, belt);
}

void Mining::mECycle(Player& mPlayer, aBelt* belt)
{
	if (belt->roids.at(mTarget).getAOAmount() <= mOPCycle)
	{
		mSOre(mPlayer, belt);
		belt->removeAsteroid(mTarget);
		cout << mp_mn.mRMessage(2033) << endl;
		mTarget = -1;
	}

	else
	{
		belt->roids.at(mTarget).updateOAmount(mOPCycle, "sub");
		mSOre(mPlayer, belt);
	}
}

void Mining::mSOre(Player& mPlayer, aBelt* belt)
{
	mPlayer.ship.addCItem(belt->roids.at(mTarget).getAOID(), "Ore", mOPCycle, true);
}

void Mining::mUAsteroid()
{
	mTarget = -1;
}

void Mining::mPMShip(Player& mPlayer, aBelt* belt)
{
	mPRPoint = mp_mn.mGRPoint(sAsteroids, belt->roids, mPlayer); //Get a reference point for moving the player ship.

	if (mPRPoint != -1)
	{
		mPlayer.ship.sPMove_M(mPlayer, belt->roids.at(sAsteroids.at(mPRPoint)));
	}
}

//Cycle Functions
Cycle::Cycle(int clen, int time_left)
{
	mlCLen = clen;
	mCTime_left = time_left;
	bIsCompleted = false;
}

int Cycle::getCLen()
{
	return mlCLen;
}

void Cycle::setMCOld(int old)
{
	mCTime_old = old;
}

void Cycle::mCycle()
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

int Cycle::getCTime()
{
	return cur_time;
}

int Cycle::getCTLeft()
{
	return mCTime_left;
}

void Cycle::mCComp()
{
	bIsCompleted = true;
}

bool Cycle::getCompleted()
{
	return bIsCompleted;
}