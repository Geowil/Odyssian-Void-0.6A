/*FILE HEADER

File Name:

engine.h

File Description:

This class encapsulates the engine ship system and will return, on function call, various statistics used in their operation

How it Works:

Statistics are pulled from the database and saved here based on the ID passed to the "i" (install) function.  Acts as a source for the base statistics
which the game acts upon and uses for bonus modifications.

Created On:

Monday, July 1, 2015

Version:

1.0 - 07/1/2015
1.1 - 07/8/2015
1.2 - 07/13/2015

Changes:

1.0:
-Created engine class and added basic members.

1.1:
-Added i-function to install new engine objects to the ship.
-Added the get functions to return the values stored in this class.

1.2:
-Removed ePCon and related functions.  Engines will not deplete secondary power under normal flight conditions; only at warp.  Afterburners, which would drain SPS in normal flight, will be separate system.

End File Header*/

#ifndef ENGINE_H
#define ENGINE_H
#include <string>
using std::string;
class Engine
{
	public:
		Engine();
	
		void iEngine(int eID);
		
		int getID();
		string getName();
		float getMThrust();
		float getSMax();
		float getECon();
		float getTRCWgt();
		float getPReq();
		float getCReq();
		float getRReq();
	

	private:
		string eName;
		int eID;
		float eMThrust; //Max Thrust (acceleration)
		float eSMax; //Max Speed
		float ePCon; //Power Consumption
		float eTRCWgt; //Weighting on time to complete turn radius for course changes
		float ePReq; //Main Power Requirement
		float eCReq; //CPU Requirement
		float eRReq; //RAM Requirement
};
#endif;
