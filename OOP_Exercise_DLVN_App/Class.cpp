
#include "Class.h"
#include <Windows.h>

/******************************************************Class Factory******************************************************/ 

string FactoryAbstract::getName()
{
	return nameOfFactory;
}

unsigned int FactoryAbstract::getNumberOfConveyors(kindOFConveyor kOC)
{
	unsigned int number = 0;
	switch (kOC)
	{
	case Normal:
	{
		number = numberOfProductConveyors;
		break;
	}
	case Test:
	{
		number = numberOfTestConveyors;
		break;
	}
	default:
		break;
	}
	return number;
}


FactoryUI::FactoryUI()
{
	firstProductConveyor = NULL;
	firstTestConveyor = NULL;
}

void FactoryUI::setName()
{
	cout << "Enter the name of factory: ";
	cin >> nameOfFactory;
}

void FactoryUI::setNumberOfConveyors()
{
	cout << "Enter the number of product conveyor: ";
	cin >> numberOfProductConveyors;
	cout << "Enter the number of test conveyor: ";
	cin >> numberOfTestConveyors;
	cout << "*************************************************************************" << endl;
}

void FactoryUI::insertConveyor(kindOFConveyor kOC)
{
	switch (kOC)
	{
	case Normal:
	{
		conveyor = new NormalConveyorUI;
		conveyor->setNextConveyor(firstProductConveyor);
		firstProductConveyor = conveyor;
		break;
	}
	case Test:
	{
		conveyor = new TestConveyorUI;
		conveyor->setNextConveyor(firstTestConveyor);
		firstTestConveyor = conveyor;
		break;
	}
	default:
	break;
	}
	conveyor->setUpConveyor();
	cout << "*************************************************************************" << endl;
}

void FactoryAbstract::setUpFactory()
{
	for (unsigned int i = 0; i < numberOfProductConveyors; i++)
	{
		insertConveyor(Normal);
	}
	for (unsigned int i = 0; i < numberOfTestConveyors; i++)
	{
		insertConveyor(Test);
	}
}

void FactoryAbstract::displayNameOfConveyorInFactory()
{
	ConveyorBase *ptr;
	ptr = firstProductConveyor;
	while(ptr != NULL)
	{
		cout << ptr->getName() << endl;
		ptr = ptr->getNextConveyor();
	}
}

void FactoryAbstract::productManufactoring(string ListOfMaterial)
{
	// create link list of material from the List was entered by user
	unsigned countNode = 0;
	std::istringstream ss(ListOfMaterial);
	string tokenNodeMatrial;
	NodeMaterial *headOfListMaterialEnteredByUser = NULL;
	while (getline(ss, tokenNodeMatrial, ','))
	{
		NodeMaterial *newNode = new NodeMaterial;  // remember to delete after use
		newNode->data = tokenNodeMatrial;
		newNode->nextNodeMaterial = headOfListMaterialEnteredByUser;
		headOfListMaterialEnteredByUser = newNode;
		countNode++;
	}

	// find the Conveyor that make product from the list of material
	ConveyorBase *pConveyer = NULL;
	pConveyer = firstProductConveyor;
	while(pConveyer != NULL)
	{
		NormalConveyorUI *pConveyorNormal = (NormalConveyorUI *)pConveyer;
		Product *pProduct = NULL;
		pProduct = pConveyorNormal->getHeadOfProductList();
		while (pProduct != NULL)
		{
			if (pProduct->getNumberOfMaterial() == countNode)
			{
				Material *pMaterial = NULL;
				pMaterial = pProduct->getFirstMaterialOfProduct();
				unsigned int _countNumberMaterialEqualToListMaterialEntered = 0;
				while (pMaterial != NULL)
				{
					NodeMaterial *pNodeMaterial = headOfListMaterialEnteredByUser;
					while (pNodeMaterial != NULL)
					{
						if (pMaterial->getNameOfMaterial() == pNodeMaterial->data)
							_countNumberMaterialEqualToListMaterialEntered++;
						pNodeMaterial = pNodeMaterial->nextNodeMaterial;
					}
					pMaterial = pMaterial->getNextMaterial();
				}
				if (_countNumberMaterialEqualToListMaterialEntered == countNode)
				{
					unsigned int ProductWeight = 0;
					pConveyer->Run();
					ProductWeight = rand() % 100 + 1;
					cout << "The product: " << pProduct->getNameOfProduct() << " has make already!! " << endl;
					cout << "The weight of product is: " << ProductWeight << endl;
					cout << "It stays on: " << pConveyer->getName() << " conveyor" << endl;
					cout << "You can go to there to take it!!" << endl;
					cout << "*************************************************************************" << endl;
					deleteListOFNodeMAterial(headOfListMaterialEnteredByUser);
					return;  // exit the function
				}
			}
			pProduct = pProduct->getNextProduct();
		}
		pConveyer = pConveyer->getNextConveyor();
	}
	cout << "Our Factory do not make the product from the material that you have entered!!" << endl;
	cout << "*************************************************************************" << endl;
	deleteListOFNodeMAterial(headOfListMaterialEnteredByUser);
}

