/*FILE HEADER

File Name:
datasystem.h

File Description:
This class is used to interact and obtain data from the database class.  This class acts as a buffer to get the specific data needed.  How it Works:  Functions are called that will try to obtain specific types of data for specific elements.
The neccessary information is sent to the database class and then when the data is retrieved it is loaded into a vector reference from this class.  That vector is then searched for the information needed.  Since this class is instance-based
the vector must only be created when first accessing this class, all subsequent calls to the class will be when the class already has the information.  Unless new data is needed refilling the vector is not neccessary.

Created On:  Sunday, April 24, 2011

Version:
1.0 - 04/24/2011
1.1 - 04/25/2011
1.2 - 04/28/2011
1.3 - 05/23/2011
1.4 - 05/24/2011
1.5 - 05/30/2011
1.6 - 07/13/2011
1.7 - 07/19/2011
1.8 - 07/23/2011
1.9 - 08/04/2011
1.10 - 08/10/2011
1.11 - 08/13/2011
1.12 - 09/28/2011
1.13 - 10/19/2011
1.14 - 10/23/2011
1.15 - 02/13/2012
1.16 - 02/14/2012
1.17 - 02/15/2012
1.18 - 02/16/2012
1.19 - 02/18/2012
1.20 - 06/20/2012
1.21 - 06/22/2012
1.22 - 06/28/2012
1.23 - 08/20/2012
1.24 - 08/23/2012
1.25 - 12/26/2012
1.26 - 12/28/2012
1.27 - 01/01/2013
1.28 - 02/05/2013
1.29 - 04/30/2013
1.30 - 06/28/2013
1.31 - 07/01/2013
1.32 - 07/09/2015
1.33 - 07/10/2015
1.34 - 07/13/2015
1.35 - 10/09/2015
1.36 - 02/19/2016
1.37 - 02/21/2016

Changes:
1.0:
-Created the class

1.1:
-Fixed and changed several item descriptions
-Updated the stats of several ships

1.2:
-Fixed and changed several item descriptions
-Updated the stats of several ships

1.3:
-Fixed and changed several item descriptions
-Updated the stats of several ships

1.4:
-Fixed and changed several item descriptions
-Updated the stats of several ships

1.5:
-Fixed and changed several item descriptions
-Updated the stats of several ships
-Added getSName, getSShield, getSArmor, and getSHull

1.6:
-Finished recoding the ship database; replaced 2,425 lines of code with 43

1.7:
-Began work on laserDB matrix
-Fixed and changed several item descriptions
-Updated the stats of several lasers

1.8:
-Fixed and changed several item descriptions
-Updated the stats of several lasers
-Finished laserDB

1.9:
-Began work on missileDB matrix
-Fixed and changed several item descriptions
-Updated the stats of several missiles

1.10:
-Fixed and changed several item descriptions
-Updated the stats of several missiles

1.11:
-Fixed and changed several item descriptions
-Updated the stats of several missiles
-Added Hellstorm Missile

1.12:
-Fixed and changed several item descriptions
-Updated the stats of several missiles
-Finished codeing the missileDB; replaced 4500 lines of code with 74

1.13:
-Started and finished recoding bombDB; replaced 1279 lines of code with 27
-Added a bomb hold to the Rifter design
-Added 'get' functions for obtaining weapon information

1.14:
-Added a missile turret to the Osprey design
-Added 'get' functions for some of the bomb and missile wepaon data

1.15:
-Remade the weapon data martices so that they could be combined into one large weaponDB matrix
-Rewrote all weapon 'get' functions and removed any that were dupicates that were no longer needed
-Added weapon type and weapon damage type fields to the weaponDB matrix along with the functions to get those fields -Removed optimum range damage from the weapon information as optimum strike damage will be done through calculations  1.16: -Added new functions to return other ship related data

1.17:
-Added new functions to return other ship related data

1.18:
-Renamed the class to datasystem since all data is now being stored in this class and not just items
-Added planetNames, ranks, raceNames, and pDD arrays
-Coded previously added functions

1.19:
-Added getRace function

1.20:
-Removed all xCode2 = xCode - 1 and replaced these statements with [xCode-1] to cut down on code excess; removed 45 lines of code
-Added class field to shipDB, it was missing
-Added getWClass and doesCMatch functions
-Found problem with Xarn return, lead to noticing that there were many structural problems with the function calls and weaponDB; fixed those

1.21:
-Added getWDesc function

1.22:
-Started adding data casts to function calls so I can remove them from other classes
-Added data, data2 variables for casting

1.23:
-Added data casts to the rest of the functions

1.24:
-Began adding weapon classes to weaponDB, it was missing here as well
-Fixed a mistke I made earlier this month when I changed getWClass to return an integer, fixed it so that it correctly returns a string

1.25:
-Added station names array

1.26:
-Changed mission time limit to days instead of miliseconds
-Added missionDB

1.27:
-Added all of the functions to return mission data
-Added new fields to the missionDB for rewards and also converted any numbered "null" fields to -1

1.28:
-Removed periods from end of descriptions
-Found more problems, structurally, with the class' 'get' functions and the matrices; got the class working properly

1.29:
-Made some major cosmetic changes, partitioned off the matrices by class type and included the IDs around the array lines per ship for easier indentification
-Fixed major issue, class and class requirement fields were not actually what they were supposed to be; fixed all of them
-Removed planet Disposition, rank, and race arrays and replaced then with enums for easier use with switches
-Added new functions to return the enums
-Fixed several ship and weapons that were still missing the correct class field.

1.30:
-Added new function that will get pNames and send them to array in Game

1.31:
-Removed shipDB, weaponDB, and missionDB from the class.  This information is now going to be stored in external databases
-While adding data to the databases I found many major issues that would have cuased crashes, bugs, or other issues with appx. 25 items
-Changed ship armor, shield, and hull values are now represented by floats in the database.

1.32:
-Added some functions from ship system classes.

1.33:
-Added the rest of the functions from ship system classes.
-Added new member to return data from database.
-Modified rData to handle ship equipment, requirement, and skill data requests.

1.34:
-Added in coding for ship equipment functions and renamed getSEPCon and getSEIPCon to more accuratly refelct what the value it is returning is used for.

1.35:
-Started refactoring data getter classes

1.36:
-Started reworking rData due to recent changes by breaking out Ship Equipment handling per equipment type.
-Started adding in functionality for getting, storing, and passing game settings data from the database.
-Added vectors to store all types of ship equipment.
-Modified existing hardpoint vectors to work with the new slot system.

1.37:
-Continued coding rData function for new changes in database.


End File Header*/

