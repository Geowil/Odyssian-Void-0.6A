#include "globalvars.h"
#include "debug.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdarg.h>

#include "boost/program_options.hpp"
#include "boost/algorithm/string.hpp"
#include "boost/algorithm/string/split.hpp"

using std::string;
using std::endl;
using std::cout;
using std::ifstream;
using std::to_string;
using std::vector;
using boost::split;

namespace pOps = boost::program_options;

Debug d_gv;


namespace gVars
{
	//Get the config data from the ini file
	void getCData()
	{
		pOps::options_description desc("Settings");
		desc.add_options()
			//Item ID Ranges

			//Ship IDs By Class
			("itemid.sidrstr", pOps::value<string>(&ships), "Ship ID Ranges")
			("itemid.ssrstr", pOps::value<string>(&sships), "Starter Ship ID Range")

			//Weapon IDs By Class
			("itemid.widrstr", pOps::value<string>(&weapons), "Weapon ID Ranges")

			//Mining Laser IDs
			("itemid.mlidrstr", pOps::value<string>(&mlasers), "Mining Laser ID Ranges")

			//EMI IDs
			("itemid.pshdidrstr", pOps::value<string>(&shields), "P. Shield ID Range")
			("itemid.pdefidrstr", pOps::value<string>(&defenses), "P. Defense ID Range")
			("itemid.clrdrstr", pOps::value<string>(&clones), "Clone ID Range")

			//Planet Values
			("planet.pnames", pOps::value<int>(&pNames), "Number of planet/system names in the database")
			("planet.psvrstr", pOps::value<string>(&prrange), "Planet Size Random Range")
			("planet.psrcrstr", pOps::value<string>(&psrchecks), "Planet Size Random Checks")
			("planet.psrstr", pOps::value<string>(&psrands), "Planet Size Randoms")
			("planet.pscrstr", pOps::value<string>(&pschecks), "Planet Size Range Checks")
			("planet.peksrange", pOps::value<string>(&eksranges), "EKS Ranges")
			("planet.poprbase", pOps::value<int>(&popBase), "Planet Pop Base")
			("planet.popr1", pOps::value<int>(&rP1.iHigh), "Planet Pop Random 1 Range; High")
			("planet.popr2", pOps::value<int>(&rP2.iHigh), "Planet Pop Random 2 Range; High")
			("planet.popr3", pOps::value<int>(&rP3.iHigh), "Planet Pop Random 3 Range; High")
			("planet.pdcr", pOps::value<string>(&pdrstr), "Plantary Defense Random Range")
			("planet.pmdef", pOps::value<int>(&pMDef), "Max Planetary Defenses")
			("planet.pdcstr", pOps::value<string>(&pdefenses), "List of Chance Ranges for P. Defenses")
			("planet.pscr", pOps::value<string>(&psrstr), "Planetary Shield Random Range")
			("planet.pmshd", pOps::value<int>(&pMShd), "Max Planetary Shields")
			("planet.pscstr", pOps::value<string>(&pshields), "List of Chance Ranges for P. Shields")

			//Game Values
			("game.gnsplanets", pOps::value<int>(&iNSPlanets), "Max Number of scannable planets")
			("game.gntstations", pOps::value<int>(&iNTStations), "Max Number of scannable stations")
			("game.gpdrstr", pOps::value<string>(&disporange), "Planet Disposition Range String")
			("game.gparstr", pOps::value<string>(&affilrange), "Planet Affiliation Range String")

			//Asteroid/Belt Values
			("abelts.abarstr", pOps::value<string>(&rprange), "Astroid Belt Asteroid Amount Range String")
			("abelts.absstr", pOps::value<string>(&rbsrange), "Asteroid Belt Size Range String")
			("abelts.astages", pOps::value<int>(&aStages), "Number of Ore Stages")
			("abelts.aoirstr", pOps::value<string>(&asoidrange), "Ore Item ID Range String")
			("abelts.asrlow", pOps::value<string>(&asasrange), "Asteroid Size Range String")
			("abelts.asmulti", pOps::value<string>(&asmulti), "Asteroid Size Multiplier String")
			("abelts.asrstr", pOps::value<string>(&asrrange), "Asteroid Stage Random Range")
			("abelts.asrngstr", pOps::value<string>(&asrange), "Asteroid Stage Ranges")

			//Ship Class Values
			("sclasses.sctypes", pOps::value<int>(&sCTypes), "Ship Class Types (number of classes)")
			("sclasses.scnames", pOps::value<string>(&scnames), "Ship Class Names (comma-delimited)")

			//Weapon Values
			("wclasses.wctypes", pOps::value<int>(&wTypes), "Weapon Class Types (Number of Classes)")
			("wclasses.wcnames", pOps::value<string>(&wtnames), "Weapon Type Names (Comma-delimited List of Weapon Type Names)")

			//Mission Values
			("missions.mirstr", pOps::value<string>(&mir), "Mission ID Range; Low")
			("missions.mmline", pOps::value<string>(&mMLine), "Main Mission Line")


			//Empire/Race Values
			("empires.etypes", pOps::value<int>(&eTypes), "Number of Empires")
			("empires.enames", pOps::value<string>(&eNames), "Empire Names (comma-delimited)")
			("races.rctypes", pOps::value<int>(&rcTypes), "Number of Races")
			("races.rcnames", pOps::value<string>(&rcNames), "Race Names (comma-delimited)")

			//Diplomacy Values
			("diplomacy.dtypes", pOps::value<int>(&dTypes), "Number of Diplomatic States")
			("diplomacy.dnames", pOps::value<string>(&dNames), "Names of Diplomating States (comma-delimited)")

			//Rank Values
			("ranks.rktypes", pOps::value<int>(&rkTypes), "Number of Ranks")
			("ranks.rknames", pOps::value<string>(&rkNames), "Rank Names (comma-delimited)")

			//Name Generation Values
			("names.nprstr", pOps::value<string>(&rnpfx), "Name Prefix ID Range String")
			("names.nsrstr", pOps::value<string>(&rnstem), "Name Stem ID Range String")
			("names.nsfxrstr", pOps::value<string>(&rnsfx), "Name Suffix ID Range String")

			//Message Values

			//Resource Values
			("resources.restypes", pOps::value<int>(&resTypes), "Number of resources in the game")
			("resources.resnames", pOps::value<string>(&resNames), "Resource Names (comma-delimited")

			//Casino Values

			//Slot Payouts
			("casino.psjp4", pOps::value<int>(&cSPJP4), "4x Jackpot Payout")
			("casino.psjp3_br", pOps::value<int>(&cSPJP3_Br), "3x Jackpot/1x Bar Payout")
			("casino.psjp3_7", pOps::value<int>(&cSPJP3_7), "3x Jackpot/1x 7 Payout")
			("casino.psjp3_h", pOps::value<int>(&cSPJP3_H), "3x Jackpot/1x Heart Payout")
			("casino.psjp3_b", pOps::value<int>(&cSPJP3_B), "3x Jackpot/1x Bell Payout")
			("casino.psjp3_n", pOps::value<int>(&cSPJP3_N), "3x Jackpot/1x Number Payout")
			("casino.psbr4", pOps::value<int>(&cSPBr4), "4x Bar Payout")
			("casino.psbr3_j", pOps::value<int>(&cSPBr3_J), "3x Bar/1x Jackpot Payout")
			("casino.psbr3_7", pOps::value<int>(&cSPBr3_7), "3x Bar/1x 7 Payout")
			("casino.psbr3_h", pOps::value<int>(&cSPBr3_H), "3x Bar/1x Heart Payout")
			("casino.psbr3_b", pOps::value<int>(&cSPBr3_B), "3x Bar/1x Bell Payout")
			("casino.psbr3_n", pOps::value<int>(&cSPBr3_N), "3x Bar/1x Number Payout")
			("casino.ps74", pOps::value<int>(&cSP74), "4x 7 Payout")
			("casino.ps73_j", pOps::value<int>(&cSP73_J), "3x 7/1x Jackpot Payout")
			("casino.ps73_br", pOps::value<int>(&cSP73_Br), "3x 7/1x Bar Payout")
			("casino.ps73_h", pOps::value<int>(&cSP73_H), "3x 7/1x Heart Payout")
			("casino.ps73_b", pOps::value<int>(&cSP73_B), "3x 7/1x Bell Payout")
			("casino.ps73_n", pOps::value<int>(&cSP73_N), "3x 7/1x Number Payout")
			("casino.psh4", pOps::value<int>(&cSPH4), "4x Heart Payout")
			("casino.psh3_j", pOps::value<int>(&cSPH3_J), "3x Heart/1x Jackpot Payout")
			("casino.psh3_br", pOps::value<int>(&cSPH3_Br), "3x Heart/1x Bar Payout")
			("casino.psh3_7", pOps::value<int>(&cSPH3_7), "3x Heart/1x 7 Payout")
			("casino.psh3_b", pOps::value<int>(&cSPH3_B), "3x Heart/1x Bell Payout")
			("casino.psh3_n", pOps::value<int>(&cSPH3_N), "3x Heart/1x Number Payout")
			("casino.psb4", pOps::value<int>(&cSPB4), "4x Bell Payout")
			("casino.psb3_j", pOps::value<int>(&cSPB3_J), "3x Bell/1x Jackpot Payout")
			("casino.psb3_br", pOps::value<int>(&cSPB3_Br), "3x Bell/1x Bar Payout")
			("casino.psb3_7", pOps::value<int>(&cSPB3_7), "3x Bell/1x 7 Payout")
			("casino.psb3_h", pOps::value<int>(&cSPB3_H), "3x Bell/1x Heart Payout")
			("casino.psb3_n", pOps::value<int>(&cSPB3_N), "3x Bell/1x Number Payout")
			("casino.psn4", pOps::value<int>(&cSPN4), "4x Number Payout")
			("casino.psn3_j", pOps::value<int>(&cSPN3_J), "3x Number/1x Jackpot Payout")
			("casino.psn3_br", pOps::value<int>(&cSPN3_Br), "3x Number/1x Bar Payout")
			("casino.psn3_7", pOps::value<int>(&cSPN3_7), "3x Number/1x 7 Payout")
			("casino.psn3_h", pOps::value<int>(&cSPN3_H), "3x Number/1x Heart Payout")
			("casino.psn3_b", pOps::value<int>(&cSPN3_B), "3x Number/1x Bell Payout")

			//Roulette Returns
			("casino.brzeros", pOps::value<float>(&cRBRZeros), "Zeroes Return")
			("casino.brnum", pOps::value<float>(&cRBRNum), "Number Return")
			("casino.brc_g", pOps::value<float>(&cRBRC_G), "Color: Green Return")
			("casino.brtype", pOps::value<float>(&cRBRType), "Even/Odd Return")
			("casino.brc_rb", pOps::value<float>(&cRBRC_RB), "Color: Red/Black Return")
			("casino.brs_s", pOps::value<float>(&cRBRS_S), "Section: Short Return")
			("casino.brs_l", pOps::value<float>(&cRBRS_L), "Section: Long Return")
			("casino.brquarter", pOps::value<float>(&cRBRQ), "Quarter Return")
			("casino.brhalf", pOps::value<float>(&cRBRH), "Half Return")

			//Damage Values
			("damage.dttypes", pOps::value<int>(&dTTypes), "Number of damage types")
			("damage.dtnames", pOps::value<string>(&dTNames), "Comma-delimited list of damage type names")
			("damage.dtedp", pOps::value<string>(&dTEDP), "Comma-delimited list of extra damage percentages")
			("damage.ddpt", pOps::value<string>(&dDPT), "Comma-delimited list of turn lengths for turn based damage")

			//Skill Values
			("skills.skidrstr",pOps::value<string>(&skillstr), "Comma-delimited list of skill ID Ranges");

		pOps::variables_map vm;

		try
		{
			ifstream settings_file("scSettings.ini", ifstream::in);
			pOps::store(pOps::parse_config_file(settings_file, desc, true), vm);
			settings_file.close();
			pOps::notify(vm);
		}

		catch (const pOps::error& e)
		{
			//std::cerr << e.what() << std::endl;

			string file = __FILE__;
			string bLocale = "File: " + file + "  Line: ";

			string time = __TIME__;
			string date = __DATE__;

			string bTDate = date + "  " + time;

			d_gv.createBReport("Configuration File Error", e.what(), bLocale + to_string(__LINE__), bTDate, "./SC_Log.txt");
		}

		if (vm.size() > 0)
		{
			//Now deal with some of the values that we could not add through options (namely the low end of the population randoms for planets)

			setNIValues();

			cout << "Data successfully loaded from configuration file." << endl;
			system("Pause");
			system("CLS");
		}

		else
		{
			cout << "Data was not successfully loaded from configuration file.  Please check the error log for more details" << endl;
			system("Pause");
			system("CLS");
		}
	}

