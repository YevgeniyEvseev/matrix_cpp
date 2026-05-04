#include "matrix_cpp.hpp"

int main() {
  double arr1[9] = {1, 2, 1, 4, 2, 2, 0, 1, 7};
  double arr2[9] = {7, 5, 1, 2, 1, 2, 4, 3, 4};
  Matrix_cpp A1(arr1, 9, 3, 3);
  Matrix_cpp A2(arr2, 9, 3, 3);
  Matrix_cpp A3 = A1;
  A3.MulMatrix(A2);
  std::cout << A1 << std::endl;
  std::cout << A2 << std::endl;
  std::cout << A3 << std::endl;
  double arr3[9] = {6, 3, 0, 4, 1, -3, -2, -3, 2};
  Matrix_cpp A4(arr3, 9, 3, 3);
  std::cout << A4.Determinant() << std::endl;
  double arr4[9] = {7, -3, 5, 5, 2, 1, 2, -1, 3};
  Matrix_cpp A5(arr4, 9, 3, 3);
  std::cout << A5.Determinant() << std::endl;
  double arr5[16] = {3, -3, -5, 8, -3, 2, 4, -6, 2, -5, -7, 5, -4, 3, 5, -6};
  Matrix_cpp A6(arr5, 16, 4, 4);
  std::cout << A6.Determinant() << std::endl;
}