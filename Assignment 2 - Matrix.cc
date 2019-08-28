//CPSC 2620
//File: Matrix.h
//This is an implementation file for Matrix class.
//Author: Queenie Zhao
//Date: Jan 31, 2019

#include "./Matrix.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <iomanip>

using namespace std;

//*************************************************************************************************************
// Function: Default constructor
// Sets all undeclared values of a Matrix variable to 2 x 2
//*************************************************************************************************************

Matrix::Matrix(int m, int n)
   : rows{m}, cols{n} //initialization list
{
   A = new int *[rows];
   for (int i = 0; i < rows; i++) {
 	 
  	A[i] = new int [cols];

  	for (int j = 0; j < cols; j++)
     A[i][j] = 0;
   }
}

//*************************************************************************************************************
// Function: Gets dimension of m and n
// Returns dimension of matrix through reference
//*************************************************************************************************************

void Matrix::getDimensions(int& m, int& n)
{
   m = rows;
   n = cols;
}

//*************************************************************************************************************
// Function: This function takes in the indices i and j and returns a reference to that element
//
//*************************************************************************************************************
int& Matrix::element(int i, int j)
{
   assert(i <= rows);
   assert(j <= cols);
 	 
   // int *p = new int;

   return A[i][j];

}

//*************************************************************************************************************
// Function:
//
//*************************************************************************************************************
const int& Matrix::constElement(int i, int j) const
{
   assert(i <= rows);
   assert(j <= cols);
   
   return A[i][j];
}

//*************************************************************************************************************
// Function: This function adds two matrices together and changes A
//*************************************************************************************************************
void Matrix::add(const Matrix& M)
{
   assert(rows == M.rows);
   assert(cols == M.cols);
   
   for(int i = 0; i < rows; i++)
 	 
  	for(int j = 0; j < cols; j++)

     A[i][j] += M.A[i][j];
}

//*************************************************************************************************************
// Function: This function subtracts M from A and changes A
//*************************************************************************************************************
void Matrix::subtract(const Matrix& M)
{
   assert(rows == M.rows);
   assert(cols == M.cols);
   
   for(int i = 0; i < rows; i++)
 	 
  	for(int j = 0; j < cols; j++)

     A[i][j] -= M.A[i][j];
}

//*************************************************************************************************************
// Function: This function multiplies two matrices of compatible dimensions together, and returns their product
// Compatible dimensions: If A is p x q and B is q x r, their product is C with dimensions of p x r
//*************************************************************************************************************
Matrix Matrix::multiply(const Matrix& B) const
{
   assert(cols == B.rows);

   Matrix C(rows, B.cols);
   
   for(int i = 0; i < rows; i++)
 	 
  	for(int j = 0; j < B.cols; j++)

     for(int k = 0; k < cols; k++)

    	C.element(i,j) += constElement(i,k) * B.constElement(k,j);
   
   
   return C;
}

//*************************************************************************************************************
// Function: Reads in the matrix dimensions and then the individual numbers within the matrix
// Does not include deallocating memory code
//*************************************************************************************************************
void Matrix::read()
{
   cout << "Please enter your matrix dimensions(ie. m n): ";
   cin >> rows >> cols;

   if (rows > 0 && cols > 0) {
 	 
  	cout << "Enter the numbers in your matrix indicated." << endl;
 	 
  	A = new int *[rows];
   
  	for(int i = 0; i < rows; i++) {
 	 
     A[i] = new int [cols];
   
     for(int j = 0; j < cols; j++) {

    	cout << "(" << i << "," << j << "): ";
    	cin >> A[i][j];
     }
  	}
   }

   else
  	cout << "Dimensions are out of bounds (must be positive), please try again." << endl;
}

//*************************************************************************************************************
// Function: Writes out the matrix m x n in row-major form
//
//*************************************************************************************************************
void Matrix::write() const
{
   int count = 0;
   
   for(int i = 0; i < rows; i++)
 	 
  	for(int j = 0; j < cols; j++) {

     if(i > count) {
    	cout << endl;
    	count++;
     }
    
     cout << setw(4) << A[i][j];
  	}
   cout << endl;
}
