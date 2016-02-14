#ifndef msgproc_H
#define msgproc_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "entity.h"
#include "bentity.h"
#include "weapon.h"
#include "mission.h"
#include "station.h"
#include "game.h"
#include "g_structs.h"

using std::string;
using std::vector;
using std::pair;

class Planet;

class msgProc
{
public:
	msgProc();

	//Game Menus
	int gTMenu(); //title menu
	bool cClone(int* sID, int* sIID, Game& mGame); //Check for clones
	void gOver();

	//Player Menus
	int pCMenu1(); //player creation menu 1
	int pCMenu2(); //player creation menu 2
	int pCMenu3(); //player creation menu 3
	int pCMenu4(); //player creation menu 4
	void pInfo(Player& mPlayer, Game& mGame); //Player information

	//Battle Menus
	int bMenu1(); //battle menu 1
	int bMenu1A(); //battle menu 1
	int bMenu1B(int hostiles);
	int bMenu1B_PB1();
	int bMenu1B_PB3(int hostiles);
	int bMenu2(); //battle menu 2
	int bMenu2_PB(); //battle menu 2 - PB
	int bPBMenu(); //bombing menu
	void pBAStatus(Player& mPlayer, int allies); //player ally battle status
	void pBStatus(Player& mPlayer); //player battle status
	int hBStatus(NPC& mNPC, int hostiles); //hostile battle status (multiple)
	int hBStatusB(NPC& mNPC, int hostiles); //hostile battle status (multiple)
	void hBStatus(NPC& target); //hostile battle status (single)
	int hBStatus_PB(Planet* gPlanet); //hostile battle status (multiple)
	void hBSStatus_PB(Planet* gPlanet, bool shield, int sID, bool defense, int dID, bool planet); //All purpose information display; single target
	int bCSpread(int sWSpreads, Player& mPlayer); //Battle choose weapon spread
	int bCWSystem(Player& mPlayer); //Battle choose weapon system
	int bCWeapon(Player& mPlayer, string* wtype); //Battle choose single weapon
	int bCBomb(Player& mPlayer, string* wtype); //Battle choose bomb
	bool bHail1(string affiliation, string race, int affinity);
	int bHail2(int affinity);
	bool bHail3(int affinity, int pChoice, string race, string affil);
	bool bNHail1(); //Ask player to accept or deny npc hail
	bool bNHDemand(); //NPC demands surrender
	bool bNHSurrender(); //NPC surrenders to player
	void bHInfo(int affinity, string race);
	void bHEnemies(string race);
	void bHSurrender(int affinity, string race); //TODO: create a third parameter to determine enemy strength to also be considered for surrender or not
	int bPSurrender(int ransom[]); //Display ransom that player must pay
	int bHTrade(); //Figure out what will be required for this; might have to wait for station merge for inventories
	void bHNothing();
	void bEMiss_PD(Defense& pDefense);
	void bRewards(Player& mPlayer, int rX, int rR, int rDi, int rD, int rL, int rPl, int rU, int rP, int rNW, int rCXP, int fK, int dK, int cK, int bcK, int bK, int mK, int tK, bool planet);

	//Damage Output
	void dDamage1S(float dam, bEntity& bAttacker, bEntity& bTarget, bool defense); //Damage against ship - shield
	void dDamage1SA(float dam1, float dam2, bEntity& bAttacker, bEntity& bTarget, bool defense); //Damage against ship - shield to armor
	void dDamage1A(float dam, bEntity& bAttacker, bEntity& bTarget, bool defense); //Damage against ship - armor
	void dDamage1AH(float dam1, float dam2, bEntity& bAttacker, bEntity& bTarget, bool defense); //Damage against ship - armor to hull
	void dDamage1H(float dam, bEntity& bAttacker, bEntity& bTarget, bool defense); //Damage against ship - hull
	void dDamage1H_K(bEntity& bAttacker, bEntity& bTarget, bool defense); //Damage against ship - hull - ship destroyed

