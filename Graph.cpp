#include "Graph.h"

void Graph::addMember(const Member& newMember)
{
	allMembers.push_back(newMember);
}

void Graph::addMembers(const std::vector<Member>&newArr)
{
	allMembers.insert(allMembers.end(), newArr.begin(), newArr.end());
}



std::vector <int> Graph::getIdOfContacts(const char* beginer, const int depth)
{
	std::vector <int> res;
	return res;
}

void Graph::addConnection(const char* firstName, const char* secondName)
{
	if (allMembers.size() == 0) return;

	bool isFirstFind = false;
	bool isSecondFind = false;
	int firstPos = -1;
	int secondPos = -1;
	
	for (int i = 0; i < allMembers.size(); ++i)
	{
		if (!isFirstFind && allMembers[i].getName() == firstName)
		{
			firstPos = i;
			isFirstFind = true;
			if (isSecondFind) break;
		}
		else if (!isSecondFind && allMembers[i].getName() == secondName)
		{
			secondPos = i;
			isSecondFind = true;
			if (isFirstFind) break;
		}
	}
	
	if (!isFirstFind)
	{
		std::cout << "Внимание! Не найден участник под именем " << firstName << std::endl;
		return;
	}
	if (!isSecondFind)
	{
		std::cout << "Внимание! Не найден участник под именем " << secondName << std::endl;
		return;
	}


	allMembers[firstPos].addEdge(allMembers[secondPos].getUnicumID());
	allMembers[secondPos].addEdge(allMembers[firstPos].getUnicumID());
}

void Graph::printAllEdgeLists()
{
	if (allMembers.size() == 0) return;

	for (int i = 0; i < allMembers.size(); ++i)
	{
		Member currMember = allMembers[i];
		int currID = currMember.getUnicumID();
		for(int j = 0; j < currMember.getEdgeList().size(); ++j)
			if(currMember.getEdgeList()[j] > currMember.getUnicumID())		// отсекаем повторяющиеся ребра
				std::cout << "( " << currMember.getUnicumID() << "; " << currMember.getEdgeList()[j] << " ); ";
		std::cout << std::endl;
	}
}

void Graph::printAllMembers()
{
	if (allMembers.size() == 0) return;

	std::cout << "Члены группы:\n";
	for (int i = 0; i < allMembers.size(); ++i)
		std::cout << "Имя: " << allMembers[i].getName() << "; ID = " << allMembers[i].getUnicumID() << std::endl;
}
