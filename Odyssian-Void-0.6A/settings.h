#ifndef SETTING_H
#define SETTING_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Setting {
public:
	Setting(string name, string val, bool bIsVect);
	Setting(string name, int val, bool bIsVect);
	Setting(string name, float val, bool bIsVect);
	Setting(string name, long long val, bool bIsVect);

private:
	string setName;
	int setIVal;
	float setFVal;
	string setSVal;
	
	vector<string> setVSVal;
	vector<int> setVIVal;
	vector<float> setVFVal;
	vector<long long> setVI64Val;
};

#endif;