	void dDamage2S(float dam, bEntity& bAttacker, bEntity& bTarget, Planet* planet); //Damage against planet - shield
	void dDamage2D(float dam, bEntity& bAttacker, bEntity& bTarget, Planet* planet); //Damage against planet - defense
	void dDamage2D_K(bEntity& bAttacker, bEntity& bTarget, Planet* planet); //Damage against planet - defense - destroyed
	void dDamage2P(float dam, bEntity& bAttacker, bEntity& bTarget); //Damage against planet
	void dDamage2P_K(bEntity& bAttacker, bEntity& bTarget); //Damage against planet - all pop killed

	void dPSDisabled(Planet* planet, bEntity& bTarget, int turns); //notify if planetary shield collapses and is disabled for a number of turns
	void dSDInflicted(bEntity& bAttacker, bEntity& bTarget, string dType, int turns); //Notify when a secondary turn based damage has been inflicted
	void dBonus(float dam1, float dam2, string dType, bEntity& bAttacker); //Alert of increased damage due to bonuses
	void dSDisabled(bEntity& bTarget, int truns); //bTarget ship disabled for turns
	void dSSDisabled(bEntity& bTarget, int turns); //bTarget shields disabled for turns

	void dSDamageS(float dam, string dType, bEntity& bTarget); //Secondary damage - shield
	void dSDamageSA(float dam1, float dam2,  string dType, bEntity& bTarget); //Secondary damage - shield to armor
	void dSDamageA(float dam, string dType, bEntity& bTarget); //Secondary damage - armor
	void dSDamageAH(float dam1, float dam2,  string dType, bEntity& bTarget); //Secondary damage - armor to hull
	void dSDamageH(float dam, string dType, bEntity& bTarget); //Secondary damage - hull


	//Nav Menus
	int nMenu1(); //navigation menu 1
	int gGTPlanet(vector<Planet> planets, Player& mPlayer);
	int gGTStation(vector<Station> tStats, Player& mPlayer, Game* mGame);
	//int nMenu2(); //navigation menu 2
	void nBSPos(Player& mPlayer, NPC& mNPC); //Navigation battle ship positions
	void mTPos(Player& mPlayer, Asteroid roid); //Navigation battle ship positions

	//Station menus
	int sMenu(Station& stat); //station main menu
	int sMBS(); //station buy/sell menu
	int sMMenu(); //Main Market Menu

	//Primary Market Tree
	int sMEMLoop(); //station equipment menu loop
	int sMMMLoop(); //station misc menu loop
	int sMSMLoop(); //station ships menu loop
	int sMSKMLoop(); //station skills menu loop


	//Secondary Market Tree
	
	//Eqipment Market
	int sMEMAmmo(); //Ammunition
	int sMEMDrones(); //Drones
	int sMEMMining(); //Mining
	int sMEMMods(); //Modules
	int sMEMPEquip(); //P. Equipment
	int sMEMRigs(); //Rigs
	int sMEMSEquip(); //S. Equipment
	int sMEMWeaps(); //Weapons

	//Misc. Market
	int sMMMOres(); //Ores
	int sMMMRes(); //Resources
	int sMMMStat(); //Stations	

	//Ship Market
	int sMSMFrigs(); //Frigates
	int sMSMDests(); //Destroyers
	int sMSMCruis(); //Cruisers
	int sMSMBCrus(); //Battle Cruisers
	int sMSMBShips(); //Battleships
	int sMSMCShips(); //Commandships
	int sMSMMShips(); //Motherships
	int sMSMTitas(); //Titans
	int sMSMMBarges(); //Mining Barges
	
	//Skill Market
	int sMSKMBSkills(); //Battle Skills
	int sMSKMCSkills(); //Cartography Skills
	int sMSKMMSkills(); //Mining Skills
	int sMSKMPLSkills(); //Planetary Skills
	int sMSKMPRSkills(); //Production Skills
	int sMSKMMCRSkill(); //Reprocessing Skills
	int sMSKMSSkills(); //Ship Skills
	int sMSKMSTSkills(); //Station Skills
	int sMSKMTSkills(); //Trade Skills
	int sMSKMTRSkills(); //Training Skills
	int sMSKMWSkills(); //Weapon Skills

	
	//Tertiary Market Tree

