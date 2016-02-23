/*FILE HEADER

File Name:
data_placeholder

File Description:
Create a framework for vectors to import data into the game from the database.

Created On:  Sunday, January 31, 2016 (file header added on this date)

Version:
1.0 - 01/31/2016
1.2 - 02/20/2016


Changes:
1.0:
-Modified existing structures to align to recent database changes.
-Added new struct to contain game settings once the offloading of settings from the ini file into the database is completed.

1.1:
-Changed settings struct so that it works with the gVars concept.  Will contain every setting which is then passed to namespace and formatted as required.

1.2:
-Broke out the ship equipment struct into individual equipment types to eliminate unused variables per-type.


End File Header*/

#ifndef	DATA_PLACEHOLDER_H
#define DATA_PLACEHOLDER_H

#include <string>
#include <vector>

using std::string;
using std::vector;

struct settings
{
	//game settings imported here
	string sDTypes; //Difficulty Types
	vector<string> sDSettings; //Vector that will contain a list of - delimited key/value pairs for the difficulty chosen by the player.
	string sSSIDs; //- delimited range of starter ship IDs
	string sSCNames; //, delimited list of ship classes
	string sWCNames; //, delimited list of weapon classes
	float setFVal; //Setting Float Value
	int setIVal; //Setting Int Value
	long long setI64Val; //Setting Int64 Value
	string setS; //Setting String Value
	long long sSNames; //Stores the number of system names in the database

};

struct ship
{
	int sID;
	string sName;
	string sDesc;
	string sType;
	string sClass;
	string sSClass; //sub-class
	int sTLevel;
	int sTSlots;
	int lSlots;
	int mSlots;
	int hSlots;
	int sEng; //Engine
	int sPS; //Power System
	int sCPU; //CPU
	int sRAM; //RAM
	int sSPS; //Cap
	int sWFG; //Warp Gen
	int sSM; //Shield Matrix
	int sAP; //Armor Plating
	int sHS; //Hull Structure
	int sWTS; //Weap Target System
	float sSG2;
	float sCargo;
	//vector<int> resources;
	long long sXCost;
	long long sRCost;
	long long sDiCost;
	long long sDCost;
	long long sLCost;
	long long sUCost;
	long long sPCost;
	int sCEXP;
};

struct weapon
{
	int wID;
	string wName;
	string wDesc;
	string wType;
	string wClass;
	float wPReq;
	float wCReq;
	float wRReq;
	float wIPCon; //activation of weapon
	float wPCon; //continued use of weapon (const drain: hw; drain per fire: Lasers, MLauncher, Rail)
	int wTLevel;
	//float wAtkSpd;
	float wMDmg;
	float wMxDmg;
	float wDILow; //weapon damage intensity range low
	float wDIHigh; //weapon damage intensity range high
	int wACon; //weapon ammo consumption rate
	int wACap; //max ammo that can be stored in weapon at a time
	float wMass;
	int wMTDistance;
	int wMOTDistance;
	int wMxOTDistance;
	int wMxTDistance;
	float wSG2;
	int wMCDur;
	float wMCYld;
	long long wXCost;
	long long wRCost;
	long long wDiCost;
	long long wDCost;
	long long wLCost;
	long long wUCost;
	long long wPCost;
	long long wNWCost;
};

struct pshield
{
	int psID;
	string psName;
	string psDesc;
	string psType;
	int psTLevel;
	float psCapacity;
	float psSPRRate; //Rate of shield recharge
	float psSPRAmount; //How much shields  recharge by
	float psSG2;
	long long psXCost;
	long long psRCost;
	long long psDiCost;
	long long psDCost;
	long long psLCost;
	long long psUCost;
	long long psPluCost;
	long long psNWCost;
};

struct pdefense
{
	int pdID;
	string pdName;
	string pdDesc;
	string pdType;
	int pdTLevel;
	int pdCPU;
	int pdRAM;
	int pdPSys;
	int pdCap;
	int pdSMatrix;
	int pdAPlating;
	int pdHStruc;
	int pdWTSys;
	int pdTSlots;
	int pdLSLots;
	int pdMSlots;
	int pdHSlots;
	float pdCargo;
	float pdSG2;
	long long pdXCost;
	long long pdRCost;
	long long pdDiCost;
	long long pdDCost;
	long long pdLCost;
	long long pdUCost;
	long long pdPluCost;
	long long pdNWCost;
	int pdCXP;
};

