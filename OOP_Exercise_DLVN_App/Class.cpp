
#include "Class.h"

/******************************************************Class Factory******************************************************/ 
ConveyorBase* FactoryAbstract::headOfConveyorInList = NULL;

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
	return headOfConveyorInList;
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
		break;
	}
	default:
	break;
	}
	conveyor->Run();
	conveyor->setNextConveyor(headOfConveyorInList);
	headOfConveyorInList = conveyor;
}

void FactoryAbstract::displayNameOfConveyorInFactory()
{
	ConveyorBase *ptr;
	ptr = headOfConveyorInList;
	while(ptr != NULL)
	{
		cout << ptr->getName() << endl;
		ptr = ptr->getNextConveyor();
	}
}

/******************************************************Class Conveyor*****************************************************/
Product* NormalConveyorUI::headOfProductList = NULL;
void NormalConveyorUI::insertProduct(unsigned int index)
{
	Product* newProduct = new Product;
	newProduct->setName(index);
	newProduct->setUpMaterial();
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
	nextConveyorInList = nextConveyor;
}

ConveyorBase * ConveyorBase::getNextConveyor()
{
	return nextConveyorInList;
}

/******************************************************Class Product******************************************************/
void Product::setNextProduct(Product * nextProduct)
{
	nextProductInList = nextProduct;
}


void Product::setUpMaterial()
{
	unsigned int _dem = 0;
	string MaterialList;
	cout << "Enter the list of material that need to make product - separate by the comma " << name << ": ";
	cin >> MaterialList;
	string tokenMaterial;
	std::istringstream ss(MaterialList);
	while (getline(ss, tokenMaterial, ','))
	{
		insertMaterial(tokenMaterial);
		_dem++;
	}
	numberOfMaterial = _dem;
}

unsigned int Product::getNumberOfMaterial()
{
	return numberOfMaterial;
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
	return nextProductInList;
}

void Product::insertMaterial(string MaterialName)
{
	Material* newMaterial = new Material;
	newMaterial->setNameMaterial(MaterialName);
	newMaterial->setNextMaterial(headOfMaterialList);
	headOfMaterialList = newMaterial;
}

/*****************************************************class Material*****************************************************/
Material* Product::headOfMaterialList = NULL;
void Material::setNameMaterial(string name)
{
	nameOfMaterial = name;
}

string Material::getNameOfMaterial()
{
	return nameOfMaterial;
}

void Material::setNextMaterial(Material *next)
{
	nextMaterialInList = next;
}

Material * Material::getNextMaterial()
{
	return nextMaterialInList;
}