#ifndef DATASYSTEM_H 
#define DATASYSTEM_H  
#include <string> 
#include "data_placeholder.h" 
#include "hardPoint.h" 
#include "sinv.h" 
#include "defenses.h" 
#include "mission.h" 
#include "relation.h" 
#include "ship2.h" 
#include "asteroid.h" 
#include "abelt.h"  

class Game;
class Station;
class Planet;
class Entity;
class Player;
class NPC;

using std::string;
class dataSystem
{
public:
	//Ship Data Search
	template<class t> t getData(string mObj, string sObj, string tObj); //get ship name

	string getSName(); //get ship name
	string getSDesc(); //get ship description
	string getSClass(); //get ship class
	int getSSM(); //get default shield matrix
	int getSAP(); //get default armor plating
	int getSHS(); //get default hull structure
	int getSCPU(); //get default cpu
	int getSRAM(); //get default ram
	int getSEngine(); //get default engine
	int getSPS(); //get default primary power system
	int getSSPS(); //get default secondary power system
	int getSTS(); //get default targeting system
	int getSWFG(); //get default warp field generator
	int getSLSlots(); //get low ship slots
	int getSMSlots(); //get mid ship slots
	int getSHSlots(); //get high ship slots
	float getSSG2(); //get ship SG2
	float getSCargo(); //get ship cargo
	int getSTLevel(); //get ship tech level
	int getSXCost(); //get ship xarn cost
	int getSRCost(); //get ship ruby cost
	int getSDiCost(); //get ship diamond cost
	int getSDCost(); //get ship draconic cost
	int getSUCost(); //get ship ura cost
	int getSPCost(); //get ship plut cost

	//Weapon Data Search
	int getWID(); //get weapon ID
	string getWName(); //get weapon name
	string getWDesc(); //get weapon description
	float getWDRLow(); //get weapon damage range low
	float getWDRHigh(); //get weapon damage range high
	float getWWeight(); //get weapon weight
	int getWAMin(); //get weapon accuracy minimum (min. target distance)
	int getWAOMin(); //get weapon optimum accuracy low (min. opt. target distance)
	int getWAOMax(); //get weapon optimum accuracy high (max. opt. target distance)
	int getWAMax(); //get weapon accuracy maximum (max. target distance)
	float getWDIRLow(); //get weapon damage intensity range low 
	float getWDIRHigh(); //get weapon damage intensity range high
	int getWACRate(); //get weapon ammo consumption rate
	int getWTLevel(); //get weapon tech level
	string getWClass(); //get weapon class
	float getWSG2(); //get weapon space
	int getWMCLength(); //get mining cycle length
	float getWMCAmount(); //get amount of ore mined per cycle
	int getWXC(); //get weapon xarn cost
	int getWRC(); //get weapon ruby cost
	int getWDiC(); //get weapon diamond cost
	int getWDC(); //get weapon draconic cost
	int getWLC(); //get weapon lithium cost 
	int getWUC(); //get weapon uranium cost
	int getWPC(); //get weapon plutonium cost
	int getWNWC(); //weapon nuclear waste cost
	string getWType(); //get weapon type
	string getWEName(); //get weapon effect name
	float getWEAmount(); //get weapon effect amount
	int getWEDuration(); //get weapon effect duration

