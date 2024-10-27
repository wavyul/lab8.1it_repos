#include "pch.h"
#include "CppUnitTest.h"
#include "../LB8.1it/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(ChangeTest)
        {
            char str1[] = "This is a aa bb cc test string";
            char str2[] = "No triple asterisks here";
            char str3[] = "aaAnotherbbtestccstringaa";

            char* result1 = Change(str1);
            char* result2 = Change(str2);
            char* result3 = Change(str3);

            Assert::AreEqual("This is a *** *** *** test string", result1);
            Assert::AreEqual("No triple asterisks here", result2);
            Assert::AreEqual("***Another***test***string***", result3);
        }
    };
}
