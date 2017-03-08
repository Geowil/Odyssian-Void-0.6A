#include<map>
#include<string>
#include<vector>
#include "planet.h"
#include "abelt.h"
#include "debug.h"
#include "plSystem.h"

using std::map;
using std::string;
using std::pair;
using std::vector;
using std::to_string;

//Utility Function Predefs
static map<string, float> fillMap(map<string, float>argMap);
static map<string, int> fillMap(map<string, int>argMap);
static vector<Planet> updateVec(vector<Planet> plVec, Planet pl);
static vector<aBelt> updateVec(vector<aBelt> abVec, aBelt ab);
static vector<planetarySystem> updateVec(vector<planetarySystem> plsVec, planetarySystem plSys);

//Utility Members
static map<string, float>::iterator itf1;
static map<string, int>::iterator iti1;
static vector<Planet>::iterator itpl1;
static vector<aBelt>::iterator itab1;
static vector<planetarySystem>::iterator itpls1;
static map<string, float>rtnFMap;
static map<string, int>rtnIMap;
static vector<Planet>rtnPlVec;
static vector<aBelt>rtnABVec;
static vector<planetarySystem>rtnPLSVec;

int i1;

//For Debug
Debug db;
string file, bLocale, bTDate;


//Name: fillMap
//Description: Fill a map reference passed through with the contents of another map from dataSystem
/*Arguments:
*argMap1 - This map contains a map of settings loaded passed in from another function
*/
static map<string, float> fillMap(map<string, float>argMap1) {
	for (itf1 = argMap1.begin(); itf1 != argMap1.end(); itf1++) {
		rtnFMap.insert(pair<string, float>(itf1->first, itf1->second));
	}

	return rtnFMap;
}

//Name: fillMap
//Description: Fill a map reference passed through with the contents of another map from dataSystem; int value override
/*Arguments:
*argMap1 - This map contains a map of settings loaded passed in from another function
*/
static map<string, int> fillMap(map<string, int>argMap1) {
	for (iti1 = argMap1.begin(); iti1 != argMap1.end(); iti1++) {
		rtnIMap.insert(pair<string, int>(iti1->first, iti1->second));
	}

	return rtnIMap;
}

static vector<Planet> updateVec(vector<Planet> plVec, Planet pl) {
	for (i1 = 0; i1 < plVec.size(); i1++) {
		if (i1 == plVec.size() - 1 && plVec[i1].getName() != pl.getName()) {
			createBInfo(__FILE__, to_string(__LINE__), __DATE__, __TIME__, "Planet Not Found", "Planet " + pl.getName() + " not found in expected system.  Cannot update.", "./OV_Log.txt");
		} else if (plVec[i1].getName() == pl.getName()) {
			plVec[i1] = pl;
			break; //Found and update, no longer need to loop
		}
	}

	return plVec;
}

static vector<aBelt> updateVec(vector<aBelt> abVec, aBelt ab) {
	for (i1 = 0; i1 < abVec.size(); i1++) {
		if (i1 == abVec.size() - 1 && abVec[i1].getName() != ab.getName()) {
			createBInfo(__FILE__, to_string(__LINE__), __DATE__, __TIME__, "Asteroid belt Not Found", "Asteroid belt " + ab.getName() + " not found in expected system.  Cannot update.", "./OV_Log.txt");
		}
		else if (abVec[i1].getName() == ab.getName()) {
			abVec[i1] = ab;
			break; //Found and update, no longer need to loop
		}
	}

	return abVec;
}

static vector<planetarySystem> updateVec(vector<planetarySystem> plsVec, planetarySystem plSys) {
	for (i1 = 0; i1 < plsVec.size(); i1++) {
		if (i1 == plsVec.size() - 1 && plsVec[i1].getName() != plSys.getName()) {
			createBInfo(__FILE__, to_string(__LINE__), __DATE__, __TIME__, "Planetary system Not Found", "Planetary system " + plSys.getName() + " not found in universe.  Cannot update.", "./OV_Log.txt");
		}
		else if (plsVec[i1].getName() == plSys.getName()) {
			plsVec[i1] = plSys;
			break; //Found and update, no longer need to loop
		}
	}

	return plsVec;
}

static void createBInfo(string fl, string lnNm, string dt, string tm, string errCode, string errMsg, string fPath) {
	file = fl;
	bLocale = "File: " + file + "  Line: " + lnNm;
	bTDate = dt + "  " + tm;

	db.createBReport(errCode, errMsg, bLocale, bTDate, fPath);
}