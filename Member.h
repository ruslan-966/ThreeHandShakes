#pragma once
#include <iostream>
#include <vector>

class Member
{
public:
	Member() = default;
	Member(std::string name);
	~Member() {};

    int totalCount() {return getCount();}
    int getUnicumID();                  //Возвращает ID участника
    std::string getName();              //Возвращает имя участника
  
    void setName(std::string);          //Присваивает имя участнику
    void addEdge(int);                  //Добавляет ID другого участника, если есть между ними связь
    void printEdges();                  //Выводит все ID ребра из списка смежности
    std::vector <int> getEdgeList();    //Выводит список ребер

private:
	std::string _name;                  //Ник нейм участника
	int _unicumID;                      //Присвоенный ID участнику (присваивает автоматически)
    std::vector <int> _edgeList;         //Список смежности вершины графа
    static int& getCount()              //Генератор ID для участника
    {
        static int theCount = 0;
        return theCount;
    }
};


