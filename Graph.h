#pragma once
#include "Member.h"
#include <vector>
#include <iostream>
#define SIZE 10
class Graph
{
public:
    Graph() = default;
    
    void addMember(const Member&);                    // добавить одного члена в список
    void addMembers(const std::vector<Member>&);      // добавить несколько членов в список

    void addConnection(Member& , Member&);      // добавить прямой контакт между членами

     void printAllContacts(const Member&, const int );        // Вывести все контакты члена в глубину

    void getPairContacts(Member&, Member&, int);// Вывести все возможные контакты между членами

private:
    std::vector <Member> allMembers;            // Хранилище пользователей
    int graphTops[SIZE];                        // вершины в графе

    bool isConnectBetween(Member&, Member&);      // Есть ли ребро между двумя членами

    bool isConnectBetween(int&, int&);            // Есть ли реборо между двумя членами, определенными через ID

    int matrix[SIZE][SIZE];                     // матрица смежности
};

