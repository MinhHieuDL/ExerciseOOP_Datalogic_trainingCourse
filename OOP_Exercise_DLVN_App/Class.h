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
	Material *nextMaterialOfProduct;
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
	unsigned int weightOfProduct;
	bool productIsGood;
	string lablelOfProduct;
	Product *nextProductInList;
	unsigned int numberOfMaterial;
	Material *firstMaterialOfProduct;
public:
	Product();
	void setUpMaterial();
	void setWeightProduct();
	unsigned int getWeightProduct();
	void setIsGood(bool);
	bool getIsGood();
	void setLabel(string);
	string getLabel();
	unsigned int getNumberOfMaterial();
	void setNameForProduct(string);
	string getNameOfProduct();
	void setNextProduct(Product *nextProduct);
	Product* getNextProduct();
	void insertMaterial(string MaterialName);
	Material* getHeadOfMaterialList();
};

// Conveyor
typedef enum
{
	normal, testWeight, makeLabel
}kindOFConveyor;

class ConveyorBase
{
protected:
	string nameOfConveyor;
	ConveyorBase *nextConveyorInList;
	virtual void setNameForConveyor() = 0;
public:
	string getName();
	void setNextConveyor(ConveyorBase *nextConveyor);
	ConveyorBase* getNextConveyor();
	virtual void setUpConveyor() = 0;
	virtual void Run(Product *thisProduct) = 0;
	virtual kindOFConveyor getType() = 0;
};

class NormalConveyorUI : public ConveyorBase
{
private:
	unsigned int numberOfProduct;
	Product *headOfProductList;
	void setNameForConveyor();
	void setUpProduct();
public:
	NormalConveyorUI();
	unsigned int getNumberOfProduct();
	void insertProduct(string ProductName);
	void setUpConveyor();
	kindOFConveyor getType();
	void displayNameofProductInConveyor();
	Product* getHeadOfProductList();
	void Run(Product *thisProduct);
};

class TestWeightUI : public ConveyorBase
{
private:
	void setNameForConveyor();
public:
	void setUpConveyor();
	void Run(Product *thisProduct);
	kindOFConveyor getType();
};

class MakeLabelUI : public ConveyorBase
{
private:
	void setNameForConveyor();
public:
	void setUpConveyor();
	void Run(Product *thisProduct);
	kindOFConveyor getType();
};



// Factory
class FactoryAbstract
{
protected:
	string nameOfFactory;
	unsigned int numberOfConveyors;
	ConveyorBase *conveyor;
	static ConveyorBase *headOfConveyorInList;
	virtual void setNameForFactory() = 0;
public:
	virtual void setUpFactory() = 0;
	string getName();
	void setNumberOfConveyors();
	unsigned int getNumberOfConveyors();
	virtual void insertConveyor(kindOFConveyor) = 0;
	ConveyorBase* getConveyor();
	void displayNameOfConveyorInFactory();
	void productManufacturing(string ListOfMaterial);
};

class FactoryUI : virtual public FactoryAbstract
{
private:
	void setNameForFactory();
public:
	void setUpFactory();
	void insertConveyor(kindOFConveyor);
};


#endif