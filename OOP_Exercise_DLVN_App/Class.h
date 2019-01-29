#ifndef CLASS_H
#define CLASS_H


#pragma once
#include <iostream>
#include <string>

using namespace std;
// Conveyor
typedef enum  
{
	Normal, Test, Encap
}kindOFConveyor;

class ConveyorBase
{
protected:
	string nameOfConveyor;
public:
	virtual void setNameForConveyor() = 0;
	string getName();
	ConveyorBase *next;
};

class NormalConveyorUI : public ConveyorBase
{
public:
	void setNameForConveyor();
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
};

class FactoryUI : virtual public FactoryAbstract
{
public:
	void setName();
	void setNumberOfConveyors();
	void insertConveyor(kindOFConveyor);
};


#endif