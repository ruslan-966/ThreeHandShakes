#pragma once
#include <iostream>
class Member
{
public:
	Member() = default;
	Member(std::string name);
	~Member() {};

    int totalCount() {return getCount();}
    int getUnicumID();
    std::string getName();
  
    void setName(std::string);

private:
	std::string _name;
	int _unicumID;
    static int& getCount() 
    {
        static int theCount = 0;
        return theCount;
    }
};


