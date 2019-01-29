#include "stdafx.h"
#include "CppUnitTest.h"
#include "../OOP_Exercise_DLVN_App/Class.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OOP_Exercise_DLVN
{
	// Class Conveyor test
	class NormalConveyorTest : public ConveyorBase
	{
	public:
		static unsigned int _count;
		NormalConveyorTest()
		{
			_count++;
		}
		void setNameForConveyor()
		{
			nameOfConveyor = "Normal"+to_string(_count);
		}
	};
	unsigned int NormalConveyorTest::_count = 0;

	// Class Factory test
	class FactoryTest : public FactoryAbstract
	{
	public:
		void setName()
		{
			nameOfFactory = "DLVN";
		}
		void setNumberOfConveyors()
		{
			numberOfConveyors = 3;
		}
		void insertConveyor(kindOFConveyor kOC)
		{
			switch (kOC)
			{
			case Normal:
				conveyor = new NormalConveyorTest;
				break;
			default:
				break;
			}
			conveyor->setNameForConveyor();
			conveyor->next = head;
			head = conveyor;
		}
	};

	TEST_CLASS(ManageFactoryTest)
	{
	private:
		FactoryAbstract *CandyFactory = new FactoryTest;
	public:
		string GetNameOfConveyorFromFactory()
		{
			return CandyFactory->getConveyor()->getName();
		}

		TEST_METHOD(canInsertMultipleConveyors)
		{
			CandyFactory->setName();
			Assert::IsTrue(CandyFactory->getName() == "DLVN");
			CandyFactory->setNumberOfConveyors();
			Assert::IsTrue(CandyFactory->getNumberOfConveyors() == 3);
			for (unsigned int i = 0; i < CandyFactory->getNumberOfConveyors(); i++)
			{
				CandyFactory->insertConveyor(Normal);
				Assert::IsTrue(GetNameOfConveyorFromFactory() == "Normal" + to_string(NormalConveyorTest::_count));
				if (i == CandyFactory->getNumberOfConveyors())
				{
					ConveyorBase *ptr;
					ptr = CandyFactory->getConveyor(); // ptr = head
					for (unsigned j = i; j > 0; j--)
					{
						Assert::IsTrue(ptr->getName() == "Normal"+to_string(j));
						if (j == 0)
						{
							Assert::IsTrue(ptr == NULL);
						}
					}
				}
			}
		}


	};
}