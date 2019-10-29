Freq.cc:

//*************************************************************************************************************************
// CPSC 2620
// File: freq.cc
// This is a program that reads in a list of words and outputs them in alphabetical and descending frequency, using the STL
// Author: Queenie Zhao
// Date: March 6th, 2019
//*************************************************************************************************************************

#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <vector>
#include <iomanip>
#include <cctype>
using namespace std;

typedef map<string, int> mapType;

//Function Prototypes
void convert(string&);
void readInput(mapType&);
void printList1(const mapType&);
bool descend(const pair<int,string>&, const pair<int,string>&);

int main () {

   mapType freqMap;

   readInput(freqMap);
   printList1(freqMap);

   cout << endl;
   
   vector< pair<int,string> > freqVec;
   for(auto it : freqMap)
  	freqVec.push_back(make_pair(it.second, it.first));
   
   sort(freqVec.begin(), freqVec.end(), descend);
   
   cout << "Frequency  Word" << endl
    << "---------  ---------------------" << endl;
   
   for(auto it = freqVec.cbegin(); it != freqVec.cend(); ++it)
  	cout << setw(9) << right << it->first << "  "
   	<< setw(21) << left << it->second << endl;
   
   return 0;
}

//Function Definitions

//******************************************************************************************************
// Purpose: A helper function to convert uppercase characters to lowercase using transform from the STL.
//******************************************************************************************************
void convert(string& word)
{
   transform (begin(word), end(word), begin(word), [](char c) { return tolower(c); });
}

//******************************************************************************************************
// Purpose: To read in the keys of map freqMap and use function convert to make all words lowercase.
// This function also counts the value of each key entered.
//******************************************************************************************************
void readInput(mapType& freqMap)
{
   string words;

   cout << "Enter a list of words with spaces in between, end with ctrl-D:" << endl;
   while (cin >> words)
   {
  	convert(words);
  	cin.ignore();
  	freqMap[words]++;
   }
}

//******************************************************************************************************
// Purpose: To output the first list sorted alphabetically.
// The list outputs the word(key) then the frequency(value).
//******************************************************************************************************
void printList1(const mapType& freqMap)
{
   cout << "Word                 	Frequency" << endl
    << "---------------------	---------" << endl;
   
   for(auto it = begin(freqMap); it != end(freqMap); ++it)
  	cout << setw(25) << left << it->first
   	<< setw(9) << right << it->second << endl;

}

//******************************************************************************************************
// Purpose: Comparison function to fine tune the sort() function
// Sorts the frequency from largest to smallest
//******************************************************************************************************
bool descend(const pair<int,string>& x, const pair<int,string>& y)
{
   return (x.first > y.first);
}