	void printData()
	{
		//TODO: Raname variable labels to ini file keys instead

		//Ship ID Ranges By Class
		cout << "Format: Description: name of low entry from scSettings.ini: imported value |" << endl;
		cout << "name of high entry from scSettings.ini: imported value" << endl << endl;

		cout << "Number of ship classes: " << sCTypes << endl << endl;

		//cout << ssIDS.size() << endl;


		cout << "Starter Ship ID Range: Low: " << ssIDS.iLow << "| High: " << ssIDS.iHigh << endl;


		system("Pause");
		system("CLS");


		cout << sIDS.size() << endl;
		for (i1 = 0; i1 < sIDS.size(); i1++)
		{
			cout << sClasses.at(i1) << " ID Range: Low: " << sIDS.at(i1).vRange.iLow << "| High: " << sIDS.at(i1).vRange.iHigh << endl;
		}

		system("Pause");
		system("CLS");

		cout << "Class names imported:" << endl;

		for (i1 = 0; i1 < sClasses.size(); i1++)
		{
			cout << sClasses.at(i1) << endl;
		}

		system("Pause");
		system("CLS");

		//Weapon ID Ranges By Class
		cout << "Format: Description: Name of Ship Class: Low: imported value |" << endl;
		cout << " High: imported value" << endl << endl;


		for (i1 = 0; i1 < wTypes; i1++)
		{
			cout << wTNames.at(i1) << " Weapon ID Ranges:" << endl;

			for (i2 = 0; i2 < sCTypes - 1; i2++) //-1 to kick out mining barges
			{
				cout << sClasses.at(i2) << " ID Range: Low: " << wIDS[i1].at(i2).vRange.iLow << " | High: " << wIDS[i1].at(i2).vRange.iHigh << endl;
			}

			cout << endl;
		}


		//Mining Barge Class
		//cout << "Mining Barge Utility Ranges:" << endl;


		system("Pause");
		system("CLS");

		//EMI ID Ranges
		//cout << "Format: Description: name of low entry from scSettings.ini: imported value |" << endl;
		//cout << "name of high entry from scSettings.ini: imported value" << endl << endl;
	}

