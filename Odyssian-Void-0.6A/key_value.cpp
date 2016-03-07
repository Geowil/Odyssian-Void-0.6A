#include "key_value.h";

keyVal::keyVal(string key, int val) {
	sKey = key;
	iVal = val;
	sType = "Int";
}

keyVal::keyVal(string key, float val) {
	sKey = key;
	fVal = val;
	sType = "Float";
}

string keyVal::getKey() {
	return sKey;
}

string keyVal::getType() {
	return sType;
}

int keyVal::getIVal() {
	return iVal;
}

float keyVal::getFVal() {
	return fVal;
}

void keyVal::updateIVal(int val) {
	iVal = val;
}

void keyVal::updateFVal(float val) {
	fVal = val;
}

