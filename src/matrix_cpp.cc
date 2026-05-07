#include "matrix_cpp.hpp"

void Matrix_cpp::copy_matrix(const Matrix_cpp& m) {
  for (int i = 0; i < cols_; ++i) {
    for (int j = 0; j < rows_; ++j) {
      matrix[i][j] = m.matrix[i][j];
    }
  }
}

void Matrix_cpp::set_value_mat(double* arr, int size_arr) {
  int size_matr = rows_ * cols_;
  if (size_matr > size_arr) {
    std::out_of_range("size array is less size of matrix");
  }
  for (int i = 0; i < cols_; ++i) {
    for (int j = 0; j < rows_; ++j) {
      matrix[i][j] = arr[i * rows_ + j];
    }
  }
}
void Matrix_cpp::create_matr(int r, int c) {
  if (r <= 0 || c <= 0)
    std::out_of_range("rows or cols is negative or equel 0 ");
  rows_ = r;
  cols_ = c;
  matrix = new double*[cols_];
  for (int i = 0; i < cols_; i++) {
    matrix[i] = new double[rows_];
  }
}
void Matrix_cpp::erase_matr() {
  for (int i = 0; i < cols_; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
  rows_ = cols_ = 0;
}

Matrix_cpp::~Matrix_cpp() { erase_matr(); }

Matrix_cpp::Matrix_cpp(double* m, int len, int r, int c) {
  create_matr(r, c);
  set_value_mat(m, len);
}
Matrix_cpp::Matrix_cpp(const Matrix_cpp& m) {
  create_matr(m.rows_, m.cols_);
  copy_matrix(m);
}
Matrix_cpp& Matrix_cpp::operator=(const Matrix_cpp& m) {
  if (this == &m) return *this;
  erase_matr();
  create_matr(m.rows_, m.cols_);
  return *this;
}
Matrix_cpp::Matrix_cpp(Matrix_cpp&& m) {
  rows_ = m.rows_;
  cols_ = m.cols_;
  matrix = m.matrix;
  m.matrix = nullptr;
  m.cols_ = m.rows_ = 0;
}
Matrix_cpp& Matrix_cpp::operator=(Matrix_cpp&& m) {
  rows_ = m.rows_;
  cols_ = m.cols_;
  matrix = m.matrix;
  m.matrix = nullptr;
  m.cols_ = m.rows_ = 0;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix_cpp& m) {
  for (int i = 0; i < m.cols_; i++) {
    for (int j = 0; j < m.rows_; j++) {
      os << m.matrix[i][j] << ' ';
    }
    os << std::endl;
  }
  return os;
}
std::istream& operator>>(std::istream& is, Matrix_cpp& m) {
  int r, c;
  std::cout << "Enter count rows: ";
  is >> r;
  std::cout << "\nEnter count cols: ";
  is >> c;
  m.create_matr(r, c);
  for (int i = 0; i < m.cols_; i++) {
    for (int j = 0; j < m.rows_; j++) {
      std::cout << "Enter value cols=" << i << " rows=" << j;
      is >> m.matrix[i][j];
    }
  }
  return is;
}

bool Matrix_cpp::EqMatrix(const Matrix_cpp& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) return false;
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      if (matrix[i][j] != other.matrix[i][j]) return false;
    }
  }
  return true;
}

void Matrix_cpp::SumMatrix(const Matrix_cpp& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    std::invalid_argument("rows!=cols");
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      matrix[i][j] += other.matrix[i][j];
    }
  }
}

void Matrix_cpp::SubMatrix(const Matrix_cpp& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    std::invalid_argument("rows!=cols");
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      matrix[i][j] -= other.matrix[i][j];
    }
  }
}

void Matrix_cpp::MulNumber(const double num) {
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      matrix[i][j] *= num;
    }
  }
}