	//Equipment
	//Ammmo Market
	int sMEMAMissiles(); //Missiles
	int sMEMARMBlocks(); //Railgun Ammo Blocks

	//Drones
	int sMEMDEWDrones(); //E. Warfare Drones
	int sMEMDECDrones(); //E. W. C. M. Drones
	int sMEMDMDrones(); //Military Drones
	int sMEMDMIDrones(); //Mining Drones
	int sMEMDRDrones(); //Repair Drones

	//Mining
	int sMEMMACrystals(); //A. Crystals
	int sMEMMLasers(); //Mining Lasers
	int sMEMMStrippers(); //Strip Miners

	//Modules
	int sMEMMDActive(); //Active Modules
	int sMEMMDPassive(); //Passive Modules

	//P. Equipment
	int sMEMPECPrefabs(); //Colonization Prefabs
	int sMEMPEOWPlatforms(); //P. Defenses
	int sMEMPEPACT(); //Planetary Administration and Colonization Tools (PACTs)		
	int sMEMPEPShields(int type); //P. Shields

	//Rigs
	int sMEMRLSlot(); //Low Slot Rigs
	int sMEMRMSlot(); //Med Slot Rigs
	int sMEMRHSlot(); //High Slot Rigs

	//S. Equip
	int sMEMSECSystems(); //Capacitor Systems
	int sMEMSECCores(); //CPU Cores
	int sMEMSEESystems(); //Engine Systems
	int sMEMSEMCores(); //Memory Cores
	int sMEMSEPSystem(); //Power Systems
	int sMEMSEWDSystem(); //Warp Drive Systems
	int sMEMSEWTSystem(); //Weapons Targeting Systems

	//Weapons
	int sMEMWBombs(); //Weapons- Bombs
	int sMEMWHeavy(); //Weapons- Heavy
	int sMEMWLasers(); //Weapons- Lasers
	int sMEMWMLasers(); //Weapons- Mining Lasers
	int sMEMWMissiles(); //Weapons- Missiles
	int sMEMWRail(); //Weapons- Railguns

	//Misc.
	//Ores
	int sMMMOCarboid(); //Carboid Ores
	int sMMMOCesogyn(); //Cesogyn Ores
	int sMMMOMethyx(); //Methyx Ores
	int sMMMOPyrax(); //Pyrax Ores

	//Skills
	int sMSKMBSBSkills(); //Battle- Ship Battle Skills
	int sMSKMBPBSkills(); //Battle- Planetary Battle Skills
	int sMSKMPLSASkills(); //Planetary- Administration Skills
	int sMSKMPLSCSkills(); //Planetary- Colonization Skills
	int sMSKMSSCASkills(); //Ship- Cargo Skills
	int sMSKMSSCPSkills(); //Ship- CPU Skills
	int sMSKMSSESkills(); //Ship- Engine Skills
	int sMSKMSSMESkills(); //Ship- Memory Skills
	int sMSKMSSMOSkills(); //Ship- Module Skills
	int sMSKMSSPSSkills(); //Ship- Power System Skills
	int sMSKMSSRSkills(); //Ship- Rig Skills
	int sMSKMSSSSkills(); //Ship- Shield Skills
	int sMSKMSSWSSkills(); //Ship- Weapon System Skills
	int sMSKMWSBSkills(); //Weapon- Bomb Skills
	int sMSKMWSHSkills(); //Weapon- Heavy Skills
	int sMSKMWSLSkills(); //Weapon- Laser Skills
	int sMSKMWSMLSkills(); //Weapon- Missile Launcher Skills
	int sMSKMWSRSkills(); //Weapon- Railgun Skills

	
	//Quaternary Market Tree

