#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <utility>
#include <cassert>

template<typename T>
struct matrix{
  public:
    // default
    matrix() : row(2), col(2), mat(2, std::vector<T>(2)) {}
    // empty matrix with given size
    explicit matrix(int r, int c) : row(r), col(c), mat(r, std::vector<T>(c)) {}
    // matrix with 2D array
    explicit matrix(const std::vector<std::vector<T>> &data) : row(data.size()), col(data.empty() ? 0 : data[0].size()), mat(data) {}

    // size
    std::pair<int, int> size() const {
      return {row, col};
    }

    // access
    const T& operator()(int i, int j) const {
      return mat[i][j];
    }

    // modification
    T& operator()(int i, int j){
      return mat[i][j];
    }
    
    // multiplication under modulo m
    template<typename U, typename V>
    static matrix<U> multiply_modulo(const matrix<U> &a, const matrix<U> &b, const V m){
      assert(a.size().second == b.size().first);
      matrix<U> r = matrix(a.size().first, b.size().second);
      for(int i = 0; i < r.size().first; i++){
        for(int j = 0; j < r.size().second; j++){
          for(int k = 0; k < a.size().second; k++){
            r(i,j) = (r(i,j) + (a(i, k) % m * b(k, j) % m) % m) % m;
          }
        }
      }
      return r;
    }
    
    // power raised to n
    template<typename U, typename V>
    static matrix<U> matpow(matrix<U> a, V n){
      assert(a.size().first == a.size().second);
      matrix<U> r = matrix<U>::eye(a.size().first);
    
      while(n){
        if(n&1)
          r = r * a;
        a = a * a;
        n >>= 1;
      }
      return r;
    }

    // power raised to n under modulo m
    template<typename U, typename V, typename W>
    static matrix<U> matpow_modulo(matrix<U> a, V n, W m){
      assert(a.size().first == a.size().second);
      matrix<U> r = matrix<U>::eye(a.size().first);
    
      while(n){
        if(n&1)
          r = multiply_modulo(r, a, m);
        a = multiply_modulo(a , a, m);
        n >>= 1;
      }
      return r;
    }
  
    // identity matrix of size n
    static matrix<T> eye(int n) {
      if (n <= 0) {
        return matrix<T>(0, 0);
      }
      matrix<T> identity(n, n);
      for (int i = 0; i < n; ++i) {
        identity(i, i) = static_cast<T>(1);
      }
      return identity;
    }


  private:
    std::vector<std::vector<T>> mat;
    int row;
    int col;
};

// multiplication operation
template<typename U>
matrix<U> operator *(const matrix<U> &a, const matrix<U> &b){
  assert(a.size().second == b.size().first);
  matrix<U> r = matrix<U>(a.size().first, b.size().second);
  for(int i = 0; i < r.size().first; i++){
    for(int j = 0; j < r.size().second; j++){
      for(int k = 0; k < a.size().second; k++){
        r(i,j) += a(i, k) * b(k, j);
      }
    }
  }
  return r;
}

#endif