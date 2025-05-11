#include "Member.h"

Member::Member(std::string name)
{
	_name = name;
	_unicumID = getCount()++;
}

int Member::getUnicumID() {return _unicumID;}

std::string Member::getName() {return _name;}

void Member::setName(std::string name) {_name = name;}
