/*#ifndef E_NODE.h
#define E_NODE.h

#include <string>
#include <vector>
#include "res.h";
#include "item.h";
#include "tnode.h";

using std::string;
using std::vector;

class E_Node
{
public:
	//NO CONSTRUCTOR!!!!!11!11!1
	virtual void setupNode() = 0; //Function to set up node values
	virtual void createTRegion() = 0; //Function to create trade region
	virtual void processContract() = 0; //Function that will set up a buy contract for highest demanded (after supply factored [factored each time a deal is processed to account for sales]) item
	virtual void popTTargets(int ID) = 0; //Function to find trade nodes that have the item we are looking for
	virtual void getCAvg(int ID) = 0; //Get the trade region cost average for the specified item
	virtual void popcAList(vector<float> avgs) = 0; //Function to calculate total cost average and then store in list
	virtual void compelteContract(vector<Resource> rlist, int ID, int amount, string flag) = 0; //Function to effect changes in various trade node members resultant of a completed trade deal

	virtual int getHDemand() = 0; //Function to return the highest demanded item after supply has been factored
	
	virtual vector<Item> requestSupply(string node) = 0; //Request supply list from specified node
	virtual vector<Item> getSupply() = 0; //Return supply list to requesting node

	virtual bool isTrading() = 0; //Return if this node is already trading with another node

protected:
	vector<Resource> res_list; //List of resources available to this node
	vector<Item> supply_list; //List of items this node owns
	vector<Item> demand_list; //List of items this node wants
	vector<tNode> tRegion; //List of nodes abailavle for trading with
	vector<tNode> tTargets; //List of nodes that have the item to be bought
	vector<tNode> cAvg_list; //A list of brest average to worst average
	int nJRestrict; //Restricts how many nodes away this node can trade with; does not keep nodes outside of trade region from trading with this node though
	float nDRatio; //Used in algorithm to determine how good of a deal to find (can result in bad trade deals)
	float nDPanic; //Value at which node will no longer trade for; if avg below this, no trade
	int nTLimit; //Number of trades this node can make per turn (per minute for later versions)
	vector<float> nRCAvgs; //Store the regional cost averages of a sought after item for later use
	vector<Resource> nRCAVals; //Actual regional resource costs for sought after item for later use
	float nTCAvg; //Total cost average for each tNode.  An average of resource cost averages.
	bool bIsTrading; //If this is true then other nodes cannot contact this node for a trade deal

	bool bDone; //Determine if a trade has been completed or not
	
};
#endif*/