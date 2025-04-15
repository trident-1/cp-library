# CP-Library

Library of useful templates for competitive programming

## Table of Contents
1. [Matrix](#Matrix)
   1. [Constructor](#constructor)
   2. [Access values in the matrix](#access)
   3. [Size](#size)
   4. [Multiplication operation](#multiply)
   5. [Multiplication under modulo M](#multiply_modulo)
   6. [Matrix power raised to n](#matpow)
   7. [Matrix power raised to n under modulo M](#matpow_modulo)

## Matrix

### Constructor <a name="constructor"></a>

#### Default
```cpp
matrix<typename T> m
matrix<typename T> m = matrix<typename T>()
```

- It creates a 2x2 matrix with all elements having intial value as $0$.

**complexity**

- $O(1)$

#### Constructor with size
```cpp
matrix<typename T>(int r, int c)
```
- It creates a matrix of $r$ rows and $c$ columns with all elements having intial value as $0$.


**constraints**

- $0 \leq r \leq 10^9$
- $0 \leq c \leq 10^9$

**complexity**

- $O(r \cdot c)$

#### Constructor with data
```cpp
matrix<typename T> m = matrix<typename T>(vector<vector<typename T>> v)
```

- It creates a matrix of given 2D vector which has number of rows $r$ and columns $c$

**constraints**

- $0 \leq r \leq 10^9$
- $0 \leq c \leq 10^9$

**complexity**

- $O(r \cdot c)$

### Access values in the matrix <a name="access"></a>

#### read
```cpp
typename<T> x = m(int i, int j)
```

- reads the value at (i, j) in the matrix.

**constraints**

- $0 \leq i < r$
- $0 \leq j < c$

**complexity**

- $O(1)$

#### write
```cpp
m(int i, int j) = (typename T) x
```

**constraints**

- $0 \leq i < r$
- $0 \leq j < c$

**complexity**

- $O(1)$

### Size <a name="size"></a>
```cpp
pair<int, int> m.size()
```

- It returns the size of the matrix as pair of number of rows $r$ and columns $c$.

**complexity**

- $O(1)$

### Multiplication operation <a name="multiply"></a>
```cpp
matrix<typename T> r = m1 * m2;
```

- Here m1 and m2 are matrices of type $T$ and their dimensions satisfy the requirement for matrix multiplication.<br>
i.e. number of columns $(c1)$ in first matrix $=$  number of rows $(r2)$ in second matrix 

**constraints**

- $c1 = r2$

**complexity**

- $O(k^3)$<br>
where $k$ is largest dimension of the given matrices

### Multiplication under modulo M <a name="multipy_modulo"></a>
```cpp
matrix<typename T> r = multipy_modulo(matrix <typename T> m1, matrix<typename T> m2, typename U M);
```

- Here in multiplication all values are computed under modulo m.<br>
i.e. all values in result matrix $0  \leq r_{ij} \lt m$

**constraints**

- $c1 = r2$

**complexity**

- $O(k^3)$<br>
where $k$ is largest dimension of the given matrices

### Matrix power raised to n <a name="matpow"></a>
```cpp
matrix<typename T> r = matpow(matrix <typename T> m1, typename U n);
```

- Computes the matrix power raise to n using binary exponentiation technique.

**constraints**
- Given matrix must be a square matrix. i.e. $r = c$

**complexity**
- $O(k^3 \cdot \log n)$<br>
  If complexity of multiplication is $O(k^3)$ and $k = r = c$

### Matrix power raised to n under modulo M <a name="matpow_modulo"></a>
```cpp
matrix<typename T> r = matpow_modulo(matrix <typename T> m1, typename U n, typename V M);
```

- Computes the matrix power raise to n under modulo M using binary exponentiation technique.
i.e. all values in result matrix $0  \leq r_{ij} \lt m$

**constraints**
- Given matrix must be a square matrix. i.e. $r = c$

**complexity**
- $O(k^3 \cdot \log n)$<br>
  If complexity of multiplication is $O(k^3)$ and  $k = r = c$