struct clone
{
	int		cID;
	string  cName;
	string  cDesc;
	string  cType;
	int		cTLevel;
	float   cSG2;
	long long		cXCost;
	long long		cRCost;
	long long		cDiCost;
	long long		cDCost;
	long long		cLCost;
	long long		cUCost;
	long long		cPluCost;
	long long		cNWCost;
	string  cEffect;
	float cEAmount;
};


struct mission
{
	int		mID;
	string	mName;
	string	mDesc;
	int		mCBELevel;
	string  mSCReq;
	string  mMWReq;
	int		mTLimit;
	string  mDifficulty;
	string  mSector;
	string  mSystem;
	string  mTName;
	string  mTSClass;
	int		mBounty;
	long long		mXarn;
	long long		mRubies;
	long long		mDiamonds;
	long long		mDraconic;
	long long		mLithium;
	long long		mPlatinum;
	long long		mUranium;
	long long		mPlutonium;
	long long		mNWaste;
	int		mCEXP;
	string  mItem;
	string  mType;
};

struct skill
{
	int		 skID; //Skill ID
	string	 skName; //Skill Name
	string	 skDesc; //Skill Description
	string	 skEffect; //Skill Effect
	float		skEAmount;
	string	 skType; //Type
	string	 skSGroup; //Skill Group
	float	 skSG2; //SG2
	int	 skTTime; //Training Time
	float	 skTDiff; //Training Difficulty
	int	 skXCost; //Xarn Cost
	int	 skCXPCost; //CXP Cost
};

struct req
{
	int rEID; //Entity ID (ID of the item this requirement is for)
	int rRID; //Requirement ID OR Skill Rank, Player Rank, Player CEL, ext.
	string rType; //Describes that the value of rRID is; ex: Player Rank means the value of rRID is a numerical value representing the rank the play must have
};


struct message
{
	string mes;
};

struct planetName
{
	string pName;
	int pID;
};

/*
struct pMData //For Planetary militia in later versions
{

};
*/

struct empires
{

};

struct corporations
{

};

struct diplomacy
{
	string dDisposition;
};

struct race
{
	string rName;
};

struct ranks
{
	string rkName;
};

struct name
{
	string name_;
};

struct resource
{
	string rName;
	string rDesc;
	float rSG2;
	string rType;
	int rXCost;
};

struct ore
{
	string oName;
	string oDesc;
	float oSG2;
	string oType;
	int oStage;
	float oBSize;
	string oResource;
	string oOre;
	float oRUnits;
	int oRProduced;
	int oRCost;
	float oRPLoss;
	long long oXCost;
};

struct equipment {
	string eName; //Name
	string eDesc; //Description
	string eType; //Type
	string eClass; //Class
	string eSClass; //Subclass
	int eTLevel; //Tech Level
	float eMnDmg; //Min Damage
	float eMxDmg; //Max Damage
	int eMxSDist; //Max Scan Dist
	int eMxTDist; //Max Target Distance
	int eTTime; //Time to Target in ms
	float ePReq; //Primary Power Requirement
	float eCReq; //CPU Requirement
	float eRReq; //RAM Requirement
	float eRPCon; //Rate of Power Consumption (some weapons/shield/stc)
	float eIPCon; //Initial Power Consumption (powering up cost; different from continuous drain)
	float eSDRed; //Shield damage reduction (for shield hardeners)
	float eMThrust; //Max thrust (acceleration; afterburners)
	float eMSpeed; //Max additional speed (afterburners)
	float eRRate; //Recharge Rate (multiple uses)
	float eDTime; //Delay time (not sure)
	float eSG2; //SG2
	
	long long eXCost;
	long long eRCost;
	long long eDiCost;
	long long eDCost;
	long long eLCost;
	long long eUCost;
	long long ePCost;
	long long eNWCost;
};

