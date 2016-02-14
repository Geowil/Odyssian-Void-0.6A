#include <string>
#include "ship.h"
#include "weapon.h"
#include "random.h"
#include "datasystem.h"
#include "msgproc.h"
#include "map.h"

using std::cout;
using std::cin;

dataSystem ds_s;
msgProc mp_s;
Map m_s;


Ship::Ship()
{
	lHPoints = 0;
	mHPoints = 0;
	bHPoints = 0;
	rHPoints = 0;
	hHPoints = 0;

	sWSpreads = 0;

	bIsSDisabled = false;
	bAreSSDisabled = false;
	bContinue = false;

	sLSlots = 0;
	sMSlots = 0;
	sHSLots = 0;

	sULSlots = 0;
	sUMSlots = 0;
	sUHSlots = 0;


	sDTimer = 0; //ship disabled timer
	sXC = 0; //ship xarn cost
	sRC = 0; //ship ruby cost
	sDiC = 0; //ship diamond cost
	sDC = 0; //ship draconic cost
	sLC = 0; //ship lithium cost
	sUC = 0; //ship uranium cost
	sPC = 0; //ship plutonium cost

	pChoice = 0;
	pCChoice = ' ';

	sCWSpread = 0;

	bWIsAUsed = false;

	i1 = 0;
	i2 = 0;

	sPosX = 0; //ship x pos
	sPosY = 0; //ship y pos
	sPosZ = 0; //ship z pos
}

float Ship::getSArmor()
{
	return sArmor;
}

float Ship::getSHull()
{
	return sHull;
}

float Ship::getSHRegen()
{
	return sHRegen;
}

float Ship::getSARegen()
{
	return sARegen;
}

float Ship::getSRegen()
{
	return sSRegen;
}

float Ship::getSMArmor()
{
	return sMArmor;
}

float Ship::getSMHull()
{
	return sMHull;
}

float Ship::getSMShield()
{
	return sMShield;
}

float Ship::getSShield()
{
	return sShield;
}

string Ship::getSClass()
{
	return sClass;
}

int Ship::getSClassI(string sclass)
{
	if (sclass == "Frigate")
	{
		return 1;
	}

	else if (sclass == "Destroyer")
	{
		return 2;
	}

	else if (sclass == "Cruiser")
	{
		return 3;
	}

	else if (sclass == "Battlecruiser")
	{
		return 4;
	}

	else if (sclass == "Battleship")
	{
		return 5;
	}

	else if (sclass == "Mothership")
	{
		return 6;
	}

	else if (sclass == "Titan")
	{
		return 7;
	}
}

string Ship::getSName()
{
	return sName;
}

int Ship::getSTLevel()
{
	return sTLevel;
}

void Ship::updateSArmor(float f, string operation)
{
	if (operation == "add")
	{
		sArmor += f;
	}

	else if (operation == "sub")
	{
		sArmor -= f;
	}

	else if (operation == "set")
	{
		sArmor = f;
	}
}

void Ship::setSClass(string s)
{
	sClass = s;
}

void Ship::updateSHull(float f, string operation)
{
	if (operation == "add")
	{
		sHull += f;
	}

	else if (operation == "sub")
	{
		sHull -= f;
	}

	else if (operation == "set")
	{
		sHull = f;
	}
}

void Ship::updateSMArmor(float f, string operation)
{
	if (operation == "add")
	{
		sMArmor += f;
	}

	else if (operation == "sub")
	{
		sMArmor -= f;
	}

	else if (operation == "set")
	{
		sMArmor = f;
	}
}

void Ship::updateSMHull(float f, string operation)
{
	if (operation == "add")
	{
		sMHull += f;
	}

	else if (operation == "sub")
	{
		sMHull -= f;
	}

	else if (operation == "set")
	{
		sMHull = f;
	}
}

void Ship::updateSMShield(float f, string operation)
{
	if (operation == "add")
	{
		sMShield += f;
	}

	else if (operation == "sub")
	{
		sMShield -= f;
	}

	else if (operation == "set")
	{
		sMShield = f;
	}
}

void Ship::setSName(string s)
{
	sName = s;
}

void Ship::updateSShield(float f, string operation)
{
	if (operation == "add")
	{
		sShield += f;
	}

	else if (operation == "sub")
	{
		sShield -= f;
	}

	else if (operation == "set")
	{
		sShield = f;
	}
}

void Ship::updateSSRegen(float f, string operation)
{
	if (operation == "add")
	{
		sSRegen += f;
	}

	else if (operation == "sub")
	{
		sSRegen -= f;
	}

	else if (operation == "set")
	{
		sSRegen = f;
	}
}

void Ship::updateSARegen(float f, string operation)
{
	if (operation == "add")
	{
		sARegen += f;
	}

	else if (operation == "sub")
	{
		sARegen -= f;
	}

	else if (operation == "set")
	{
		sARegen = f;
	}
}

void Ship::updateSHRegen(float f, string operation)
{
	if (operation == "add")
	{
		sHRegen += f;
	}

	else if (operation == "sub")
	{
		sHRegen -= f;
	}

	else if (operation == "set")
	{
		sHRegen = f;
	}
}

void Ship::setSTLevel(int i)
{
	sTLevel = i1;
}

int Ship::getLS()
{
	return sLS;
}

int Ship::getMS()
{
	return sMS;
}

int Ship::getHS()
{
	return sHS;
}

void Ship::initSlots()
{
	for (i1 = 0; i1 < sLS; i1++)
	{
		sLSlots.push_back(mHPoint(i1, "Initialized"));
	}

	for (i1 = 0; i1 < sMS; i1++)
	{
		sMSlots.push_back(mHPoint(i1, "Initialized"));
	}

	for (i1 = 0; i1 < sHS; i1++)
	{
		sHSlots.push_back(wHPoint(i1, "Initialized"));
	}
}

bool Ship::isDestroyed()
{
	return sHull <= 0;
}

bool Ship::isDisabled()
{
	return bIsSDisabled;
}

bool Ship::getShieldStatus()
{
	return bAreSSDisabled;
}

void Ship::toggleShields(int time)
{
	if (bAreSSDisabled == false)
	{
		bAreSSDisabled = true;
		sDTimer = time;
	}

	else
	{
		bAreSSDisabled = false;
	}
}

void Ship::toggleSStat(int time)
{
	if (bIsSDisabled == false)
	{
		bIsSDisabled = true;
		sDTimer = time;
	}

	else
	{
		bIsSDisabled = false;
	}
}

void Ship::disableShip(int time)
{
	//Disable shields
	disableShield(time);

	//Disable Weapons/Modules
	if (sLS > 0)
	{
		for (i1 = 0; i1 < sLB; i1++)
		{
			sLSlots.at(i1).mHP.toggleModule(time);
		}
	}

	if (sMS > 0)
	{
		for (i1 = 0; i1 < sMT; i1++)
		{
			sMSlots.at(i1).mHP.toggleModule(time);
		}
	}

	if (sHS > 0)
	{
		for (i1 = 0; i1 < sBH; i1++)
		{
			sHSlots.at(i1).wHP.toggleWeapon(time);
		}
	}

	//Set ship disabled status to true
	bIsSDisabled = true;

	//Set disabled timer
	sDTimer = time;
}

void Ship::disableShield(int time)
{
	sShield = 0;
	sDTimer = time;
}

void Ship::initShip(int sCode)
{
	ds_s.rData("Ship_Data", "select from", sCode);

	sName = ds_s.getData<string>("Name","Ship");
	sClass = ds_s.getData<string>("Class","Ship");
	sTLevel = ds_s.getData<int>("TLevel","Ship");
	nSM = ds_s.getData<int>("Shield","Ship"); //get ship shields
	nAP = ds_s.getData<int>("Armor","Ship"); //get ship armor
	nHS = ds_s.getData<int>("Hull","Ship"); //get ship hull
	nEng = ds_s.getData<int>("Engine","Ship");
	sLS = ds_s.getData<int>("Low SLots","Ship");
	sMS = ds_s.getData<int>("Med Slots","Ship");
	sHS = ds_s.getData<int>("High Slots","Ship");
	nCPU = ds_s.getData<int>("CPU","Ship");
	nRAM = ds_s.getData<int>("RAM","Ship");
	nPS = ds_s.getData<int>("Power System","Ship");
	nSPS = ds_s.getData<int>("Capacitor","Ship");
	nWT = ds_s.getData<int>("Targeting System","Ship");
	nWG = ds_s.getData<int>("Warp Generator","Ship");
	sUCSpace = 0.0f;
	sMCSpace = ds_s.getData<float>("Cargo","Ship");
	sSG2 = ds_s.getData<float>("SG2","Ship");
	sID = sCode;
	sSID = -1;
	sSTID = -1;
	sLocal = "none";

	//Set up ship components/values
	sEngine.iEngine(nEng);
	sCCore.iCPU(nCPU);
	sMDVRAM.iRAM(nRAM);
	sPPSystem.iPS(nPS);
	sCap.iSPS(nSPS);
	sAPlating.iAPlating(nAP);
	sSMatrix.iSMatrix(nSM);
	sHSStruct.iHS(nHS);
	sWFGen.iWFGen(nWG);
	sWTSystem.iWTS(nWT);
	
	initSlots();
}

void Ship::initSlots()
{
	for (i1 = 0; i1 < sLS; i1++)
	{
		sLSlots.push_back(mHPoint(i1, "Low"));
	}

	for (i1 = 0; i1 < sMS; i1++)
	{
		sMSlots.push_back(mHPoint(i1, "Med"));
	}

	for (i1 = 0; i1 < sHS; i1++)
	{
		sHSlots.push_back(wHPoint(i1, "High"));
	}
}

int Ship::getMInit()
{
	return sMInit;
}

int Ship::getSDTimer()
{
	return sDTimer;
}

bool Ship::iWeapon(int icode)
{
	//Cycle through availalbe hard points
	for (i1 = 0; i1 <= sHSLots.size() - 1; i1++)
	{
		if (i1 == sHSlots.size()) //If no open hard points return false for further processing
		{
			return false;
		}

		else if (sHSlots.at(i1).getWType() == "Initialized") //If no weapon installed, install the passed weapon
		{
			sHSlots.at(i1).wHP.wSetup(icode); //Set up data for passed weapon
			sHSlots.at(i1).wHP.iWeapon(); //Install the passed weapon
			sUHS += 1;
			return true; //We can only install one weapon at a time, so break the loop and return
		}
	}
}

boo Ship::iModule(int icode, string slevel)
{
	if (slevel == "Low")
	{
		//Cycle through availalbe hard points
		for (i1 = 0; i1 <= sLSLots.size() - 1; i1++)
		{
			if (i1 == sLSlots.size()) //If no open hard points return false for further processing
			{
				return false;
			}

			else if (sLSlots.at(i1).getMType() == "Initialized") //If no weapon installed, install the passed weapon
			{
				sLSlots.at(i1).wHP.mSetup(icode); //Set up data for passed weapon
				sLSlots.at(i1).wHP.iModule(); //Install the passed weapon
				sULS += 1;
				return true; //We can only install one weapon at a time, so break the loop and return
			}
		}
	}

	else if (slevel == "Mid")
	{
		//Cycle through availalbe hard points
		for (i1 = 0; i1 <= sMSLots.size() - 1; i1++)
		{
			if (i1 == sMSlots.size()) //If no open hard points return false for further processing
			{
				return false;
			}

			else if (sMSlots.at(i1).getMType() == "Initialized") //If no weapon installed, install the passed weapon
			{
				sMSlots.at(i1).mHP.mSetup(icode); //Set up data for passed weapon
				sMSlots.at(i1).mHP.iModule(); //Install the passed weapon
				sUMS += 1;
				return true; //We can only install one weapon at a time, so break the loop and return
			}
		}
	}
}

