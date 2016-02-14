/*FILE HEADER

File Name:

ram.h

File Description:

This class encapsulates the ram system and will return, on function call, various statistics used in their operation

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
-Created ram class and added basic members.

1.1:
-Added i-function to install new engine objects to the ship.
-Added the get functions to return the values stored in this class.

End File Header*/

#ifndef RAM_H
#define RAM_H
#include <string>
using std::string;
class RAM
{
	public:
		RAM();

		void iRAM(int eid);
		
		bool bIsInstalled();
		string getName();
		int getID();
		float getCMax();
		float getPReq();

	private:
		string rName;
		int eID;
		float rCMax; //Max Capacity
		float rPReq; //Main Power Requirement
};
#endif;
