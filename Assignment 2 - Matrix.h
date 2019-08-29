//CPSC 2620
//File: Matrix.h
//This is a header file for Matrix class.
//The matrix is defined by m x n.
//Author: Queenie Zhao
//Date: Jan 31, 2019

#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

using namespace std;

class Matrix
{
  public:
   
   Matrix(int m = 2, int n = 2); //Default constructor. m = n = 2, all values are set to zero.

   void getMxNDimen(int& m, int& n);

   int& element(int i, int j);
   const int& constElement(int i, int j) const;

   void add(const Matrix& M); //Adds two matrices of the same parameters together.
   void subtract(const Matrix& M); //Subtracts a matrix from another, both with the same parameters.
   Matrix multiply(const Matrix& M)const; //Multiplies two matrices together.

   void read(); //Reads in matrix numbers with cin
   void write() const; //Prints out matrix numbers with cout
   

  private:
   int rows;
   int cols;
   int **A;

};

#endif
