/*FILE HEADER

File Name:
datasystem.h

File Description:
This class is used to interact and obtain data from the database class.  This class acts as a buffer to get the specific data needed.  How it Works:  Functions are called that will try to obtain specific types of data for specific elements.
The neccessary information is sent to the database class and then when the data is retrieved it is loaded into a vector reference from this class.  That vector is then searched for the information needed.  Since this class is instance-based
the vector must only be created when first accessing this class, all subsequent calls to the class will be when the class already has the information.  Unless new data is needed refilling the vector is not neccessary.

Created On:  Sunday, April 24, 2011

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
	vector<misc> iMisc;
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