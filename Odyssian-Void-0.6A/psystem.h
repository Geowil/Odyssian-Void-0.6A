/*FILE HEADER

File Name:

psystem.h

File Description:

This class encapsulates the primary power system ship system and will return, on function call, various statistics used in their operation

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
-Created engine class and added basic members.

1.1:
-Added i-function to install new power system objects to the ship.
-Added the get functions to return the values stored in this class.

End File Header*/

#ifndef PSYSTEM_H
#define PSYSTEM_H
#include <string>
using std::string;
class pSystem
{
	public:
		pSystem();

		void iPS(int eid);

		bool bIsInstalled();
		string getName();
		int getID();
		float getCMax();
		float getSRRate();
		float getCReq();
		float getRReq();


	private:
		string psName;
		int eID;
		float psCMax; //Max Capacity
		float spsRRate; //Recharge Rate for Secondary Power System
		float psCReq; //CPU Requirement
		float psRReq; //RAM Requirment
};
#endif;
