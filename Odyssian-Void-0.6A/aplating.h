/*FILE HEADER

File Name:

aplating.h

File Description:

This class encapsulates the armor plating ship system and will return, on function call, various statistics used in their operation

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
-Created aplating class and added basic members.

1.1:
-Added i-function to install new engine objects to the ship.
-Added the get functions to return the values stored in this class.

End File Header*/

#ifndef APLATING_H
#define APLATING_H
#include <string>
using std::string;
class aPlating
{
	public:
		aPlating();

		void iAPlating(int eid);

		bool bIsInstalled();

		string getName();
		int getID();
		float getMAP();
		float getRRate();
		float getRPCon();
		float getPReq();
		float getCReq();
		float getRReq();

	private:
		string apName;
		int eID;
		float apMAP; //Max Armor Points
		float apRRate; //Armor regeration rate (only for some types of armor)
		float apRPConsumption; //Armor Recharge Power Consumption (Capacitor)
		float apPReq; //Armor Plating Power Requirement (Main Power)
		float apCReq; //CPU Requirement
		float apRReq; //RAM Requirment
};
#endif;
