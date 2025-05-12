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
    int getUnicumID();                  //Возвращает ID пользователя
    std::string getName();              //Возвращает имя пользователя
  
    void setName(std::string);          //Присваивает имя пользователю
    void addEdge(int);                  //Добавляет ID другого пользователя, если есть между ними связь
    void printEdges();                  //Выводит все ID ребра из списка смежности
    std::vector <int> getEdgeList();    //Выводит список ребер

private:
	std::string _name;                  //Ник нейм пользователя
	int _unicumID;                      //Присвоенный ID пользователю (присваивает автоматически)
    std::vector <int> _edgeList;         //Список смежности вершины графа
    static int& getCount()              //Генератор ID пользователя
    {
        static int theCount = 0;
        return theCount;
    }
};


