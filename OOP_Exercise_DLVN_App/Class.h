#pragma once
#include <iostream>
#include <string>

using namespace std;

class FactoryAbstract
{
protected:
	string nameOfFactory;
	unsigned int numberOfConveyors;
public:
	virtual void setName() = 0;
	string getName();
	virtual void setNumberOfConveyors() = 0;
	unsigned int getNumberOfConveyors();
};


class FactoryUI : virtual public FactoryAbstract
{
public:
	void setName();
	void setNumberOfConveyors();
};
