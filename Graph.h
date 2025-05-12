#pragma once
#include "Member.h"
#include <vector>
#include <iostream>
#define SIZE 10
class Graph
{
public:
    Graph() = default;
    
    void addMember(const Member&);                      // добавить одного члена в список
    void addMembers(const std::vector<Member>&);        // добавить несколько членов в список

    void addConnection(Member& , Member&);              // добавить прямой контакт между членами
    void printAllEdgeLists();                           // вывести все ребра в список смежности 
    void printAllMembers();                             // выводит все имена и ID членов

    void printAllContacts(const Member&, const int );   // Вывести все контакты члена в глубину

private:
    std::vector <Member> allMembers;            // Хранилище пользователей
    
    
};

