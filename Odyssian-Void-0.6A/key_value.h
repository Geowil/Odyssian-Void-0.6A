/*FILE HEADER

File Name:
Key_Value

File Description:
This class will be used in many places where we need to store a single string key and a float or int value.  Mainly used for settings and effects.

Created On:  Sunday, March 06, 2016

Version:
1.0 - 03/06/2016


Changes:
1.0:
-Created the class and added functions and class variables; will support just ints and floats for now but will extend as required


End File Header*/

#ifndef KEY_VALUE__H
#define KEY_VALUE__H

#include <string>

using std::string;

class keyVal
{
public:
	keyVal(string key, int val);
	keyVal(string key, float val);

	string getKey(); //Return key
	string getType(); //Return val type
	int getIVal(); //Return int val
	float getFVal(); //Return float val

	void updateIVal(int val); //Update int val
	void updateFVal(float val); //Update float val

private:
	string sKey;
	string sType;
	int iVal;
	float fVal;
};
#endif;