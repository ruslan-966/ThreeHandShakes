#include "Graph.h"

void Graph::addMember(const Member& newMember)
{
	allMembers.push_back(newMember);
}

void Graph::addMembers(const std::vector<Member>&newArr)
{
	allMembers.insert(allMembers.end(), newArr.begin(), newArr.end());
}



void Graph::printAllContacts(const Member& frand, const int depth)
{

}

void Graph::addConnection(Member& mem_one, Member& mem_two)
{
	mem_one.addEdge(mem_two.getUnicumID());
	mem_two.addEdge(mem_one.getUnicumID());
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
