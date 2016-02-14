#ifndef RES_H
#define RES_H

#include <string>

using std::string;

class Resource
{
public:
	Resource(string name, int val); //Create Resource

	int getRes(); //Get Resource Val

	void updateRes(string op, int val); //Change the val of resource via op

private:
	string rName;
	int rVal;
};
#endif