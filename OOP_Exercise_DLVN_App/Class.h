#ifndef CLASS_H
#define CLASS_H


#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

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
	Material *firstMaterialOfProduct;
public:
	Product();
	void setUpMaterial();
	unsigned int getNumberOfMaterial();
	void setName(string);
	string getNameOfProduct();
	void setNextProduct(Product *nextProduct);
	Product* getNextProduct();
	void insertMaterial(string MaterialName);
	Material* getFirstMaterialOfProduct();
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
	Product *firstProductInConveyor;
	void insertProduct(string ProductName);
	void setUpProduct();
	void setNameForConveyor();
public: 
	NormalConveyorUI();
	unsigned int getNumberOfProduct();
	void setUpConveyor();
	kindOFConveyor getType();
	void displayNameofProductInConveyor();
	Product* getHeadOfProductList();
	void Run();
};

class TestConveyorUI : public ConveyorBase
{
private:
	bool PassTest;
	void setNameForConveyor();
public:
	void setUpConveyor();
	void Run();
	kindOFConveyor getType();
	bool getPassTest();
};

// Factory
class FactoryAbstract
{
protected:
	string nameOfFactory;
	unsigned int numberOfProductConveyors;
	unsigned int numberOfTestConveyors;
	ConveyorBase *conveyor;
	ConveyorBase *firstProductConveyor;
	ConveyorBase *firstTestConveyor;
public:
	virtual void setName() = 0;
	string getName();
	virtual void setNumberOfConveyors() = 0;
	unsigned int getNumberOfConveyors(kindOFConveyor);
	virtual void insertConveyor(kindOFConveyor) = 0;
	void setUpFactory();
	void displayNameOfConveyorInFactory();
	void productManufactoring(string ListOfMaterial);
};

class FactoryUI : virtual public FactoryAbstract
{
public:
	FactoryUI();
	void setName();
	void setNumberOfConveyors();
	void insertConveyor(kindOFConveyor);
};


#endif