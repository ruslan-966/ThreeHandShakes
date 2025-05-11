#include "Graph.h"

void Graph::addMember(const Member& newMember)
{
	allMembers.push_back(newMember);
}

void Graph::addMembers(const std::vector<Member>&newArr)
{
	allMembers.insert(allMembers.end(), newArr.begin(), newArr.end());
}

void Graph::addConnection(Member& firstMember, Member& secondMember)
{
	matrix[firstMember.getUnicumID()][secondMember.getUnicumID()] = 1;
	matrix[secondMember.getUnicumID()][firstMember.getUnicumID()] = 1;
}

void Graph::printAllContacts(const Member& frand, const int depth)
{

}

void Graph::getPairContacts(Member&, Member&, int)
{
}

bool Graph::isConnectBetween(Member& firstMember, Member& secondMember)
{
	return matrix[firstMember.getUnicumID()][secondMember.getUnicumID()] > 0;
	
}

bool Graph::isConnectBetween(int& firstNumber, int& secondNumber)
{
	return matrix[firstNumber][secondNumber] > 0;
}
