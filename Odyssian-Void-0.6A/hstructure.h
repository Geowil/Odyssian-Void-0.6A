/*FILE HEADER

File Name:

hstructure.h

File Description:

This class encapsulates the hull structure ship system and will return, on function call, various statistics used in their operation

How it Works:

Statistics are pulled from the database and saved here based on the ID passed to the "i" (install) function.  Acts as a source for the base statistics
which the game acts upon and uses for bonus modifications.

Created On:

Monday, July 1, 2015

Version:

1.0 - 07/9/2015

Changes:

1.0:
-Created hstructure class and added basic members.
-Added i-function to install new engine objects to the ship.
-Added the get functions to return the values stored in this class.

End File Header*/

#ifndef HSTRUCTURE_H
#define HSTRUCTURE_H
#include <string>

using std::string;

class hStructure
{
	public:
		hStructure();
	
		void iHS(int eID);
		
		int getID();
		string getName();
		float getMHP();
		float getRRate();
		float getRPCon();
		float getPReq();
		float getCReq();
		float getRReq();
	

	private:
		string hsName;
		int eID;
		float hsMHP; //Max Normal Thurst (acceleration)
		float hsRRate; //Max Normal Speed
		float hsRPCon; //Normal Speed Power Consumption
		float hsPReq; //Main Power Requirement
		float hsCReq; //CPU Requirement
		float hsRReq; //RAM Requirement
};
#endif;