	//Equipment
	//Ammo
	int sMEMAMRMBA(); //R.G. Ammo- Antimatter
	int sMEMAMRMBTi(); //R.G. Ammo- Titanium
	int sMEMAMRMBTu(); //R.G. Ammo- Tungsten
	
	//Drones
	//EW Drones
	int sMEMDEWDCJammers(); //E.W. Drones- Cloak Jammers
	int sMEMDEWDHackers(); //E.W. Drones- Hackers
	int sMEMDEWDSJammers(); //E.W. Drones- Sensor Jammers
	int sMEMDEWDTJammers(); //E.W. Drones- Targeting Jammers
	int sMEMDEWDWScrams(); //E.W. Drones- Warp Scramblers

	//EWCM Drones
	int sMEMDECDCBoosters(); //E.W.C.M. Drones- Cloak Boosters
	int sMEMDECDEDDrones(); //E.W.C.M. Drones- EDDs
	int sMEMDECDSModulators(); //E.W.C.M. Drones- Sensor Modulators
	int sMEMDECDTRepeaters(); //E.W.C.M. Drones- Targeting Repeaters
	int sMEMDECDWStabalizers(); //E.W.C.M. Drones- Warp Stabalizers

	//Military Drones
	int sMEMDMDRecon(); //Military Drones- Recon
	int sMEMDMDScouts(); //Military Drones- Scouts
	int sMEMDMDWar(); //Military Drones- War
	int sMEMDMTanks(); //Military Drones- Tanks

	int sMEMDMining(); //Mining Drones

	//Repair Drones
	int sMEMDRDArmor(); //Repair Drones- Armor
	int sMEMDRDHull(); //Repair Drones- Hull
	int sMEMDRDVersitile(); //Repair Drones- Versitile

	//Mining
	//Attunement Crystals
	int sMEMMACCarboid(); //A. Crystals- Carboid
	int sMEMMACCesogyn(); //A. Crystals- Cesogyn
	int sMEMMACMethyx(); //A. Crystals- Methyx
	int sMEMMACPyrax(); //A. Crystals- Pyrax

	//Modules
	//Active
	int sMEMMDAABurners(); //Active Modules- Afterburners
	int sMEMMDAEWarfare(); //Active Modules- E.W.
	int sMEMMDAEWCM(); //Active Modules- E.W.C.M.
	int sMEMMDARBooms(); //Active Modules- Repair Booms
	int sMEMMDAScanners(); //Active Modules- Scanners
	int sMEMMDASHardeners(); //Active Modules- Shield Hardeners

	//Passive
	int sMEMMDPSEnhancements(); //Passive Modules- Ship Enhancements

	//P. Equipment
	//Orbital Weapons Platforms
	int sMEMPEOWPHeavy(); //OWP- Heavy
	int sMEMPEOWPLaser(); //OWP- Laser
	int sMEMPEOWPMissile(); //OWP- Missile
	int sMEMPEOWPRail(); //OWP- Rail

	//PACTs
	int sMEMPEPACTMTools(); //PACTs- Management Tools
	int sMEMPEPACTTTools(); //PACTs- Terraforming Tools

	
	//Quinary Market Tree

	//War Drones
	int sMEMDMDWBomb(); //War Drones- Bomb
	int sMEMDMDWHeavy(); //War Drones- Heavy
	int sMEMDMDWLaser(); //War Drones- Laser
	int sMEMDMDWMissile(); //War Drones- Missile
	int sMEMDMDWRail(); //War Drones- Rail

	//EW Modules
	int sMEMMDAEWJammers(); //E.W. Modules- Cloak Jammers
	int sMEMMDAEWHackers(); //E.W. Modules- Hackers
	int sMEMMDAEWSJammers(); //E.W. Modules- Sensor Jammers
	int sMEMMDAEWTJammers(); //E.W. Modules- Targeting Jammers
	int sMEMMDAEWWScrams(); //E.W. Modules- Warp Scramblers

