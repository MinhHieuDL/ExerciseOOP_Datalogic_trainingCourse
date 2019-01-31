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

	string ListMater;
	while(ListMater != "exit")
	{
		cout << "Enter the list of material that you want - separate by comma: ";
		cin >> ListMater;
		Scanner->productManufactoring(ListMater);
	}
	system("pause");
	return 0;
}

