
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
	cout << "Enter the name of factory: ";
	cin >> nameOfFactory;
}

void FactoryUI::setNumberOfConveyors()
{
	cout << "Enter the number of conveyor: ";
	cin >> numberOfConveyors;
}

void FactoryUI::insertConveyor(kindOFConveyor kOC)
{
	switch (kOC)
	{
	case Normal:
	{
		conveyor = new NormalConveyorUI;
		NormalConveyorUI *pNCUI = (NormalConveyorUI *)conveyor;
		pNCUI->setNameForConveyor();
		pNCUI->setNumberOfProduct();
		pNCUI->Run();
		pNCUI->displayNameofProductInConveyor();
		break;
	}
	default:
	break;
	}
	conveyor->setNextConveyor(head);
	head = conveyor;
}

void FactoryAbstract::displayNameOfConveyorInFactory()
{
	ConveyorBase *ptr;
	ptr = head;
	while(ptr != NULL)
	{
		cout << ptr->getName() << endl;
		ptr = ptr->getNextConveyor();
	}
}

Product* NormalConveyorUI::headOfProductList = NULL;
void NormalConveyorUI::insertProduct(unsigned int index)
{
	Product* newProduct = new Product;
	newProduct->setName(index);
	newProduct->setNextProduct(headOfProductList);
	headOfProductList = newProduct;
}

void NormalConveyorUI::setNameForConveyor()
{
	cout << "Enter the name of conveyor: ";
	cin >> nameOfConveyor;
}

void NormalConveyorUI::setNumberOfProduct()
{
	cout << "Enter number of Product on " << nameOfConveyor << " conveyor: ";
	cin >> numberOfProduct;
}

unsigned int NormalConveyorUI::getNumberOfProduct()
{
	return numberOfProduct;
}

inline void NormalConveyorUI::Run()
{
	for (unsigned int i = 0; i < numberOfProduct; i++)
	{
		insertProduct(i);
	}
}

Product * NormalConveyorUI::getProduct()
{
	return headOfProductList;
}

kindOFConveyor NormalConveyorUI::getType()
{
	return Normal;
}

void NormalConveyorUI::displayNameofProductInConveyor()
{

	Product *pProduct;
	pProduct = headOfProductList;
	while(pProduct != NULL)
	{
		cout << pProduct->getNameOfProduct() << endl;
		pProduct = pProduct->getNextProduct();
	}
}

string ConveyorBase::getName()
{
	return nameOfConveyor;
}

void ConveyorBase::setNextConveyor(ConveyorBase * nextConveyor)
{
	next = nextConveyor;
}

ConveyorBase * ConveyorBase::getNextConveyor()
{
	return next;
}


void Product::setNextProduct(Product * nextProduct)
{
	next = nextProduct;
}

void Product::setName(unsigned int index)
{
	cout << "Enter the name of product " << "[" << index << "]: ";
	cin >> name;
}

string Product::getNameOfProduct()
{
	return name;
}

Product * Product::getNextProduct()
{
	return next;
}
