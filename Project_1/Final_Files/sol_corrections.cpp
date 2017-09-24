/*
James Roesemann
CSCI360
project 1
sol_corrections.cpp


this program reads in the characters from cracked.txt and outputs a file called clear.txt
character substitiutions are made where apropriate tobased on manual observations. 

clear.txt contains the orignal unencrypted plain text used to make ciphertext.txt.
*/

#include <iostream>
#include <list>
#include <fstream>
using namespace std;

int main()
{
	fstream infile, outfile;
	char temp;
	infile.open("cracked.txt");
	outfile.open("clear.txt", std::fstream::out | std::fstream::trunc);
	temp=infile.get();
	while(!infile.eof())
	{

		//these were chosen in no particular order.
		switch(temp)
		{
			case 'O':outfile <<'H';
				break;
			case 'C':outfile <<'U';
				break;
			case 'H':outfile <<'N';
				break;
			case 'R':outfile <<'D';
				break; 
			case 'L':outfile <<'R';
				break; 
			case 'N':outfile <<'O';
				break; 
			case 'W':outfile <<'G';
				break; 
			case 'F':outfile <<'M';
				break; 
			case 'M': outfile <<'F';
				break; 
			case 'Y':outfile <<'P';
				break;
			case 'P':outfile <<'B';
				break;
			case 'K':outfile <<'V';
				break;
			case 'U':outfile <<'C';
				break;
			case 'G':outfile <<'W';
				break;
			case 'D':outfile <<'L';
				break;
			case 'B':outfile <<'Y';
				break;
			case 'V':outfile <<'K';
				break;
			case 'J':outfile <<'Z';
				break;
			case 'Q':outfile <<'X';
				break;
			case 'X':outfile <<'J';
				break;
			case 'Z':outfile <<'Q';
				break;
			default: outfile << temp;
				break;
			
		}
		temp=infile.get();
	}
	infile.close();
	outfile.close();
	return 0;

}

/*running list of characters that have been switched. there should be a case and a switch of each character listed here. characters with an x on the right have found a match 
	O->H x definatly
	c->U x (definatly)
	H->N x (definatly)
	R->D x definatly
	L->R x
	N->O x
	W->G x
	F->M x (definitly)
	M->F x
	Y->P x definatly
	P->B x definatly
	K->V x definatly
	U->C x
	G->W x definatly
	D->L x
	B->Y x
	V->K x definatly
	j->Z x Definatly
	Q->x x
	x->J x
	z->Q x
	
*/
