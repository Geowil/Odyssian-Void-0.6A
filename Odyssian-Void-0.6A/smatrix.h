/*FILE HEADER

File Name:

smatrix.h

File Description:

This class encapsulates the shield matrix ship system and will return, on function call, various statistics used in their operation

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
-Created smatrix class and added basic members.

1.1:
-Added i-function to install new engine objects to the ship.
-Added the get functions to return the values stored in this class.

End File Header*/

#ifndef SMATRIX_H
#define SMATRIX_H
#include <string>
using std::string;
class sMatrix
{
	public:
		sMatrix();

		void iSMatrix(int eid);

		bool bIsInstalled();

		string getName();
		int getID();
		float getMSP();
		float getRRate();
		float getRPCon();
		float getPReq();
		float getCReq();
		float getRReq();

	private:
		string smName;
		int eID;
		float smMSP; //Max Shield Points
		float smRRate; //Reharge Rate
		float smRPConsumption; //Recharge Power Consumption (Capacitor)
		float smPReq; //Power Requirement (Main Power)
		float smCReq; //CPU Requirement
		float SMRReq; //RAM Requirement
};
#endif;
