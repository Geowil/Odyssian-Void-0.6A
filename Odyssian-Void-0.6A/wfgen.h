/*FILE HEADER

File Name:

wfgen.h

File Description:

This class encapsulates the warp field generation system and will return, on function call, various statistics used in their operation

How it Works:

Statistics are pulled from the database and saved here based on the ID passed to the "i" (install) function.  Acts as a source for the base statistics
which the game acts upon and uses for bonus modifications.

Created On:

Monday, July 1, 2015

Version:

1.0 - 07/1/2015
1.1 - 07/8/2015

Changes:

1.0:
-Created wfg class and added basic members.

1.1:
-Added i-function to install new engine objects to the ship.
-Added the get functions to return the values stored in this class.

End File Header*/

#ifndef WFGEN_H
#define WFGEN_H
#include <string>
using std::string;
class wFGen
{
	public:
		wFGen();
		
		void iWFGen(int eid);
	
		bool bIsInstalled();
		string getName();
		int getID();
		float getSMax();
		float getCReq();
		float getRReq();
		float getPSReq();
		float getCDrain();
		float getPCon();
		int getDTime();
		

	private:
		string wfgName;
		int eID;
		float wfgSMax; //Max Speed
		float wfgPCon; //Initial Power Consumption (powering up cost; different from continuous drain)
		float wfgCReq; //CPU Requirement
		float wfgRReq; //RAM Requirement
		float wfgPSReq; //Power System Requirement
		float wfgCDrain; //Secondry Power System Drain per AU
		int wfgDTime; //Delay to warp in ms
};
#endif;
