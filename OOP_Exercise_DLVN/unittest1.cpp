#include "stdafx.h"
#include "CppUnitTest.h"
#include "../OOP_Exercise_DLVN_App/Class.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OOP_Exercise_DLVN
{		
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
	};

	TEST_CLASS(ManageFactoryTest)
	{
	private:
		FactoryAbstract *CandyFactory = new FactoryTest;
	public:
		TEST_METHOD(canSetNameForFactory)
		{
			CandyFactory->setName();
			Assert::IsTrue(CandyFactory->getName() == "DLVN");
		}

		TEST_METHOD(canSetNumberOfConveyorInFactory)
		{
			CandyFactory->setNumberOfConveyors();
			Assert::IsTrue(CandyFactory->getNumberOfConveyors() == 3);
		}
	};
}