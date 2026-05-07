#ifndef MATRIX_CPP_HPP
#define MATRIX_CPP_HPP

#include <iostream>

class Matrix_cpp {
 private:
  int rows_;
  int cols_;
  double** matrix;

  void set_value_mat(double* arr, int size_arr);
  void create_matr(int row, int col);
  void erase_matr();
  void copy_matrix(const Matrix_cpp& m);
  bool EqMatrix(const Matrix_cpp& other);

 public:
  Matrix_cpp() : rows_(0), cols_(0), matrix(nullptr) {}
  Matrix_cpp(double* m, int len, int r, int c);
  Matrix_cpp(const Matrix_cpp& m);
  Matrix_cpp& operator=(const Matrix_cpp& m);
  Matrix_cpp(Matrix_cpp&& m);
  Matrix_cpp& operator=(Matrix_cpp&& m);
  ~Matrix_cpp();

  Matrix_cpp& operator+=(const Matrix_cpp& other);
  Matrix_cpp& operator-=(const Matrix_cpp& other);
  Matrix_cpp& operator*=(const Matrix_cpp& other);

  Matrix_cpp operator+(const Matrix_cpp& op2) const;
  Matrix_cpp operator-(const Matrix_cpp& op2) const;
  Matrix_cpp operator*(const Matrix_cpp& op2) const;

  double operator()(int i, int j);
  bool operator==(const Matrix_cpp& op2);

      void SumMatrix(const Matrix_cpp& other);
  void SubMatrix(const Matrix_cpp& other);
  void MulNumber(const double num);
  void MulMatrix(const Matrix_cpp& other);
  Matrix_cpp Transpose();
  Matrix_cpp CalcComplements();
  double Determinant();
  Matrix_cpp component(int i, int j);
  Matrix_cpp InverseMatrix();

  friend std::ostream& operator<<(std::ostream& os, const Matrix_cpp& m);
  friend std::istream& operator>>(std::istream& is, Matrix_cpp& m);
};

#endif