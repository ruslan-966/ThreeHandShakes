// ThreeHandShakes.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include "Member.h"
#include <vector>
#include "Graph.h"

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
}