	void setNIValues()
	{
		rP1.iLow = popBase;
		rP2.iLow = popBase;
		rP3.iLow = popBase;

		//Rank Data
		splitData(eRanks, rkNames, ",");
		
		//Race Data
		splitData(rNames, rcNames, ",");
		splitData(rENames, eNames, ",");

		//cout << "Resource Names:" << endl << endl;
		splitData(gRNames, resNames, ",");

		//Diplomacy Data
		splitData(gDNames, dNames, ",");

		//Game Data
		setRange(rGPDispo, disporange, "-" , "int");
		setRange(rGPAff, affilrange, "-","int");

		//Asteroid Stage Data
	    setRange(rBAAmount, rprange, "-", "int");
		setRange(rBSize, rbsrange, "-", "int");
		setupADVect(); //Setup the aData Vector		

		//Weapon Data
		iDProc(weapons, wIDS, wirV, wir, "int", 3, ';', ',', '-');
		splitData(wTNames, wtnames, ",");

		//Ship Data
		iDProc(ships, sIDS, sir, "int", 2, ',', '-');
		setRange(ssIDS, sships, "-", "int");
		splitData(sClasses, scnames, ",");

		//Mission Data
		clearVect(temp1); //Clear temp1 before each use
		splitData(temp1, mMLine, ",");
		fillVect(gMMissions, "int");

		//Damage Data
		splitData(sDNames, dTNames, ",");
		clearVect(temp1);
		splitData(temp1, dDPT, ",");
		fillVect(sDETurns, "int");
		clearVect(temp1);
		splitData(temp1, dTEDP, ",");
		fillVect(sDDPerc, "float");

		//Skill IDS
		iDProc(skillstr, skIDS, sd, "int", 2, ',','-');

		//Name Generation Data
		setRange(rNPfx, rnpfx, "-", "int");
		setRange(rNStem, rnstem, "-", "int");
		setRange(rNSfx, rnsfx, "-", "int");
	}

