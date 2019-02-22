
#include "Class.h"
#include <Windows.h>

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


void FactoryUI::setNameForFactory()
{
	cout << "Enter the name of factory: ";
	cin >> nameOfFactory;
}

void FactoryUI::setUpFactory()
{
	setNameForFactory();
	unsigned int countConveyor = 0;
	cout << "Enter number of production conveyor: ";
	cin >> countConveyor;
	cout << "*************************************************************************" << endl;
	for (unsigned int i = 0; i < countConveyor; i++)
	{
		insertConveyor(normal);
	}
	insertConveyor(testWeight);
	insertConveyor(makeLabel);
}


void FactoryUI::insertConveyor(kindOFConveyor kOC)
{
	switch (kOC)
	{
	case normal:
	{
		conveyor = new NormalConveyorUI;
		break;
	}
	case testWeight:
	{
		conveyor = new TestWeightUI;
		break;
	}
	case makeLabel:
	{
		conveyor = new MakeLabelUI;
		break;
	}
	default:
		break;
	}
	conveyor->setUpConveyor();
	conveyor->setNextConveyor(headOfConveyorInList);
	headOfConveyorInList = conveyor;
	numberOfConveyors++;
	cout << "*************************************************************************" << endl;
}

void FactoryAbstract::displayNameOfConveyorInFactory()
{
	ConveyorBase *ptr;
	ptr = headOfConveyorInList;
	while (ptr != NULL)
	{
		cout << ptr->getName() << endl;
		ptr = ptr->getNextConveyor();
	}
}

void FactoryAbstract::productManufacturing(string ListOfMaterial)
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
	ConveyorBase *pConveyor = NULL;
	pConveyor = headOfConveyorInList;
	while (pConveyor != NULL)
	{
		if (pConveyor->getType() == normal)
		{
			NormalConveyorUI *pConveyorNormal = (NormalConveyorUI *)pConveyor;
			Product *pProduct = NULL;
			pProduct = pConveyorNormal->getHeadOfProductList();
			while (pProduct != NULL)
			{
				if (pProduct->getNumberOfMaterial() == countNode)
				{
					Material *pMaterial = NULL;
					pMaterial = pProduct->getHeadOfMaterialList();
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
						pConveyor->Run(pProduct);
						cout << "The product " << pProduct->getNameOfProduct() << " has been created already on the conveyor " << pConveyor->getName() << ". The weight of product is: " << pProduct->getWeightProduct() << " kg" << endl;
						// test product 
						pConveyor = headOfConveyorInList;
						while (pConveyor->getType() != testWeight)
						{
							pConveyor = pConveyor->getNextConveyor();
						}
						pConveyor->Run(pProduct);
						// make label
						pConveyor = headOfConveyorInList;
						while (pConveyor->getType() != makeLabel)
						{
							pConveyor = pConveyor->getNextConveyor();
						}
						pConveyor->Run(pProduct);
						cout << "*************************************************************************" << endl;
						deleteListOFNodeMAterial(headOfListMaterialEnteredByUser);
						return;  // exit the function
					}
				}
				pProduct = pProduct->getNextProduct();
			}
		}
		pConveyor = pConveyor->getNextConveyor();
	}
	cout << "Our Factory does not make the product from the material that you have entered!!" << endl;
	cout << "*************************************************************************" << endl;
	deleteListOFNodeMAterial(headOfListMaterialEnteredByUser);
}

/******************************************************Class Conveyor*****************************************************/

// Normal Conveyor
void NormalConveyorUI::insertProduct(string ProductName)
{
	Product* newProduct = new Product;
	newProduct->setNameForProduct(ProductName);
	newProduct->setUpMaterial();
	newProduct->setNextProduct(headOfProductList);
	headOfProductList = newProduct;
	numberOfProduct++;
}

void NormalConveyorUI::setUpProduct()
{
	string ProductList;
	cout << "Enter the list of product that was made on " << nameOfConveyor << " conveyor -- separate by the comma" << ": ";
	cin >> ProductList;
	string tokenProduct;
	std::istringstream ss(ProductList);
	while (getline(ss, tokenProduct, ','))
	{
		insertProduct(tokenProduct);
	}
}

NormalConveyorUI::NormalConveyorUI()
{
	headOfProductList = NULL;
	numberOfProduct = 0;
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
	return normal;
}

