#ifndef TARGET_H
#define TARGET_H

#include <vector>
#include <string>

using std::vector;
using std::string;

class target
{
public:
	target();
	target(string tid);

	void setTID(string tid);
	void addSIDS(vector<string> sids);

	vector<string> getTSources();
	string getTID();

private:
	string tID; //ID of the target
	vector<string> sID; //ID list of the sources; sources being the source of the target lock (individual weapons).

	string tSource;
	int i1;
};

#endif