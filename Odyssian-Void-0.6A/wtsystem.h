/*FILE HEADER

File Name:

wtsystem.h

File Description:

This class encapsulates the ship weapon targeting system and will return, on function call, various statistics used in their operation

How it Works:

Statistics are pulled from the database and saved here based on the ID passed to the "i" (install) function.  Acts as a source for the base statistics
which the game acts upon and uses for bonus modifications.

Created On:

Monday, July 1, 2015

Version:

1.0 - 07/1/2015
1.1 - 07/9/2015

Changes:

1.0:
-Created wtsystem class and added basic members.

1.1:
-Added i-function to install new engine objects to the ship.
-Added the get functions to return the values stored in this class.

End File Header*/

#ifndef WTSYSTEM_H
#define WTSYSTEM_H
#include <string>
using std::string;
class wTSystem
{
	public:
		wTSystem();

		void iWTS(int eid);

		bool bIsInstalled();

		string getName();
		int getID();
		int getTTime();
		int getMTargs();
		float getPReq();
		float getCReq();
		float getRReq();

	private:
		string wtsName;
		int eID;
		int wtsTTime; //Time it takes, in ms, to lock onto a target
		int wtsMTargets; //Max number of targets this system can lock on to at once
		float wtsPReq; //Main Power Requirement
		float wtsCReq; //CPU Requirment
		float wtsRReq; //RAM Requirement
};
#endif;