	template<typename t> void cIData(string idata, string type, t& rdata)
	{
		if (type == "int")
		{
			rdata = atoi(idata.c_str());
		}

		else if (type == "float")
		{
			rdata = strtof(idata.c_str(), NULL));
		}

		else if (type == "double")
		{
			rdata = atof(idata.c_str());
		}
	}

	void setRange(Range& r, string idata, string delimiter, string type)
	{
		clearVect(temp1);
		splitData(temp1, idata, delimiter);

		if (temp1.size() > 0)
		{
			if (type == "int")
			{
				r.iLow = atoi(temp1.at(0).c_str());
				r.iHigh = atoi(temp1.at(1).c_str());
			}

			else if (type == "float")
			{
				r.fLow = strtof(temp1.at(0).c_str(), NULL);
				r.fHigh = strtof(temp1.at(1).c_str(), NULL);
			}

			else if (type == "double")
			{
				r.dLow = atof(temp1.at(0).c_str());
				r.dHigh = atof(temp1.at(1).c_str());
			}								
		}

		else
		{
			cout << temp1.size() << endl;
		}
	}

	void iDProc()
	{
		
	}

	void splitData(vector<string>& vect, string idata, string delimiter)
	{
		split(vect, idata, boost::is_any_of(delimiter));
	}

	//To Return a Vector of Strings
	template<typename t> void iDProc(string idata, vector<t>& vect, int splits, ...)
	{
		va_list delims;
		va_start(delims, splits);
	
		for ( i1 =0; i1 < splits; i1++)
		{
			if (i1 == 0)
			{
				delim = va_arg(delims,char);

				clearVect(temp1); //Make sure temp1 is empty

				splitData(temp1, idata, delim); //Split idata on first delimiter and store in temp1 vector
			}

			else if (i1 == 1) //Second Split
			{
				size1 = temp1.size(); //Get size of temp1 vector

				delim = va_arg(delims, char); //Load the next delimiter from the list

				//Clear temp2 before use
				clearVect(temp2);

				for (i2 = 0; i2 < size1; i2++) //Loop through for each element in temp1
				{
					clearVect(storage); //Clear storage vector each iteration

					splitData(storage, temp1.at(i2), delim); //Split the current element of temp1 along the delimiter

					//Now save the split data into temp2
					size2 = storage.size(); //Get the size of storage, do this instead of hard code 8 to account for new ship classes

					for (i3 = 0; i3 < size2; i3++) //Loop through each element of storage
					{
						temp2.push_back(storage.at(i3)); //Save each element of storage into temp2
					}
				}
			}
		}

		if (splits == 1)
		{
			string tempstr;
			for (i1 = 0; i1 < temp1.size(); i1++)
			{
				vect.push_back(tempstr);

				vect.at(vect.size() - 1) = temp1.at(i1);
			}
		}

		else if (splits == 2)
		{
			string tempstr;
			for (i1 = 0; i1 < temp2.size(); i1++)
			{
				vect.push_back(tempstr);

				vect.at(vect.size() - 1) = temp2.at(i1);
			}
		}

		clearVect(temp1);
		clearVect(temp2);
		clearVect(temp3);

		va_end(delims);
	}

	template<typename t> void iDProc(string idata, vector<t>& vect, t sdef, string type, int splits, ...)
	{
		va_list delims; //Setup variable list 
		va_start(delims, splits); //Indicate where argument list begins

		for (i1 = 0; i1 < splits; i1++) //Loop through once for each split, undertaking new operations in each iteration until done
		{
			if (i1 == 0) //First Split
			{
				delim = va_arg(delims, char); //Get the first delimiter from the argument list

				clearVect(temp1); //Make sure temp1 is empty

				splitData(temp1, idata, delim); //Split idata on first delimiter and store in temp1 vector
			}

			else if (i1 == 1) //Second Split
			{
				size1 = temp1.size(); //Get size of temp1 vector

				delim = va_arg(delims, char); //Load the next delimiter from the list

				//Clear temp2 before use
				clearVect(temp2);

				for (i2 = 0; i2 < size1; i2++) //Loop through for each element in temp1
				{
					clearVect(storage); //Clear storage vector each iteration

					splitData(storage, temp1.at(i2), delim); //Split the current element of temp1 along the delimiter

					//Now save the split data into temp2
					size2 = storage.size(); //Get the size of storage, do this instead of hard code 8 to account for new ship classes

					for (i3 = 0; i3 < size2; i3++) //Loop through each element of storage
					{
						temp2.push_back(storage.at(i3)); //Save each element of storage into temp2
					}
				}
			}
		}

		for (i1 = 0; i1 < temp2.size(); i1++)
		{
			vect.push_back(sdef);

			if (type == "int")
			{
				vect.at(vect.size() - 1).vRange.iLow = atoi(temp2.at(i1).c_str());
				vect.at(vect.size() - 1).vRange.iHigh = atoi(temp2.at(i1 + 1).c_str());
				i1++;
			}

			else if (type == "float")
			{
				vect.at(vect.size() - 1).vRange.fLow = strtof(temp2.at(i1).c_str(), NULL);
				vect.at(vect.size() - 1).vRange.fHigh = strtof(temp2.at(i1 + 1).c_str(), NULL);
			}

			else if (type == "double")
			{
				vect.at(vect.size() - 1).vRange.dLow = atof(temp2.at(i1).c_str());
				vect.at(vect.size() - 1).vRange.dHigh = atof(temp2.at(i1 + 1).c_str());
			}
		}

		//Clear temp vectors now that we are done with them
		clearVect(temp1);
		clearVect(temp2);

		va_end(delims);
	}

	template<typename t> extern void iDProc(string idata1, string idata2, string idata3, vector<t>& vect, t sdef, int splits, ...)
	{
		va_list delims; //Setup variable list 
		va_start(delims, splits); //Indicate where argument list begins

		for (i1 = 0; i1 < splits; i1++) //Loop through once for each split, undertaking new operations in each iteration until done
		{
			if (i1 == 0) //First Split
			{
				delim = va_arg(delims, char); //Get the first delimiter from the argument list

				clearVect(temp1); //Make sure temp1 is empty
				clearVect(temp2); //Make sure temp2 is empty
				clearVect(temp3); //Make sure temp3 is empty
			
				//TODO!!!!

				//For temp2/temp3 ONLY SPLIT ONCE!!!!  Then use them later on to do splits so we do not have to deal with uneven numbers of values
				//per planet types for different p. equip. chances.

				splitData(temp1, idata1, delim); //Split idata1 on first delimiter and store in temp1 vector; Planet Type Data
				splitData(temp2, idata2, delim); //Split idata2 on first delimiter and store in temp2 vector; P. Defenses Chances
				splitData(temp3, idata3, delim); //Split idata3 on first delimiter and store in temp3 vector; P. Shields Chances
			}

			else if (i1 == 1) //Second Split
			{
				size1 = temp1.size(); //Get size of temp1 vector
				size2 = temp2.size(); //Get size of temp2 vector
				size3 = temp3.size(); //Get size of temp3 vector

				delim = va_arg(delims, char); //Load the next delimiter from the list

				//Clear temp4 before use
				clearVect(temp4);
				clearVect(temp5);
				clearVect(temp6);

				for (i2 = 0; i2 < size1; i2++) //Loop through for each element in temp1
				{
					clearVect(storage); //Clear storage vector each iteration

					splitData(storage, temp1.at(i2), delim); //Split the current element of temp1 along the delimiter

					//Now save the split data into temp2
					size2 = storage.size(); //Get the size of storage, do this instead of hard code 8 to account for new ship classes

					for (i3 = 0; i3 < size2; i3++) //Loop through each element of storage
					{
						temp4.push_back(storage.at(i3)); //Save each element of storage into temp2
					}
				}

				for (i2 = 0; i2 < size2; i2++) //Loop through for each element in temp1
				{
					clearVect(storage); //Clear storage vector each iteration

					splitData(storage, temp2.at(i2), delim); //Split the current element of temp1 along the delimiter

					//Now save the split data into temp2
					size1 = storage.size(); //Get the size of storage, do this instead of hard code 8 to account for new ship classes

					for (i3 = 0; i3 < size1; i3++) //Loop through each element of storage
					{
						temp5.push_back(storage.at(i3)); //Save each element of storage into temp2
					}
				}

				for (i2 = 0; i2 < size3; i2++) //Loop through for each element in temp1
				{
					clearVect(storage); //Clear storage vector each iteration

					splitData(storage, temp3.at(i2), delim); //Split the current element of temp1 along the delimiter

					//Now save the split data into temp2
					size1 = storage.size(); //Get the size of storage, do this instead of hard code 8 to account for new ship classes

					for (i3 = 0; i3 < size1; i3++) //Loop through each element of storage
					{
						temp6.push_back(storage.at(i3)); //Save each element of storage into temp2
					}
				}
			}

			else if (i1 == 2) //Third Split
			{
				delim = va_arg(delims, char); //Get the next delimiter from the list

				size1 = temp4.size(); //Get the size of temp2
				size2 = temp5.size();
				size3 = temp6.size();

				clearVect(temp1);
				clearVect(temp2);
				clearVect(temp3);

				for (i4 = 0; i4 < size1; i4++) //Loop through for each element of temp2
				{
					clearVect(storage); //Clear storage each iteration

					splitData(storage, temp4.at(i4), delim); //Split the current element of temp2 along the delimiter

					//Now save the data in storage to temp3
					size4 = storage.size(); //Get the current size of storage

					for (i5 = 0; i5 < size4; i5++) //Loop through for each element of storage
					{
						temp1.push_back(storage.at(i5)); //Save the current element of storage into temp3
					}
				}

				for (i4 = 0; i4 < size2; i4++) //Loop through for each element of temp2
				{
					clearVect(storage); //Clear storage each iteration

					splitData(storage, temp5.at(i4), delim); //Split the current element of temp2 along the delimiter

					//Now save the data in storage to temp3
					size4 = storage.size(); //Get the current size of storage

					for (i5 = 0; i5 < size4; i5++) //Loop through for each element of storage
					{
						temp2.push_back(storage.at(i5)); //Save the current element of storage into temp3
					}
				}

				for (i4 = 0; i4 < size3; i4++) //Loop through for each element of temp2
				{
					clearVect(storage); //Clear storage each iteration

					splitData(storage, temp6.at(i4), delim); //Split the current element of temp2 along the delimiter

					//Now save the data in storage to temp3
					size4 = storage.size(); //Get the current size of storage

					for (i5 = 0; i5 < size4; i5++) //Loop through for each element of storage
					{
						temp3.push_back(storage.at(i5)); //Save the current element of storage into temp3
					}
				}
			}
		}
	}

	template<typename t> void iDProc(string idata, vector<vector<t>>& vect, vector<t> mVector, t sdef, string type, int splits, ...)
	{

		cout << std::is_pod<char>() << endl;

		va_list delims; //Setup variable list 
		va_start(delims, splits); //Indicate where argument list begins

		for (i1 = 0; i1 < splits; i1++) //Loop through once for each split, undertaking new operations in each iteration until done
		{
			if (i1 == 0) //First Split
			{
				delim = va_arg(delims, char); //Get the first delimiter from the argument list

				clearVect(temp1); //Make sure temp1 is empty

				splitData(temp1, idata, delim); //Split idata on first delimiter and store in temp1 vector
			}

			else if (i1 == 1) //Second Split
			{
				size1 = temp1.size(); //Get size of temp1 vector

				delim = va_arg(delims, char); //Load the next delimiter from the list

				//Clear temp2 before use
				clearVect(temp2);

				for (i2 = 0; i2 < size1; i2++) //Loop through for each element in temp1
				{
					clearVect(storage); //Clear storage vector each iteration

					splitData(storage, temp1.at(i2), delim); //Split the current element of temp1 along the delimiter

					//Now save the split data into temp2
					size2 = storage.size(); //Get the size of storage, do this instead of hard code 8 to account for new ship classes

					for (i3 = 0; i3 < size2; i3++) //Loop through each element of storage
					{
						temp2.push_back(storage.at(i3)); //Save each element of storage into temp2
					}
				}
			}

			else if (i1 == 2) //Third Split
			{
				delim = va_arg(delims, char); //Get the next delimiter from the list

				size1 = temp2.size(); //Get the size of temp2

				for (i4 = 0; i4 < size1; i4++) //Loop through for each element of temp2
				{
					clearVect(storage); //Clear storage each iteration

					splitData(storage, temp2.at(i4), delim); //Split the current element of temp2 along the delimiter

					//Now save the data in storage to temp3
					size2 = storage.size(); //Get the current size of storage

					for (i5 = 0; i5 < size2; i5++) //Loop through for each element of storage
					{
						temp3.push_back(storage.at(i5)); //Save the current element of storage into temp3
					}
				}
			}
		}

		i3 = 0;

		for (i1 = 0; i1 < wTypes; i1++) //Iterate through each weapon type
		{
			vect.push_back(mVector); //Push back a new vector object to store weapon type class id ranges (ex: laser calss ID ranges in element 0)

			for (i2 = 0; i2 < sCTypes - 1; i2++) //Iterate through each ship class except mining barge (hence - 1); i3 not iterated automatically, use to traverse temp3
			{
				vect[i1].push_back(sdef);

				if (type == "int")
				{
					vect[i1].at(vect[i1].size() - 1).vRange.iLow = atoi(temp3.at(i3).c_str());
					vect[i1].at(vect[i1].size() - 1).vRange.iHigh = atoi(temp3.at(i3 + 1).c_str());
					i3 += 2;
				}

				else if (type == "float")
				{
					vect[i1].at(vect[i1].size() - 1).vRange.fLow = strtof(temp3.at(i3).c_str(), NULL);
					vect[i1].at(vect[i1].size() - 1).vRange.fHigh = strtof(temp3.at(i3 + 1).c_str(), NULL);
					i3 += 2;
				}

				else if (type == "double")
				{
					vect[i1].at(vect[i1].size() - 1).vRange.dLow = atof(temp3.at(i3).c_str());
					vect[i1].at(vect[i1].size() - 1).vRange.dHigh = atof(temp3.at(i3 + 1).c_str());
					i3 += 2;
				}
			}
		}

		//Clear temp vectors now that we are done with them
		clearVect(temp1);
		clearVect(temp2);
		clearVect(temp3);

		va_end(delims);
	}

	template<typename t> void iDProc(string idata, Range& r, string type, ...)
	{
		va_list delims; //Setup variable list 
		va_start(delims, type); //Indicate where argument list begins

		delim = va_arg(delims, string); //Get the first delimiter from the argument list

		clearVect(temp1); //Make sure temp1 is empty

		splitData(temp1, idata, delim); //Split idata on first delimiter and store in temp1 vector

		if (type == "int")
		{
			r.vRange.iLow = atoi(temp1.at(0).c_str());
			r.vRange.iHigh = atoi(temp1.at(1).c_str());
		}

		else if (type == "float")
		{
			r.vRange.fLow = strtof(temp1.at(0).c_str(), NULL);
			r.vRange.fHigh = strtof(temp1.at(1).c_str(), NULL);
		}

		else if (type == "double")
		{
			r.vRange.dLow = atof(temp1.at(1).c_str());
			r.vRange.dHigh = atof(temp1.at(1).c_str());
		}

		//Clear temp vectors now that we are done with them
		clearVect(temp1);

		va_end(delims);
	}

	template<typename t> void clearVect(vector<t>& vect)
	{
		vect.clear();
	}

	void setupADVect()
	{
		//Setup imported values into vectors
		iDProc(asoidrange, temp3, 2, ',', '-');
		iDProc(asasrange, temp4, 2, ',', '-');
		iDProc(asrange, temp5, 2, ',', '-');
		iDProc(asmulti, temp6, 1, ',');

		i2 = 0; //for multiplier; have to hack it this way until I can think of a better way to do this

		//Load imported data into iAData vector
		for (i1 = 0; i1 < temp4.size();)
		{
			tempstr1 = temp3.at(i1);
			tempstr2 = temp3.at(i1 + 1);
			tempstr3 = temp4.at(i1);
			tempstr4 = temp4.at(i1 + 1);
			tempstr5 = temp5.at(i1);
			tempstr6 = temp5.at(i1 + 1);
						
			for (;; i2++)
			{
				tempstr7 = temp6.at(i2);
				break;
			}

			iAData.push_back(tempstr1);
			iAData.push_back(tempstr2);
			iAData.push_back(tempstr3);
			iAData.push_back(tempstr4);
			iAData.push_back(tempstr5);
			iAData.push_back(tempstr6);
			iAData.push_back(tempstr7);

			i1 += 2;
		}

		//Clear used vectors
		clearVect(temp3);
		clearVect(temp4);
		clearVect(temp5);
		clearVect(temp6);

		//Move data from iAData into gPAData and format the data into stages
		for (i1 = 0, i2 = 0; i1 < aStages;i1++)
		{
			gPAData.push_back(ad);		

			gPAData.at(gPAData.size() - 1).vRange1.iLow = atoi(iAData.at(i2).c_str());
			gPAData.at(gPAData.size() - 1).vRange1.iHigh = atoi(iAData.at(i2 + 1).c_str());
			gPAData.at(gPAData.size() - 1).vRange2.fLow = strtof(iAData.at(i2 + 2).c_str(), NULL);
			gPAData.at(gPAData.size() - 1).vRange2.fHigh = strtof(iAData.at(i2 + 3).c_str(), NULL);
			gPAData.at(gPAData.size() - 1).vRange3.fLow = strtof(iAData.at(i2 + 4).c_str(), NULL);
			gPAData.at(gPAData.size() - 1).vRange3.fHigh = strtof(iAData.at(i2 + 5).c_str(), NULL);
			gPAData.at(gPAData.size() - 1).aSMulti = strtof(iAData.at(i2 + 6).c_str(), NULL);

			i2 += 7;
		}

		clearVect(iAData);
	}



	//Configuration Variables

	//Equip ID Ranges 
	string shields; //Holds imported shield data
	vector<string> shields2; //Holds strings after split on comma
	vector<psIDRange> psIDS; //Planetary Shield Item ID Range
	string defenses; //Holds imported defense data
	vector<string> defenses2; //Holds strings after split on comma
	vector<pdIDRange> pdIDS; //Planetary Defense Item ID Range
	string clones; //Holds imported clone data
	vector<string> clones2; //Holds strings after split on comma
	Range cIDS; //Clone Item ID Range

	Range ssIDS; //Starter Ship Range

	//Ship ID Ranges By Class
	string ships; //Holds imported ship data
	vector<sIDRange> sIDS; //Vector of ship class ID ranges

	//Weapon ID Ranges By Class
	string weapons; //Holds imported weapons data
	vector<string> weapons2; //Holds split weapon data
	vector<vector<wIDRange>> wIDS; //Stores finalized weapon ID ranges; has to be done like this for complete modularity.  Number of elements will be related to value of wctypes and wcnames
	string mlasers; //Holds imported mining laser data
	vector<string> mlasers2; //Holds split mining laser data
	vector<wIDRange> wNSMLIDS; //Vector of non-specific mining laser class ID ranges

	//Mining Barge Mining Laser ID Range
	Range mlIDS;


	//Ship Related Values
	string scnames; //Comma-delimited list of ship class names
	int sCTypes; //Number of ship classes
	vector<string> sCNames; //Vector of ship classes
	string sships;

	//Weapon Related Values
	int wTypes; //Number of weapon types
	string wtnames; //Imported comma-delimited list of weapon types
	vector<string> wTNames; //Vector of weapon types
	string mlnames;
	int mLTypes;
	vector<string> mLNames;


	//Planet Related Values	
	int pNames; //Number of planet/system names in the database
	string eksrange;
	Range pEKSRange;
	string pdata;
	vector<ptRange> pTData; //Vector containing type data
	int popBase; //Base for pop random ranges	
	Range rP1; //Planet Pop Range 1
	Range rP2; //Planet Pop Range 2
	Range rP3; //Planet Pop Range 3
	int pMDef; //Maximum defenses a planet can have
	int pMShd; //Maximum shields a planet can have

	string prrange;
	string psrchecks;
	string psrands;
	string pschecks;
	string eksranges;
	string pdrstr;
	string pdefenses;
	string psrstr;
	string pshields;
	

	//Game Related Values
	int iNSPlanets; //The number of planets scannable at once
	int iNTStations; //The number of stations scannable at once
	string disporange;
	Range rGPDispo; //Planet disposition range
	string affilrange;
	Range rGPAff; //Planet affitiliation range


	//Asteroid/Belt Related Values
	string rprange;
	Range rBAAmount; //Asteroid belt asteroid amount range
	string rbsrange;
	Range rBSize; //Asteroid belt size range
	int aStages;
	string asoidrange; //Store imported asteroid stage data - id range
	string asasrange; //Store imported asteroid stage data - size range
	string asmulti; //Store imported asteroid stage data - size multiplier
	string asrrange;
	Range aSRRange;
	string asrange;

	//Mission Related Values
	string mir;
	Range mIR; //Mission ID Range
	string mMLine; //Comma-delimited list of main mission line IDs
	vector<int>	gMMissions; //Main mission line

	//Empire/Race Related Values
	int rcTypes; //Number of races
	int eTypes; //Number of empires
	string rcNames; //Comma-delimited list of race names
	string eNames; //Comma-delimited list of empire names
	vector<string> rNames; //Race Names
	vector<string> rENames; //Race Empire Names

	//Displomacy Related Values
	int dTypes; //Number of diplomatic states
	string dNames; //Comma-delimited list of diplomatic state names
	vector<string> gDNames; //Diplomatic State Names

	//Rank Related Values
	int rkTypes; //Number of ranks
	string rkNames; //Comma-delimited list of rank names
	vector<string> eRanks; //Entity Ranks

	//Name Generation Related Values
	string rnpfx;
	string rnstem;
	string rnsfx;
	Range rNPfx; //Prefix ID Range
	Range rNStem; //Stem ID Range
	Range rNSfx; //Suffix ID Range

	//Message Related Values

	//Resource Related Values
	int resTypes; //Number of resources in the game
	string resNames; //Comma-delimited list of resource names
	vector<string> gRNames; //Resource Names


	//Casino Related Values

	//Slot Payouts
	int cSPJP4; //Four Jackpots
	int cSPJP3_Br; //Three Jackpots + Bar
	int cSPJP3_7; //Three Jackpots + 7
	int cSPJP3_H; //Three Jackpots + Heart
	int cSPJP3_B; //Three Jackpots + Bell
	int cSPJP3_N; //Three Jackpots + Number

	//Bars
	int cSPBr4; //Four Bars
	int cSPBr3_J; //Three Bars + Jackpot
	int cSPBr3_7; //Three Bars + 7
	int cSPBr3_H; //Three Bars + Heart
	int cSPBr3_B; //Three Bars + Bell
	int cSPBr3_N; //Three Bars + Number

	//Sevens
	int cSP74; //Four Sevens
	int cSP73_J; //Three Sevens + Jackpot
	int cSP73_Br; //Three Sevens + Bar
	int cSP73_H; //Three Sevens + Heart
	int cSP73_B; //Three Sevens + Bell
	int cSP73_N; //Three Sevens + Number

	//Hearts
	int cSPH4; //Four Hearts
	int cSPH3_J; //Three Hearts + Jackpot
	int cSPH3_Br; //Three Hearts + Bar
	int cSPH3_7; //Three Hearts + 7
	int cSPH3_B; //Three Hearts + Bell
	int cSPH3_N; //Three Hearts + Number

	//Bells
	int cSPB4; //Four Bells
	int cSPB3_J; //Three Bells + Jackpot
	int cSPB3_Br; //Three Bells + Bar
	int cSPB3_7; //Three Bells + 7
	int cSPB3_H; //Three Bells + Heart
	int cSPB3_N; //Three Bells + Number

	//Numbers
	int cSPN4; //Four Numbers
	int cSPN3_J; //Three Numbers + Jackpot
	int cSPN3_Br; //Three Numbers + Bar
	int cSPN3_7; //Three Numbers + 7
	int cSPN3_H; //Three Numbers + Heart
	int cSPN3_B; //Three Numbers + Bell


	//Roulette Returns
	float cRBRZeros; //Zeros
	float cRBRNum; //Number
	float cRBRC_G; //Color; Green
	float cRBRType; //Type
	float cRBRC_RB; //Color; Red/Black
	float cRBRS_S; //Section; Small
	float cRBRS_L; //Section; Long
	float cRBRQ; //Quarter
	float cRBRH; //Half


	//Damage Related Values
	int dTTypes; //Number of damage types
	string dTNames; //Comma-delimited string of damage type names
	string dTEDP; //Comma-delimited string of extra damage percentages
	string dDPT; //Comma-delimited string of turns for turn based damage
	vector<string> sDNames; //Secondary Damage Names
	vector<float>  sDDPerc; //Secondary Damage Damage Percentges
	vector<int>	   sDETurns; //Secondary Damage Effect Turns


	//Skill Related Values
	string skillstr;
	vector<sData> skIDS;

	//Vectors
	vector<string> sClasses;
	vector<sIDRange> sirV;
	vector<wIDRange> wirV;
	vector<psIDRange> sidV;
	vector<pdIDRange> didV;
	vector<aData> gPAData;
	vector<string> iAData; //Imported Asteroid Data

	//Doubles

	//Floats

	//Ints
	int i1, i2, i3, i4, i5; //For for loops
	int size1, size2, size3, size4; //Store vector size

	//References
	sIDRange sir;
	wIDRange wir;
	psIDRange sid;
	pdIDRange did;
	aData ad;
	sData sd;

	//Strings
	string delim; //Hold delimiter from va_list

	//Vectors
	vector<wIDRange> weaps;
	vector<string> temp1, temp2, temp3, temp4, temp5, temp6; //Temp vectors for storing strings to be cast to something else
	vector<string> storage; //Holds data from second and third splits to be used to insert that data into a temp vector for later use
	string tempstr1, tempstr2, tempstr3, tempstr4, tempstr5, tempstr6, tempstr7;
}