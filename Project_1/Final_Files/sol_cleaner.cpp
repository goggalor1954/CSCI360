/*
James Roesemann
CSCI360
project 1
sol_cleaner.cpp

Opens and reads in a file named corpus.txt
Outputs a file name corpus_clean.txt
corpus_clean.txt Contains the same characters as corpus.txt, except all not-alphabetical or space characters have been removed, and all alphabetical characters have been capliized.

I altered this slightly to count new lines as spaces because i noticed alot of words ended up geting combined and i was worried it would throw off the statistical analysis.
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream infile, outfile;
	char temp;
	infile.open("corpus.txt");
	outfile.open("corpus_clean.txt");
	
	while(!infile.eof())
	{
		infile.get(temp);
		//if the character is a lowercase letter, changers it to an upper case letter.
		if(temp<=122 && temp >=97){temp=temp-32;}
		if(temp=='\n'){temp=' ';}
		if(temp<=90 && temp>=65 || temp==32){outfile << temp;}
	}
	infile.close();
	outfile.close();

	return 0;
}
