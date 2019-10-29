//CPSC 2620
//File: Matrix2.cc
//This is an implementation file for Matrix class.
//Author: Queenie Zhao
//Date: Feb 13, 2019

#include "./Matrix2.h"
#include <iostream>
#include <cassert>
#include <iomanip>

using namespace std;

//*************************************************************************************************************
// Function: Default constructor
// Sets all undeclared values of a Matrix variable to 2 x 2
//*************************************************************************************************************
template <typename T>
Matrix<T>::Matrix(int m, int n)
   : rows{m}, cols{n} //initialization list
{
   assert(m > 0);
   assert(n > 0);

   A = new T *[rows];
   for (int i = 0; i < rows; i++) {
 	 
  	A[i] = new T [cols];
  	for (int j = 0; j < cols; j++)
     A[i][j] = 0;
   }
}

//*************************************************************************************************************
// Function: Copy constructor
// Performs deep copy from one matrix to another
//*************************************************************************************************************
template <typename T>
Matrix<T>::Matrix(const Matrix& X)
   : rows{X.rows}, cols{X.cols} //initialization list
{
   A = new T *[X.rows];
   for (int i = 0; i < rows; i++) {
 	 
  	A[i] = new T [X.cols];
  	for (int j = 0; j < cols; j++)
     A[i][j] = X.A[i][j];
   }
}

//*************************************************************************************************************
// Function: DESTRUCTOR
// Deallocates heap memory when leaving scope
//*************************************************************************************************************
template <typename T>
Matrix<T>::~Matrix()
{
   for (int i = 0; i < rows; i++) {
  	delete[] A[i];
  	A[i] = nullptr;
   }

   delete[] A;
   A = nullptr;
}
 
//*************************************************************************************************************
// Function: Overloads assignment operator =
//
//*************************************************************************************************************
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& X)
{
   if (this != &X) {

  	for (int i = 0; i < rows; i++) {
     delete[] A[i];
     A[i] = nullptr;
  	}
  	delete[] A;
  	A = nullptr;

  	rows = X.rows;
  	cols = X.cols;

  	A = new T *[X.rows];
  	for (int i = 0; i < rows; i++) {
 	 
     A[i] = new T [X.cols];
     for (int j = 0; j < cols; j++)
    	A[i][j] = X.A[i][j];
  	}
   }
   return *this;
}

//*************************************************************************************************************
// Function: Private helper function to deallocate previous values of a matrix, sets dimensions to m x n, and
//       	initialize all entries to 0.
// Prevents code being repeated.
//*************************************************************************************************************
template <typename T>
void Matrix<T>::setSize(int m, int n)
{
   for (int i = 0; i < rows; i++) {
  	delete[] A[i];
  	A[i] = nullptr;
   }
   delete[] A;
   A = nullptr;
   A = new T *[m];

   rows = m;
   cols = n;

   A = new T *[rows];
   
   for (int i = 0; i < m; i++) {
  	A[i] = new T [n];
 	 
  	for (int j = 0; j < n; j++)
     A[i][j] = 0;
   }
}

//*************************************************************************************************************
// Function: Overloads assignment operator ()
// Takes in the indices i and j and returns a reference to that element
//*************************************************************************************************************
template <typename T>
T& Matrix<T>::operator()(int i, int j)
{
   assert(i <= rows);
   assert(j <= cols);
   
   return A[i][j];
}

//*************************************************************************************************************
// Function: Const version of operator() overloading
//
//*************************************************************************************************************
const T& Matrix<T>::operator()(int i, int j) const
{
   assert(i <= rows);
   assert(j <= cols);
   
   return A[i][j];
}

//*************************************************************************************************************
// Function: Gets dimension of m and n
// Returns dimension of matrix through reference
//*************************************************************************************************************
template <typename T>
void Matrix<T>::getDimensions(int& m, int& n) const
{
   m = rows;
   n = cols;
}

//*************************************************************************************************************
// Function: Overloads assignment operator +=
//
//*************************************************************************************************************
template <typename T>
const Matrix<T>& Matrix<T>::operator+=(const Matrix& M)
{
   assert(rows == M.rows);
   assert(cols == M.cols);

   for(int i = 0; i < rows; i++)
 	 
  	for(int j = 0; j < cols; j++)
    
     A[i][j] = A[i][j] + M.A[i][j];
   
   return *this;
}

//*************************************************************************************************************
// Function: Overloads assignment operator -=
//
//*************************************************************************************************************
template <typename T>
const Matrix<T>& Matrix<T>::operator-=(const Matrix& M)
{
   assert(rows == M.rows);
   assert(cols == M.cols);
   
   for(int i = 0; i < rows; i++)
 	 
  	for(int j = 0; j < cols; j++)
    
     A[i][j] = A[i][j] - M.A[i][j];

   return *this;
}

//*************************************************************************************************************
// Function: Overloads assignment operator *=
//
//*************************************************************************************************************
template <typename T>
const Matrix<T>& Matrix<T>::operator*=(const Matrix& M)
{
   assert(cols == M.rows);

   Matrix temp{*this};

   setSize(temp.rows, M.cols);

   for(int i = 0; i < rows; i++)
 	 
  	for(int j = 0; j < M.cols; j++)

     for(int k = 0; k < cols; k++)

    	A[i][j] += temp(i,k) * M(k,j);

   return *this;
}

//*************************************************************************************************************
// Function: Overloads assignment operator +
//
//*************************************************************************************************************
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& M) const
{
   assert(rows == M.rows);
   assert(cols == M.cols);
   
   Matrix temp{*this};

   temp += M;

   return temp;
}

//*************************************************************************************************************
// Function: Overloads assignment operator -
//
//*************************************************************************************************************
template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& M) const
{
   assert(rows == M.rows);
   assert(cols == M.cols);
   
   Matrix temp{*this};

   temp -= M;

   return temp;
}

//*************************************************************************************************************
// Function: Overloads assignment operator *
//
//*************************************************************************************************************
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& M) const
{
   assert(cols == M.rows);

   Matrix temp{*this};

   temp *= M;

   return temp;
}
   
//*************************************************************************************************************
// Function: Overloads assignment operator >>
// Replaces the read() function.
//*************************************************************************************************************
template <typename U>
istream& operator>>(istream& is, Matrix& M)
{
   cout << "Please enter your matrix dimensions(ie. m n): ";
   cin >> M.rows >> M.cols;

   if (M.rows > 0 && M.cols > 0) {

  	cout << "Enter the numbers in your matrix indicated." << endl;
 	 
  	M.A = new U *[M.rows];
   
  	for(int i = 0; i < M.rows; i++) {
 	 
     M.A[i] = new U [M.cols];
    
     for(int j = 0; j < M.cols; j++) {
      	 
    	cout << "(" << i << "," << j << "): ";
    	cin >> M.A[i][j];
     }
  	}
  	cout << endl;
   }

   else
  	cout << "Dimensions are out of bounds (must be positive), please try again." << endl;

   return is;
}

//*************************************************************************************************************
// Function: Overloads assignment operator <<
// Replaces the write() function.
//*************************************************************************************************************
template <typename U>
ostream& operator<<(ostream& os, const Matrix& M)
{
   int count = 0;
   
   for(int i = 0; i < M.rows; i++)
 	 
  	for(int j = 0; j < M.cols; j++) {

     if(i > count) {
    	cout << endl;
    	count++;
     }
    
     cout << setw(4) << M.A[i][j];
  	}
   
   cout << endl;

   return os;
}
