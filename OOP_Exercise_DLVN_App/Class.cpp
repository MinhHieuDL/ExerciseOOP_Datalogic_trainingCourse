
#include "Class.h"

// Class Factory
string FactoryAbstract::getName()
{
	return nameOfFactory;
}

unsigned int FactoryAbstract::getNumberOfConveyors()
{
	return numberOfConveyors;
}

void FactoryUI::insertConveyor()
{
	conveyor = new NormalConveyorUI;
	conveyor->setNameForConveyor();
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


// class Conveyor
void NormalConveyorUI::setNameForConveyor()
{
	cout << "Enter the name of conveyor";
	cin >> nameOfConveyor;
}
