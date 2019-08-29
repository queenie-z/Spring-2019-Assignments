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
  private:
   int rows;
   int cols;
   int **thisMatrix;
  
  public:
   
   Matrix(int m = 2, int n = 2); //Default constructor. m = n = 2, all values are set to zero.

   void getDimen(int& m, int& n);
  
   int& returnElemAt(int i, int j);
   const int& constElemAt(int i, int j) const;

   void addMatrixOfSameDimen(const Matrix& M);
   void subtractMatrixOfSameDimen(const Matrix& M);
   Matrix multiplyMatrices(const Matrix& M)const;
  
   void assembleMatrix(); 
   void printMatrix() const; //Prints out matrix numbers with cout
   
};

#endif
