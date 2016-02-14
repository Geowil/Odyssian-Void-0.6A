/*FILE HEADER

File Name:

ship.h

File Description:

The ship class contains all functions and variables related to the ships in the game

How it Works:

Ships are created through the constructor and then the other areas of the game interact and modify these classes.

Created On:

Monday, February 11, 2013

Version:

1.0 - 02/11/2013
1.1 - 02/13/2013
1.2 - 02/16/2013
1.3 - 02/27/2013
1.4 - 02/28/2013
1.5 - 04/30/2013
1.6 - 06/18/2013
1.7 - 10/09/2013
1.8 - 10/10/2013
1.9 - 06/30/2015
2.0 - 07/01/2015
2.1 - 07/07/2015
2.2 - 07/09/2015
2.3 - 10/10/2015

Changes:

1.0:
-Moved the class to this project
-Changed hardpoint arrays into vectors
-Added weapon firing spreads
-Renamed several bools for bool naming convention
-Added bool bContinue
-Added counters for hardpoint and weapon spread creation
-Added two new functions: cWSpreads and getWSpreads

1.1:
-Added several new variables
-Added five more spread vectors as well as a vector to temporarily hold data

1.2:
-Added many new functions: setCWSpread, setCWeapon, setCWSystem, getCWeapon, getCWSystem,
getLWeapons, getMWeapons, getRWeapons,getHWeapons
-Added two new variables: sCWeapon, sCWSystem

1.3:
-Removed get/setCWeapon and get/setCWSystem, they were no longer needed
-Added new vectors to hold data for full attack, weapon systems, and single weapon attacks
-Added getSSize in order to get size of a particular weapon spread vector
-Added getWVSize for the same reason as above for the weapon vector
-Added placeholder to hold hardpoint data for transport to other classes
-Added clearWVector to clear sWVector before use

1.4:
-Added new functions to return weapon types for specific hardpoint vector slots

1.5:
-Merged second and first constructors
-Modified shield/armor/hull set functions to act like other set functions throughout
the programming.
-Changed all functions and variables dealing with shield/armor/hull to floats
-Added some extra comments to member declarations

1.6:
-Removed anything having to do with turn based damage that does not interact or relate to tDamage class; all of it was depricated by said class
-Added new function: checkTDamage

1.7:
-Added dTDecremet to decrement the disable timer as well as to make false any true disabled bools

1.8:
-Added XYZ coordinate variables and functions to get and set them

1.9:
-Changed the way hardpoints are dealt with; no segregated weapon variables, now everything will just be processed through hardPoint class and a single vector.

2.0:
-Propogated yesterday's changes to the cpp file for Ship.
-Continued making changes to accomadte new changes.
-Began modifying some functions that require it due to changes to weapon/module system changes

2.1:
-Added in a new ship system for warp drive.
-Added functions to install new ship systems and to return those items for information display purposes.
-Added in temp objects to hold uninstalled ship systems for storing them on stations.

2.2:
-Changed HSStructure references to HStructure for simpliciation of the class names and references.

2.3:
-Modified the initShip class for changes in dataSystem and setting up ship components.
-Added variables to hold ids for ship components after data has been obtained from dataSystem.
-included scomponents.h for includes for ship component classes.

End File Header*/

#ifndef SHIP_H
#define SHIP_H

#include "range.h"
#include "hardPoint.h"
#include "tDamage.h"
#include "sinv.h"
#include "abelt.h"
#include "target.h"
#include "scomponents.h";
#include <string>
#include <vector>

using std::string;
using std::vector;

class Player;
class NPC;
class Station;

class Ship
{
public:
	Ship(); //Ship constructor

	//Bools
	bool 					isDestroyed(); //Is the ship destroyed?
	bool 					isDisabled(); //Is the ship disabled?
	bool 					getShieldStatus(); //Are shields up or offline?
	bool					bAWInstalled(); //bool: Are there weapons installed? -bombs
	bool					bABInstalled(); //bool: Are there bombs installed? -only bombs