void Matrix_cpp::MulMatrix(const Matrix_cpp& other) {
  if (other.cols_ != rows_ || other.rows_ != cols_)
    std::logic_error(" rows_ or cols_ for op2 and this matrix is not equel");
  Matrix_cpp rotate_other;
  Matrix_cpp tmp;
  rotate_other.create_matr(other.cols_, other.rows_);
  tmp.create_matr(other.rows_, cols_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      rotate_other.matrix[i][j] = other.matrix[j][i];
    }
  }
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < other.rows_; j++) {
      for (int k = 0; k < rotate_other.rows_; k++)
        tmp.matrix[i][j] += matrix[i][k] * rotate_other.matrix[j][k];
    }
  }
  *this = std::move(tmp);
}

Matrix_cpp& Matrix_cpp::operator+=(const Matrix_cpp& other) {
  SumMatrix(other);
  return *this;
}

Matrix_cpp& Matrix_cpp::operator-=(const Matrix_cpp& other) {
  SubMatrix(other);
  return *this;
}

Matrix_cpp& Matrix_cpp::operator*=(const Matrix_cpp& other) {
  MulMatrix(other);
  return *this;
}

Matrix_cpp Matrix_cpp::Transpose() {
  Matrix_cpp res;
  res.create_matr(cols_, rows_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      res.matrix[i][j] = matrix[j][i];
    }
  }
  return res;
}

Matrix_cpp Matrix_cpp::CalcComplements() {
  Matrix_cpp res;
  res.create_matr(rows_, cols_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      Matrix_cpp tmp = component(i, j);
      double det = tmp.Determinant();
      int dop = ((i + j) % 2 == 0) ? 1 : -1;
      res.matrix[i][j] = dop * det;
    }
  }
  return res;
}

double Matrix_cpp::Determinant() {
  double res = 0;
  if (cols_ != rows_) std::invalid_argument("cols is no equel rows");
  if (cols_ < 10) {
    if (cols_ == 1) return matrix[0][0];
    if (cols_ == 2) {
      return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    for (int i = 0; i < rows_; i++) {
      Matrix_cpp M = component(0, i);
      int dop = (i % 2 == 0) ? 1 : -1;
      res += matrix[0][i] * dop * M.Determinant();
    }
  } else {
    return 0;
  }
  return res;
}

Matrix_cpp Matrix_cpp::component(int i_c, int j_c) {
  Matrix_cpp res;
  res.create_matr(rows_ - 1, cols_ - 1);
  int sign_cols = 0;
  for (int j = 0; j < cols_; j++) {
    int sign_rows = 0;
    if (j == i_c) {
      sign_cols = -1;
      continue;
    }
    for (int k = 0; k < rows_; k++) {
      if (k == j_c) {
        sign_rows = -1;
        continue;
      }
      res.matrix[j + sign_cols][k + sign_rows] = matrix[j][k];
    }
  }
  return res;
}

Matrix_cpp Matrix_cpp::InverseMatrix() {
  Matrix_cpp res = CalcComplements();
  double det = Determinant();
  res.MulNumber(1 / det);
  res = res.Transpose();
  return res;
}

Matrix_cpp Matrix_cpp::operator+(const Matrix_cpp& op2) const {
  Matrix_cpp res = *this;
  res.SumMatrix(op2);
  return res;
}

Matrix_cpp Matrix_cpp::operator-(const Matrix_cpp& op2) const {
  Matrix_cpp res = *this;
  res.SubMatrix(op2);
  return res;
}

Matrix_cpp Matrix_cpp::operator*(const Matrix_cpp& op2) const {
  Matrix_cpp res = *this;
  res.MulMatrix(op2);
  return res;
}

bool Matrix_cpp::operator==(const Matrix_cpp& op2) {
  if (op2.rows_ != rows_ || op2.cols_ != cols_) return false;
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      if (op2.matrix[i][j] = !matrix[i][j]) return false;
    }
  }
  return true;
}

double Matrix_cpp::operator()(int i, int j) {
  return matrix[i][j];
}