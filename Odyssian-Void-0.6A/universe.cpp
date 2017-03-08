#include "universe.h"
#include "utilities.cpp"

Universe::Universe() { }

void Universe::createUniverse() {

	uNOfExp = 1;
	uTTNextExp = calculateExpTime();
	uTSLastExp = 0;
}

void Universe::addSystem(planetarySystem plSys) {
	uSystems.push_back(plSys);
}

void Universe::updateSystem(planetarySystem plSys) {
	uSystems = updateVec(uSystems, plSys);
}

void Universe::updateExpTime(int tick, string operation) {
}

int Universe::calculateExpTime() {
	return 
}

void Universe::expansionPhase() {
	//Add code to expand universe
	//create system
	//create planets and a. belts
	//create stations, moons
	//create asteroids
}
