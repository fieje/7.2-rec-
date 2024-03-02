#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void createMatrix(int** matrix, const int k, const int n) 
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 100; 
        }
    }
}

int findMinInEvenColumn(int** matrix, const int k, const int n, const int column)
{
    int minVal = matrix[0][column];
    for (int i = 1; i < k; ++i) {
        if (matrix[i][column] < minVal) {
            minVal = matrix[i][column];
        }
    }
    return minVal;
}

int findMaxInPreviousOddColumn(int** matrix, const int k, const int n, const int column)
{
    int maxVal = INT_MIN;
    if (column > 0) { 
        for (int i = 0; i < k; ++i) {
            if (matrix[i][column - 1] > maxVal) 
            {
                maxVal = matrix[i][column - 1];
            }
        }
    }
    return maxVal;
}

void swapElements(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void processMatrix(int** matrix, const int k, const int n)
{
    for (int j = 1; j < n; j += 2) {
        int minVal = findMinInEvenColumn(matrix, k, n, j);
        int maxVal = findMaxInPreviousOddColumn(matrix, k, n, j);
        for (int i = 0; i < k; ++i) {
            if (matrix[i][j] == minVal) {
                matrix[i][j] = maxVal;
                break;
            }
        }
        for (int i = 0; i < k; ++i) {
            if (matrix[i][j - 1] == maxVal) {
                matrix[i][j - 1] = minVal;
                break;
            }
        }
    }
}


void printMatrix(int** matrix, const int k, const int n) {
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int k, n;
    cout << "Enter the number of rows (k): ";
    cin >> k;
    cout << "Enter the number of columns (n): ";
    cin >> n;

    int** matrix = new int* [k];
    for (int i = 0; i < k; ++i) {
        matrix[i] = new int[n];
    }

    createMatrix(matrix, k, n);

    cout << "Original matrix:" << endl;
    printMatrix(matrix, k, n);

    processMatrix(matrix, k, n);

    cout << "Matrix after processing:" << endl;
    printMatrix(matrix, k, n);

    for (int i = 0; i < k; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
