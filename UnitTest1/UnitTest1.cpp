#include "pch.h"
#include "CppUnitTest.h"
#include "../PR 10.2/PR 10.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectTests
{
    TEST_CLASS(YourFileTests)
    {
    public:

        TEST_METHOD(TestDeleteBetweenBrackets)
        {
            // Вхідні дані
            std::string testString1 = "This is a (test) string.";
            std::string testString2 = "No brackets here.";
            std::string testString3 = "(Nested (brackets) are (here)).";

            // Очікуваний результат
            std::string expected1 = "This is a  string.";
            std::string expected2 = "No brackets here.";
            std::string expected3 = ".";

            // Виклик функції deleteBetweenBrackets
            std::string result1 = deleteBetweenBrackets(testString1);
            std::string result2 = deleteBetweenBrackets(testString2);
            std::string result3 = deleteBetweenBrackets(testString3);

            // Перевірка результатів
            Assert::IsTrue(expected1 == result1, L"Test 1 failed");
            Assert::IsTrue(expected2 == result2, L"Test 2 failed");
            Assert::IsTrue(expected3 == result3, L"Test 3 failed");
        }
    };
}


