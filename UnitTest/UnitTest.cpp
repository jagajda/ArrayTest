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
			unsigned int i = 1;
			const wchar_t* msg = L"Constructor failed";
			Array<int> arr = Array<int>(i);
			Assert::IsNull(arr.getPointer());
		}
		TEST_METHOD(TestSetter)
		{
			Array<int> arr = Array<int>(1);
			arr.Set(0, 0);
			const wchar_t* msg = L"Attempting array out of range";
			Assert::AreEqual(arr.Get(1), 0, msg);
		}
	};
}
