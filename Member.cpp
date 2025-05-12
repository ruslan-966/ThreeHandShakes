#include "Member.h"

Member::Member(std::string name)
{
	_name = name;
	_unicumID = getCount()++;
}

int Member::getUnicumID() 
{
	return _unicumID;
}

std::string Member::getName() 
{
	return _name;
}

void Member::setName(std::string name) 
{
	_name = name;
}

void Member::addEdge(int num)
{
	_edgeList.push_back(num);
}

void Member::printEdges()
{
	if (_edgeList.size()==0)
		std::cout << "Врешина графа: " << _unicumID << " не содержит рёбер.";
	else
		for (int i = 0; i < _edgeList.size(); ++i)
			std::cout << "( " << getUnicumID() << "; " << _edgeList[i] << " ); ";
	std::cout << std::endl;
}

std::vector<int> Member::getEdgeList()
{
	return _edgeList;
}
