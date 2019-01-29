#include "Class.h"

string FactoryAbstract::getName()
{
	return nameOfFactory;
}

unsigned int FactoryAbstract::getNumberOfConveyors()
{
	return numberOfConveyors;
}

void FactoryUI::setName()
{
	cout << "Enter the name of factory";
	cin >> nameOfFactory;
}

void FactoryUI::setNumberOfConveyors()
{
	cout << "Enter the number of conveyor";
	cin >> numberOfConveyors;
}


