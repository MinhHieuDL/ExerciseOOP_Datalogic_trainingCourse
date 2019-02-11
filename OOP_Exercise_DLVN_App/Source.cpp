#include "Class.h"

int main(void)
{
	// Create Factory
	FactoryAbstract *Scanner = new FactoryUI;
	Scanner->setUpFactory();

	// User interface
	string ListMater;
	while (1)
	{
		cout << "Enter the list of material that you want - separate by comma: ";
		cin >> ListMater;
		if (ListMater == "exit") break;
		Scanner->productManufacturing(ListMater);
	}
	system("pause");

	return 0;
}

