#include "hardpoint.h"
#include "weapon.h"
#include "module.h"

using std::string;

hardPoint::hardPoint()
{

}

hardPoint::hardPoint(int slot)
{
	hpSlot = slot;
}

hardPoint::hardPoint(int slot, string type)
{
	hpType = type;
	hpSlot = slot;
}

void hardPoint::setHPSlot(int slot)
{
	hpSlot = slot;
}

void hardPoint::setHPType(string type)
{
	hpType = type;
}

int hardPoint::getHPSlot()
{
	return hpSlot;
}

//Weapon HP
wHPoint::wHPoint(int slot)
{
	hpSlot = slot;
	wHP.initWeapon();
}

wHPoint::wHPoint(int slot, string type)
{
	hpSlot = slot;
	hpType = type;
	wHP.initWeapon();
}


//Module HP
mHPoint::mHPoint(int slot)
{
	hpSlot = slot;
	mHP.initModule();
}

mHPoint::mHPoint(int slot, string type)
{
	hpSlot = slot;
	hpType = type;
	mHP.initModule();
}

