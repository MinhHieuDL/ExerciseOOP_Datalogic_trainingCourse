#ifndef CLASS_H
#define CLASS_H


#pragma once
#include <iostream>
#include <string>

using namespace std;
//Material
class Material
{
private:
	string nameOfMaterial;
public:
	void setNameOfMaterial();
	string getNameOfMaterial();
};
//Product
class Product
{
private:
	string name;
	Product *next;
public:
	void setNextProduct(Product *nextProduct);
	void setName(unsigned int);
	string getNameOfProduct();
	Product* getNextProduct();
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
	ConveyorBase *next;
public:
	virtual void setNameForConveyor() = 0;
	string getName();
	void setNextConveyor(ConveyorBase *nextConveyor);
	ConveyorBase* getNextConveyor();
	virtual void Run() = 0;
	virtual kindOFConveyor getType() = 0;
};

class NormalConveyorUI : public ConveyorBase
{
private:
	unsigned int numberOfProduct;
	Product product;
	static Product *headOfProductList;
	void insertProduct(unsigned int);
public: 
	// class Conveyor
	void setNameForConveyor();
	void setNumberOfProduct();
	unsigned int getNumberOfProduct();
	void Run();
	Product* getProduct();
	kindOFConveyor getType();
	void displayNameofProductInConveyor();
};

// Factory
class FactoryAbstract
{
protected:
	string nameOfFactory;
	unsigned int numberOfConveyors;
	ConveyorBase *conveyor;
	static ConveyorBase *head;
public:
	virtual void setName() = 0;
	string getName();
	virtual void setNumberOfConveyors() = 0;
	unsigned int getNumberOfConveyors();
	virtual void insertConveyor(kindOFConveyor) = 0;
	ConveyorBase* getConveyor();
	void displayNameOfConveyorInFactory();
};

class FactoryUI : virtual public FactoryAbstract
{
public:
	void setName();
	void setNumberOfConveyors();
	void insertConveyor(kindOFConveyor);
};


#endif