struct cpu
{
	int seID; //ID
	string seName; //Name
	string seDesc; //Description
	string seType; //Type
	int seTLevel; //Tech Level	
	float sePReq; //Primary Power Requirement
	float seCMax; //RAM/CPU/PSys/SPSys - Max Capacity
	float seSG2; //SG2
	long long seXCost;
	long long seRCost;
	long long seDiCost;
	long long seDCost;
	long long seLCost;
	long long seUCost;
	long long sePCost;
	long long seNWCost;
};

struct ram
{
	int seID; //ID
	string seName; //Name
	string seDesc; //Description
	string seType; //Type
	int seTLevel; //Tech Level
	float sePReq; //Primary Power Requirement
	float seCReq; //CPU Requirement
	float seCMax; //RAM/CPU/PSys/SPSys - Max Capacity
	float seSG2; //SG2
	long long seXCost;
	long long seRCost;
	long long seDiCost;
	long long seDCost;
	long long seLCost;
	long long seUCost;
	long long sePCost;
	long long seNWCost;
};

struct psys
{
	int seID; //ID
	string seName; //Name
	string seDesc; //Description
	string seType; //Type
	int seTLevel; //Tech Level
	float seCMax; //RAM/CPU/PSys/SPSys - Max Capacity
	float seSG2; //SG2

	long long seXCost;
	long long seRCost;
	long long seDiCost;
	long long seDCost;
	long long seLCost;
	long long seUCost;
	long long sePCost;
	long long seNWCost;
};

struct spsys
{
	int seID; //ID
	string seName; //Name
	string seDesc; //Description
	string seType; //Type
	float sePReq; //Primary Power Requirement
	float seCReq; //CPU Requirement
	float seRReq; //RAM Requirement
	float seCMax; //RAM/CPU/PSys/SPSys - Max Capacity
	float seSRRate; //Capacitor (Secondary Power System; SPS) Recharge Rate
	float seSRAmount; //% of cap recharged per seSRRate period
	float seSG2; //SG2

	long long seXCost;
	long long seRCost;
	long long seDiCost;
	long long seDCost;
	long long seLCost;
	long long seUCost;
	long long sePCost;
	long long seNWCost;
};

struct ap
{
	int seID; //ID
	string seName; //Name
	string seDesc; //Description
	string seType; //Type
	int seTLevel; //Tech Level
	float sePReq; //Primary Power Requirement
	float seCReq; //CPU Requirement
	float seRReq; //RAM Requirement	
	float seRRate; //Recharge/Repair Rate for everything else BUT the capacitor (some weapon/shield/etc)
	float seRAmount; //% repair/regenerated per seRRate
	float seMAP; //Max Armor Points
	float seRPCon; //Rate of Power Consumption (some weapons/shield/stc)
	float seRDelay; //Delay before recharge/repair starts (for shields and some other things)
	float seSG2; //SG2

	long long seXCost;
	long long seRCost;
	long long seDiCost;
	long long seDCost;
	long long seLCost;
	long long seUCost;
	long long sePCost;
	long long seNWCost;
};

struct sm
{
	int seID; //ID
	string seName; //Name
	string seDesc; //Description
	string seType; //Type
	int seTLevel; //Tech Level
	float sePReq; //Primary Power Requirement
	float seCReq; //CPU Requirement
	float seRReq; //RAM Requirement
	float seRRate; //Recharge/Repair Rate for everything else BUT the capacitor (some weapon/shield/etc)
	float seRPCon; //Rate of Power Consumption (some weapons/shield/stc)
	float seRAmount; //% repair/regenerated per seRRate
	float seRDelay; //Delay before recharge/repair starts (for shields and some other things)
	float seMSP; //Max Shield Points
	float seSG2; //SG2

	long long seXCost;
	long long seRCost;
	long long seDiCost;
	long long seDCost;
	long long seLCost;
	long long seUCost;
	long long sePCost;
	long long seNWCost;
};

