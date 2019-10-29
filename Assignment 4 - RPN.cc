//******************************************************************************************************
// CPSC 2620
// File: RPN.cc
// This is a program that mimics the Reverse Polish Notation using the STL
// Author: Queenie Zhao
// Date: March 6th, 2019
//******************************************************************************************************

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main () {

   char repeat;
   
   do {
 	 
  	stack<int> st;
  	string s, forPrinting;
 	 
  	string space = " "; //To remember the string read.
  	int left, right, ans; //For arithmetic operations.
 	 
  	cout << "Enter arithmetic expressions with spaces between each character, ending with a period:" << endl;
   
  	while(cin >> s && s != ".")
  	{
     forPrinting += s + space; //To keep track of expression entered.

     //For all three of +, -, and * a check is put in place in case less than 2 numbers are entered.
    
     if (s == "+")
     {
    	if (st.size() > 1)
    	{
       	right = st.top();
       	st.pop();
       	left = st.top();
       	st.pop();
       	ans = left + right;
       	st.push(ans);
    	}
    	else
       	cout << "INVALID EXPRESSION (Error at +)" << endl;
     }
    
     else if (s == "-")
     {
    	if (st.size() > 1)
    	{
       	right = st.top();
       	st.pop();
       	left = st.top();
       	st.pop();
       	ans = left - right;
       	st.push(ans);
    	}
   	 
    	else
       	cout << "INVALID EXPRESSION (Error at -)" << endl;
     }
    
     else if (s == "*")
     {
    	if (st.size() > 1)
    	{
       	right = st.top();
       	st.pop();
       	left = st.top();
       	st.pop();
       	ans = left * right;
       	st.push(ans);
    	}
   	 
    	else
       	cout << "INVALID EXPRESSION (Error at *)" << endl;
     }
    
     else
     {
    	st.push(stoi(s));
     }
  	}

  	//Printing of stack, or if there is not exactly 1 item left then INVALID EXPRESSION.
  	if (st.size() == 1)
     cout << "Result of RPN: " << forPrinting << " is " << ans << endl;
  	else
     cout << "INVALID EXPRESSION" << endl;
 	 
  	//Asking the user to repeat or end program.
  	cout << "Would you like to try again (Y/N)? ";
  	cin >> repeat;
 	 
   } while(toupper(repeat) == 'Y');
   
   return 0;
}
