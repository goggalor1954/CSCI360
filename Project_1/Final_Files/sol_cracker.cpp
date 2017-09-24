/*
James Roesemann
CSCI360
project 1
sol_cracker.cpp

read in 3 files, ciphertext.txt, cipher_freq.txt, and corpus_freq.txt.
Outputs the file cracked.txt.
cracked is the result of replaceing each character of ciphertext.txt with a capital letter of space character.
The characters a replaced by occurance of frequency. this will not be a perfect decryption.
*/

#include <iostream>
#include <list>
#include <fstream>
#include "hFiles/charBox.h"
#include "hFiles/statAnalyzer.h"
using namespace std;


int main()
{
	fstream infile, outfile;
	list<charBox> corresponding;
	char temp1, temp2;
	string temp;

	buildCharBox(&corresponding);
	infile.open("corpus_freq.txt");
	//reads in the characters from corpus_freq.txt
	while(getline(infile, temp))
	{
		charCount(&corresponding, temp[0]);
	}
	infile.close();

	infile.open("cipher_freq.txt");
	//reads in the characters from cipher_freq.txt
	while(getline(infile, temp))
	{
		cryptInsert(&corresponding, temp[0]);
	}
	infile.close();
	infile.open("ciphertext.txt");
	outfile.open("cracked.txt", std::fstream::out | std::fstream::trunc);
	//reads in characters from ciphertext.txt. outputs the decrypted characters to cracked.txt
	while(!infile.eof())
	{
		decrypt(&corresponding, outfile, infile.get());
	}
	infile.close();
	outfile.close();
	

	//test


	
		
	return 0;
}