void NormalConveyorUI::displayNameofProductInConveyor()
{

	Product *pProduct;
	pProduct = headOfProductList;
	while (pProduct != NULL)
	{
		cout << pProduct->getNameOfProduct() << endl;
		pProduct = pProduct->getNextProduct();
	}
}

Product * NormalConveyorUI::getHeadOfProductList()
{
	return headOfProductList;
}

void NormalConveyorUI::Run(Product *thisProduct)
{
	cout << "Product is being maked! Please wait.";
	thisProduct->setWeightProduct();
	for (unsigned int i = 0; i < 5; i++)
	{
		cout << ".";
		Sleep(200);
	}
	cout << endl;
}

// Test Conveyor
void TestWeightUI::setNameForConveyor()
{
	cout << "Enter the name of test weight conveyor: ";
	cin >> nameOfConveyor;
}

void TestWeightUI::setUpConveyor()
{
	setNameForConveyor();
}

void TestWeightUI::Run(Product * thisProduct)
{
	cout << "Product is being tested on conveyor name " << this->getName() << "! Please wait.";
	for (unsigned int i = 0; i < 5; i++)
	{
		cout << ".";
		Sleep(200);
	}
	cout << endl;
	if ((thisProduct->getWeightProduct() > 10) && (thisProduct->getWeightProduct() < 30))
	{
		thisProduct->setIsGood(true);
		cout << "This product has passed the Weight Test!! Cool ^^" << endl;
	}
	else
	{
		thisProduct->setIsGood(false);
		cout << "This product has failed the Weight Test!" << endl;
	}
}

kindOFConveyor TestWeightUI::getType()
{
	return testWeight;
}

// MakeLabel Conveyor

void MakeLabelUI::setNameForConveyor()
{
	cout << "Enter the name for the make lable conveyor: ";
	cin >> nameOfConveyor;
}

void MakeLabelUI::setUpConveyor()
{
	setNameForConveyor();
}

void MakeLabelUI::Run(Product * thisProduct)
{
	bool productIsGood = thisProduct->getIsGood();
	cout << "Product is being labeled on conveyor name: " << this->getName() << "! Please wait.";
	for (unsigned int i = 0; i < 5; i++)
	{
		cout << ".";
		Sleep(200);
	}
	cout << endl;
	switch (productIsGood)
	{
	case true:
	{
		thisProduct->setLabel("ISO9001");
		break;
	}
	case false:
	{
		thisProduct->setLabel("The product is not good quality");
		break;
	}
	}
	cout << "Label of product is: " << thisProduct->getLabel() << endl;
}

kindOFConveyor MakeLabelUI::getType()
{
	return makeLabel;
}


// Conveyor Base
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
	numberOfMaterial = 0;
}

void Product::setUpMaterial()
{
	string MaterialList;
	cout << "Enter the list of material that need to make product " << nameOfProduct << " separate by the comma: ";
	cin >> MaterialList;
	string tokenMaterial;
	std::istringstream ss(MaterialList);
	while (getline(ss, tokenMaterial, ','))
	{
		insertMaterial(tokenMaterial);
	}
}

void Product::setIsGood(bool good)
{
	productIsGood = good;
}

bool Product::getIsGood()
{
	return productIsGood;
}

void Product::setLabel(string label)
{
	this->lablelOfProduct = label;
}

string Product::getLabel()
{
	return lablelOfProduct;
}

void Product::setWeightProduct()
{
	weightOfProduct = rand() % 50 + 1;
}

unsigned int Product::getWeightProduct()
{
	return weightOfProduct;
}

unsigned int Product::getNumberOfMaterial()
{
	return numberOfMaterial;
}

void Product::setNameForProduct(string PrName)
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
	numberOfMaterial++;
}

Material * Product::getHeadOfMaterialList()
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
	nextMaterialOfProduct = next;
}

Material * Material::getNextMaterial()
{
	return nextMaterialOfProduct;
}

void deleteListOFNodeMAterial(NodeMaterial * head)
{
	NodeMaterial *ptCurrent = head;
	NodeMaterial *ptNext = head;
	while (ptNext != NULL)
	{
		ptNext = ptCurrent->nextNodeMaterial;
		free(ptCurrent);
		ptCurrent = ptNext;
	}
}