	//Get Funcs
	int 					getAcc(string wName); //Get accuracy
	float 					getSArmor(); //Get ship armor points
	float					getSHull(); //Get ship hull points
	float 					getSShield(); //Get ship shield points	
	float					getSRegen(); //Get Shield Regen
	float					getARegen(); //Get Armor Regen
	float					getHRegen(); //Get Hull Regen
	float 					getSMArmor(); //Get ship max armor points
	float					getSMHull(); //Get ship max hull points
	float 					getSMShield(); //Get ship max shield points	
	int 					getSTLevel(); //Get ship technology level
	int 					getLSlots(); //Get ship laser hardpoints
	int						getULSlots(); //Get number of installed weapons
	int						getMSlots(); //Get ship missile turret points
	int						getUMSlots();//Get number of installed weapons
	int						getHSlots(); //Get ship bomb holds
	int						getUHSlots();//Get number of installed weapons
	int						getMInit(); //Get movement initiative
	int						getSWHP(); //Get the total number of hardpoints
	int						getSWSpreads(); //Get number of weapon spreads available;
	int						getSSize(int i); //Get currently selected weapon spread size
	int						getSVSize(int i); //Get size of specific slot hardpoint vector
	int						getCSVector(); //Get the id of the currently selected weapon vector
	vector<hardPoint>		getSVect(int i); //Return the specified spread vector	
	string					getLWDType(int slot); //Get weapon damage type of the weapon installed in int slot
	string					getMWDType(int slot); //Get weapon damage type of the weapon installed in int slot
	string					getBWDType(int slot); //Get weapon damage type of the weapon installed in int slot
	string					getRWDType(int slot); //Get weapon damage type of the weapon installed in int slot
	string					getHWDType(int slot); //Get weapon damage type of the weapon installed in int slot
	string 					getSClass(); //Get ship class
	int						getSClassI(string sclass); //Return int value of ship class
	string 					getSName(); //Get ship name
	string					getCWSystem();
	int						getSDTimer(); //Get time disabled
	hardPoint				getSHPoint(int i); //Get data of specific spread hard point
	hardPoint				getWVHPoint(int i); //Get data of specific weapon vector hard point
	int						getSID();
	int						getSTID();
	string					getSLocal();
	int						getID(); //Get ship data table ID
	float					getCSpace();
	float					getSSG2();
	float					getMCSpace();
	int 					getXPos();
	int 					getYPos();
	int 					getZPos();


	//Init/Install/Load Funcs
	void					initAIHPoint(string type); //Initialize AI hard points; needed because player version above returns messages
	void					cWSVector(); //Load the selected weapon system weapons into sWVector
	void					initShip(int sCode); //set up ship
	void					initSlots(); //Initialize hard points
	bool					iWeapon(string wType, int iCode); //Install weapon
	bool					loadCargo(int iID, int iAmount, string itype, float sg2, bool mining, string name);
	void					loadSCargo(int amount, string type, Ship2 lShip); //Load a ship object into cargo
	//bool				storeItem(Station& stat, Player& mPlayer); //Store an item on a station
	bool					storeItem(Station& stat, Player& mPlayer);
	void					iEngine(int id);
	void					iPSystem(int id);
	void					iCPU(int id);
	void					iRAM(int id);
	void					iSPSystem(int id);
	void					iWTS(int id);
	void					iWFG(int id);
	void					iSMatrix(int id);
	void					iAPlating(int id);
	void					iHSStruct(int id);
	void					loadSStats(); //Grab stats from systems after load game


