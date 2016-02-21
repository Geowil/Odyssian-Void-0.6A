/*FILE HEADER

File Name:
	settings


File Description:
	Contains all of the external settings for the game


Created On:  Friday, 02/19/2016

Version:
1.0 - 02/19/2016
1.1 - 02/20/2016


Changes:
1.0:
-Changed out new settings files with gVars and just renamed the name space.
-Removed old getCData code as it is not needed now that Boost will no longer be used.  Leave boost refs in place in case they are needed in the future for something though.
-Started recoding getCData.

1.1:
-Removed many class variables that are no longer neeed because we are not storing item ID ranges any more.
-Continued recoding getCData.


End File Header*/

#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <vector>
#include "g_structs.h"


using std::string;
using std::vector;

namespace gS
{
	void getCData(); //Get the config data from the database
	void printData(); //Print out loaded data
	void setNIValues(); //Deal with imported lists
	void setRange(Range& r, string idata, string delimiter, string type);
	template<typename t> void cIData(string idata, string type, t& rdata);
	template<typename t> extern void iDProc(string idata, vector<t>& vect, t sdef, string type, int splits, ...); //For Various Info
	template<typename t> extern void iDProc(string idata, vector<t>& vect, int splits, ...); //For Various Info
	template<typename t> extern void iDProc(string idata1, string idata2, string idata3, vector<t>& vect, t sdef, int splits, ...); //Specifically for Planet Info
	template<typename t> extern void iDProc(string idata, vector<vector<t>>& vect, vector<t> mVector, t sdef, string type, int splits, ...); //Specifically for Weapon Info
	template<typename t> extern void iDProc(string idata, Range& r, string type, int splits, ...); //For Various Info
	void iDProc(); //Handle imported data not dealt with by setNIValues
	void splitData(vector<string>& vect, string idata, string delimiter); //Use the passed parameters to split idata strong along the delimiter and then load data into vect
	void setupADVect(); //Setup aData vector

	//dasdasdasdasd

	//Comma-Delimited Strings
	template<typename t> extern void fillVect(vector<t>& vect, string type) //Fill a vector from an imported string list
	{
		if (type == "int")
		{
			for (i1 = 0; i1 < temp1.size(); i1++)
			{
				vect.push_back(atoi(temp1.at(i1).c_str()));
			}
		}

		if (type == "float")
		{
			for (i1 = 0; i1 < temp1.size(); i1++)
			{
				vect.push_back(strtof(temp1.at(i1).c_str(), NULL));
			}
		}

		if (type == "double")
		{
			for (i1 = 0; i1 < temp1.size(); i1++)
			{
				vect.push_back(atof(temp1.at(i1).c_str()));
			}
		}
	}

	template<typename t> extern void clearVect(vector<t>& vect); //Clear the passed vector


	//Configuration Variables

	

	extern string sships;
	extern Range ssIDS; //Starter Ship Range




	//Ship Related Values
	extern string scnames; //Comma-delimited list of ship class names
	extern int sCTypes; //Number of ship classes

	//Weapon Related Values
	extern string wtnames;
	extern int wTypes;
	extern vector<string> wTNames;
	extern string mlnames;
	extern int mLTypes;

	//Planet Related Values	
	extern int pNames; //Number of planet/system names in the database
	
	extern string eksrange;
	extern Range pEKSRange;
	extern string pdata;
	extern vector<ptRange> pTData; //Vector containing planet type data
	extern int popBase; //Base for pop random ranges	
	extern Range rP1; //Planet Pop Range 1
	extern Range rP2; //Planet Pop Range 2
	extern Range rP3; //Planet Pop Range 3
	extern int pMDef; //Maximum defenses a planet can have
	extern int pMShd; //Maximum shields a planet can have

	extern string prrange;
	extern string psrchecks;
	extern string psrands;
	extern string pschecks;
	extern string eksranges;
	extern string pdrstr;
	extern string pdefenses;
	extern string psrstr;
	extern string pshields;

	//Game Related Values
	extern int iNSPlanets; //The number of planets scannable at once
	extern int iNTStations; //The number of stations scannable at once
	extern string disporange;
	extern Range rGPDispo; //Planet disposition range
	extern string affilrange;
	extern Range rGPAff; //Planet affitiliation range


	//Asteroid/Belt Related Values
	extern string rprange; //Store imported asteroid belt population range
	extern Range rBAAmount; //Asteroid belt asteroid amount range
	extern string rbsrange; //Store imported belt size range
	extern Range rBSize; //Asteroid belt size range
	extern int aStages; //Number of stages of ore
	extern string asoidrange; //Store imported asteroid stage data - id range
	extern string asasrange; //Store imported asteroid stage data - size range
	extern string asmulti; //Store imported asteroid stage data - size multiplier
	extern string asrrange; //Store imported asteroid stage data - random range
	extern Range aSRRange; //Stage Random Range
	extern string asrange; //Store imported asteroid stage data - random range checks


	//Mission Related Values
	extern string mir;
	extern Range mIR; //Mission ID Range
	extern string mMLine; //Comma-delimited list of main mission line mission and their order


