//CPSC 2620
//File: calc.cc
//This is a client file used to test the Matrix class
//Author: Queenie Zhao
//Date: Feb 13, 2019

#include "./Matrix.h"
#include <iostream>

using namespace std;

int main () {

   Matrix A, B, C;
   int r1, c1;

   //Reading in matrices A, B, and C.
   cout << "Now executing cin >> A:" << endl;
   cin >> A;
   cout << "Now executing cin >> B:" << endl;
   cin >> B;
   cout << "Now executing cin >> C:" << endl;
   cin >> C;
   
   //Creating matrix D and initializes all elements of A to D, then all entries of the first column to zero.
   A.getDimensions(r1, c1);
   Matrix D(r1, c1);

   for(int i = 0; i < r1; i++)
  	for(int j = 0; j < c1; j++)
     D(i, j) = A(i, j);
   for(int i = 0; i < r1; i++)
  	D(i, 0) = 0;

   //Printing matrices A, B, C, and D.
   cout << "A is:" << endl
    << A << endl;

   cout << "B is:" << endl
    << B << endl;

   cout << "C is:" << endl
    << C << endl;

   cout << "D is:" << endl
    << D << endl;


   //Creating matrix G from dimensions of A
   Matrix G(r1, c1);

   //Executing and printing A + B.
   cout << "After G = A + B, the sum (G) is now:" << endl;
   G = A + B;

   cout << G << endl;

   //Printing matrix A to let user know it has not changed.
   cout << "And A is still:" << endl;
   cout << A << endl;

   //Printing matrix B to let user know it has not changed.
   cout << "And B is still:" << endl;
   cout << B << endl;

   //************************************************************************************************
   
   //Creating matrix E and initialize dimensions to row of A and column of C.
   int r3, c3;
   C.getDimensions(r3, c3);
   Matrix E(r1, c3);

   //Executing and printing A * C - A.
   cout << "After E = A * C - A, the new product (E) is: " << endl;
   E = A * C - A;
   
   cout << E << endl;

   //Printing matrices used, A, C, and D, to let user know they have not changed.
   cout << "A is still:" << endl;
   cout << A << endl;

   cout << "C is still:" << endl;
   cout << C << endl;

   cout << "D is still:" << endl;
   cout << D << endl;

   //************************************************************************************************
   
   //Creating matrix F and initialize dimensions to row of A and column of C.
   Matrix F(r1, c3);

   //Executing and printing (A + D) * C (without operator overloading).
   cout << "After F = (A + D) * C, the new product (F) is: " << endl;
   F = (A + D) * C;

   cout << F << endl;
   
   //Printing matrices used, A, C, and D, to let user know they have not changed.
   cout << "A is still:" << endl;
   cout << A << endl;
   
   cout << "C is still:" << endl;
   cout << C << endl;
   
   cout << "D is still:" << endl;
   cout << D << endl;

   //************************************************************************************************

   if (r1 == c1) {

  	int n;
 	 
  	cout << "A is a square matrix, please enter a positive integer (n): ";
  	cin >> n;

  	Matrix temp(r1, c1);
  	temp = A;
 	 
  	for (int i = 1; i < n; i++)
     A *= temp;    
 	 
  	cout << "A to the power of " << n << " is: "
   	<< endl << A;
   }
    
   else
  	cout << "A is not a square matrix." << endl;
   
   return 0;
}