	//EWCM Modules
	int sMEMMDAEWCMCBoosters(); //E.W. Modules- Cloak Boosters
	int sMEMMDAEWCMEDModules(); //E.W. Modules- EDMs
	int sMEMMDAEWCMSModulators(); //E.W. Modules- Sensor Modulators
	int sMEMMDAEWCMTRepeaters(); //E.W. Modules- Targeting Repeaters
	int sMEMMDAEWCMWStabalizers(); //E.W. Modules- Warp Stabalizers

	//Repair Booms
	int sMEMMDARBArmor(); //Repair Booms- Armor
	int sMEMMDARBHull(); //Repair Booms- Hull
	int sMEMMDARBVersatile(); //Repair Booms- Versatile

	//Scanner Modules
	int sMEMMDASCargo(); //Scanners- Cargo
	int sMEMMDASMineral(); //Scanners- Mineral
	
	//Ship Enhancement Modules
	int sMEMMDPSECap(); //Ship Enhancements- Capacitor
	int sMEMMDPSECargo(); //Ship Enhancements- Cargo
	int sMEMMDPSECPU(); //Ship Enhancements- CPU
	int sMEMMDPSEEngine(); //Ship Enhancements- Engine
	int sMEMMDPSEMemory(); //Ship Enhancements- Memory
	int sMEMMDPSEPSystem(); //Ship Enhancements- Power System
	int sMEMMDPSESSystem(); //Ship Enhancements- Shield System
	int sMEMMDPSEWSystem(); //Ship Enhancements- Weapon System

	//Management Tools
	int sMEMPEPACTMTOSD(); //Management Tools- Obrital Supply Depot (OSD)


	//Senary Menu Tree

	//Capacitor Enhancements
	int sMEMMDPSECCE(); //Capcitor Enahncements- Capacity Enhancement
	int sMEMMDPSECEE(); //Capcitor Enahncements- Efficiency Enhancement
	int sMEMMDPSECRE(); //Capcitor Enahncements- Rechage Enhancement

	//CPU Enhancements
	int sMEMMDPSECPUEE(); //CPU Enahncements- Efficiency Enhancement
	int sMEMMDPSECPUPE(); //CPU Enahncements- Power Enhancement

	//Engine Enhancements
	int sMEMMDPSEESE(); //Engine Enhancements- Sub-warp Enhancements
	int sMEMMDPSEEWE(); //Engine Enahncements- Warp Enhancement

	//Memory Enhancements
	int sMEMMDPSEMCE(); //Memory Enahncements- Capacity Enhancement
	int sMEMMDPSEMEE(); //Memory Enahncements- Efficiency Enhancement

	//Power System Enhancements
	int sMEMMDPSEPSCE(); //Power System Enahncements- Capacity Enhancement
	int sMEMMDPSEPSEE(); //Power System Enahncements- Efficiency Enhancement

	//Shield System Enahncements
	int sMEMMDPSESSCE(); //Shield System Enahncements- Capacity Enhancement
	int sMEMMDPSESSRE(); //Shield System Enahncements- Recharge Enhancement

	//Weapon Systems Enhancements
	int sMEMMDPSEWSEE(); //Weapon Systems Enahncements- Efficiency Enhancement
	int sMEMMDPSEWSTE(); //Weapon Systems Enahncements- Targeting Expansions


	//Septernary Market Tree

	//Engine Systems Sub-Warp Enhancements
	int sMEMMDPSEESENE(); //Sub-Warp Enhancements- Navigation Enhancements
	int sMEMMDPSEESESE(); //Sub-Warp Enhancements- Speed Enhancements

	//Engine Systems Warp Enhancements
	int sMEMMDPSEEWEFE(); //Warp Enhancements- Field Enhancements
	int sMEMMDPSEEWEPCE(); //Warp Enhancements- Power Consumption Enhancements

	//Shield System Recharge Enhancements
	int sMEMMDPSESSREPCE(); //Recharge Enhancements- Power Consumption Enhancements
	int sMEMMDPSESSRETE(); //Recharge Enhancements- Recharge Time Enhancements

