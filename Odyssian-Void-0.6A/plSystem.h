#ifndef PLSYSTEM__H
#define PLSYSTEM__H

#include <string>
#include <vector>
#include "planet.h";
#include "abelt.h";

using std::vector;
using std::string;

class planetarySystem {
public:
	planetarySystem();
	planetarySystem(string sysName, float sec);

	void setSysName(string name);
	void addPlanet(Planet pl);
	void addABelt(aBelt ab);

	void modifyPlanet(Planet pl);
	void modifyABelt(aBelt ab);

	float getSecRating();
	string getSysName();
	vector<Planet> getPlanets();
	vector<aBelt> getABelts();

	Planet getPlanet(int index);
	aBelt getABelt(int index);

	void updateSecRating(float sec, string operation);

	string getName();

private:
	string plsName;
	float plsSec;

	vector<Planet> plsPlanets;
	vector<aBelt> plsABelts;
};
#endif