	//Misc Funcs
	void					toggleSStat(int time); //Toggle ship status
	void					toggleShields(int time); //Toggle shields
	void					disableShip(int time); //Disable ship
	void					disableShield(int time); //Disable shields
	void					sWSCenter(Player& mPlayer); //All actions dealing with weapon spreads are routed through here
	void					cWSpread(Player& mPlayer); //Create weapon spread
	void					clearWSpread(int wSpread); //Remove vector elements
	void					editSpread(int wSpread, Player& mPlayer); //Edit chosen weapon spread
	void					cWVector(); //Create all out attack vector
	void					cWSVector_AI(); //Create weapon system vector - AI
	void					cWVector_AI(); //Create single weapon vector - AI
	void					cWSVector_AI_PB(); //Create weapon system vector - AI
	void					cWVector_AI_PB(); //Create single weapon vector - AI
	void					cSWArray(int slot, string wtype); //Create single weapon array
	void					sSAVector(bool bombing); //Setup allout attack vector
	void					cRSpread(); //Create random weapon spread
	void					cRSpread_B(); //Create random bomb spread
	void					aWTVector(int wtype); //Add weapons to vector
	void					dTDecrement(); //Decrement disable timer
	void					addTDamage(float damage, int turns, string type); //Add a new turn based damage to the vector
	void					checkTDamage(); //Check the vector for zero turn damage and remove those that are found
	void					removeTDamage(int i); //Remove a turn based damage from the vector
	void					addSVElement(int sID, string type, int slot); //Use this to load spread data from the save file
	void					addWHPVElement(int slot, int wID, string type); //Use this to load weapon hardpoint vector data
	void					clearSData(); //If player captured or ship looted, remove the ship information
	void					changeShip(string name, string sclass, float shield, float mshield, float armor, float marmor, float hull, float mhull, int lb, int mt, int bh, int rm, int hwb, int twhp, int minit, int tlevel, float sg2, float mcspace, int sSID, int sSTID, string sLocal); //Change the player ship
	void					calcCSpace(); //Initialize cargo space
	bool					checkSpace(float nSpace); //Can a new item be stored or not?
	bool					addCItem(int iID, string iType, int amount, bool mining);
	void					removeCItem(int slot);
	void					setSSG2(float sg2);
	void 					sPMove_M(Player& mPlayer, Asteroid roid); //Movement system for mining
	bool 					getMLInfo(int* cTime, int* mlTDist, float* cMAmount); //Get mining laser targeting range
	void 					sPMove(Player& mPlayer, NPC& mNPC); //Player ship movement
	void 					sAIMove(Player& mPlayer, NPC& mNPC, bool ally); //AI ship movement
	void					addTarget(string tID, int objdist);
	void					removeTarget(string tID);


	//Set/Update Funcs
	void					setName(string s); //Set player name
	void 					setRank(string s); //Set player rank
	void 					updateSArmor(float f, string operation); //Set ship armor points
	void 					setSClass(string s); //Set ship class
	void 					updateSHull(float f, string operation); //Set ship hull points
	void 					updateSMArmor(float f, string operation); //Set ship max armor points
	void 					updateSMHull(float f, string operation); //Set ship max hull points
	void 					updateSMShield(float f, string operation); //Set ship max shield points
	void 					setSName(string s); //Set ship name
	void 					updateSShield(float f, string operation); //Set ship shield points
	void 					setSTLevel(int i); //Set ship tech level
	void					setCWSpread(int cspread); //Set user selected spread for use
	void					setCWSystem(int i); //Set the chosen weapon system	
	void 					setLSlot(int i); //Get ship laser hardpovoids
	void					setULSot(int i);
	void					setMSlot(int i); //Get ship missile turret povoids
	void					setUMSlot(int i);
	void					setHSlot(int i); //Get ship bomb holds
	void					setUHSlot(int i);
	void					setMInit(int i);
	void					setMWSpreads(int i);
	void					setSID(int i); //Set sSID
	void					setSTID(int i); //Set sSTID
	void					setSLocal(string s); //Set sLocal
	void					setID(int i); //Set ship data table ID
	void					updateCSpace(float space, string operation);
	void					updateMCSpace(float space, string opteraion);
	bool					updateCIAmount(int slot, int amount, string operation, bool mining, string name);
	void 					setPos(int x, int y, int z); //Set position data