	//Weapon Systems Efficiency Enhancements
	int sMEMMDPSEWSEEPC(); //Efficiency Enahncements- Power Consumption Enhancement
	int sMEMMDPSEWSEETE(); //Efficiency Enahncements- Targeting Efficiency Enhancement


	//Octonary Market Tree

	//Warp Enhancements Field Enhancements
	int sMEMMDPSEEWEFECSE(); //Field Enhancements- Warp Conduit Stabilization Enhancements
	int sMEMMDPSEEWEFEFSE(); //Field Enhancements- Warp Field Stabilization Enhancements

	
	int sMMenu2(); //market weapons menu


	int sMMenu9(int cCode); //market mods menu

	int checkMInput(int pChoice, int low, int high, int def, bool bIsZero); //Check to make sure that the menu choice is within the proper range
	void pBTPMenu(int lastOption); //Print a cout for return to last menu
	
	int sMMenu1B2(); //market menu sell - indicate the location of item
	int sMMenu1C1(Player& mPlayer, string iType); //Display items in cargohold
	int sMMenu1C2(Station& stat_g, string iType); //Display items in station inventory
	int mSSIAmount(int amount);
	int mSSIConfirm(int amount, int iID, string iType);
	int mSTIConfirm(int amount, int iID, string iType);
	
	int sISItem(); //Install or Store Item?
	int sBSShip(); //Board or Store ship?
	int sKVEquipment(); //Keep valid eqipment installed?
	bool sMIInfo(int iCode, string iType, string iType2, Player& mPlayer, Station& stat, int amount); //Return item info and determine if user can/will buy; if so return true for further processing.
	void sGSData(); //get ship data
	void sGWData(); //get weapon data
	void sGMData(); //get module data
	int sRMenu1(); //repair menu 1
	int sRMenu2(); //repair menu 2
	int sBMenu1(); //bar menu 1
	int sBMenu2(); //bar menu 2
	int sEAOMenu1(); //EA office menu 1
	int sEAOMenu2(); //EA office menu 2
	int sEAOMenu3(); //EA office menu 3
	float sBISPMenu(float cSpace, float mSpace, float nSpace, Player& mPlayer); //add inv space menu
	int sBClone(); //Buy a clone
	int sMOMenu1();
	int sMOMenu2(int* mID, Player& mPlayer);
	int sMOMenu3(Player& mPlayer);
	int sBOMenu1();
	int sBOMenu2(int* mID, Player& mPlayer);
	int sBOMenu3(Player& mPlayer);
	int sEAFOMenu1();
	int sEAFOMenu2(int* mID, Player& mPlayer);
	int sEAFOMenu3(Player& mPlayer);
	bool sSMission(int mID);

	//Misc
	int sMCMenu(); //Get the player to pick ship class
	int sMTMenu(); //Get player to pick planet type
	int sMDSMenu(); //Get the player to pick a drone size

