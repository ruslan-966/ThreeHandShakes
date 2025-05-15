// ThreeHandShakes.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include "Member.h"
#include <vector>
#include "Graph.h"

void printResult(const std::string& mainName, const std::vector <std::string>& result, const int& depth)
{
    std::cout << "Было проведено исследование связей участников. Глубина рукопожатия: " << depth << ".\n";
    std::cout << "Ник нейим первого участника: " << mainName << std::endl;
    std::cout << "Последующие участники:\n";
    if (result.size() == 0)
    {
        std::cout << "Не обнаружены.\n";
        return;
    }
    for (int i = 0; i < result.size(); ++i)
        std::cout << result[i] << " ";
    std::cout << std::endl;
    return;
}

int main()
{
    setlocale(LC_ALL, "");
    std::vector<Member> arr;
    arr.push_back(Member("Саша"));
    arr.push_back(Member("Маша"));
    arr.push_back(Member("Коля"));
    arr.push_back(Member("Петя"));
    arr.push_back(Member("Лёня"));
    arr.push_back(Member("Лена"));
    arr.push_back(Member("Слава"));
    arr.push_back(Member("Савва"));
    arr.push_back(Member("Шурик"));
    
    Graph g;

    g.addMembers(arr);

    g.printAllMembers();

    g.addConnection("Саша", "Маша");
    g.addConnection("Маша", "Коля");
    g.addConnection("Коля", "Саша");
    g.addConnection("Коля", "Петя");
    g.addConnection("Петя", "Лёня");
    g.addConnection("Лёня", "Лена");
    
    g.printAllEdgeLists();

    int depth = 3;
    std::string firstParticipant = "Шурик";
    std::vector <std::string> result = g.calcAllPairs(firstParticipant, depth);

    printResult(firstParticipant, result, depth);

}
