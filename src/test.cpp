#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "matrix_cpp.hpp"

const double arr1[9] = {1, 2, 1, 4, 2, 2, 0, 1, 7};
const double arr2[9] = {7, 5, 1, 2, 1, 2, 4, 3, 4};
const double arr3[9] = {6, 3, 0, 4, 1, -3, -2, -3, 2};

TEST(matrix, determinant_1) {
  Matrix_cpp A4(arr3, 9, 3, 3);
  EXPECT_EQ(A4.Determinant(), -48);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  // ::testing::InitGoogleMock(&argc, argv);

  return RUN_ALL_TESTS();
}

#if 0
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
  std::cout << A6 << std::endl;
  std::cout << A6.Determinant() << std::endl;
  std::cout << A6.CalcComplements() << std::endl;
  double arr7[16] = {1, 2, -1, 0, 3, 1, 0, -4, -2};
  Matrix_cpp inv(arr7, 9, 3, 3);

  std::cout << inv << std::endl;
  std::cout << inv.Transpose() << std::endl;
  std::cout << inv.InverseMatrix() << std::endl;
  std::cout << A1 + A2 << std::endl;
}
#endif