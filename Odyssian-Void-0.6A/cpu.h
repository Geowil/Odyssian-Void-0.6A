/*FILE HEADER

File Name:

cpu.h

File Description:

This class encapsulates the cpu system and will return, on function call, various statistics used in their operation

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
-Created cpu class and added basic members.

1.1:
-Added i-function to install new engine objects to the ship.
-Added the get functions to return the values stored in this class.

End File Header*/

#ifndef CPU_H
#define CPU_H
#include <string>
using std::string;
class CPU
{
	public:
		CPU();

		void iCPU(int id);

		bool bIsInstalled();
		string getName();
		int getID();
		float getPMax();
		float getPReq();

	private:
		string cName;
		int eID;
		float cPMax; //Max Performance (aka the max amount of usage)
		float cPReq; //Main Power Requirement
};
#endif;