struct hss
{
	int seID; //ID
	string seName; //Name
	string seDesc; //Description
	string seType; //Type
	int seTLevel; //Tech Level
	float sePReq; //Primary Power Requirement
	float seCReq; //CPU Requirement
	float seRReq; //RAM Requirement
	float seSRRate; //Capacitor (Secondary Power System; SPS) Recharge Rate
	float seRRate; //Recharge/Repair Rate for everything else BUT the capacitor (some weapon/shield/etc)
	float seRPCon; //Rate of Power Consumption (some weapons/shield/stc)
	float seRAmount; //% repair/regenerated per seRRate
	float seRDelay; //Delay before recharge/repair starts (for shields and some other things)
	float seMHP; //Max Hull Points
	float seSG2; //SG2

	long long seXCost;
	long long seRCost;
	long long seDiCost;
	long long seDCost;
	long long seLCost;
	long long seUCost;
	long long sePCost;
	long long seNWCost;
};

struct wfg
{
	int seID; //ID
	string seName; //Name
	string seDesc; //Description
	string seType; //Type
	int seTLevel; //Tech Level
	float sePReq; //Primary Power Requirement
	float seCReq; //CPU Requirement
	float seRReq; //RAM Requirement
	float seCDrain; //Capacitor Drain per AU
	int seDTime; //Delay to warp in ms
	float seSMax; //Max Speed - warp
	float seSG2; //SG2

	long long seXCost;
	long long seRCost;
	long long seDiCost;
	long long seDCost;
	long long seLCost;
	long long seUCost;
	long long sePCost;
	long long seNWCost;
};

struct wts
{
	int seID; //ID
	string seName; //Name
	string seDesc; //Description
	string seType; //Type
	int seTLevel; //Tech Level
	int seTTime; //Time to Target in ms
	int seMTargs; //Max Targets
	float sePReq; //Primary Power Requirement
	float seCReq; //CPU Requirement
	float seRReq; //RAM Requirement
	float seMSRng; //Max Scan Range
	float seSG2; //SG2

	long long seXCost;
	long long seRCost;
	long long seDiCost;
	long long seDCost;
	long long seLCost;
	long long seUCost;
	long long sePCost;
	long long seNWCost;
};

struct eng
{
	int seID; //ID
	string seName; //Name
	string seDesc; //Description
	string seType; //Type
	int seTLevel; //Tech Level
	float sePReq; //Primary Power Requirement
	float seCReq; //CPU Requirement
	float seRReq; //RAM Requirement
	float seCMax; //RAM - Max Capacity
	float seMThrust; //Max Thrust
	float seNSMax; //Max Speed - Normal
	float seNPCon; //Power Consumption - Normal
	float seTRCWgt; //Turn Rate Completion Weighting
	int seMInit;
	float seSG2; //SG2

	long long seXCost;
	long long seRCost;
	long long seDiCost;
	long long seDCost;
	long long seLCost;
	long long seUCost;
	long long sePCost;
	long long seNWCost;
};


//Save File Table Structs
struct planetData
{
	int pID; //Planet ID
	string pName;
	string pAffiliation;
	string pDispo;
	string pRace;
	int bIsPOwned;
	int bIsDestroyed;
	float pEKS;
	float pSize;
	long long int pCPop;
	long long int pMPop;
};

struct pDefData
{
	int pID; //Planet ID from table
	int pDID; //Planetary Defense ID for table lookup
};

struct pSData
{
	int pID;
	int mID; //Moduel table item ID for table look up
};

struct pABelts
{
	int bID; //Belt ID from table
	int pID; //Planet ID that this belt belongs to
	string bName; //Belt name
	float bSize; //The size of the belt
	int bBIsFull; //bool: is this belt full (using integer interface)
};

struct pABRoids
{
	int aID; //Asteroid ID from table
	int bID; //Belt ID that this roid belongs to
	int pID;
	string aName; //Name of this roid
	string aDesc; //Roid description
	float aSize; //Size of this roid
	string aOName; //Ore name
	int aOID; //Ore ID
	float aOAmount; //How much ore is present in the roid

	//Roid position in belt
	int xPos;
	int yPos;
	int zPos;
};

struct playerData
{
	string pName;
	string pRank;
	int pCXPLevel;
	int pPDestroyed;
	int pFKills;
	int pDKills;
	int pCKills;
	int pBCKills;
	int pBKills;
	int pCSKills;
	int pMKills;
	int pTKills;
	int pCEXP;
	int pCXPTNL;
	long long pXarn;
	long long pRubies;
	long long pDiamonds;
	long long pDrac;
	long long pLith;
	long long pPla;
	long long pUra;
	long long pPlu;
	long long pNWaste;
	string pAffiliation;
};