	//Mission Data Search
	int getMisID(); //get mission id
	string getMName(); //get mission name
	string getMDesc(); //get mission description
	int getMCBEReq(); //get mission CBE level req
	string getMSCReq(); //get mission ship class req
	string getMMWReq(); //get mission equipment req
	int getMTLimit(); //get mission time limit
	string getMDiff(); //get mission difficulty
	string getMSector(); //get mission sector
	string getMSystem(); //get mission system
	string getMTName(); //get mission target name
	string getMTSClass(); //get mission target ship class
	int getMBounty(); //get mission bounty
	string getMType(); //get mission type

	//Mission Reward Return Functions
	int getMXR(); //Xarn
	int getMRR(); //Ruby
	int getMDiR(); //Diamond
	int getMDR(); //Draconic
	int getMLR(); //Lithium
	int getMPlR(); //Platinum
	int getMUR(); //Uranium
	int getMPR(); //Plutonium
	int getMNWR(); //N. Waste
	int getMEXPR(); //EXP
	string getMIR(); //item 

	//Planet Data Search Functions
	//void dADPlanet();
	//void dAIPlanet(); 
	//void dACStation();
	string getPName(int pCode); //planet array debugging
	void getPNames(vector<string>& names);  	//Entity Data Search Functions
	string getERace();
	string getERank();  	//Get Message Data
	string getMsg();
	bool doesCMatch(int cCode, int iCode, string iType); //Does required class match item class?

	//Planetary Shield Data
	int getPSID(); //get equipment id
	string getPSName(); //get equipment name
	string getPSDesc(); //get equipment description
	string getPSType(); //get equipment type
	int getPSTLevel(); //get equipment tech level
	float getPSSP(); //get equipment s points
	float getPSSPR(); //get equipment shield regen
	float getPSSG2(); //get equip space
	int getPSXC(); //get equipment xarn cost
	int getPSRC(); //get equipment ruby cost
	int getPSDiC(); //get equipment diamond cost
	int getPSDC(); //get equipment drac cost
	int getPSLC(); //get equipment lithium cost
	int getPSUC(); //get equipment ura cost
	int getPSPC(); //get equipment plut cost
	int getPSNWC(); //get equipment nwaste costw

	//Planetary Defense Data
	int getPDID(); //get equipment id
	string getPDName(); //get equipment name
	string getPDDesc(); //get equipment description
	string getPDType(); //get equipment type
	int getPDTLevel(); //get equipment tech level
	float getPDSP(); //get equipment s points
	string getPDDType(); //get equipment damage type
	float getPDMDmg(); //get equipment min damage
	float getPDMxDmg(); //get equipment max damage
	int getPDRng(); //get equipment range 
	float getPDSG2(); //get equip space 
	int getPDXC(); //get equipment xarn cost
	int getPDRC(); //get equipment ruby cost
	int getPDDiC(); //get equipment diamond cost
	int getPDDC(); //get equipment drac cost
	int getPDLC(); //get equipment lithium cost
	int getPDUC(); //get equipment ura cost 
	int getPDPC(); //get equipment plut cost
	int getPDNWC(); //get equipment nwaste cost
	int getPDCXP(); //get equipment cxp reward 

	//Clone Data
	int getCID(); //get equipment id
	string getCName(); //get equipment name
	string getCDesc(); //get equipment description
	string getCType(); //get equipment type
	int getCTLevel(); //get equipment tech level
	float getCSG2(); //get equip space
	int getCXC(); //get equipment xarn cost
	int getCRC(); //get equipment ruby cost
	int getCDiC(); //get equipment diamond cost
	int getCDC(); //get equipment drac cost
	int getCLC(); //get equipment lithium cost
	int getCUC(); //get equipment ura cost
	int getCPC(); //get equipment plut cost
	int getCNWC(); //get equipment nwaste cost
	string getCEffect(); //get equipment effect