	//For Mining


	//Coord System Functions
	//Get position data





	//Targeting Functions



	//TODO: Check to see if this is still needed
	Ship* rShip(); //Return this ship class as a pointer

	//Weapon Spreads
	vector<hardPoint> 		sTWSpread; //hold data temporarily for insertment into a spread vector
	vector<hardPoint>		sWSpread1;
	vector<hardPoint> 		sWSpread2;
	vector<hardPoint> 		sWSpread3;
	vector<hardPoint> 		sWSpread4;
	vector<hardPoint>		sWSpread5;
	vector<hardPoint>		sWSpread6;
	vector<hardPoint> 		sWSpread7;
	vector<hardPoint> 		sWSpread8;

	/*
	HPSlot Number, Weapon Spread Vector, and Weapon Vector Explanation:

	This is not immediatly identifiable and somewhat difficult to graspe from the code.
	Putting this in Database and in Ship because of the nature of the code above these comment blocks.

	In ship weapon spreads are handled in a semi-relationship (in reference to databases) way where the
	spread vector contains the hardpoint slot number and weapon type for the weapon located in the specified
	weapon vector (weapon type of Laser and HPSlot of 3 indicates that the weapon element currently being worked with
	is located in slot 4 (0 indexed) of the sHSlots vector in Ship.

	In the save file database weapon spread vectors are handled in the same way.  ID is the HPSlot in the weapon vector specified
	by the HPWeapType field.  Position in the actual spread vector is handled by the order in which the records are added to the
	table in the database.

	*/


	//For Weapon System
	vector<hardPoint> 		sWVector; //Vector to store all currently installed weapons -bombs
	vector<int> 			sWSystems; //Order to add weapons systems to sWVector

	//store turn based damage
	vector<tDamage> 		cDamage;

	//ship cargo hold
	vector<sInv> 			sCargo;

	vector<mHPoint>			sLSlots; //Low Slots
	vector<mHPoint>			sMSlots; //Medium Slots
	vector<wHPoint>			sHSlots; //High Slots

	//Target Handling
	vector<target> 			sTargets;

	//Ship Systems
	int						iCPU(CPU nCPU, int eID); //Install New CPU
	int						iRAM(RAM nRAM, int eID); //Install New Ram
	int						iPSystem(pSystem newPS, int eID); //Install New Primary Power System
	int						iSPSystem(sPSystem newSPS, int eID); //Install New Secondary Power System
	int						iSMatrix(sMatrix newSM, int eID); //Install New Shield Matrix
	int						iAPlating(aPlating newAP, int eID); //Install New Armor Plating
	int						iHStructure(hSStructure newHull, int eID); //Install New Ship Hull
	int						iWTSystem(wTSystem newWTS, int eID); //Install New Weapon Targeting System
	int						iEngine(Engine newEngine, int eID); //Install New Ship Engine
	int						iWFGen(wFGen newWFGen, int eID); //Install New Warp Field Generator

	CPU						getCPU();
	RAM						getRAM();
	pSystem					getPS();
	sPSystem				getSPS();
	sMatrix					getSM();
	aPlating				getAP();
	hStructure				getSH();
	wTSystem				getWTS();
	Engine					getE();
	wFGen					getWFG();


private:

	string				sObjID; //Stores an alphanumeric string that contains the Object ID of this ship

	//Equipment Handles
	CPU 					sCCore;
	RAM 					sMDVRAM; //Multiplexing Dynamic Virtual RAM
	pSystem 				sPPSystem;
	sPSystem 				sCap;
	sMatrix 				sSMatrix;
	aPlating 				sAPlating;
	hStructure 				sHSStruct;
	wTSystem 				sWTSystem;
	Engine 					sEngine;
	wFGen 					sWFGen;