void Ship::sWSCenter(Player& mPlayer)
{
	if (sUWSpreads == 0)
	{
		cWSpread(mPlayer);
	}

	while (!bContinue)
	{
		pChoice = mp_s.sSCMenu();

		switch (pChoice)
		{
		case 1:

			cWSpread(mPlayer);
			break;

		case 2:
			pChoice = mp_s.sDSpread(sWSpreads, mPlayer);

			if (pChoice != 0)
			{
				clearWSpread(pChoice);
			}

			break;

		case 3:
			pChoice = mp_s.bCSpread(sWSpreads, mPlayer);

			editSpread(pChoice, mPlayer);
		}
	}

}

void Ship::cWSpread(Player& mPlayer)
{
	bContinue = false;

	while (!bContinue)
	{
		pChoice = mp_s.sCEWSpread(sWSpreads, mPlayer);

		if ((pChoice == 1) && (sWSpread1.size() == 0))
		{
			sCWSpread = 1;
			bContinue = true;
		}

		else if ((pChoice == 2) && (sWSpread2.size() > 0))
		{
			sCWSpread = 2;
			bContinue = true;
		}

		else if ((pChoice == 3) && (sWSpread3.size() > 0))
		{
			sCWSpread = 3;
			bContinue = true;
		}

		else if ((pChoice == 4) && (sWSpread4.size() > 0))
		{
			sCWSpread = 4;
			bContinue = true;
		}

		else if ((pChoice == 5) && (sWSpread5.size() > 0))
		{
			sCWSpread = 5;
			bContinue = true;
		}

		else if ((pChoice == 6) && (sWSpread6.size() > 0))
		{
			sCWSpread = 6;
			bContinue = true;
		}

		else if ((pChoice == 7) && (sWSpread7.size() > 0))
		{
			sCWSpread = 7;
			bContinue = true;
		}

		else if ((pChoice == 8) && (sWSpread8.size() > 0))
		{
			sCWSpread = 8;
			bContinue = true;
		}

		//TODO: Check for 0
	}

	bContinue = false;

	if (sUHS < 1) //Check to see if any weapons are installed; if no weapons installed then cancel
	{
		cout << mp_s.mRMessage(27) << endl;
		cout << endl;
		cout << endl;
	}

	else
	{
		while (!bContinue)
		{
			//TODO: Fix this function to use the new hardpoint system
			pChoice = mp_s.sWSSelection(getULHP(), getUMTP(), getURM(), getUHWB()); //Get a weapon group to select weapons from

			switch (pChoice)
			{
			case 0:
			{
				cout << "Completing weapon spread creation..." << endl;
				bContinue = true;

				if (sTWSpread.size() == 0) //Extra checking in case player does not add any weapons to the spread; to prevent issues of a player trying to by passs spread creation in certain circumstances where it is required
				{
					sWSpreads = 0;
					sCWSpread = 0;
				}

				break;
			}

			case 1:
			{
				for (i1 = 0; i1 < lBanks.size(); i1++)
				{
					tempLaser = lBanks.at(i1).hpWeapon.getWeapon();

					if (tempLaser->getWName() != "No Weapon Installed") //Only continue if there is a weapon installed.  Since there is no way to distinguish between an installed and non-installed weapon after the initial installation if the player changes the weapon positions, the sUX variables cannot be used here.
					{
						pCChoice = mp_s.sLWSelection(tempLaser);

						for (i2 = 0; i2 < sTWSpread.size(); i2++)
						{
							if ((sTWSpread.at(i2).getHPWType() == "laser") && (sTWSpread.at(i2).getHPSlot() == lBanks.at(i1).getHPSlot()))
							{
								cout << "This weapon has already been included in this weapon spread.  Please choose a different weapon." << endl;
								cout << endl;

								bWIsAUsed = true;
								break;
							}
						}

						if ((!bWIsAUsed) && (pCChoice == 'y' || pCChoice == 'Y'))
						{
							sTWSpread.push_back(hardPoint(lBanks.at(i1).getHPSlot(), "laser"));
							break;
						}

						bWIsAUsed = false;
					}
				}

				break;
			}

			case 2:
			{
				for (i1 = 0; i1 < mTurrets.size(); i1++)
				{
					tempMissile = mTurrets.at(i1).hpWeapon.getWeapon();

					if (tempMissile->getWName() != "No Weapon Installed")
					{
						for (i2 = 0; i2 < sTWSpread.size(); i2++)
						{
							if ((sTWSpread.at(i2).getHPWType() == "missile") && (sTWSpread.at(i2).getHPSlot() == mTurrets.at(i1).getHPSlot()))
							{
								cout << "This weapon has already been included in this weapon spread.  Please choose a different weapon." << endl;
								cout << endl;

								bWIsAUsed = true;
								break;
							}
						}

						if ((!bWIsAUsed) && (pCChoice == 'y' || pCChoice == 'Y'))
						{
							sTWSpread.push_back(hardPoint(mTurrets.at(i1).getHPSlot(), "missile"));
							break;
						}

						bWIsAUsed = false;
					}
				}

				break;
			}

			case 3:
			{
				for (i1 = 0; i1 < rMounts.size(); i1++)
				{
					tempRail = rMounts.at(i1).hpWeapon.getWeapon();

					if (tempRail->getWName() != "No Weapon Installed")
					{
						for (i2 = 0; i2 < sTWSpread.size(); i2++)
						{
							if ((sTWSpread.at(i2).getHPWType() == "rail") && (sTWSpread.at(i2).getHPSlot() == rMounts.at(i1).getHPSlot()))
							{
								cout << mp_s.mRMessage(41) << endl;
								cout << endl;

								bWIsAUsed = true;
								break;
							}
						}

						if ((!bWIsAUsed) && (pCChoice == 'y' || pCChoice == 'Y'))
						{
							sTWSpread.push_back(hardPoint(rMounts.at(i1).getHPSlot(), "rail"));
							break;
						}

						bWIsAUsed = false;
					}
				}

				break;

			}

			case 4:
			{
				for (i1 = 0; i1 < hWBays.size(); i1++)
				{
					tempHeavy = hWBays.at(i1).hpWeapon.getWeapon();

					if (tempHeavy->getWName() != "No Weapon Installed")
					{
						for (i2 = 0; i2 < sTWSpread.size(); i2++)
						{
							if ((sTWSpread.at(i2).getHPWType() == "heavy") && (sTWSpread.at(i2).getHPSlot() == hWBays.at(i1).getHPSlot()))
							{
								cout << "This weapon has already been included in this weapon spread.  Please choose a different weapon." << endl;
								cout << endl;

								bWIsAUsed = true;
								break;
							}
						}

						if ((!bWIsAUsed) && (pCChoice == 'y' || pCChoice == 'Y'))
						{
							sTWSpread.push_back(hardPoint(hWBays.at(i1).getHPSlot(), "heavy"));
							break;
						}

						bWIsAUsed = false;
					}
				}

				break;
			}
			}
		}

		if (sCWSpread != 0)
		{
			for (i1 = 0; i1 < sTWSpread.size(); i1++)
			{
				switch (sCWSpread)
				{
				case 1:
					sWSpread1.push_back(hardPoint(sTWSpread.at(i1).getHPSlot(), sTWSpread.at(i1).getHPWType()));
					break;

				case 2:
					sWSpread2.push_back(hardPoint(sTWSpread.at(i1).getHPSlot(), sTWSpread.at(i1).getHPWType()));
					break;

				case 3:
					sWSpread3.push_back(hardPoint(sTWSpread.at(i1).getHPSlot(), sTWSpread.at(i1).getHPWType()));
					break;

				case 4:
					sWSpread4.push_back(hardPoint(sTWSpread.at(i1).getHPSlot(), sTWSpread.at(i1).getHPWType()));
					break;

				case 5:
					sWSpread5.push_back(hardPoint(sTWSpread.at(i1).getHPSlot(), sTWSpread.at(i1).getHPWType()));
					break;

				case 6:
					sWSpread6.push_back(hardPoint(sTWSpread.at(i1).getHPSlot(), sTWSpread.at(i1).getHPWType()));
					break;

				case 7:
					sWSpread7.push_back(hardPoint(sTWSpread.at(i1).getHPSlot(), sTWSpread.at(i1).getHPWType()));
					break;

				case 8:
					sWSpread8.push_back(hardPoint(sTWSpread.at(i1).getHPSlot(), sTWSpread.at(i1).getHPWType()));
					break;
				}
			}
		}
	}
}

void Ship::clearWSpread(int wSpread)
{
	if (wSpread == 1)
	{
		sWSpread1.clear();
	}

	else if (wSpread == 2)
	{
		sWSpread2.clear();
	}

	else if (wSpread == 3)
	{
		sWSpread3.clear();
	}

	else if (wSpread == 4)
	{
		sWSpread4.clear();
	}

	else if (wSpread == 5)
	{
		sWSpread5.clear();
	}

	else if (wSpread == 6)
	{
		sWSpread6.clear();
	}

	else if (wSpread == 7)
	{
		sWSpread7.clear();
	}

	else if (wSpread == 8)
	{
		sWSpread8.clear();
	}

	else if (wSpread == 9)
	{
		sWVector.clear();
	}
}

void Ship::editSpread(int wSpread, Player& mPlayer)
{
	cout << mp_s.mRMessage(2001) << endl;
}

void Ship::cWVector()
{
	//TODO: Fix this function to use the new hardpoint system
	mp_s.sWSSelection(getULHP(), getUMTP(), getURM(), getUHWB());

	for (i1 = 0; i1 < sWSystems.size(); i1++)
	{
		if (sWSystems.at(i1) == 1)
		{
			aWTVector(1);
		}

		if (sWSystems.at(i1) == 2)
		{
			aWTVector(2);
		}

		if (sWSystems.at(i1) == 4)
		{
			aWTVector(4);
		}

		if (sWSystems.at(i1) == 5)
		{
			aWTVector(5);
		}
	}
}

