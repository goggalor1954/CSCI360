/*
James Roesemann
CSCI360
project 1
sol_sap.cpp

opens and reads in a file named corpus_clean.txt
outputs to corpus_freq.txt 
corpus_freq.txt contains, in decending order, a row containing the pairs  <letter>, <rel_freq> 
letter is a alphabetical or space character and rel_freq is a floting point number is the relitive frequency of its occurance.
*/

#include <iostream>
#include <list>
#include <fstream>
#include "charBox.h"
#include "statAnalyzer.h"
using namespace std;
	

int main()
{

	list<charBox> alphaChars;
	buildCharBox(&alphaChars);
	fstream infile, outfile;
	infile.open("corpus_clean.txt");
	while(!infile.eof()){charCount( &alphaChars, infile.get());}
	infile.close();
	setFreq(&alphaChars, getTotal(alphaChars));
	outfile.open("corpus_freq.txt");
	charBox temp;

	while(!alphaChars.empty()) 	
	{
		temp=getHighest(alphaChars, 0, alphaChars.front().getName());
		outfile << temp.getName() << ", "<< temp.getFreq() << endl;
		removeCharBox( &alphaChars, temp.getName());
	}
	outfile.close();

	

	return 0;
}

