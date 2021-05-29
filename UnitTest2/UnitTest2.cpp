#include "pch.h"
#include "CppUnitTest.h"
#include "../l_10_3/l_10_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			ofstream f("test.txt");
			Rep student;
			student.fiz = 3;
			student.math = 3;
			student.prog = 3;
			student.web = 3;
			student.elect = 3;
			f.write((char*)&student, sizeof(Rep));
			f.close();
			ifstream file("test.txt");
			bool x = StudThree("test.txt");
			Assert::AreEqual(x, true);
		}
	};
}
