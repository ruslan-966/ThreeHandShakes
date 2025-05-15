#pragma once
#include "Member.h"
#include <vector>
#include <iostream>
#define SIZE 10
#define BIGINT 1000000

class Graph
{
public:
    Graph() = default;
    
    void addMember(const Member&);                      // добавить одного участника в список
    void addMembers(const std::vector<Member>&);        // добавить несколько участников в список
    
    void addConnection(const char*, const char*);       // добавить прямой контакт между участниками
    void printAllEdgeLists();                           // вывести все ребра в список смежности 
    void printAllMembers();                             // выводит все имена и ID участников

    std::vector <int> getIdOfContacts(const char*, const int );   // Находит все вершины, минимальное расстояние между которыми не превосходит int
    std::vector <std::string> calcAllPairs(const std::string&, const int&);           // Возвращает вершины (Ник неймы) расположенные на глубину от указанной вершины 

private:
    std::vector <Member> allMembers;                    // Хранилище участников
    void stepWriter(std::vector <int>&, int&, int&, const int&);    // заносит в массив количество ребер от главной вершины до выбранной
    
    
};