	//Ship Equipment
	int getSETTime();
	int getSEMTargs();
	float getSEPReq();
	float getSECReq();
	float getSERReq();
	float getSECMax();
	float getSESRRate();
	float getSERRate();
	float getSEMAP();
	float getSERPCon();
	float getSEMThrust();
	float getSENSMax();
	float getSENPCon();
	float getSETRCWgt();
	float getSECDrain(); //Secondry Power System Drain per AU
	int getSEDTime(); //Delay to warp in ms
	float getSESMax(); //Max Speed
	float getSEIPCon(); //Initial Power Consumption (powering up cost; different from continuous drain)
	float getSEPMax();
	float getSEMHP();
	float getSEMSP();


	//Get Name
	string getRName();

	//Resource Data 
	string getResName();
	string getResDesc();
	string getResType();
	float getResSG2();
	int getResXCost();

	//Ore Data
	string getOName();
	string getODesc();
	string getOType();
	float getOSG2();
	int getOStage();
	float getOBSize();
	string getOResource();
	string getOOre();
	float getORUnits();
	int getORProduced();
	int getORCost();
	float getORPLoss();
	int getOXCost();

	/*//Skills
	string getSkName();
	string getSkDesc();
	string getSkEffect();
	string getSkType();
	string getSkGroup();
	int getSkTTime();
	float getSkTDiff();
	int getSkXCost();
	int getSkCXPCost();*/

	/*//Reqs
	vector<req> getReqs();*/

	//Retrieve Data
	void rData(string table, string operation, int ID);

	//Save Functions

	//Loading
	bool lData(Player& mPlayer, Game* mGame); //Load save data

	//Saving
	bool sData(Player& mPlayer, Game* mGame); //Create new save data

	//For debug
	void problems(string operation);

	//Misc 
	int getFlag(string fName); //Return the value of the passed flag

private:
	int			i, i2, i3; //For For Loops
	string		data, data3; //For casting
	int			data2; //For casting
	string		wType; //Weapon type

	int lastABID, lastAID; //Last ID for asteroid belts and asteroids for ID congruency between planets
	bool bErrors; //bool: errors were present during operations
	int bECount; //Number of errors thrown


	//Data temp storage
	vector<ship> ships;
	vector<weapon> weapons;
	vector<mission> missions;
	vector<diplomacy> dispositions;
	vector<planetName> pNames;
	vector<ranks> rank;
	vector<race> races;
	vector<message> messages;
	vector<pshield> pShield;
	vector<pdefense> pDefense;
	vector<clone> iClone;
	vector<name> names;
	vector<resource> resources;
	vector<ore> ores;
	vector<skill> skills;
	vector<req> reqs;
	vector<sequipment> sEquipment;
	vector<settings> sSettings;
	vector<cpu> sCpu;
	vector<ram> sRam;
	vector<psys> sPSystem;
	vector<spsys> sCap;
	vector<sm> sSMatrix;
	vector<wfg> sWFGen;
	vector<wts> sWTSystem;
	vector<eng> sEng;
	vector<ap> sAPlating;
	vector<hss> sHSStruct;
	vector<settings> gSettings;


	//Save/Load Vectors
	vector<playerData> pData;
	vector<pShip> plShips; //Store all player owned ships here for saving
	vector<pSSpread> plSSpreads;
	vector<pSHPVect> plSHPVectors;
	vector<pSInv> plSCargo;
	vector<pWingmenData> pWMData;
	vector<pWShip> pWMSData;
	vector<pWSSpread> pWMSSpreads;
	vector<pWSHPVect> pWMSHPVectors;
	vector<stationData> stData;
	vector<sPInv> sPInventory;
	vector<planetData> plData;
	vector<pDefData> plDData;
	vector<pSData> plSData;
	vector<pABelts> belts;
	vector<pABRoids> roids;
	vector<missionData> pMData;
	vector<relationData> pRData;
	vector<saveFlag> saveFlags;

	//Misc
	vector<hardPoint> tempHP;
	vector<hardPointL> tempLWV;
	vector<hardPointM> tempMWV;
	vector<hardPointB> tempBWV;
	vector<hardPointR> tempRWV;
	vector<hardPointH> tempHWV;
	vector<sInv> tempInv;
	vector<Defense> tempDData;
	vector<Shield> tempSData;
	vector<aBelt> tempBelts;
	vector<Asteroid> tempRoids;
	vector<Mission> tempMis1;
	vector<Mission> tempMis2;
	vector<Relation> tempR;
	Ship2 tShip;
	Ship2 tempShip;
};
#endif 