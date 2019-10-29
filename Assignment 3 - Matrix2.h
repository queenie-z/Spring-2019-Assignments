//CPSC 2620
//File: Matrix2.h
//This is a header file for Matrix class.
//The matrix is defined by m x n.
//Author: Queenie Zhao
//Date: Feb 13, 2019

#ifndef MATRIX_H
#define MATRIX_J
#include <iostream>

using namespace std;

template <typename T>
class Matrix
{
  public:
   
   //The -structors
   Matrix(int m = 2, int n = 2); //Default constructor. m = n = 2, all values are set to zero.
   Matrix(const Matrix&); //Copy constructor.
   ~Matrix(); //Destructor.

   //Operator Overloading
   Matrix& operator=(const Matrix&); //Overloading assignment operator.

   //Getting info from a matrix
   void getDimensions(int& m, int& n) const; //Returns the dimensions of the matrix.
   T& operator()(int, int); //Replaces element.
   const T& operator()(int, int) const; //Replaces const version of element.

   //Add, subtract, and multiply overloading
   const Matrix& operator+=(const Matrix&); //+= operator overloading.
   const Matrix& operator-=(const Matrix&); //-= operator overloading.
   const Matrix& operator*=(const Matrix&); //*= operator overloading.

   Matrix operator+(const Matrix&) const; //+ operator overloading.
   Matrix operator-(const Matrix&) const; //- operator overloading.
   Matrix operator*(const Matrix&) const; //* operator overloading.

   //Read and write overloading
   friend istream& operator>>(istream&, Matrix&);
   friend ostream& operator<<(ostream&, const Matrix&);

   
  private:
   int rows;
   int cols;
   T **A;

   void setSize(int, int); //Private Helper function
};

#include "./Matrix2.cc"
#endif