/******************************************************Class Conveyor*****************************************************/
//Product* NormalConveyorUI::headOfProductList = NULL;
void NormalConveyorUI::insertProduct(string ProductName)
{
	Product* newProduct = new Product;
	newProduct->setName(ProductName);
	newProduct->setUpMaterial();
	newProduct->setNextProduct(firstProductInConveyor);
	firstProductInConveyor = newProduct;
}

void NormalConveyorUI::setUpProduct()
{
	unsigned int _dem = 0;
	string ProductList;
	cout << "Enter the list of product that was made on " << nameOfConveyor << " conveyor -- separate by the comma"  << ": ";
	cin >> ProductList;
	string tokenProduct;
	std::istringstream ss(ProductList);
	while (getline(ss, tokenProduct, ','))
	{
		insertProduct(tokenProduct);
		_dem++;
	}
	numberOfProduct = _dem;
}

NormalConveyorUI::NormalConveyorUI()
{
	firstProductInConveyor = NULL;
}

void NormalConveyorUI::setNameForConveyor()
{
	cout << "Enter the name of production conveyor: ";
	cin >> nameOfConveyor;
}


unsigned int NormalConveyorUI::getNumberOfProduct()
{
	return numberOfProduct;
}

void NormalConveyorUI::setUpConveyor()
{
	setNameForConveyor();
	setUpProduct();
}

kindOFConveyor NormalConveyorUI::getType()
{
	return Normal;
}

void NormalConveyorUI::displayNameofProductInConveyor()
{

	Product *pProduct;
	pProduct = firstProductInConveyor;
	while(pProduct != NULL)
	{
		cout << pProduct->getNameOfProduct() << endl;
		pProduct = pProduct->getNextProduct();
	}
}

Product * NormalConveyorUI::getHeadOfProductList()
{
	return firstProductInConveyor;
}

void NormalConveyorUI::Run()
{
	cout << "Product was making! Please wait.";
	for (unsigned int i = 0; i < 5; i++)
	{
		cout << ".";
		Sleep(500);
	}
	cout << endl;
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


Product::Product()
{
	firstMaterialOfProduct = NULL;
}

void Product::setUpMaterial()
{
	unsigned int _dem = 0;
	string MaterialList;
	cout << "Enter the list of material that need to make product " << nameOfProduct << " separate by the comma: ";
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

void Product::setName(string PrName)
{
	nameOfProduct = PrName;
}

string Product::getNameOfProduct()
{
	return nameOfProduct;
}

Product * Product::getNextProduct()
{
	return nextProductInList;
}

void Product::insertMaterial(string MaterialName)
{
	Material* newMaterial = new Material;
	newMaterial->setNameMaterial(MaterialName);
	newMaterial->setNextMaterial(firstMaterialOfProduct);
	firstMaterialOfProduct = newMaterial;
}

Material * Product::getFirstMaterialOfProduct()
{
	return firstMaterialOfProduct;
}

/*****************************************************class Material*****************************************************/
//Material* Product::headOfMaterialList = NULL;
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

void deleteListOFNodeMAterial(NodeMaterial * head)
{
	NodeMaterial *ptCurrent = head;
	NodeMaterial *ptNext = head;
	while(ptNext != NULL)
	{
		ptNext = ptCurrent->nextNodeMaterial;
		free(ptCurrent);
		ptCurrent = ptNext;
	}
}

void TestConveyorUI::setNameForConveyor()
{
	cout << "Enter the name of Test conveyor: ";
	cin >> nameOfConveyor;
}

void TestConveyorUI::setUpConveyor()
{
	setNameForConveyor();
}

void TestConveyorUI::Run()
{

}

kindOFConveyor TestConveyorUI::getType()
{
	return Test;
}

bool TestConveyorUI::getPassTest()
{
	return PassTest;
}