	//Empire/Race Related Values
	extern int rcTypes; //Number of races
	extern int eTypes; //Number of empires
	extern string rcNames; //Comma-delimited list of race names
	extern string eNames; //Comma-delimited list of empire names


	//Displomacy Related Values
	extern int dTypes; //Number of diplomatic states
	extern string dNames; //Comma-delimited list of diplomatic state names


	//Rank Related Values
	extern int rkTypes; //Number of ranks
	extern string rkNames; //Comma-delimited list of rank names


	//Name Generation Related Values
	extern string rnpfx;
	extern string rnstem;
	extern string rnsfx;
	extern Range rNPfx; //Prefix ID Range
	extern Range rNStem; //Stem ID Range
	extern Range rNSfx; //Suffix ID Range


	//Message Related Values



	//Resource Related Values
	extern int resTypes; //Number of resources
	extern string resNames; //Comma-delimited list of resources

	//Casino Related Values

	//Slot Payouts
	extern int cSPJP4; //Four Jackpots
	extern int cSPJP3_Br; //Three Jackpots + Bar
	extern int cSPJP3_7; //Three Jackpots + 7
	extern int cSPJP3_H; //Three Jackpots + Heart
	extern int cSPJP3_B; //Three Jackpots + Bell
	extern int cSPJP3_N; //Three Jackpots + Number

	//Bars
	extern int cSPBr4; //Four Bars
	extern int cSPBr3_J; //Three Bars + Jackpot
	extern int cSPBr3_7; //Three Bars + 7
	extern int cSPBr3_H; //Three Bars + Heart
	extern int cSPBr3_B; //Three Bars + Bell
	extern int cSPBr3_N; //Three Bars + Number

	//Sevens
	extern int cSP74; //Four Sevens
	extern int cSP73_J; //Three Sevens + Jackpot
	extern int cSP73_Br; //Three Sevens + Bar
	extern int cSP73_H; //Three Sevens + Heart
	extern int cSP73_B; //Three Sevens + Bell
	extern int cSP73_N; //Three Sevens + Number

	//Hearts
	extern int cSPH4; //Four Hearts
	extern int cSPH3_J; //Three Hearts + Jackpot
	extern int cSPH3_Br; //Three Hearts + Bar
	extern int cSPH3_7; //Three Hearts + 7
	extern int cSPH3_B; //Three Hearts + Bell
	extern int cSPH3_N; //Three Hearts + Number

	//Bells
	extern int cSPB4; //Four Bells
	extern int cSPB3_J; //Three Bells + Jackpot
	extern int cSPB3_Br; //Three Bells + Bar
	extern int cSPB3_7; //Three Bells + 7
	extern int cSPB3_H; //Three Bells + Heart
	extern int cSPB3_N; //Three Bells + Number

	//Numbers
	extern int cSPN4; //Four Numbers
	extern int cSPN3_J; //Three Numbers + Jackpot
	extern int cSPN3_Br; //Three Numbers + Bar
	extern int cSPN3_7; //Three Numbers + 7
	extern int cSPN3_H; //Three Numbers + Heart
	extern int cSPN3_B; //Three Numbers + Bell


	//Roulette Returns
	extern float cRBRZeros; //Zeros
	extern float cRBRNum; //Number
	extern float cRBRC_G; //Color; Green
	extern float cRBRType; //Type
	extern float cRBRC_RB; //Color; Red/Black
	extern float cRBRS_S; //Section; Small
	extern float cRBRS_L; //Section; Long
	extern float cRBRQ; //Quarter
	extern float cRBRH; //Half


	/*Damage Related Values
	extern int dTTypes; //Number of damage types
	extern string dTNames; //Comma-delimited string of damage type names
	extern string dTEDP; //Comma-delimited string of extra damage percentages
	extern string dDPT; //Comma-delimited string of turns for turn based damage*/

	//Skill Related Values
	extern string skillstr;
	extern vector<sData> skIDS;


	extern sIDRange sir;
	extern wIDRange wir;
	extern psIDRange sid;
	extern pdIDRange did;
	extern aData ad;
	extern sData sd;

	//Vectors
	 vector<string> sClasses; //Ship Classes
	extern vector<string> eRanks; //Entity Ranks
	extern vector<string> rNames; //Race Names
	extern vector<string> rENames; //Race Empire Names
	extern vector<string> gRNames; //Resource Names
	extern vector<string> gDNames; //Diplomatic State Names
	extern vector<aData>	gPAData; //Vector to hold data on asteroids
	//template<typename t> extern vector<t> mVector; //A magical vector that can hold any data type
	extern vector<string> iAData; //Imported Asteroid Data

	//Misc
	extern int i1, i2, i3, i4, i5; //For for loops
	extern int size1, size2, size3, size4; //Store vector size
	extern vector<string> temp1, temp2, temp3, temp4, temp5, temp6; //For vector imports that have to be cast to another type
	extern string tempstr1, tempstr2, tempstr3, tempstr4, tempstr5, tempstr6, tempstr7;


};
#endif