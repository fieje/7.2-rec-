#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2(rec)/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCreateMatrix)
		{
			const int k = 3;
			const int n = 4;
			int** matrix = new int* [k];
			for (int i = 0; i < k; ++i) {
				matrix[i] = new int[n];
			}

			createMatrix(matrix, k, n);

			bool isValid = true;
			for (int i = 0; i < k; ++i) {
				for (int j = 0; j < n; ++j) {
					if (matrix[i][j] < 0 || matrix[i][j] >= 100)
					{
						isValid = false;
						break;
					}
				}
			}

			Assert::IsTrue(isValid);

			for (int i = 0; i < k; ++i) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}

		TEST_METHOD(TestFindMinInEvenColumn)
		{
			const int k = 3;
			const int n = 4;
			int** matrix = new int* [k];
			for (int i = 0; i < k; ++i) {
				matrix[i] = new int[n];
			}

			matrix[0][0] = 10; matrix[0][1] = 20; matrix[0][2] = 30; matrix[0][3] = 40;
			matrix[1][0] = 50; matrix[1][1] = 60; matrix[1][2] = 70; matrix[1][3] = 80;
			matrix[2][0] = 90; matrix[2][1] = 100; matrix[2][2] = 110; matrix[2][3] = 120;

			int min = findMinInEvenColumn(matrix, k, n, 2);

			Assert::AreEqual(30, min);

			for (int i = 0; i < k; ++i) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}

		TEST_METHOD(TestFindMaxInPreviousOddColumn)
		{
			const int k = 3;
			const int n = 4;
			int** matrix = new int* [k];
			for (int i = 0; i < k; ++i) {
				matrix[i] = new int[n];
			}

			matrix[0][0] = 10; matrix[0][1] = 20; matrix[0][2] = 30; matrix[0][3] = 40;
			matrix[1][0] = 50; matrix[1][1] = 60; matrix[1][2] = 70; matrix[1][3] = 80;
			matrix[2][0] = 90; matrix[2][1] = 100; matrix[2][2] = 110; matrix[2][3] = 120;

			int max = findMaxInPreviousOddColumn(matrix, k, n, 2); 

			Assert::AreEqual(100, max);

			for (int i = 0; i < k; ++i) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}

		TEST_METHOD(TestProcessMatrix)
		{
			const int k = 3;
			const int n = 4;
			int** matrix = new int* [k];
			for (int i = 0; i < k; ++i) {
				matrix[i] = new int[n];
			}

			matrix[0][0] = 10; matrix[0][1] = 20; matrix[0][2] = 30; matrix[0][3] = 40;
			matrix[1][0] = 50; matrix[1][1] = 60; matrix[1][2] = 70; matrix[1][3] = 80;
			matrix[2][0] = 90; matrix[2][1] = 100; matrix[2][2] = 110; matrix[2][3] = 120;

			processMatrix(matrix, k, n);

			Assert::AreEqual(90, matrix[0][1]);
			Assert::AreEqual(60, matrix[1][1]);
			Assert::AreEqual(100, matrix[2][1]);

			for (int i = 0; i < k; ++i) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}
	};
}
