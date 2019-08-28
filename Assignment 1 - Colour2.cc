Colour2.cc

//This program determines if a colour can be found in a given list of colours using vectors
//By Queenie Zhao

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Function Prototypes
int findMaxIndex(vector<string>&, int);
void swap(string&, string&);
void sort(vector<string>&, int);
bool linear_search(const vector<string>, int, string, int&);
bool binary_search(const vector<string>, int, string, int&);
void search_and_report(const vector<string>, int, string, string, bool (*search)(const vector<string>, int, string, int&));

int main () {

   vector<string> A;
   string inputColour, searchingColour;
   int n = 0;
   
   cout << "Enter a colour (# when done): ";
   getline(cin, inputColour);

   while (inputColour != "#") {

  	A.push_back(inputColour);

  	cout << "Enter a colour (# when done): ";
  	getline(cin, inputColour);
   }
   
   n = A.size();

   sort(A, n);
   
   cout << "Search (# when done): ";
   getline(cin, searchingColour);
 	 
   while (searchingColour != "#") {

  	search_and_report(A, n, searchingColour, "Linear Search", linear_search);
  	cout << endl;
  	search_and_report(A, n, searchingColour, "Binary Search", binary_search);
  	cout << endl;

  	cout << "Search (# when done): ";
  	getline(cin, searchingColour);
   }
   
   return 0;
}

//Function Definitions

//Purpose: To find the bigger item; used by sort
//Parameters: I/O - string for array
//        	I - int for number of items
//Return: Maximum index
int findMaxIndex(vector<string>& A, int n)
{
   int maxIndex=0;
   for(int i=1; i <= n; i++)
  	if(A[i] > A[maxIndex])
     maxIndex = i;
   return maxIndex;
}

//Purpose: To swap two strings; used by sort
//Parameters: I/O - string for a
//        	I/O - string for b
//Return:
void swap(string& a, string& b)
{
   string temp;
   temp = a;
   a = b;
   b = temp;
}

//Purpose: Sorts array of n elements in ascending order
//Parameters: I/O - string for array
//        	I - int for n
//Return:
void sort(vector<string>& A, int n) {

   int max;
   for(int i = n-1; i >= 0; i--) {
 	 
  	max = findMaxIndex(A, i);
 	 
  	if(max != i)
     swap(A[i],A[max]);
   }
}



//Purpose: Does linear search for a specific colour in array of n elements, while counting how many times the search has executed, even if failed
//Parameters: I/O - string for array of colours
//        	I - int for size of array
//        	I - string for colour to search for
//        	I/O - int for number of times linear search has been performed
//Return: T/F whether input colour has been found
bool linear_search(const vector<string> A, int n, string colour, int &count) {

   for (int i = 0; i < n; i++) {
 	 
  	count++;
 	 
  	if (A[i] == colour)
     return true;
   }
   
   return false;
}

//Purpose: Does binary search for a specific colour in array of n elements, while counting how many times the search has executed, even if failed
//Parameters: I/O - string for array of colours
//        	I - int for size of array
//        	I - string for colour to search for
//        	I/O - int for number of times binary search has been performed
//Return: T/F whether input colour has been found
bool binary_search(const vector<string> A, int n, string colour, int &count) {

   int start = 0, end = n;
   
   while (start < end) {
 	 
  	count++;
  	int mid = start + (end - start) / 2;
 	 
  	if (A[mid] == colour)
     return true;
 	 
  	else if (A[mid] < colour)
     start = mid + 1;
 	 
  	else
     end = mid;
   }
   return false;
}

//Purpose: To run a search on the array and outputs whether it is found and how many times the search is run
//Parameters: I - const string for the array
//        	I - int for size of array
//        	I - string for colour to search for
//        	I - string for labeling of different searching functions
//        	I - bool for pointer pointing to searching functions
//Return:
void search_and_report(const vector<string> A, int n, string colour, string label, bool (*search)(const vector<string> A, int n, string colour, int &count)) {

   int count = 0;
   bool found = search(A, n, colour, count);

   if (found){

  	cout << label << ": found, comparisons = " << count;
   }
   
   else {

  	cout << label << ": not found, comparisons = " << count;
   }
}
