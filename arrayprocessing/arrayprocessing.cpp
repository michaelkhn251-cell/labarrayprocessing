#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  constexpr int maxSize = 20;
  constexpr int maxMagnitude = 1000;
  constexpr int matrixFieldWidth = 10;
  constexpr int averageFieldWidth = 12;
  constexpr int outputPrecision = 2;

  double matrix[maxSize][maxSize];
  double rowAverages[maxSize];
  int rowCount;
  int columnCount;
  int minAverageRowIndex;
  int maxAverageRowIndex;
  double rowSum;
  double tempValue;

  cout << "Enter number of rows and columns (1 to 20): ";
  if (!(cin >> rowCount >> columnCount) || rowCount < 1 || rowCount > maxSize || columnCount < 1 || columnCount > maxSize) {
    cout << "INVALID\n";
    return 1;
  }

  cout << "Enter matrix elements:\n";
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      if (!(cin >> matrix[rowIndex][columnIndex]) || matrix[rowIndex][columnIndex] < -maxMagnitude || matrix[rowIndex][columnIndex] > maxMagnitude) {
        cout << "INVALID\n";
        return 1;
      }
    }
  }

  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    rowSum = 0.0;
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      rowSum += matrix[rowIndex][columnIndex];
    }
    rowAverages[rowIndex] = rowSum / columnCount;
  }

  minAverageRowIndex = 0;
  maxAverageRowIndex = 0;

  for (int rowIndex = 1; rowIndex < rowCount; ++rowIndex) {
    if (rowAverages[rowIndex] < rowAverages[minAverageRowIndex]) {
      minAverageRowIndex = rowIndex;
    }
    if (rowAverages[rowIndex] > rowAverages[maxAverageRowIndex]) {
      maxAverageRowIndex = rowIndex;
    }
  }

    cout << "\nOriginal matrix and row averages:\n";
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
      for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
          cout << setw(matrixFieldWidth) << fixed << setprecision(outputPrecision) << matrix[rowIndex][columnIndex];
      }
      cout << setw(averageFieldWidth) << fixed << setprecision(outputPrecision) << rowAverages[rowIndex] << "\n";
    }

    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      tempValue = matrix[minAverageRowIndex][columnIndex];
      matrix[minAverageRowIndex][columnIndex] = matrix[maxAverageRowIndex][columnIndex];
      matrix[minAverageRowIndex][columnIndex] = tempValue;
    }

    cout << "\nModified matrix: \n";
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
      for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
        cout << setw(matrixFieldWidth) << fixed << setprecision(outputPrecision) << matrix[rowIndex][columnIndex];
      }
      
      if (rowIndex < rowCount - 1) {
        cout << "\n";
      }
    }

    return 0;
}