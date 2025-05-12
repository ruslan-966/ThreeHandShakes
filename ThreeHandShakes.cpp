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
    /*
    arr.push_back(Member("Коля"));
    arr.push_back(Member("Петя"));
    arr.push_back(Member("Лёня"));
    arr.push_back(Member("Лена"));
    arr.push_back(Member("Слава"));
    arr.push_back(Member("Савва"));
    arr.push_back(Member("Шурик"));
    */
    Graph g;

    g.addMembers(arr);

    g.printAllMembers();

    g.addConnection(arr[0], arr[1]);
    /*
    g.addConnection(arr[0], arr[2]);
    g.addConnection(arr[0], arr[3]);
    g.addConnection(arr[3], arr[1]);
    g.addConnection(arr[3], arr[4]);
    g.addConnection(arr[4], arr[5]);
    */
    g.printAllEdgeLists();
}
