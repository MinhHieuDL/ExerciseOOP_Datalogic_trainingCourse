#include "Class.h"

int main(void)
{
	FactoryAbstract *Scanner = new FactoryUI;
	Scanner->setName();
	Scanner->setNumberOfConveyors();
	for (unsigned i = 0; i < Scanner->getNumberOfConveyors(); i++)
	{
		Scanner->insertConveyor(Normal);
	}
	Scanner->displayNameOfConveyorInFactory();
	cin.get();
	cin.get();
	return 0;
}