#include "plSystem.h"
#include "utilities.cpp"

planetarySystem::planetarySystem() {}

planetarySystem::planetarySystem(string sysName, float sec) {
	plsName = sysName;
	plsSec = sec;
}

void planetarySystem::setSysName(string name) {
	plsName = name;
}

void planetarySystem::addPlanet(Planet pl) {
	plsPlanets.push_back(pl);
}

void planetarySystem::addABelt(aBelt ab) {
	plsABelts.push_back(ab);
}

void planetarySystem::modifyPlanet(Planet pl) {
	plsPlanets = updateVec(plsPlanets, pl);
}

void planetarySystem::modifyABelt(aBelt ab) {
	plsABelts = updateVec(plsABelts, ab);
}

float planetarySystem::getSecRating() {
	return plsSec;
}

string planetarySystem::getSysName() {
	return plsName;
}

vector<Planet> planetarySystem::getPlanets() {
	return plsPlanets;
}

vector<aBelt> planetarySystem::getABelts() {
	return plsABelts;
}

Planet planetarySystem::getPlanet(int index) {
	return plsPlanets.at(index);
}

aBelt planetarySystem::getABelt(int index) {
	return plsABelts.at(index);
}

void planetarySystem::updateSecRating(float sec, string operation) {
	if (operation == "add") {
		plsSec += sec;
	} else if (operation == "sub") {
		plsSec -= sec;
	} else if (operation == "set") {
		plsSec = sec;
	}
}

string planetarySystem::getName() {
	return plsName;
}
