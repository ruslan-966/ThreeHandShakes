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

std::vector <std::string> Graph::calcAllPairs(const std::string& MainMember, const int& depth)
{
	std::vector <std::string> arrMembers;
	// шаг номер 0
	if (depth == 0)
	{
		return arrMembers;		
	}
	int idMainMember = -1;
	for (int i = 0; i < allMembers.size(); ++i)
		if (allMembers[i].getName() == MainMember)
		{
			idMainMember = i;
			break;
		}
	if (idMainMember == -1)							// проверка на косорукость
	{
		std::cout << "Имя " << MainMember << " не зарегистрировано среди пользователей.\n";
		return arrMembers;
	}

	std::vector<int> arr;							// массив подсчета связей
	for (int i = 0; i < allMembers.size(); ++i)
		arr.push_back(BIGINT);
	arr[idMainMember] = 0;							// внесли начальный элемент
	int step = 1;
	stepWriter(arr, step, idMainMember, depth);		// анализ вынесен в эту функцию

	for(int i = 0; i < arr.size(); ++i)
		if (arr[i] <= depth && arr[i] > 0)
		{
			Member cM = allMembers[i];
			arrMembers.push_back(cM.getName());
		}
	return arrMembers;
}

void Graph::stepWriter(std::vector<int>& arr, int& step, int& memberID, const int& depth)
{
	if (step > depth) return;								// условие окончания поиска
	int newStep = step + 1;
	Member currElement = allMembers[memberID];				// извлекли текущий элемент
	std::vector <int> eL = currElement.getEdgeList();		// извлекли перечень ID вершин, с которыми есть ребра
	for (int i = 0; i < eL.size(); ++i)
	{
		int num = eL[i];									// извлекли ID вершины, связанной с текущей
		if (arr[num] > step)								// если вершина отстоит на большее расстояние, чем step, меняем значение
			arr[num] = step;
		stepWriter(arr, newStep, num, depth);				// запустили рекурсию
	}
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