void Ship::cRSpread()
{
	//TODO: Fix this function to use the new hardpoint system
	for (i1 = 0; i1 <= sWSpreads; i1++)
	{
		if (i1 == sWSpreads) //If no spreads are free then force overwrite of the weapon spread
		{
			clearWSpread(9);
			sCWSpread = 9;
		}

		else if (getSSize(i1) == 0) //Else select the first empty spread
		{
			sCWSpread = i1;
		}
	}

	sTIWeapons = sUHSLots; //We need the total number of installed weapons for the sR1 random

	sR1 = getIRange(1, sTIWeapons); //This determines the number of installed weapons to be used in the spread

	//Get all installed weapons and load them into tmeporary vectors for use later
	for (i1 = 0; i1 < getSVSize(3); i1++)
	{
		if (sHSlots.at(i1).wHP.getWName() != "No Weapon Installed") //If there is a weapons installed
		{
			tempWHP.push_back(wHPoint(sHSLots.at(i1).getHPSlot(), sHSlots.at(i1).getHPWType())); //then load the slot and weapon type into the temp vector
		}
	}

	for (i1 = 0; i1 <= sR1; i1++)
	{
		if (i1 == sR1) //Needed to prevent index out of bounds crashes
		{

		}

		else
		{
			sR2 = getIRange(1, 100); //Thie random will determine which weapon group to add from; the first non-used weapon will be used and if all the weapons have been used from a group then we move on to the next group

			if ((sR2 >= 1) && (sR2 <= 24))
			{
				if (tempWHP.size() == 0) //If all weapons used
				{
					sR2 = 25; //then set sR2 to 25
				}

				else
				{

					addSVElement(sCWSpread, tempLBank.at(0).getHPWType(), tempLBank.at(0).getHPSlot()); //Repurpose the add element function used primarily for loading data; this way no extra code or duplicate function is needed

					//Now remove the current element from the temp vector as it has been used
					tempLBank.erase(tempLBank.begin());
				}
			}

			//If's instead of else ifs because if a sereis of weapons has been completely used then we want to be able to switch to the next weapon group.

			if ((sR2 >= 25) && (sR2 <= 49))
			{
				if (tempMTurret.size() == 0) //If all weapons used
				{
					sR2 = 50; //then set sR2 to 50
				}

				else
				{
					addSVElement(sCWSpread, tempMTurret.at(0).getHPWType(), tempMTurret.at(0).getHPSlot()); //Repurpose the add element function used primarily for loading data; this way no extra code or duplicate function is needed

					//Now remove the current element from the temp vector as it has been used
					tempMTurret.erase(tempMTurret.begin());
				}
			}

			if ((sR2 >= 50) && (sR2 <= 74))
			{
				if (tempRMount.size() == 0) //If all weapons used
				{
					sR2 = 75; //then set sR2 to 75
				}

				else
				{
					addSVElement(sCWSpread, tempRMount.at(0).getHPWType(), tempRMount.at(0).getHPSlot()); //Repurpose the add element function used primarily for loading data; this way no extra code or duplicate function is needed

					//Now remove the current element from the temp vector as it has been used
					tempRMount.erase(tempRMount.begin());
				}
			}

			if (sR2 >= 75)
			{
				if (tempHWBay.size() == 0) //If all weapons used
				{
					//sR2 = 101; //then set sR2 to 101
				}

				else
				{
					addSVElement(sCWSpread, tempHWBay.at(0).getHPWType(), tempHWBay.at(0).getHPSlot()); //Repurpose the add element function used primarily for loading data; this way no extra code or duplicate function is needed

					//Now remove the current element from the temp vector as it has been used
					tempHWBay.erase(tempHWBay.begin());
				}
			}

			/*if (sR2 > 100) //All weapons have been used
			{
			break; //Just incase something goes wrong and the for loop does not cancel | Commented this block out because if all heavy weaps used it might be called before the first for loops runs out; figure out how to deal with that
			}*/
		}
	}
}

void Ship::cRSpread_B()
{
	//TODO: Fix this function to use the new hardpoint system
	if (sUBH != 0)
	{
		for (i1 = 0; i1 <= sWSpreads; i1++)
		{
			if (i1 == sWSpreads) //If no spreads are free then force overwrite of the weapon spread
			{
				clearWSpread(9);
				sCWSpread = 9;
			}

			else if (getSSize(i1) == 0) //Else select the first empty spread
			{
				sCWSpread = i1;
			}
		}

		sR1 = getIRange(1, sUBH); //This determines the number of installed weapons to be used in the spread

		//Get all installed weapons and load them into tmeporary vectors for use later
		for (i1 = 0; i1 < getWHPVSize(3); i1++)
		{
			if (bHolds.at(i1).hpWeapon.getWName() != "No Weapon Installed") //If there is a weapons installed
			{
				tempBHold.push_back(hardPointB(bHolds.at(i1).getHPSlot(), bHolds.at(i1).getHPWType())); //then load the slot and weapon type into the temp vector
			}
		}

		for (i1 = 0; i1 <= sR1; i1++)
		{
			if (tempBHold.size() == 0 || i1 == sR1) //If all weapons used
			{
				//	sR2 = 101; //then set sR2 to 101
				break; //and break
			}

			else
			{
				sR2 = getIRange(1, tempBHold.size()); //Thie random will determine which weapon group to add from; the first non-used weapon will be used and if all the weapons have been used from a group then we move on to the next group

				addSVElement(sCWSpread, tempBHold.at(i1).getHPWType(), tempBHold.at(i1).getHPSlot()); //Repurpose the add element function used primarily for loading data; this way no extra code or duplicate function is needed

				//Now remove the current element from the temp vector as it has been used
				tempBHold.erase(tempBHold.begin() + i1);
			}

			/*if (sR2 > 100) //All weapons have been used
			{
			break; //Just incase something goes wrong and the for loop does not cancel
			}*/
		}
	}

	else
	{
		cout << mp_s.mRMessage(2021) << endl;
	}
}

