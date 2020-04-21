#include "pch.h"
#include "CppUnitTest.h"
#include "..\ArrayTest\Array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestConstructor)
		{
			unsigned int i = 0;
			const wchar_t* msg = L"Constructor failed";
			Array<int> arr = Array<int>(i);
			Assert::IsNotNull(arr.getPointer());
		}

		TEST_METHOD(TestSetter)
		{
			Array<int> arr = Array<int>(1);
			bool res = arr.Set(0, 0);
			const wchar_t* msg = L"Attempting array value out of range";
			Assert::AreNotEqual(arr.Get(1), 0, msg);
		}
	};
}
