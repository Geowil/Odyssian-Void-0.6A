#ifndef SKILLS_H
#define SKILLS_H

#include <string>

using std::string;


class Skill
{
public:
	Skill();
	string getSName(); //Return skill name
	string getSDesc(); //Return skill desc
	string getSEffect(); //Return skill effect
	int getSRank(); //Return skill rank
	int getTTime(); //Return training time to next rank
	int getSID();
	
	void rankUp(); //Rank up skill
	void checkTTime();
	void newSkill(int id); //Setup a new skill
	void aTraining(int i);

private:
	int sID; //Skill ID
	string sName; //Skill Name
	string sDesc; //Skill Description
	string sEffect; //Description of the effects of this skill
	string sGroup; //What group the skill belongs to (eg: ship battle, mining)
	float sTDiff; //Training Difficulty of this skill
	int sTTime; //Total time it will take to attain the next rank of this skill
	int sCTTime; //Completed Training Time
	int sRank; //Current Skill Rank
};
#endif