	int sMCasino(); //Casino Menu
	int sCRMenu1(); //Casino; Roulette Menu 1
	void sCRTMenu(); //Casino; Roulette Tutorial Menu
	int sCMRBet1(); //Casino; Roulette Bet Choice Menu 1
	int sCMRBet2(); //Casino; Roulette Number Bet (Number)
	string sCMRBet3(); //Casino; Roulette Number Bet (Zeros)
	int sCMRBet4(); //Casino; Roulette Color Bet
	int sCMRBet5(); //Casino; Roulette Type Bet
	int sCMRBet6(); //Casino; Roulette Section Bet
	int sCMRBet7(); //Casino; Roulette Quarter Bet
	int sCMRBet8(); //Casino; Roulette Half Bet
	int sCMBet(int chips); //Casino; Get player to make bet
	int sCMBJBet(vector<string>& cards, int chips); //Casino; Get player blackjack bet
	int sCSMenu1(); //Casino; Slots Menu 1
	void sCSTMenu(); //Casino; Slots Tutorial Menu
	int sCBJMenu1(); //Casino; Blackjack Menu 1
	int sCBJMenu2(vector<string>& cards, int chips, int bet); //Casino; Blackjack Menu 2
	void sCBJTMenu(); //Casino; Blackjack Tutorial Menu
	int sCBJMenu3(); //Casino; Blackjack Menu 3
	int sCPMenu(); //Get player to choose which poker game to play
	int sCP5Menu1(); //Casino; 5-card menu 1
	void sCP5TMenu(); //Casino; 5-card tutorial menu
	int sCP5Menu2(vector<string> cards, int lBet, int chips); //Casino; 5-card action menu
	int sCP5BMenu(vector<string> cards, int lBet, int chips); //Casino; 5-card betting menu
	void sCP5CTMenu(vector<string>& cards); //Casino, 5-card card trading menu
	int sCPAnte(int ante); //Casino; Ask player for ante
	int sCPBlind(int blind); //Casino; Ask player for blind
	int sSFMenu1(); //Station ship fitting menu 1
	//int sSFMenu2(); //Station ship fitting menu 2; install equipment from ship
	int sSFMenu3(Station& stat, Player& mPlayer); //Station ship fitting menu 3; install equipment from station
	//int sSFMenu4(Player& mPlayer); //Station ship fitting menu 4; uninstall equipment from ship
	//int sSFMenu5(); //Station ship fitting menu 5; where to store uninstalled eqiupment
	void sSSMenu(Station& stat); //Station storage print out




	int sInv(Station& stat);
	int sInv_S(Station& stat);

	int sMBRes(); //What resource to buy
	int sMBOre(); //What ore to buy
	int sMBAmount(int iCode, string type, Player& mPlayer, Station& stat); //Select the amount of items to buy

	int sMSI1(); //Have the player choose where the item they want to move is coming from
	int sMSI2(); //Have player choose what type of item they want to store
	int sMSI3A(Player& mPlayer); //Choose a stored ship from player ship to store in station
	int sMSI3B(Station* stat); //Choose a stored ship from station to store in ship cargo hold
	int sMSI4A(Station* stat); //Choose an item from station storage to move to ship
	int sMSI4B(Ship* ship); //Choose an item from the ship to store on a station

	bool sMECShip(); //Ask player if they want to exchange their ship for one just bought


	int sDRMenu1(Player& mPlayer);
	bool sDRMenu2(int affin, Player& mPlayer, int xcost, int rcost, int dicost, int dcost);
	bool sDRMenu3(int affin, Player& mPlayer, int xcost, int rcost, int dicost, int dcost);
	bool sDRMenu4(int affin, Player& mPlayer, int xcost, int rcost, int dicost, int dcost);

	//Misc Functions
	string mRMessage(int mCode); //Return message
	void mCScreen(bool pause); //Clear screen + pause

	//Mission Info Functions
	void mInfo(Mission* m, bool bCInfo); //Basic Mission Info

	//Planet Menus
	int plMenu1();
	int gGTABelt(Planet* gPlanet);

	//Ship Menus
	int sWSSelection(int lasers, int missiles, int rails, int heavies); //weapon system selection
	char sLWSelection(Laser* weapon); //laser weapon selection
	char sMWSelection(Missile* weapon); //missile weapon selection
	char sRWSelection(Rail* weapon); //rail gun selection
	char sHWSelection(Heavy* weapon); //heavy weapon selection
	char sBWSelection(Bomb* weapon); //bomb weapon selection
	int sSCMenu(); //Weapon Spread Center
	int sDSpread(int sWSpreads, Player& mPlayer); //Delete weapon spread
	int	sCWSpread(); //Create a weapon spread
	int sCEWSpread(int sWSpreads, Player& mPlayer); //Choose empty weapon spread
	char sOWSpread(Player& mPlayer); //Overwrite weapon spread?
	int sMSystem(int sAMInit); //Movement system menu - battle
	int sMSystem2(int sAMInit); //Movement system menu - mining

