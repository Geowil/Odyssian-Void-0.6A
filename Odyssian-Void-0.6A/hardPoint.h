/*File Header

/*FILE HEADER

File Name:

hardpoint.h

File Description:

A hardpoint is defined, in Odyssian Void, as a contact point on a ship hull where a weapon or other equipment is
attached to the hull of a ship and from where it obtains its power, ammo, and control instructions.  This class
will handle the interface to connect these points from ships to weapons and vice-versa.

How it Works:

This class will be used in object vectors to store individual linkage between the weapons/modules classes and the
ship class.  Weapon instance objects are actually stored in these classes and that then allows the ship class
access to those object's informaiton.

Created On:

? (File Header was created on 06/30/2015)

Version:

1.0 - 06/30/2015 (when file header was created)

Changes:

1.0:
-Removed other sub-classes that were used on a per-weapon-type basis.
-Added a two new sub-classes; one for weapons and one for non-weapons.


End File Header*/

#ifndef HARDPOINT_H
#define HARDPOINT_H

#include <string>
#include "weapon.h"

using std::string;

class hardPoint
{
public:
	hardPoint();
	hardPoint(int slot);
	hardPoint(int slot, string wtype);

	void setHPSlot(int slot); //set slot number
	void setHPType(string type); //set weapon type

	int getHPSlot(); //get slot number
	string getHPType(); //get weapon type

protected:
	int hpSlot; //the number of this hard point; corresponds to a slot value in the weapon vector specified in hpWType
	string hpType; //What tpye of equipment is installed in this hardpoint
};

class wHPoint : hardPoint
{
public:
	wHPoint(int slot);
	wHPoint(int slot, string wtype);

	Weapon wHP;
};

class mHPoint : hardPoint
{
public:
	mHPoint(int slot);
	mHPoint(int slot, string mtype);

	Module mHP;
};
#endif