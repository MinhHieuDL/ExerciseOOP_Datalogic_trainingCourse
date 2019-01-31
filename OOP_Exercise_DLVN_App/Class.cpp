
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
		break;
	}
	default:
	break;
	}
	conveyor->setNameForConveyor();
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

	cout << "countNode = " << countNode << endl;

	// find the Conveyor that make product from the list of material
	ConveyorBase *pConveyer = NULL;
	pConveyer = headOfConveyorInList;
	while(pConveyer != NULL)
	{
		if (pConveyer->getType() == Normal)
		{
			NormalConveyorUI *pConveyorNormal = (NormalConveyorUI *)pConveyer;
			Product *pProduct = NULL;
			pProduct = pConveyorNormal->getHeadOfProductList();
			while(pProduct != NULL)
			{
				if (pConveyorNormal->getNumberOfProduct() == countNode)
				{
					Material *pMaterial = NULL;
					pMaterial = pProduct->getHeadOfMaterialList();
					unsigned int _countNumberMaterialEqualToListMaterialEntered = 0;
					while(pMaterial != NULL)
					{
						NodeMaterial *pNodeMaterial = headOfListMaterialEnteredByUser;
						while(pNodeMaterial != NULL)
						{
							//cout << "the material of" << pProduct->getNameOfProduct() << " is: " << pMaterial->getNameOfMaterial() << endl;
							if (pMaterial->getNameOfMaterial() == pNodeMaterial->data)
								_countNumberMaterialEqualToListMaterialEntered++;
							pNodeMaterial = pNodeMaterial->nextNodeMaterial;
						}
						pMaterial = pMaterial->getNextMaterial();
					}
					cout << "_countNumberMaterialEqualToListMaterialEntered = " << _countNumberMaterialEqualToListMaterialEntered << endl;
					if (_countNumberMaterialEqualToListMaterialEntered == countNode)
					{
						cout << "The product: " << pProduct->getNameOfProduct() << " has make already!! " << "It stays on: " << pConveyer->getName() << " conveyor" << endl;
						cout << "You can go to there to take it" << endl;
						deleteListOFNodeMAterial(headOfListMaterialEnteredByUser);
						return;  // exit the function
					}
				}
				pProduct = pProduct->getNextProduct();
			}
		}
		pConveyer = pConveyer->getNextConveyor();
	}
	cout << "Our Factory do not make the product from the material that you have entered!!" << endl;
	deleteListOFNodeMAterial(headOfListMaterialEnteredByUser);
}

/******************************************************Class Conveyor*****************************************************/
//Product* NormalConveyorUI::headOfProductList = NULL;
void NormalConveyorUI::insertProduct(string ProductName)
{
	Product* newProduct = new Product;
	newProduct->setName(ProductName);
	newProduct->setUpMaterial();
	newProduct->setNextProduct(headOfProductList);
	headOfProductList = newProduct;
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
	headOfProductList = NULL;
}

void NormalConveyorUI::setNameForConveyor()
{
	cout << "Enter the name of conveyor: ";
	cin >> nameOfConveyor;
}


unsigned int NormalConveyorUI::getNumberOfProduct()
{
	return numberOfProduct;
}

inline void NormalConveyorUI::Run()
{
	setUpProduct();
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

Product * NormalConveyorUI::getHeadOfProductList()
{
	return headOfProductList;
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
	headOfMaterialList = NULL;
}

void Product::setUpMaterial()
{
	unsigned int _dem = 0;
	string MaterialList;
	cout << "Enter the list of material that need to make product --" << nameOfProduct << " separate by the comma: ";
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
	newMaterial->setNextMaterial(headOfMaterialList);
	headOfMaterialList = newMaterial;
}

Material * Product::getHeadOfMaterialList()
{
	return headOfMaterialList;
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