	//Defenses
	void sSEnabled(Planet* planet, string sname);

	//Mining
	int mMenu1A(); //If no scanned asteroids
	int mMenu1B(); //If scanned asteroids but no targets
	int mMenu1C(); //If scanned asteroids, one or more targets, and targeting phase has ended
	int mMenu1D(); //If scanned asteroids, one or more targets, targeting phase has ended, and mining phase has started
	int mTMenuA();
	int mTMenuB();
	int mCTarget(vector<Asteroid> roids, vector<int> scanned, Player& mPlayer, int mTDist);
	int mGRPoint(vector<int> scanned, vector<Asteroid> roids, Player& mPlayer);
	void mMLInfo(int ctime, int tdist, float mopc);

	//Config Data
	void cdPrint(); //Print loaded configuration data

	//Misc Functions
	template<typename t> pair<int, int> getIPair(vector<vector<t>> vect, int type, int condition); //Return a value pair based on the range passed, weapon type passed, and ship class passed
	template<typename t> pair<int, int> getIPair(vector<t> vect, int condition); //Return a value pair based on ship class; for ship ids
	void	pIInfo(pair<int,int> vRange); //Print out item information based on passed IDs

private:
	int i, i2; //For incrementing For loops
	int pChoice, pChoice2; //For returning player menu choices
	char pCChoice; //For player choices; characters
	string pSChoice; //For player choices; strings
	int dLastValue; //For moving around weapons lists
	bool bContinue; //For market scrolling
	bool bValid; //For menu looping for valid choices where needed
	int totalWeapons, laser, missile, bomb, rail, heavy;
	string type;
	int sCRand,mRand, eRand; //Randoms
	int cCode; //For buying ships
	int iCode;
	bool bRetreat;

	float dPerc;
	float dPerc_R;
	int   dPerc_I,dPerc_I2;

	bool bErrors;
	int rCount;

	int pSStat; //Player selected station

	string wName;
	string iType;
	string dbTable;
	int iID;

	int hSRate; //Store random value to determine success or failure for hailing

	bool bCReturn; //bool: Can return a value?
	bool bNTarget; //bool: no target selected yet?
	bool bIsTDest; //bool: is target destroyed?

	//For selling
	int pSCSize, sISize, sSSize, nOShips;

	vector<hardPoint> tempSpread; //Temp spread storage

	//Information Output Variables

	//Player/Wingmen
	string pname;
	string prank;
	string psname;
	string psclass;
	float pssp;
	float psap;
	float pshp;
	float psmsp;
	float psmap;
	float psmhp;
	int psdt;
	string psstatus;

	//NPC/Wingmen
	string hname;
	string hrank;
	string hsname;
	string hsclass;
	float hssp;
	float hsap;
	float hshp;
	float hsmsp;
	float hsmap;
	float hsmhp;
	int hsdt;
	string hsstatus;

	//Planetary Shield
	string mname;
	int mtlevel;
	float msp;
	float mmsp;
	float spr;
	bool mstat;
	string mstats;
	int dtimer;

	//Planetary Defenses
	string dname;
	int dtlevel;
	float dsp;
	float dmsp;
	string dstat;

	//Planet
	string plname;
	float peks;
	float plsize;
	int ndef;
	int nshd;
	float ppop;
	float pmpop;

	//Station Cost Variables
	int xCost;
	int rCost;
	int diCost;
	int dCost;
	int lCost;
	int plaCost;
	int uCost;
	int pluCost;
	int nwCost;
	float sCMulti;
	float sTBuy; //Space to buy

	//Station Casino
	string temp, temp2, temp3; //Store temp strings here
	int sSValue; //Store casted substring value
	int cTValue; //Total value of the player's cards
	bool bHasAce, bHasFCard; //bool: player has an ace or a face card in their hand

	//For Mining
	int tDist; //Target distance
	int tRoids; //Targetable roids; for checking if there are any roids the player can target

	//Misc
	pair<int,int> pVRange; //pair value range- for looping through items from database
};
#endif
