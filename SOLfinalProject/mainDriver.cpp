// main.cpp
#include <iostream>
#include <string>
#include <fstream>
#include "Count.h"
#include "mtf.h"
#include "transpose.h"

void pausespace(); //created this function to consolidate space, simply pauses the program and adds space for readability
using namespace std;

int main()
{
	cout << "<TYLER ELLIS --- CSIS215>\n\n";

	cout << "\n\n ----------TEST 1 ----- PROCESSING CHARS----------";

	pausespace();

	//Add characters A-H, making sure 'I' is excluded
	Count<char> cList;
	cList.add('A');
	cList.add('B');
	cList.add('C');
	cList.add('D');
	cList.add('E');
	cList.add('F');
	cList.add('G');
	cList.add('H');

	//Finding the specified characters, including I
	cList.find('F');
	cList.find('D');
	cList.find('F');
	cList.find('G');
	cList.find('E');
	cList.find('G');
	cList.find('F');
	cList.find('A');
	cList.find('D');
	cList.find('F');
	cList.find('G');
	cList.find('E');
	cList.find('H');
	cList.find('I');

	//print the count results
	cList.printlist();

	pausespace();

	//same as above for move-to-front heuristic
	mtf<char> mtfList;
	mtfList.add('A');
	mtfList.add('B');
	mtfList.add('C');
	mtfList.add('D');
	mtfList.add('E');
	mtfList.add('F');
	mtfList.add('G');
	mtfList.add('H');

	mtfList.find('F');
	mtfList.find('D');
	mtfList.find('F');
	mtfList.find('G');
	mtfList.find('E');
	mtfList.find('G');
	mtfList.find('F');
	mtfList.find('A');
	mtfList.find('D');
	mtfList.find('F');
	mtfList.find('G');
	mtfList.find('E');
	mtfList.find('H');
	mtfList.find('I');

	mtfList.printlist();

	pausespace();

	//same as above for transpose heuristic
	transpose<char> tranList;
	tranList.add('A');
	tranList.add('B');
	tranList.add('C');
	tranList.add('D');
	tranList.add('E');
	tranList.add('F');
	tranList.add('G');
	tranList.add('H');

	tranList.find('F');
	tranList.find('D');
	tranList.find('F');
	tranList.find('G');
	tranList.find('E');
	tranList.find('G');
	tranList.find('F');
	tranList.find('A');
	tranList.find('D');
	tranList.find('F');
	tranList.find('G');
	tranList.find('E');
	tranList.find('H');
	tranList.find('I');

	tranList.printlist();

	pausespace();

	cout << "\n\n ----------TEST 2 ----- PROCESSING STRINGS----------";

	pausespace();

	// open file to receive data
	fstream infile;
	infile.open("test.txt");

	//create a string list object for each of the three heuristics 
	Count<string> cstr;
	mtf<string> mtfstr;
	transpose<string> tstr;

	string nextWord;

	// processes each word into all 3 lists
	while (infile >> nextWord)
	{
		cstr.find(nextWord);
		mtfstr.find(nextWord);
		tstr.find(nextWord);
	}

	//reads the first 10 entries of each heuristic's string list
	cstr.printlist(10);
	pausespace();
	mtfstr.printlist(10);
	pausespace();
	tstr.printlist(10);
	infile.close();
	pausespace;

	return 0;
}

void pausespace() {

	cout << endl << endl;
	system("pause");
	cout << endl;

}