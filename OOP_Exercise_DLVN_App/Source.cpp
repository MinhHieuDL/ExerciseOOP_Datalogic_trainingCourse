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
	while(1)
	{
		cout << "Enter the list of material that you want - separate by comma: ";
		cin >> ListMater;
		if (ListMater == "exit") break;
		Scanner->productManufactoring(ListMater);
	}
	system("pause");
	return 0;
}

