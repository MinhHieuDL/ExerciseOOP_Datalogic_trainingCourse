
#include "Class.h"

// Class Factory
ConveyorBase* FactoryAbstract::head = NULL;

string FactoryAbstract::getName()
{
	return nameOfFactory;
}

unsigned int FactoryAbstract::getNumberOfConveyors()
{
	return numberOfConveyors;
}

ConveyorBase * FactoryAbstract::getConveyor()
{
	return head;
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

void FactoryUI::insertConveyor(kindOFConveyor kOC)
{
	switch (kOC)
	{
	case Normal:
		conveyor = new NormalConveyorUI;
		break;
	default:
		break;
	}
	conveyor->setNameForConveyor();
	conveyor->next = head;
	head = conveyor;
}


// class Conveyor
void NormalConveyorUI::setNameForConveyor()
{
	cout << "Enter the name of conveyor";
	cin >> nameOfConveyor;
}

string ConveyorBase::getName()
{
	return nameOfConveyor;
}


