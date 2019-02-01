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
			nameOfConveyor = "normal" + to_string(_count);
		}
	};
	unsigned int NormalConveyorTest::_count = 0;

	// Class Factory test
	class FactoryTest : public FactoryAbstract
	{
	public:
		void setNameForFactory()
		{
			nameOfFactory = "DLVN";
		}
		void setNumberOfConveyors()
		{
//			numberOfProductConveyors = 3;
		}
#if 0
		void insertConveyor(kindOFConveyor kOC)
		{
			switch (kOC)
			{
			case normal:
				conveyor = new NormalConveyorTest;
				break;
			default:
				break;
			}
			conveyor->setNameForConveyor();
			conveyor->setNextConveyor(head);
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
		TEST_METHOD(canSetNameForFactory)
		{
			CandyFactory->setNameForFactory();
			Assert::IsTrue(CandyFactory->getName() == "DLVN");
		}

		TEST_METHOD(canSetNumberOfConveyorInFactory)
		{
			CandyFactory->setNumberOfConveyors();
			Assert::IsTrue(CandyFactory->getNumberOfConveyors() == 3);
		}

		TEST_METHOD(canInsertOneConveyor)
		{
			CandyFactory->insertConveyor(normal);
			Assert::IsTrue(GetNameOfConveyorFromFactory() == "Normal1");
			Assert::IsTrue(NormalConveyorTest::_count == 1);
		}

		TEST_METHOD(canInsertMultipleConveyors)
		{
			CandyFactory->setNumberOfConveyors();
			for (unsigned int i = 0; i < CandyFactory->getNumberOfConveyors(); ++i)
			{
				CandyFactory->insertConveyor(normal);
				Assert::IsTrue(GetNameOfConveyorFromFactory() == "normal" + to_string(NormalConveyorTest::_count));
			}
		}


	};
#endif 
	};
}