bool Ship::bASInstalled()
{
	if (sULS > 0 || sUMS > 0 || sUHS > 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Ship::bABInstalled()
{
	return sUHS > 0;
}

void Ship::aWTVector(int wtype)
{
	clearWSpread(9); //Make sure sWVector is clean

	if (wtype == 1)
	{
		for (i1 = 0; i1 < lBanks.size(); i1++)
		{
			sWVector.push_back(hardPoint(i1, "laser"));
		}
	}

	if (wtype == 2)
	{
		for (i1 = 0; i1 < mTurrets.size(); i1++)
		{
			sWVector.push_back(hardPoint(i1, "missile"));
		}
	}

	if (wtype == 4)
	{
		for (i1 = 0; i1 < rMounts.size(); i1++)
		{
			sWVector.push_back(hardPoint(i1, "rail"));
		}
	}

	if (wtype == 5)
	{
		for (i1 = 0; i1 < hWBays.size(); i1++)
		{
			sWVector.push_back(hardPoint(i1, "heavy"));
		}
	}
}

void Ship::cSWArray(int slot, string wtype)
{
	clearWSpread(9); //Make sure sWVector is clean
	sWVector.push_back(hardPoint(slot, wtype));
	sCWSpread = 9;
}

void Ship::sSAVector(bool bombing)
{
	sCWSpread = 9; //The weapon vector will store all out attacks
	clearWSpread(9); //Make sure the vector is empty before we begin

	if (!bombing) //If no bombing then continue
	{
		sTIWeapons = sULB + sUMT + sURM + sUHWB; //Get the total number of installed weapons - bombs

		//Get all installed weapons and load them into tmeporary vectors for use later
		for (i1 = 0; i1 < getWHPVSize(1); i1++)
		{
			if (lBanks.at(i1).hpWeapon.getWName() != "No Weapon Installed") //If there is a weapons installed
			{
				tempLBank.push_back(hardPointL(lBanks.at(i1).getHPSlot(), lBanks.at(i1).getHPWType())); //then load the slot and weapon type into the temp vector
			}
		}

		for (i1 = 0; i1 < getWHPVSize(2); i1++)
		{
			if (mTurrets.at(i1).hpWeapon.getWName() != "No Weapon Installed")
			{
				tempMTurret.push_back(hardPointM(mTurrets.at(i1).getHPSlot(), mTurrets.at(i1).getHPWType()));
			}
		}

		for (i1 = 0; i1 < getWHPVSize(4); i1++)
		{
			if (rMounts.at(i1).hpWeapon.getWName() != "No Weapon Installed")
			{
				tempRMount.push_back(hardPointR(rMounts.at(i1).getHPSlot(), rMounts.at(i1).getHPWType()));
			}
		}

		for (i1 = 0; i1 < getWHPVSize(5); i1++)
		{
			if (hWBays.at(i1).hpWeapon.getWName() != "No Weapon Installed")
			{
				tempHWBay.push_back(hardPointH(hWBays.at(i1).getHPSlot(), hWBays.at(i1).getHPWType()));
			}
		}

		for (i1 = 0; i1 < sTIWeapons - 1;) //Now loop for as many times as there are weapons installed with manual iteration
		{
			sR1 = getIRange(1, 4); //Get a random weapon type

			if (sR1 == 1) //Laser
			{
				if (tempLBank.size() != 0) //Need this so we do not go out of bounds on the index
				{
					addSVElement(sCWSpread, tempLBank.at(0).getHPWType(), tempLBank.at(0).getHPSlot()); //Repurpose the add element function used primarily for loading data; this way no extra code or duplicate function is needed

					//Now remove the current element from the temp vector as it has been used
					tempLBank.erase(tempLBank.begin());
					i1 += 1; //Since we added a weapon, iterate i
				}
			}

			else if (sR1 == 2)
			{
				if (tempMTurret.size() != 0) //Need this so we do not go out of bounds on the index
				{
					addSVElement(sCWSpread, tempMTurret.at(0).getHPWType(), tempMTurret.at(0).getHPSlot()); //Repurpose the add element function used primarily for loading data; this way no extra code or duplicate function is needed

					//Now remove the current element from the temp vector as it has been used
					tempMTurret.erase(tempMTurret.begin());
					i1 += 1; //Since we added a weapon, iterate i
				}
			}

			else if (sR1 == 3)
			{
				if (tempRMount.size() != 0) //Need this so we do not go out of bounds on the index
				{
					addSVElement(sCWSpread, tempRMount.at(0).getHPWType(), tempRMount.at(0).getHPSlot()); //Repurpose the add element function used primarily for loading data; this way no extra code or duplicate function is needed

					//Now remove the current element from the temp vector as it has been used
					tempRMount.erase(tempRMount.begin());
					i1 += 1; //Since we added a weapon, iterate i
				}
			}

			else if (sR1 == 4)
			{
				if (tempHWBay.size() != 0) //Need this so we do not go out of bounds on the index
				{
					addSVElement(sCWSpread, tempHWBay.at(0).getHPWType(), tempHWBay.at(0).getHPSlot()); //Repurpose the add element function used primarily for loading data; this way no extra code or duplicate function is needed

					//Now remove the current element from the temp vector as it has been used
					tempHWBay.erase(tempHWBay.begin());
					i1 += 1; //Since we added a weapon, iterate i
				}
			}
		}
	}

	else if (bombing)
	{
		sTIWeapons = sUBH; //Get the total number of installed weapons only bombs

		//Get all installed weapons and load them into tmeporary vectors for use later
		for (i1 = 0; i1 < getWHPVSize(3); i1++)
		{
			if (bHolds.at(i1).hpWeapon.getWName() != "No Weapon Installed") //If there is a weapons installed
			{
				tempBHold.push_back(hardPointB(bHolds.at(i1).getHPSlot(), bHolds.at(i1).getHPWType())); //then load the slot and weapon type into the temp vector
			}
		}

		for (i1 = 0; i1 < sTIWeapons;) //Now loop for as many times as there are weapons installed with manual iteration
		{
			if (tempBHold.size() != 0) //Need this so we do not go out of bounds on the index
			{
				addSVElement(sCWSpread, tempBHold.at(0).getHPWType(), tempBHold.at(0).getHPSlot()); //Repurpose the add element function used primarily for loading data; this way no extra code or duplicate function is needed

				//Now remove the current element from the temp vector as it has been used
				tempBHold.erase(tempBHold.begin());
				i1 += 1; //Since we added a weapon, iterate i
			}
		}
	}
}

int Ship::getSWSpreads()
{
	return sWSpreads;
}

void Ship::setMWSpreads(int i)
{
	sWSpreads = i1;
}

void Ship::setCWSpread(int cspread)
{
	sCWSpread = cspread;
}

void Ship::setCWSystem(int i)
{
	if (i1 == 1)
	{
		sCWSystem == "laser";
	}

	else if (i1 == 2)
	{
		sCWSystem == "missile";
	}

	else if (i1 == 3)
	{
		sCWSystem == "bomb";
	}

	else if (i1 == 4)
	{
		sCWSystem == "rail";
	}

	else if (i1 == 5)
	{
		sCWSystem = "heavy";
	}
}

void Ship::cWSVector()
{
	clearWSpread(9);
	sCWSpread = 9;

	if (sCWSystem == "laser")
	{
		for (i1 = 0; i1 < lBanks.size(); i1++)
		{
			if (lBanks.at(i1).hpWeapon.getWName() != "No Weapon Installed")
			{
				addSVElement(sCWSpread, lBanks.at(i1).getHPWType(), lBanks.at(i1).getHPSlot());
			}
		}
	}

	else if (sCWSystem == "missile")
	{
		for (i1 = 0; i1 < mTurrets.size(); i1++)
		{
			if (mTurrets.at(i1).hpWeapon.getWName() != "No Weapon Installed")
			{
				addSVElement(sCWSpread, mTurrets.at(i1).getHPWType(), mTurrets.at(i1).getHPSlot());
			}
		}
	}

	else if (sCWSystem == "bomb")
	{
		for (i1 = 0; i1 < bHolds.size(); i1++)
		{
			if (bHolds.at(i1).hpWeapon.getWName() != "No Weapon Installed")
			{
				addSVElement(sCWSpread, bHolds.at(i1).getHPWType(), bHolds.at(i1).getHPSlot());
			}
		}
	}

	else if (sCWSystem == "rail")
	{
		for (i1 = 0; i1 < rMounts.size(); i1++)
		{
			if (rMounts.at(i1).hpWeapon.getWName() != "No Weapon Installed")
			{
				addSVElement(sCWSpread, rMounts.at(i1).getHPWType(), rMounts.at(i1).getHPSlot());
			}
		}
	}

	else if (sCWSystem == "heavy")
	{
		for (i1 = 0; i1 < hWBays.size(); i1++)
		{
			if (hWBays.at(i1).hpWeapon.getWName() != "No Weapon Installed")
			{
				addSVElement(sCWSpread, hWBays.at(i1).getHPWType(), hWBays.at(i1).getHPSlot());
			}
		}
	}
}

string Ship::getCWSystem()
{
	return sCWSystem;
}

hardPoint Ship::getSHPoint(int i)
{
	if (sCWSpread == 1)
	{
		placeHolder = sWSpread1.at(i1);

		return placeHolder;
	}

	if (sCWSpread == 2)
	{
		placeHolder = sWSpread2.at(i1);

		return placeHolder;
	}

	if (sCWSpread == 3)
	{
		placeHolder = sWSpread3.at(i1);

		return placeHolder;
	}

	if (sCWSpread == 4)
	{
		placeHolder = sWSpread4.at(i1);

		return placeHolder;
	}

	if (sCWSpread == 5)
	{
		placeHolder = sWSpread5.at(i1);

		return placeHolder;
	}

	if (sCWSpread == 6)
	{
		placeHolder = sWSpread6.at(i1);

		return placeHolder;
	}

	if (sCWSpread == 7)
	{
		placeHolder = sWSpread7.at(i1);

		return placeHolder;
	}

	if (sCWSpread == 8)
	{
		placeHolder = sWSpread8.at(i1);

		return placeHolder;
	}

	if (sCWSpread == 9)
	{
		placeHolder = sWVector.at(i1);

		return placeHolder;
	}
}

hardPoint Ship::getWVHPoint(int i)
{
	placeHolder = sWVector.at(i1);

	return placeHolder;
}

int Ship::getSSize(int i)
{
	if (i1 == 1)
	{
		return sWSpread1.size();
	}

	else if (i1 == 2)
	{
		return sWSpread2.size();
	}

	else if (i1 == 3)
	{
		return sWSpread3.size();
	}

	else if (i1 == 4)
	{
		return sWSpread4.size();
	}

	else if (i1 == 5)
	{
		return sWSpread5.size();
	}

	else if (i1 == 6)
	{
		return sWSpread6.size();
	}

	else if (i1 == 7)
	{
		return sWSpread7.size();
	}

	else if (i1 == 8)
	{
		return sWSpread8.size();
	}

	else if (i1 == 9)
	{
		return sWVector.size();
	}
}

int Ship::getWHPVSize(int i)
{
	switch (i1)
	{
	case 1:
		return lBanks.size();
		break;

	case 2:
		return mTurrets.size();
		break;

	case 3:
		return bHolds.size();
		break;

	case 4:
		return rMounts.size();
		break;

	case 5:
		return hWBays.size();
		break;
	}
}

vector<hardPoint> Ship::getSVect(int i)
{
	if (i1 == 1)
	{
		return sWSpread1;
	}

	else if (i1 == 2)
	{
		return sWSpread2;
	}

	else if (i1 == 3)
	{
		return sWSpread3;
	}

	else if (i1 == 4)
	{
		return sWSpread4;
	}

	else if (i1 == 5)
	{
		return sWSpread5;
	}

	else if (i1 == 6)
	{
		return sWSpread6;
	}

	else if (i1 == 7)
	{
		return sWSpread7;
	}

	else if (i1 == 8)
	{
		return sWSpread8;
	}

	else if (i1 == 9)
	{
		return sWVector;
	}
}

string Ship::getLWDType(int slot)
{
	return lBanks.at(slot).hpWeapon.getWDType();
}

string Ship::getMWDType(int slot)
{
	return mTurrets.at(slot).hpWeapon.getWDType();
}

string Ship::getBWDType(int slot)
{
	return bHolds.at(slot).hpWeapon.getWDType();
}

string Ship::getRWDType(int slot)
{
	return rMounts.at(slot).hpWeapon.getWDType();
}

string Ship::getHWDType(int slot)
{
	return hWBays.at(slot).hpWeapon.getWDType();
}

Ship* Ship::rShip()
{
	return this;
}

void Ship::addTDamage(float damage, int turns, string type)
{
	cDamage.push_back(tDamage(damage, turns, type));
}

void Ship::checkTDamage()
{
	for (i1 = 0; i1 < cDamage.size(); i1++)
	{
		if (cDamage.at(i1).getTurns() == 0)
		{
			removeTDamage(i1); //Pass current vector element numbe to function
			i1 = 0; //Reset i to zero since the elements will be shifted down after the current on is removed
		}
	}
}

void Ship::removeTDamage(int i)
{
	cDamage.erase(cDamage.begin() + i1);
}

void Ship::dTDecrement()
{
	if (sDTimer == 1) //If one turn left enable disabled systems and set timer to 0
	{
		if (bIsSDisabled)
		{
			bIsSDisabled = false;
		}

		if (bAreSSDisabled)
		{
			bAreSSDisabled = false;
		}

		sDTimer = 0;
	}

	else if (sDTimer > 1) //If more than one turn left, decrement the timer by one
	{
		sDTimer -= 1;
	}
}

void Ship::setPos(int x, int y, int z)
{
	sPosX = x;
	sPosY = y;
	sPosZ = z;
}

int Ship::getXPos()
{
	return sPosX;
}

int Ship::getYPos()
{
	return sPosY;
}

int Ship::getZPos()
{
	return sPosZ;
}

void Ship::sPMove(Player& mPlayer, NPC& mNPC)
{
	sAMInit = getMInit();
	bIsCAffirmitive = false;
	bIsPDone = false;
	sMSelection1 = 0;
	sMSelection2 = 0;

	while (!bIsPDone)
	{
		if (sAMInit == 0)
		{
			cout << mp_s.mRMessage(40) << endl;
			break; //If no more MIinit, break loop
		}

		//Display location of player and target ship and distance between them
		mp_s.nBSPos(mPlayer, mNPC);

		sMSelection1 = mp_s.sMSystem(sAMInit);

		// Update coordinates based on selection.
		switch (sMSelection1)
		{
		case 1:
			while (!bIsCAffirmitive)
			{
				cout << mp_s.mRMessage(36) << endl;
				cout << "> ";
				cin >> sMSelection2;

				if ((sMSelection2 <= sAMInit) || (sMSelection2 >= 0))
				{
					cout << mp_s.mRMessage(37) << endl;
					sPosY += sMSelection2;
					sAMInit -= sMSelection2;
					bIsCAffirmitive = true;
				}

				else if ((sMSelection2 > sAMInit) || (sMSelection2 < 0))
				{
					cout << mp_s.mRMessage(38) << endl;
					sMSelection2 = 0;
					bIsCAffirmitive = false;
				}
			}

			break;

		case 2:
			while (!bIsCAffirmitive)
			{
				cout << mp_s.mRMessage(36) << endl;
				cout << "> ";
				cin >> sMSelection2;

				if ((sMSelection2 <= sAMInit) || (sMSelection2 >= 0))
				{
					cout << mp_s.mRMessage(37) << endl;
					sPosZ += sMSelection2;
					sAMInit -= sMSelection2;
					bIsCAffirmitive = true;
				}

				else if ((sMSelection2 > sAMInit) || (sMSelection2 < 0))
				{
					cout << mp_s.mRMessage(38) << endl;
					sMSelection2 = 0;
					bIsCAffirmitive = false;
				}
			}

			break;

		case 3:
			while (!bIsCAffirmitive)
			{
				cout << mp_s.mRMessage(36) << endl;
				cout << "> ";
				cin >> sMSelection2;

				if ((sMSelection2 <= sAMInit) || (sMSelection2 >= 0))
				{
					cout << mp_s.mRMessage(37) << endl;
					sPosZ -= sMSelection2;
					sAMInit -= sMSelection2;
					bIsCAffirmitive = true;
				}

				else if ((sMSelection2 > sAMInit) || (sMSelection2 < 0))
				{
					cout << mp_s.mRMessage(38) << endl;
					sMSelection2 = 0;
					bIsCAffirmitive = false;
				}
			}

			break;

		case 4:
			while (!bIsCAffirmitive)
			{
				cout << mp_s.mRMessage(36) << endl;
				cout << "> ";
				cin >> sMSelection2;

				if ((sMSelection2 <= sAMInit) || (sMSelection2 >= 0))
				{
					cout << mp_s.mRMessage(37) << endl;
					sPosX -= sMSelection2;
					sAMInit -= sMSelection2;
					bIsCAffirmitive = true;
				}

				else if ((sMSelection2 > sAMInit) || (sMSelection2 < 0))
				{
					cout << mp_s.mRMessage(38) << endl;
					sMSelection2 = 0;
					bIsCAffirmitive = false;
				}
			}

			break;

		case 5:
			while (!bIsCAffirmitive)
			{
				cout << mp_s.mRMessage(36) << endl;
				cout << "> ";
				cin >> sMSelection2;

				if ((sMSelection2 <= sAMInit) || (sMSelection2 >= 0))
				{
					cout << mp_s.mRMessage(37) << endl;
					sPosX += sMSelection2;
					sAMInit -= sMSelection2;
					bIsCAffirmitive = true;
				}

				else if ((sMSelection2 > sAMInit) || (sMSelection2 < 0))
				{
					cout << mp_s.mRMessage(38) << endl;
					sMSelection2 = 0;
					bIsCAffirmitive = false;
				}
			}

			break;

		case 6:
			while (!bIsCAffirmitive)
			{
				cout << mp_s.mRMessage(36) << endl;
				cout << "> ";
				cin >> sMSelection2;

				if ((sMSelection2 <= sAMInit) || (sMSelection2 >= 0))
				{
					cout << mp_s.mRMessage(37) << endl;
					sPosY -= sMSelection2;
					sAMInit -= sMSelection2;
					bIsCAffirmitive = true;
				}

				else if ((sMSelection2 > sAMInit) || (sMSelection2 < 0))
				{
					cout << mp_s.mRMessage(38) << endl;
					sMSelection2 = 0;
					bIsCAffirmitive = false;
				}
			}

			break;

		default:
			cout << mp_s.mRMessage(39) << endl;
			bIsPDone = true;
			break;
		}

		//reset for next loop
		bIsCAffirmitive = false;
	}

	cout << endl;
}

void Ship::sPMove_M(Player& mPlayer, Asteroid roid)
{
	sAMInit = getMInit();
	bIsCAffirmitive = false;
	bIsPDone = false;
	sMSelection1 = 0;
	sMSelection2 = 0;

	while (!bIsPDone)
	{
		if (sAMInit == 0)
		{
			cout << mp_s.mRMessage(40) << endl;
			break; //If no more MIinit, break loop
		}

		//Display location of player and target ship and distance between them
		mp_s.mTPos(mPlayer, roid);

		sMSelection1 = mp_s.sMSystem2(sAMInit);

		// Update coordinates based on selection.
		switch (sMSelection1)
		{
		case 1:
			while (!bIsCAffirmitive)
			{
				cout << mp_s.mRMessage(36) << endl;
				cout << "> ";
				cin >> sMSelection2;

				if ((sMSelection2 <= sAMInit) || (sMSelection2 >= 0))
				{
					cout << mp_s.mRMessage(37) << endl;
					sPosY += sMSelection2;
					sAMInit -= sMSelection2;
					bIsCAffirmitive = true;
				}

				else if ((sMSelection2 > sAMInit) || (sMSelection2 < 0))
				{
					cout << mp_s.mRMessage(38) << endl;
					sMSelection2 = 0;
					bIsCAffirmitive = false;
				}
			}

			break;

		case 2:
			while (!bIsCAffirmitive)
			{
				cout << mp_s.mRMessage(36) << endl;
				cout << "> ";
				cin >> sMSelection2;

				if ((sMSelection2 <= sAMInit) || (sMSelection2 >= 0))
				{
					cout << mp_s.mRMessage(37) << endl;
					sPosZ += sMSelection2;
					sAMInit -= sMSelection2;
					bIsCAffirmitive = true;
				}

				else if ((sMSelection2 > sAMInit) || (sMSelection2 < 0))
				{
					cout << mp_s.mRMessage(38) << endl;
					sMSelection2 = 0;
					bIsCAffirmitive = false;
				}
			}

			break;

		case 3:
			while (!bIsCAffirmitive)
			{
				cout << mp_s.mRMessage(36) << endl;
				cout << "> ";
				cin >> sMSelection2;

				if ((sMSelection2 <= sAMInit) || (sMSelection2 >= 0))
				{
					cout << mp_s.mRMessage(37) << endl;
					sPosZ -= sMSelection2;
					sAMInit -= sMSelection2;
					bIsCAffirmitive = true;
				}

				else if ((sMSelection2 > sAMInit) || (sMSelection2 < 0))
				{
					cout << mp_s.mRMessage(38) << endl;
					sMSelection2 = 0;
					bIsCAffirmitive = false;
				}
			}

			break;

		case 4:
			while (!bIsCAffirmitive)
			{
				cout << mp_s.mRMessage(36) << endl;
				cout << "> ";
				cin >> sMSelection2;

				if ((sMSelection2 <= sAMInit) || (sMSelection2 >= 0))
				{
					cout << mp_s.mRMessage(37) << endl;
					sPosX -= sMSelection2;
					sAMInit -= sMSelection2;
					bIsCAffirmitive = true;
				}

				else if ((sMSelection2 > sAMInit) || (sMSelection2 < 0))
				{
					cout << mp_s.mRMessage(38) << endl;
					sMSelection2 = 0;
					bIsCAffirmitive = false;
				}
			}

			break;

		case 5:
			while (!bIsCAffirmitive)
			{
				cout << mp_s.mRMessage(36) << endl;
				cout << "> ";
				cin >> sMSelection2;

				if ((sMSelection2 <= sAMInit) || (sMSelection2 >= 0))
				{
					cout << mp_s.mRMessage(37) << endl;
					sPosX += sMSelection2;
					sAMInit -= sMSelection2;
					bIsCAffirmitive = true;
				}

				else if ((sMSelection2 > sAMInit) || (sMSelection2 < 0))
				{
					cout << mp_s.mRMessage(38) << endl;
					sMSelection2 = 0;
					bIsCAffirmitive = false;
				}
			}

			break;

		case 6:
			while (!bIsCAffirmitive)
			{
				cout << mp_s.mRMessage(36) << endl;
				cout << "> ";
				cin >> sMSelection2;

				if ((sMSelection2 <= sAMInit) || (sMSelection2 >= 0))
				{
					cout << mp_s.mRMessage(37) << endl;
					sPosY -= sMSelection2;
					sAMInit -= sMSelection2;
					bIsCAffirmitive = true;
				}

				else if ((sMSelection2 > sAMInit) || (sMSelection2 < 0))
				{
					cout << mp_s.mRMessage(38) << endl;
					sMSelection2 = 0;
					bIsCAffirmitive = false;
				}
			}

			break;

		default:
			cout << mp_s.mRMessage(39) << endl;
			bIsPDone = true;
			break;
		}

		//reset for next loop
		bIsCAffirmitive = false;
	}

	cout << endl;
}

void Ship::sAIMove(Player& mPlayer, NPC& mNPC, bool ally)
{
	//
	sMRand1 = getIRange(1, 20);
	sMRand2 = getIRange(1, 10);
	sMRand3 = getIRange(1, 6);

	//Determine if a ship moves towards or away from target
	sMRand4 = getIRange(1, 10);
	sMRand5 = getIRange(1, 20);

	if (ally)
	{
		sEDist = m_s.getDistance(sPosX, mNPC.ship.getXPos(), sPosY, mNPC.ship.getYPos(), sPosZ, mNPC.ship.getZPos());

		if (sEDist > 13.00f)
		{
			sMRand6 = getIRange(1, 3); //Determine which direction to move in

			if (sMRand6 == 1)
			{
				if (mNPC.ship.getXPos() > sPosX)
				{
					sPosX -= 1;
				}

				else if (mNPC.ship.getXPos() < sPosX)
				{
					sPosX += 1;
				}
			}

			else if (sMRand6 == 2)
			{
				if (mNPC.ship.getYPos() > sPosY)
				{
					sPosY -= 1;
				}

				else if (mNPC.ship.getYPos() < sPosY)
				{
					sPosY += 1;
				}
			}

			else if (sMRand6 == 3)
			{
				if (mNPC.ship.getZPos() > sPosZ)
				{
					sPosZ -= 1;
				}

				else if (mNPC.ship.getZPos() < sPosZ)
				{
					sPosZ += 1;
				}
			}
		}

		else if ((sEDist > 8.00f) && (sEDist <= 13.00f))
		{
			if ((((sMRand4 >= 1) && (sMRand4 < 4)) && ((sMRand5 >= 12) && (sMRand5 < 19)))) //If true, move toward target
			{
				sMRand6 = getIRange(1, 3);

				if (sMRand6 == 1)
				{
					if (mNPC.ship.getXPos() > sPosX)
					{
						sPosX -= 1;
					}

					else if (mNPC.ship.getXPos() < sPosX)
					{
						sPosX += 1;
					}
				}

				else if (sMRand6 == 2)
				{
					if (mNPC.ship.getYPos() > sPosY)
					{
						sPosY -= 1;
					}

					else if (mNPC.ship.getYPos() < sPosY)
					{
						sPosY += 1;
					}
				}

				else if (sMRand6 == 3)
				{
					if (mNPC.ship.getZPos() > sPosZ)
					{
						sPosZ -= 1;
					}

					else if (mNPC.ship.getZPos() < sPosZ)
					{
						sPosZ += 1;
					}
				}
			}

			else //Esle move away from target
			{
				sMRand6 = getIRange(1, 3);

				if (sMRand6 == 1)
				{
					if (mNPC.ship.getXPos() > sPosX)
					{
						sPosX += 1;
					}

					else if (mNPC.ship.getXPos() < sPosX)
					{
						sPosX -= 1;
					}
				}

				else if (sMRand6 == 2)
				{
					if (mNPC.ship.getYPos() > sPosY)
					{
						sPosY += 1;
					}

					else if (mNPC.ship.getYPos() < sPosY)
					{
						sPosY -= 1;
					}
				}

				else if (sMRand6 == 3)
				{
					if (mNPC.ship.getZPos() > sPosZ)
					{
						sPosZ += 1;
					}

					else if (mNPC.ship.getZPos() < sPosZ)
					{
						sPosZ -= 1;
					}
				}
			}
		}

		else if (sEDist < 8.00f)
		{
			sMRand6 = getIRange(1, 3);

			if (sMRand6 == 1)
			{
				if (mNPC.ship.getXPos() > sPosX)
				{
					sPosX += 1;
				}

				else if (mNPC.ship.getXPos() < sPosX)
				{
					sPosX -= 1;
				}
			}

			else if (sMRand6 == 2)
			{
				if (mNPC.ship.getYPos() > sPosY)
				{
					sPosY += 1;
				}

				else if (mNPC.ship.getYPos() < sPosY)
				{
					sPosY -= 1;
				}
			}

			else if (sMRand6 == 3)
			{
				if (mNPC.ship.getZPos() > sPosZ)
				{
					sPosZ += 1;
				}

				else if (mNPC.ship.getZPos() < sPosZ)
				{
					sPosZ -= 1;
				}
			}
		}
	}

	else if (!ally)
	{
		sEDist = m_s.getDistance(sPosX, mPlayer.ship.getXPos(), sPosY, mPlayer.ship.getYPos(), sPosZ, mPlayer.ship.getZPos());

		if (sEDist > 13.00f)
		{
			sMRand6 = getIRange(1, 3); //Determine which direction to move in

			if (sMRand6 == 1)
			{
				if (mPlayer.ship.getXPos() > sPosX)
				{
					sPosX -= 1;
				}

				else if (mPlayer.ship.getXPos() < sPosX)
				{
					sPosX += 1;
				}
			}

			else if (sMRand6 == 2)
			{
				if (mPlayer.ship.getYPos() > sPosY)
				{
					sPosY -= 1;
				}

				else if (mPlayer.ship.getYPos() < sPosY)
				{
					sPosY += 1;
				}
			}

			else if (sMRand6 == 3)
			{
				if (mPlayer.ship.getZPos() > sPosZ)
				{
					sPosZ -= 1;
				}

				else if (mPlayer.ship.getZPos() < sPosZ)
				{
					sPosZ += 1;
				}
			}
		}

		else if ((sEDist > 8.00f) && (sEDist <= 13.00f))
		{
			if ((((sMRand4 >= 1) && (sMRand4 < 4)) && ((sMRand5 >= 12) && (sMRand5 < 19)))) //If true, move toward target
			{
				sMRand6 = getIRange(1, 3);

				if (sMRand6 == 1)
				{
					if (mPlayer.ship.getXPos() > sPosX)
					{
						sPosX -= 1;
					}

					else if (mPlayer.ship.getXPos() < sPosX)
					{
						sPosX += 1;
					}
				}

				else if (sMRand6 == 2)
				{
					if (mPlayer.ship.getYPos() > sPosY)
					{
						sPosY -= 1;
					}

					else if (mPlayer.ship.getYPos() < sPosY)
					{
						sPosY += 1;
					}
				}

				else if (sMRand6 == 3)
				{
					if (mPlayer.ship.getZPos() > sPosZ)
					{
						sPosZ -= 1;
					}

					else if (mPlayer.ship.getZPos() < sPosZ)
					{
						sPosZ += 1;
					}
				}
			}

			else //Esle move away from target
			{
				sMRand6 = getIRange(1, 3);

				if (sMRand6 == 1)
				{
					if (mPlayer.ship.getXPos() > sPosX)
					{
						sPosX += 1;
					}

					else if (mPlayer.ship.getXPos() < sPosX)
					{
						sPosX -= 1;
					}
				}

				else if (sMRand6 == 2)
				{
					if (mPlayer.ship.getYPos() > sPosY)
					{
						sPosY += 1;
					}

					else if (mPlayer.ship.getYPos() < sPosY)
					{
						sPosY -= 1;
					}
				}

				else if (sMRand6 == 3)
				{
					if (mPlayer.ship.getZPos() > sPosZ)
					{
						sPosZ += 1;
					}

					else if (mPlayer.ship.getZPos() < sPosZ)
					{
						sPosZ -= 1;
					}
				}
			}
		}

		else if (sEDist < 8.00f)
		{
			sMRand6 = getIRange(1, 3);

			if (sMRand6 == 1)
			{
				if (mPlayer.ship.getXPos() > sPosX)
				{
					sPosX += 1;
				}

				else if (mPlayer.ship.getXPos() < sPosX)
				{
					sPosX -= 1;
				}
			}

			else if (sMRand6 == 2)
			{
				if (mPlayer.ship.getYPos() > sPosY)
				{
					sPosY += 1;
				}

				else if (mPlayer.ship.getYPos() < sPosY)
				{
					sPosY -= 1;
				}
			}

			else if (sMRand6 == 3)
			{
				if (mPlayer.ship.getZPos() > sPosZ)
				{
					sPosZ += 1;
				}

				else if (mPlayer.ship.getZPos() < sPosZ)
				{
					sPosZ -= 1;
				}
			}
		}
	}
}

void Ship::clearSData()
{
	sName = " ";
	sClass = " ";
	sTLevel = 0;
	sShield = 0.00f; //get ship shields
	sArmor = 0.00f; //get ship armor
	sHull = 0.00f; //get ship hull
	sMInit = 0;
	sWHP = 0;
	sLB = 0;
	sMT = 0;
	sBH = 0;
	sRM = 0;
	sHWB = 0;
}

int Ship::getSWHP()
{
	return sWHP;
}

int Ship::getULHP()
{
	return sULB;
}

int Ship::getUMTP()
{
	return sUMT;
}

int Ship::getUBH()
{
	return sUBH;
}

int Ship::getURM()
{
	return sURM;
}

int Ship::getUHWB()
{
	return sUHWB;
}

void Ship::setLHP(int i)
{
	sLB = i1;
}

void Ship::setULHP(int i)
{
	sULB = i1;
}

void Ship::setMTP(int i)
{
	sMT = i1;
}

void Ship::setUMTP(int i)
{
	sUMT = i1;
}

void Ship::setBH(int i)
{
	sBH = i1;
}

void Ship::setUBH(int i)
{
	sUBH = i1;
}

void Ship::setRM(int i)
{
	sRM = i1;
}

void Ship::setURM(int i)
{
	sURM = i1;
}

void Ship::setHWB(int i)
{
	sHWB = i1;
}

void Ship::setUHWB(int i)
{
	sUHWB = i1;
}

void Ship::setSWHP(int i)
{
	sWHP = i1;
}

void Ship::setMInit(int i)
{
	sMInit = i1;
}

void Ship::addSVElement(int sID, string type, int slot)
{
	if (sID == 1)
	{
		sWSpread1.push_back(hardPoint());

		sWSpread1.at(sWSpread1.size() - 1).setHPSlot(slot);
		sWSpread1.at(sWSpread1.size() - 1).setHPWType(type);
	}

	else if (sID == 2)
	{
		sWSpread2.push_back(hardPoint());

		sWSpread2.at(sWSpread2.size() - 1).setHPSlot(slot);
		sWSpread2.at(sWSpread2.size() - 1).setHPWType(type);
	}

	else if (sID == 3)
	{
		sWSpread3.push_back(hardPoint());

		sWSpread3.at(sWSpread3.size() - 1).setHPSlot(slot);
		sWSpread3.at(sWSpread3.size() - 1).setHPWType(type);
	}

	else if (sID == 4)
	{
		sWSpread4.push_back(hardPoint());

		sWSpread4.at(sWSpread4.size() - 1).setHPSlot(slot);
		sWSpread4.at(sWSpread4.size() - 1).setHPWType(type);
	}

	else if (sID == 5)
	{
		sWSpread5.push_back(hardPoint());

		sWSpread5.at(sWSpread5.size() - 1).setHPSlot(slot);
		sWSpread5.at(sWSpread5.size() - 1).setHPWType(type);
	}

	else if (sID == 6)
	{
		sWSpread6.push_back(hardPoint());

		sWSpread6.at(sWSpread6.size() - 1).setHPSlot(slot);
		sWSpread6.at(sWSpread6.size() - 1).setHPWType(type);
	}

	else if (sID == 7)
	{
		sWSpread7.push_back(hardPoint());

		sWSpread7.at(sWSpread7.size() - 1).setHPSlot(slot);
		sWSpread7.at(sWSpread7.size() - 1).setHPWType(type);
	}

	else if (sID == 8)
	{
		sWSpread8.push_back(hardPoint());

		sWSpread8.at(sWSpread8.size() - 1).setHPSlot(slot);
		sWSpread8.at(sWSpread8.size() - 1).setHPWType(type);
	}

	else if (sID == 9)
	{
		sWVector.push_back(hardPoint());

		sWVector.at(sWVector.size() - 1).setHPSlot(slot);
		sWVector.at(sWVector.size() - 1).setHPWType(type);
	}
}

void Ship::addWHPVElement(int slot, int wID, string type)
{
	if (type == "laser")
	{
		lBanks.push_back(hardPointL(slot, "laser"));

		lBanks.at(lBanks.size() - 1).hpWeapon.wSetup(wID);
		lBanks.at(lBanks.size() - 1).hpWeapon.iWeapon();
	}

	else if (type == "mining laser")
	{
		lBanks.push_back(hardPointL(slot, "mining laser"));

		lBanks.at(lBanks.size() - 1).hpWeapon.wSetup(wID);
		lBanks.at(lBanks.size() - 1).hpWeapon.iWeapon();
	}

	else if (type == "missile")
	{
		mTurrets.push_back(hardPointM(slot, "missile"));

		mTurrets.at(mTurrets.size() - 1).hpWeapon.wSetup(wID);
		mTurrets.at(mTurrets.size() - 1).hpWeapon.iWeapon();
	}

	else if (type == "bomb")
	{
		bHolds.push_back(hardPointB(slot, "bomb"));

		bHolds.at(bHolds.size() - 1).hpWeapon.wSetup(wID);
		bHolds.at(bHolds.size() - 1).hpWeapon.iWeapon();
	}

	else if (type == "rail")
	{
		rMounts.push_back(hardPointR(slot, "rail"));

		rMounts.at(rMounts.size() - 1).hpWeapon.wSetup(wID);
		rMounts.at(rMounts.size() - 1).hpWeapon.iWeapon();
	}

	else if (type == "heavy")
	{
		hWBays.push_back(hardPointH(slot, "heavy"));

		hWBays.at(hWBays.size() - 1).hpWeapon.wSetup(wID);
		hWBays.at(hWBays.size() - 1).hpWeapon.iWeapon();
	}
}

int Ship::getCSVector()
{
	return sCWSpread;
}

void Ship::cWSVector_AI()
{
	clearWSpread(9);
	sCWSpread = 9;

	bContinue = false;
	initLB = 0;
	initMT = 0;

	while (!bContinue)
	{
		sR1 = getIRange(1, 2);

		if (sR1 == 1)
		{
			if (lBanks.size() > 0)
			{
				for (i1 = 0; i1 <= lBanks.size(); i1++)
				{
					if ((i1 == lBanks.size()) && (initLB == 0))
					{
						initLB = -1;
						break;
					}

					if ((i1 == lBanks.size()) && (initLB != 0))
					{
						bContinue = true;
						break;
					}

					else if (lBanks.at(i1).hpWeapon.getWName() != "No Weapon Installed")
					{
						initLB += 1;
					}
				}
			}
		}

		else if (sR1 == 2)
		{
			if (mTurrets.size() > 0)
			{
				for (i1 = 0; i1 <= mTurrets.size(); i1++)
				{
					if ((i1 == mTurrets.size()) && (initMT == 0))
					{
						initMT = -1;
						break;
					}

					if ((i1 == mTurrets.size()) && (initMT != 0))
					{
						bContinue = true;
						break;
					}

					else if (mTurrets.at(i1).hpWeapon.getWName() != "No Weapon Installed")
					{
						initMT += 1;
					}
				}
			}
		}

		if ((initLB == -1) && (initMT == -1))
		{
			break;
		}
	}

	if (initLB > 0)
	{
		//Get all installed weapons and load them into tmeporary vectors for use later
		for (i1 = 0; i1 < getWHPVSize(1); i1++)
		{
			if (lBanks.at(i1).hpWeapon.getWName() != "No Weapon Installed") //If there is a weapons installed
			{
				addSVElement(sCWSpread, lBanks.at(0).getHPWType(), lBanks.at(0).getHPSlot()); //Repurpose the add element function used primarily for loading data; this way no extra code or duplicate function is needed
			}
		}
	}

	else if (initMT > 0)
	{
		//Get all installed weapons and load them into tmeporary vectors for use later
		for (i1 = 0; i1 < getWHPVSize(2); i1++)
		{
			if (mTurrets.at(i1).hpWeapon.getWName() != "No Weapon Installed") //If there is a weapons installed
			{
				addSVElement(sCWSpread, mTurrets.at(0).getHPWType(), mTurrets.at(0).getHPSlot()); //Repurpose the add element function used primarily for loading data; this way no extra code or duplicate function is needed
			}
		}
	}
}

void Ship::cWVector_AI()
{
	clearWSpread(9);
	sCWSpread = 9;

	sTIWeapons = sULB + sUMT + sURM + sUHWB; //We need the total number of installed weapons for the sR1 random

	sR1 = getIRange(1, sTIWeapons); //This determines the number of installed weapons to be used in the spread

	//Get all installed weapons and load them into tmeporary vectors for use later
	for (i1 = 0; i1 < getWHPVSize(1); i1++)
	{
		if (lBanks.at(i1).hpWeapon.getWName() != "No Weapon Installed") //If there is a weapons installed
		{
			tempLBank.push_back(hardPointL(lBanks.at(i1).getHPSlot(), lBanks.at(i1).getHPWType())); //then load the slot and weapon type into the temp vector
		}
	}

	//Get all installed weapons and load them into tmeporary vectors for use later
	for (i1 = 0; i1 < getWHPVSize(2); i1++)
	{
		if (mTurrets.at(i1).hpWeapon.getWName() != "No Weapon Installed") //If there is a weapons installed
		{
			tempMTurret.push_back(hardPointM(mTurrets.at(i1).getHPSlot(), mTurrets.at(i1).getHPWType())); //then load the slot and weapon type into the temp vector
		}
	}

	for (i1 = 0; i1 <= sR1; i1++)
	{
		if (i1 == sR1) //Needed to prevent index out of bounds crashes
		{

		}

		else
		{
			sR2 = getIRange(1, 49); //Thie random will determine which weapon group to add from; the first non-used weapon will be used and if all the weapons have been used from a group then we move on to the next group

			if ((sR2 >= 1) && (sR2 <= 24))
			{
				if (tempLBank.size() == 0) //If all weapons used
				{
					sR2 = 25; //then set sR2 to 25
				}

				else
				{
					addSVElement(sCWSpread, tempLBank.at(0).getHPWType(), tempLBank.at(0).getHPSlot()); //Repurpose the add element function used primarily for loading data; this way no extra code or duplicate function is needed

					//Now remove the current element from the temp vector as it has been used
					tempLBank.erase(tempLBank.begin());
					break;
				}
			}

			//If's instead of else ifs because if a sereis of weapons has been completely used then we want to be able to switch to the next weapon group.

			if ((sR2 >= 25) && (sR2 <= 49))
			{
				if (tempMTurret.size() == 0) //If all weapons used
				{
					sR2 = 50; //then set sR2 to 50
				}

				else
				{
					addSVElement(sCWSpread, tempMTurret.at(0).getHPWType(), tempMTurret.at(0).getHPSlot()); //Repurpose the add element function used primarily for loading data; this way no extra code or duplicate function is needed

					//Now remove the current element from the temp vector as it has been used
					tempMTurret.erase(tempMTurret.begin());
					break;
				}
			}
		}
	}
}

void Ship::cWSVector_AI_PB()
{
	clearWSpread(9);
	sCWSpread = 9;

	bContinue = false;
	initBH = 0;

	while (!bContinue)
	{
		if (bHolds.size() > 0)
		{
			for (i1 = 0; i1 <= bHolds.size(); i1++)
			{
				if ((i1 == bHolds.size()) && (initBH == 0))
				{
					initBH = -1;
					break;
				}

				if ((i1 == bHolds.size()) && (initBH != 0))
				{
					bContinue = true;
					break;
				}

				else if (bHolds.at(i1).hpWeapon.getWName() != "No Weapon Installed")
				{
					initBH += 1;
				}
			}
		}
	}

	if (initBH > 0)
	{
		//Get all installed weapons and load them into tmeporary vectors for use later
		for (i1 = 0; i1 < getWHPVSize(1); i1++)
		{
			if (bHolds.at(i1).hpWeapon.getWName() != "No Weapon Installed") //If there is a weapons installed
			{
				addSVElement(sCWSpread, bHolds.at(0).getHPWType(), bHolds.at(0).getHPSlot()); //Repurpose the add element function used primarily for loading data; this way no extra code or duplicate function is needed
			}
		}
	}
}

void Ship::cWVector_AI_PB()
{
	clearWSpread(9);
	sCWSpread = 9;

	sTIWeapons = sUBH; //We need the total number of installed weapons for the sR1 random

	sR1 = getIRange(1, sTIWeapons); //This determines the number of installed weapons to be used in the spread

	//Get all installed weapons and load them into tmeporary vectors for use later
	for (i1 = 0; i1 < getWHPVSize(3); i1++)
	{
		if (bHolds.at(i1).hpWeapon.getWName() != "No Weapon Installed") //If there is a weapons installed
		{
			tempBHold.push_back(hardPointB(bHolds.at(i1).getHPSlot(), bHolds.at(i1).getHPWType())); //then load the slot and weapon type into the temp vector
		}
	}

	addSVElement(sCWSpread, tempBHold.at(sR1 - 1).getHPWType(), tempBHold.at(sR1 - 1).getHPSlot()); //Repurpose the add element function used primarily for loading data; this way no extra code or duplicate function is needed

	tempBHold.clear();
}

void Ship::calcCSpace()
{
	tempSpace = 0.0f;

	for (i1 = 0; i1 < sCargo.size(); i1++)
	{
		tempSpace += sCargo.at(i1).getISpace() * sCargo.at(i1).getIAmount();
	}

	sUCSpace = tempSpace;
}

float Ship::getCSpace()
{
	calcCSpace();

	return sUCSpace;
}

void Ship::updateMCSpace(float space, string operation)
{
	if (operation == "add")
	{
		sMCSpace += space;
	}

	else if (operation == "sub")
	{
		sMCSpace -= space;
	}

	else if (operation == "set")
	{
		sMCSpace = space;
	}
}

float Ship::getMCSpace()
{
	return sMCSpace;
}

bool Ship::addCItem(int iID, string iType, int amount, bool mining)
{
	if (iType == "Ship")
	{
		ds_s.rData("Ship_Data", "select from", iID);

		if (loadCargo(iID, amount, iType, ds_s.getSSG2(), mining, ds_s.getSName()))
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	else if (iType == "Resource")
	{
		ds_s.rData("Resource", "select from", iID);

		for (i1 = 0; i1 <= sCargo.size(); i1++)
		{
			if (i1 == sCargo.size())
			{
				if (loadCargo(iID, amount, iType, ds_s.getResSG2(), mining, ds_s.getResName()))
				{
					return true;
				}

				else
				{
					return false;
				}
			}

			else if ((iID == sCargo.at(i1).getIID()) && (iType == sCargo.at(i1).getIType()))
			{
				if (updateCIAmount(i1, amount, "add", mining, ds_s.getResName()))
				{
					return true;
				}

				else
				{
					return false;
				}
			}
		}
	}

	else if (iType == "Ore")
	{
		ds_s.rData("Ore", "select from", iID);

		for (i1 = 0; i1 <= sCargo.size(); i1++)
		{
			if (i1 == sCargo.size())
			{
				if (loadCargo(iID, amount, iType, ds_s.getOSG2(), mining, ds_s.getOName()))
				{
					return true;
				}

				else
				{
					return false;
				}
			}

			else if ((iID == sCargo.at(i1).getIID()) && (iType == sCargo.at(i1).getIType()))
			{
				if (updateCIAmount(i1, amount, "add", mining, ds_s.getOName()))
				{
					return true;
				}

				else
				{
					return false;
				}
			}
		}
	}

	else if (iType == "Item" || iType == "PShield" || iType == "PDefense" || iType == "Module")
	{
		if (iType == "Item")
		{
			//ds_s.rData("Equipment_Data","select from",iID);
		}

		else if (iType == "PShield")
		{
			ds_s.rData(iType, "select from", iID);

			sCIName = ds_s.getPSName();
			sCISG2 = ds_s.getPSSG2();
		}

		else if (iType == "PDefense")
		{
			ds_s.rData(iType, "select from", iID);
			sCIName = ds_s.getPDName();
			sCISG2 = ds_s.getPDSG2();
		}

		else if (iType == "Module")
		{
			//ds_s.rData("Equipment_Data","select from",iID);
		}


		for (i1 = 0; i1 <= sCargo.size(); i1++)
		{
			if (i1 == sCargo.size())
			{
				if (loadCargo(iID, amount, iType, sCISG2, mining, sCIName))
				{
					return true;
				}

				else
				{
					return false;
				}
			}

			else if ((iID == sCargo.at(i1).getIID()) && (iType == sCargo.at(i1).getIType()))
			{
				if (updateCIAmount(i1, amount, "add", mining, sCIName))
				{
					return true;
				}

				else
				{
					return false;
				}
			}
		}
	}

	else if (iType == "Weapon")
	{
		ds_s.rData("Weapon_Data", "select from", iID);

		for (i1 = 0; i1 <= sCargo.size(); i1++)
		{
			if (i1 == sCargo.size())
			{
				if (loadCargo(iID, amount, iType, ds_s.getWSG2(), mining, ds_s.getWName()))
				{
					return true;
				}

				else
				{
					return false;
				}
			}

			else if ((iID == sCargo.at(i1).getIID()) && (iType == sCargo.at(i1).getIType()))
			{
				if (updateCIAmount(i1, amount, "add", mining, ds_s.getWName()))
				{
					return true;
				}

				else
				{
					return false;
				}
			}
		}
	}
}

bool Ship::updateCIAmount(int slot, int amount, string operation, bool mining, string name)
{
	if (operation == "add")
	{
		tempISpace = sCargo.at(slot).getISpace();

		if (checkSpace(tempISpace * amount)) //Check to make sure we are not adding too many items
		{
			sCargo.at(slot).updateIAmount(amount, "add");
			return true;
		}

		else //If there are too many items, causing max cargo space to be reached then
		{
			if (!mining) //If not mining we do not store the item(s) at all
			{
				cout << "Items could not be stored.  Not enough space in cargo hold" << endl;

				return false;
			}

			else if (mining) //If mining then
			{
				while (!checkSpace(tempISpace * amount)) //We start removing an item at a time until it can fit
				{
					amount -= 1;
					lostItem += 1;
				}

				if (amount > 0) //Then display the losses or
				{
					cout << "Only " << amount << " units of " << name << " could be stored.  " << lostItem << " units were destroyed." << endl;

					sCargo.at(slot).updateIAmount(amount, "add");
					return true;
				}

				else //If none could be stored display all units lost
				{
					cout << "All units of " << name << " (" << lostItem << ") were destroyed.  Reason: Full cargo hold" << endl;
					return false;
				}
			}
		}
	}

	else if (operation == "sub")
	{
		if (amount >= sCargo.at(slot).getIAmount())
		{
			removeCItem(slot);
			return true;
		}

		else
		{
			sCargo.at(slot).updateIAmount(amount, "sub");
			return true;
		}
	}

	else if (operation == "set")
	{
		sCargo.at(slot).updateIAmount(amount, "set");
		return true;
	}
}

void Ship::removeCItem(int slot)
{
	sCargo.erase(sCargo.begin() + slot);
}

bool Ship::loadCargo(int iID, int iAmount, string itype, float sg2, bool mining, string name)
{
	if (checkSpace(iAmount * sg2))
	{
		sCargo.push_back(sInv(iID, iAmount, itype, sg2, false));

		cout << iAmount << " units of " << name << " have been stored on your ship." << endl;
		return true;
	}

	else //If there are too many items, causing max cargo space to be reached then
	{
		if (!mining) //If not mining we do not store the item(s) at all
		{
			cout << "Items could not be stored.  Not enough space in cargo hold" << endl;
			return false;
		}

		else if (mining) //If mining then
		{
			while (!checkSpace(iAmount * sg2)) //We start removing an item at a time until it can fit
			{
				iAmount -= 1;
				lostItem += 1;
			}

			if (iAmount > 0) //Then display the losses or
			{
				cout << "Only " << iAmount << " units of " << name << " could be stored.  " << lostItem << " units were destroyed." << endl;

				sCargo.push_back(sInv(iID, iAmount, itype, sg2, false));

				return true;
			}

			else //If none could be stored display all units lost
			{
				cout << "All units of " << name << " (" << lostItem << ") were destroyed.  Reason: Full cargo hold" << endl;
				return false;
			}
		}
	}
}

void Ship::loadSCargo(int amount, string type, Ship2 lShip)
{
	sCargo.push_back(sInv(lShip, true, lShip.getID(), 1));
	sCargo.at(sCargo.size() - 1).setIAmount(amount);
	sCargo.at(sCargo.size() - 1).setIType(type);
}

float Ship::getSSG2()
{
	return sSG2;
}

void Ship::setSSG2(float sg2)
{
	sSG2 = sg2;
}

bool Ship::getMLInfo(int* cTime, int* mlTDist, float* cMAmount)
{
	//For now we will combine the data from all installed mining lasers.  We get the longest and higher targeting distance and cycle time and then add all of the mining amounts together and then return those values

	hCTime = 0;
	lTDist = 0;
	tMAmount = 0.0f;

	for (i1 = 0; i1 < lBanks.size(); i1++)
	{
		if (lBanks.at(i1).getHPWType() == "mining laser")
		{
			if (lBanks.at(i1).hpWeapon.getCLength() > hCTime)
			{
				hCTime = lBanks.at(i1).hpWeapon.getCLength();
			}

			if (lBanks.at(i1).hpWeapon.getWAHigh() > lTDist)
			{
				lTDist = lBanks.at(i1).hpWeapon.getWAHigh();
			}

			tMAmount += lBanks.at(i1).hpWeapon.getCMAmount();
		}
	}

	if (hCTime == 0)
	{
		return false;
	}

	else
	{
		*cTime = hCTime;
		*mlTDist = lTDist;
		*cMAmount = tMAmount;

		return true;
	}
}

bool Ship::checkSpace(float nSpace)
{
	if (sMCSpace < getCSpace() + nSpace)
	{
		return false;
	}

	else
	{
		return true;
	}
}

void Ship::setSID(int i)
{
	sSID = i1;
}

void Ship::setSTID(int i)
{
	sSTID = i1;
}

void Ship::setSLocal(string s)
{
	sLocal = s;
}

int	Ship::getSID()
{
	return sSID;
}

int	Ship::getSTID()
{
	return sSTID;
}

string Ship::getSLocal()
{
	return sLocal;
}

int Ship::getID()
{
	return sID;
}

void Ship::setID(int i)
{
	sID = i1;
}

void Ship::changeShip(string name, string sclass, float shield, float mshield, float armor, float marmor, float hull, float mhull, int lb, int mt, int bh, int rm, int hwb, int twhp, int minit, int tlevel, float sg2, float mcspace, int sSID, int sSTID, string sLocal)
{
	sName = name;
	sClass = sclass;
	sTLevel = tlevel;
	sShield = shield;
	sMShield = mshield;
	sArmor = armor;
	sMArmor = marmor;
	sHull = hull;
	sMHull = mhull;
	sMInit = minit;
	sWHP = twhp;
	sLB = lb;
	sMT = mt;
	sBH = bh;
	sRM = rm;
	sHWB = hwb;
	sMCSpace = mcspace;
	sSG2 = sg2;

	initHPoints();
}

bool Ship::storeItem(Station& stat, Player& mPlayer)
{
	pChoice = mp_s.sMSI4B(this);

	if (pChoice != -1)
	{
		bDone = false;

		while (!bDone)
		{
			nOItems = mp_s.mSSIAmount(sCargo.at(pChoice).getIAmount());

			if (stat.checkSpace(sCargo.at(pChoice).getISpace()*nOItems))
			{
				//Check to see if the item exists in the cargohold
				for (i1 = 0; i1 <= stat.sInventory.size(); i1++)
				{
					if (i1 == stat.sInventory.size()) //Item does not exist
					{
						//Add the item to the station inventory
						stat.sSItem(sCargo.at(pChoice).getIID(), nOItems, sCargo.at(pChoice).getIType(), sCargo.at(pChoice).getISpace(), false);

						//Remove items from ship cargohold
						updateCIAmount(pChoice, nOItems, "sub", false, "");

						bDone = true;
						return true;
					}

					else if ((stat.sInventory.at(i1).getIID() == sCargo.at(pChoice).getIID()) && (stat.sInventory.at(i1).getIType() == sCargo.at(pChoice).getIType())) //If the item exists in the inventory
					{
						//Add the additional items to station inventory
						stat.sInventory.at(i1).updateIAmount(nOItems, "add");

						//Remove items from cargohold
						updateCIAmount(pChoice, nOItems, "sub", false, "");

						bDone = true;
						return true;
					}
				}
			}

			else
			{
				if (!stat.sBISpace(mPlayer, sCargo.at(pChoice).getIAmount()*nOItems))
				{
					cout << "Since you do not have enough room to store these items, canceling the storage operation..." << endl;

					bDone = true;
					return false;
				}
			}
		}
	}

	else
	{
		cout << "Either no items found or operation was canceled." << endl;
		return false;
	}
}

//Targeting Functions
void Ship::addTarget(string tID, int objDist)
{
	//First check if the ship can target the object
	//Check if max targets has been reached
	if (sMTargets <= sTargets.size()) //Technically sMTargets will never be less than the size of sTargets but use <= here just in case of bugs
	{
		//Message out about overruning targeting space
	}

	//Check if targeting distance has been exceeded
	else if (sMTDist < objDist)
	{
		//Message out about max targeting distance being exceeded
	}

	else //Add target lock
	{
		sTargets.push_back(target(tID));
	}
}

void Ship::removeTarget(string tID)
{
	for (i1 = 0; i1 < sTargets.size(); i1++)
	{
		if (sTargets.at(i1).getTID == tID)
		{
			sTargets.erase(sTargets.begin() + i1);
			i1 -= 1; //index out of bounds protection
		}
	}
}


int Ship::iCPU(CPU nCPU, int eID)
{
	//First we need to "unload" the old CPU if it exists.  Before this we have to see if one is already installed
	if (!sCPU.bIsInstalled()) //If there is no installed CPU then just install it
	{
		sCCore.iCPU(eID);

		return 0;
	}

	else
	{
		//Store the old CPU in a temp object
		sOCCore = sCCore;

		//Install new CPU
		sCCore.iCPU(eID);

		//return the ID of the old CPU for storage on the station
		return sOCCore.getID();
	}
}

int Ship::iRAM(RAM nRAM, int eID)
{
	//Check if RAM has already been installed
	if (!sMDVRAM.bIsInstalled())
	{
		sMDVRAM.iRAM(eID);

		return 0;
	}

	else
	{
		//Store the old RAM in a temp object
		sOMDVRAM = sMDVRAM;

		//Install the new RAM
		sMDVRAM.iRAM(eID);

		return sOMDVRAM.getID();
	}
}

int Ship::iPSystem(pSystem newPS, int eID)
{
	if (!sPSystem.bIsInstalled())
	{
		sPSystem.iPS(eID);

		return 0;
	}

	else
	{
		sOPSystem = sPSystem;

		sPSystem.iPS(eID);

		return sOPSystem.getID();
	}
}

int Ship::iSPSystem(sPSystem newSPS, int eID)
{
	if (!sCap.bIsInstalled())
	{
		sCap.iSPS(eID);

		return 0;
	}

	else
	{
		sOCap = sCap;

		sCap.iSPS(eID);

		return sOCap.getID();
	}
}

int Ship::iSMatrix(sMatrix newSM, int eID)
{
	if (!sSMatrix.bIsInstalled())
	{
		sSMatrix.iSMatrix(eID);

		return 0;
	}

	else
	{
		sOSMatrix = sSMatrix;

		sSMatrix.iSMatrix(eID);

		return sOSMatrix.getID();
	}
}

int Ship::iAPlating(aPlating newAP, int eID)
{
	if (!sAPlating.bIsInstalled())
	{
		sAPlating.iAPlating(eID);

		return 0;
	}

	else
	{
		sOAPlating = sAPlating;

		sAPlating.iAPlating(eID);

		return sOAPlating.getID();
	}
}

int Ship::iHStructure(hSStructure newHull, int eID)
{
	if (!sHSuperstructure.bIsInstalled())
	{
		sHSuperstructure.iHS(eID);

		return 0;
	}

	else
	{
		sOHSuperstructure = sHSuperstructure;

		sHSuperstructure.iHS(eID);

		return sOHSuperstructure.getID();
	}
}

int Ship::iWTSystem(wTSystem newWTS, int eID)
{
	if (!sWTSystem.bIsInstalled())
	{
		sWTSystem.iWTS(eID);

		return 0;
	}

	else
	{
		sOWTSystem = sWTSystem;

		sWTSystem.iWTS(eID);

		return sOWTSystem.getID();
	}
}

int Ship::iEngine(Engine newEngine, int eID)
{
	if (!sEngine.bIsInstalled())
	{
		sEngine.iEngine(eID);

		return 0;
	}

	else
	{
		sOEngine = sEngine;

		sEngine.iEngine(eID);

		return sOEngine.getID();
	}
}

int Ship::iWFGen(wFGen newWFGen, int eID)
{
	if (!sWFGen.bIsInstalled())
	{
		sWFGen.iWFG(eID);

		return 0;
	]

	else
	{
		sOWFGen = sWFGen;

		sWFGen.iWFG(eID);

		return sOWFGen.getID();
	}
	}

	CPU Ship::getCPU()
	{
		return sCPU;
	}

	RAM Ship::getRAM()
	{
		return sMDVRAM;
	}

	pSystem Ship::getPS()
	{
		return sPSystem;
	}

	sPSystem Ship::getSPS()
	{
		return sCap;
	}

	sMatrix Ship::getSM()
	{
		return sSMatrix;
	}

	aPlating Ship::getAP()
	{
		return sAPlating;
	}

	hSStructure Ship::getSH()
	{
		return sHSuperstructure;
	}

	wTSystem Ship::getWTS()
	{
		return sWTSystems;
	}

	Engine Ship::getE()
	{
		return sEngine;
	}

	wFGen Ship::getWFG()
	{
		return sWFGen;
	}
