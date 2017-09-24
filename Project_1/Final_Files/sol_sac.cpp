/*
James Roesemann
CSCI360
project 1
sol_sac.cpp

opens and reads in a file named ciphertext.txt
outputs to cipher_freq.txt 
cipher_freq.txt contains, in decending order, a row containing the pairs  <letter>, <rel_freq> 
letter is a printable ascii and rel_freq is a floting point number is the relitive frequency of its occurance.
*/
#include <iostream>
#include <list>
#include <fstream>
#include "hFiles/charBox.h"
#include "hFiles/statAnalyzer.h"
using namespace std;

int main()
{
	list<charBox> alphaChars;
	buildCharBox(&alphaChars);
	fstream infile, outfile;
	char tempIn;
	infile.open("ciphertext.txt");
	while(!infile.eof())
	{
		tempIn=infile.get();
		if(tempIn>=32 && tempIn<=126)
		{
			charCount( &alphaChars, tempIn);
		}
	}
	infile.close();
setFreq(&alphaChars, getTotal(alphaChars));
	outfile.open("cipher_freq.txt", std::fstream::out | std::fstream::trunc);
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


