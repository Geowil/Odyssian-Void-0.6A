/*#ifndef ITEM_H
#define ITEM_H

#include "res.h";
#include <vector>

using std::vector;

class Item
{
public:
	Item(int id, int num); //Constructor

	void updateNum(string op, int val); //Update the number of items

	int getID(); //Get Item ID
	int getNum(); //Get Number of Items
	vector<Resource> getCost(); //Get Resource Cost Vector

	void setupCost(); //Set Up Resource Cost Vector

private:
	int iID; //Item ID
	int iNum; //Number of Items
	float iCMulti; //Cost Multiplier
	vector<Resource> iRCost;
};
#endif*/