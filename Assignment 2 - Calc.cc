//CPSC 2620
//File: Matrix.h
//This is a test file for the Matrix class to perform addition, subtraction, and multiplication.
//Author: Queenie Zhao
//Date: Jan 31, 2019

#include "./Matrix.h"
#include <iostream>

using namespace std;

int main () {

   Matrix A, B, C;
   int r1, c1;

   //Reading in matrices A, B, and C.
   cout << "Now executing A.read():" << endl;
   A.assembleMatrix();
   cout << "Now executing B.read():" << endl;
   B.assembleMatrix();
   cout << "Now executing C.read():" << endl;
   C.assembleMatrix();
   
   //Creating matrix D and initializes all elements of A to D, then all entries of the first column to zero.
   A.getDimen(r1, c1);
   Matrix D(r1, c1);

   for(int i = 0; i < r1; i++)
  	for(int j = 0; j < c1; j++)
     D.element(i, j) = A.element(i, j);
   for(int i = 0; i < r1; i++)
  	D.element(i, 0) = 0;

   //Printing matrices A, B, C, and D.
   cout << "A is:" << endl;
   A.write();
   cout << endl;
   cout << "B is:" << endl;
   B.write();
   cout << endl;
   cout << "C is:" << endl;
   C.write();
   cout << endl;
   cout << "D is:" << endl;
   D.write();
   cout << endl;

   //Executing and printing A + B (without operator overloading).
   cout << "After A.add(B), A is now:" << endl;
   A.addMatrixOfSameDimen(B);
   A.write();
   cout << endl;
   //Printing matrix B to let user know it has not changed.
   cout << "And B is still:" << endl;
   B.write();
   cout << endl;

   //Creating matrix E and initialize dimensions to row of A and column of C.
   int r2, r3, c2, c3;
   A.getDimensions(r2, c2);
   C.getDimensions(r3, c3);
   Matrix E(r2, c3);

   //Executing and printing A * C - A (without operator overloading).
   cout << "After E = A.multiply(C) and E.subtract(A), the new product E is: " << endl;
   E = A.multiplyMatrices(C);
   E.subtractMatrixOfSameDime(A);
   E.write();
   cout << endl;

   //Printing matrices used, A, C, and D, to let use know they have not changed.
   cout << "A is still:" << endl;
   A.write();
   cout << endl;
   cout << "C is still:" << endl;
   C.write();
   cout << endl;
   cout << "D is still:" << endl;
   D.write();
   cout << endl;
   
   //Creating matrix F and initialize dimensions to row of A and column of C.
   int r4, r5, c4, c5;
   A.getDimen(r4, c4);
   C.getDimen(r5, c5);
   Matrix F(r4, c5);

   //Executing and printing (A + D) * C (without operator overloading).
   cout << "After A.add(D) and F = A.multiply(C), the new product F is: " << endl;
   A.addMatrixOfSameDimen(D);
   F = A.multiplyMatrices(C);
   F.write();
   cout << endl;
   
   //Printing matrices used. A have changed while C and D remains the same.
   cout << "A is now:" << endl;
   A.write();
   cout << endl;
   cout << "C is still:" << endl;
   C.write();
   cout << endl;
   cout << "D is still:" << endl;
   D.write();
   cout << endl;

   return 0;
}