	CPU 					sOCCore;
	RAM 					sOMDVRAM;
	pSystem 				sOPPSystem;
	sPSystem 				sOCap;
	sMatrix 				sOSMatrix;
	aPlating 				sOAPlating;
	hStructure 				sOHSStruct;
	wTSystem 				sOWTSystem;
	Engine 					sOEngine;
	wFGen 					sOWFGen;


	//Temorary holding variables
	int nCPU, oCPU; //New and old CPU
	int nRAM, oRAM;
	int nAP, oAP;
	int nHS, oHS;
	int nSM, oSM;
	int nWG, oWG;
	int nWT, oWT;
	int nPS, oPS;
	int nSPS, oSPS;
	int nEng, oEng;

	//Temporary holding vectors
	vector<wHPoint> tempWHP;
	vector<mHPoint> tempMHP;

	bool					bIsSDisabled; //disabled status 
	bool					bAreSSDisabled; //shield status
	bool					bContinue;

	int 					sLS, sMS, sHS; //Variable to keep track of available slots
	int 					sULS, sUMS, sUHS; //Variables to keep track of used slots (slots with something installed in them)

	hardPoint				placeHolder;

	float					sArmor; //ship armor
	float					sMArmor; //ship max armor
	float					sARegen; //Armor Regen Amount
	int					sMD; //ship move distance ?
	float					sHull; //ship hull
	float					sHRegen; //Hull Regen Amount
	float					sMHull; //ship max hull
	int					sMInit; //ship movement initiative
	float					sSRegen; //Shield Regen Amount
	float					sMShield; //ship max shield	
	int					sTLevel; //ship tech level
	int					sWHP; //ship weapon hard points	
	int					sDTimer; //ship disabled timer
	int					sXC; //ship xarn cost
	int					sRC; //ship ruby cost
	int					sDiC; //ship diamond cost
	int					sDC; //ship draconic cost
	int					sLC; //ship lithium cost
	int					sUC; //ship uranium cost
	int					sPC; //ship plutonium cost
	float					sSG2; //amount of space ship takes up when stored
	float					sUCSpace, tempSpace, tempISpace; //amount of cargo space used
	float					sMCSpace; //max amount of cargo space
	int					sMTDist; //max targeting distance
	int					sMTargets; //max number of targets

	//add in storage

	//These keep track of USED hard point types out of what CAN be used which are the ones defined above these
	int 					sWSpreads, sUWSpreads; //number of spread|number of used spreads

	int 					pChoice; //player int choice
	char 					pCChoice; //player char choice

	int 					sCWSpread; //Chosen weapon spread
	string 				sCWSystem; //Chosen weapon system

	bool 					bWIsAUsed, bValid;

	string				sClass; //ship class
	string				sName; //ship name	
	string				data; //string storage

	int 					i1, i2, sR1, sR2, sTIWeapons, initLS, initMS, initHS, lostItem; //storage variables

	//Position Data
	int 					sPosX, sPosY, sPosZ;

	//Movement System
	int 					sMSelection1;
	int 					sMSelection2;
	int 					sAMInit; //Stores available movement initiative left for the current turn
	bool 					bIsCAffirmitive, bIsPDone;
	int 					sMRand1, sMRand2, sMRand3, sMRand4, sMRand5, sMRand6; //Movement system randoms for non-player entities (both npc and allies)
	float 				sEDist; //Stores the distance from the target ship

	//Temorary holding variables
	Weapon* 				tempWeap;

	//Temporary holding vectors
	vector<hardPoint> 		tempW;

	//For Mining Values
	int 					hCTime; //Highest cycle time
	int 					lTDist; //Longest targeting distance
	float 				tMAmount; //Total mine amount

	//For storage
	int 					sSID; //Storage Ship ID
	int 					sSTID; //Storage Station ID
	string 				sLocal; //Where is this ship stored?
	int 					sID; //Ship id in database table

	bool 					bDone;
	int 					nOItems;

	//Data storage
	float 				sCISG2; //For storing cargo SG2 size
	string 				sCIName; //For storing cargo item name
};
#endif