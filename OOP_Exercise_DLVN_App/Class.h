#ifndef CLASS_H
#define CLASS_H


#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
// Material
class Material
{
private:
	string nameOfMaterial;
	Material *nextMaterialInList;
public:
	void setNameMaterial(string name);
	string getNameOfMaterial();
	void setNextMaterial(Material*);
	Material* getNextMaterial();
};

typedef struct Node
{
	string data;
	struct Node *nextNodeMaterial;
} NodeMaterial;

void deleteListOFNodeMAterial(NodeMaterial *head);

// Product
class Product
{
private:
	string nameOfProduct;
	Product *nextProductInList;
	unsigned int numberOfMaterial;
	Material *headOfMaterialList;
public:
	Product();
	void setUpMaterial();
	unsigned int getNumberOfMaterial();
	void setName(string);
	string getNameOfProduct();
	void setNextProduct(Product *nextProduct);
	Product* getNextProduct();
	void insertMaterial(string MaterialName);
	Material* getHeadOfMaterialList();
};

// Conveyor
typedef enum  
{
	Normal, Test, Encap
}kindOFConveyor;

class ConveyorBase
{
protected:
	string nameOfConveyor;
	ConveyorBase *nextConveyorInList;
public:
	virtual void setNameForConveyor() = 0;
	string getName();
	void setNextConveyor(ConveyorBase *nextConveyor);
	ConveyorBase* getNextConveyor();
	virtual void setUpConveyor() = 0;
	virtual void Run() = 0;
	virtual kindOFConveyor getType() = 0;
};

class NormalConveyorUI : public ConveyorBase
{
private:
	unsigned int numberOfProduct;
	Product product;
	Product *headOfProductList;
	void insertProduct(string ProductName);
	void setUpProduct();
	void setNameForConveyor();
public: 
	NormalConveyorUI();
	unsigned int getNumberOfProduct();
	void setUpConveyor();
	Product* getProduct();
	kindOFConveyor getType();
	void displayNameofProductInConveyor();
	Product* getHeadOfProductList();
	void Run();
};

//class TestConveyorUI : public ConveyorBase
//{
//public:
//	void setNameForConveyor();
//	void setUpConveyor();
//	kindOFConveyor getType();
//};

// Factory
class FactoryAbstract
{
protected:
	string nameOfFactory;
	unsigned int numberOfConveyors;
	ConveyorBase *conveyor;
	static ConveyorBase *headOfConveyorInList;
public:
	virtual void setName() = 0;
	string getName();
	virtual void setNumberOfConveyors() = 0;
	unsigned int getNumberOfConveyors();
	virtual void insertConveyor(kindOFConveyor) = 0;
	ConveyorBase* getConveyor();
	void displayNameOfConveyorInFactory();
	void productManufactoring(string ListOfMaterial);
};

class FactoryUI : virtual public FactoryAbstract
{
public:
	void setName();
	void setNumberOfConveyors();
	void insertConveyor(kindOFConveyor);
};


#endif