struct pShip
{
	string psName;
	string psClass;
	int psTLevel;
	int psMInit;
	float psSG2;
	float psMCSpace;
	int psLSlots;
	int psMSlots;
	int psHSlots;
	int psULSlots;
	int psUMSlots;
	int psUHSlots;
	int psMWSpreads; //Max number of usable weapon spreads
	int psID;
	int psSID; //Ship ID
	int psSTID; //Station ID
	string psLocal; //If this ship is stored, where? Station or ship?
	int psEng;
	int psPS;
	int psCPU;
	int psRAM;
	int psSPS;
	int psWFG;
	int psSM;
	int psAP;
	int psHS;
	int psWTS;
};

struct pSInv
{
	int sID; //Ship ID
	int iID; //Item ID
	string iType; //Item Type
	int iAmount; //Amount of items
	float iSG2; //Space each item takes up
};

struct pSSpread
{
	int sID; //HPSlot value in the weapon vector indicated by the below variable
	string sWType; //What type of weapon was stored in the slot
	int sPID; //Spread ID, used to track which weapons belong to which spread
};

struct pSHPVect
{
	int sID; //HPSlot value in the weapon vector indicated by the below variable
	int wID; //Weapon ID
	string sWType; //What type of weapon was stored in the slot
};

struct pWingmenData
{
	string pWName;
	string pWRank;
	int pWCXPLevel;
};

struct pWShip
{
	int pWID; //ID from table to deal with multiple wingmen w/o having to use a crap ton of tables for each
	string sName;
	string sClass;
	int sTLevel;
	float sSP;
	float sAP;
	float sHP;
	float sMSP;
	float sMAP;
	float sMHP;
	int sMInit;
	int sLB;
	int sMT;
	int sBH;
	int sRM;
	int sHWB;
	int sWHP;
	int sULB;
	int sUMT;
	int sUBH;
	int sURM;
	int sUHWB;
	int sMWSpreads;
};

struct pWSSpread
{
	int sID; //HPSlot value in the weapon vector indicated by the below variable
	string sWType; //What type of weapon was stored in the slot
	int wID; //ID of wingmen this spread belongs to
	int sPID; //Spread ID
};

struct pWSHPVect
{
	int sID; //HPSlot value in the weapon vector indicated by the below variable
	int wep_ID; //Weapon ID
	string sWType; //What type of weapon was stored in the slot
	int wID; //ID of wingmen this spread belongs to
};

struct stationData
{
	int sID; //ID from table for dealing with player inventories in various stations
	string sName;
	string sAffiliation;
	string sDispo;
	int sTLevel;
	int sLevel; //Station level
	float sMSpace; //Max usable storage space
	float sCMulti; //Cost multiplier
};

struct sPInv
{
	int sID; //Station ID
	int iID; //Item ID
	int NOI; //Number of items stored
	string iType;
	float iSG2;
};

struct missionData
{
	int mID; //Mission ID
	string mName;
	string mDesc;
	string mType;
	int mCBEReq; //combat experience requirement
	string mSCReq; //ship requirement
	string mMWReq; //module/weapon requirement
	int mDur; //duration in days
	string mDifficulty;
	string mLSector; //location; sector
	string mLSystem; //location; system
	string mTName; //target name
	string mTSClass; //target ship class
	int mBounty;
	int mXR; //xarn reward
	int mRR; //ruby reward
	int mDiR; //diamond reward
	int mDR; //draconic reward
	int mLR; //lithium reward
	int mPlR; //platinum reward
	int mUR; //uranium reward
	int mPR; //plutonium reward
	int mNWR; //nuclear waste reward
	int mEXPR; //exp reward
	string mIR; //item reward;
	int mState; //Mission State
};

struct relationData
{
	string	rName; //Name of entity the relationship is relevent to (IE: Earth Alliance)
	int		rAffinity; //Value of the relationship; negative numbers indicate a negative relationship.
};

struct saveFlag
{
	string sfName; //Flag Name
	int sfValue; //Flag Value
};

#endif
