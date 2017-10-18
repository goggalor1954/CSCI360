//james Roesemann
//CSCI360
//Project1

#include <iostream>
#include <fstream>
using namespace std;

class charBox
{
	private:
	char name;
	int count;
	charBox *next;
	
	public:
	charBox()
	{
		name='\0';
		count=0;
		next=NULL;
	}
	charBox(charBox &x)
	{
		name='\0';
		count=0;
		next=&x;
	}
	char getName(){return name;}
	int getCount(){return count;}
	charBox getNext(){return *next;}
	void setName(char x){name=x;}
	void add(){count++;}
	void setNext(charBox &x){next=&x;}
	void setNext(){this->next=new charBox();} //set next to a newly created charBox pointer.
};
void charBuild(charBox &charBoxVar, int charVal) //recursivly assigns the the character name based of the value of charVal to name. creates a new charBox object and points to it. stops when charVal=z. 
{
	charBoxVar.setName(charVal);
	if(charVal==90){return;}
	charBoxVar.setNext();
	charBuild(charBoxVar.getNext(), charVal++);
}
void charBuild(charBox &charBoxVar)//sets the first character variable to ' '  and begings the recursive fuiction charbuild.
{
	charBoxVar.setName(' ');
	charBoxVar.setNext();
	charBuild(charBoxVar.getNext(), 65);
}
void cryptoCharBuild(charBox &charBoxVar, int x) //recursivly builds 26 charBox objects to be filled later by another function.
{
	if(x==26) return;
	charBoxVar.setNext();
	cryptoCharBuild(charBoxVar.getNext(), x-++);
}
void charBoxCount(charBox &charBoxVar, char x) //counts how many times the given character occurs. if the charBoxVal for name == NULL, asigns the curent character to name.
{
	if(charBox.getName()=='\0'){charBox.setName(x)};
	if( x==charBoxVar.getName())
	{
		charBoxVar.add();
		return;
	}
	if(charBoxVar.getNext()=='\0'){return;}
	charBoxCount(charBoxVar.getNext(), x);
}
void readAlphaChars( charBox &charBoxVar) //reads in the characters of moby dick, counts A-z and the space character.
{
	ifstream inFile("MobyDick.txt");
	while(!inFile.eof())
	{ //need to make sure that lower case letters a read in as upercase letters.
		if(infile.get()<=122 && infile.get>=97)
		{
			charBoxCount( charBoxVar, infile.get()-32)
		}//why 32 insted of 26? make sure that numbers right.
		else 
		{
			charBoxCount( charBoxVar, infile.get());
		}//not done here. i need to fix it so that if it's a lower case letter it becomes an upper case letter.
	}
	inFile.close();	
}
void readCryptoChars(charBox &charBoxVar)//reads in the crypto text and counts the characters
{
	ifstream inFile("ciphertext.txt");
	while(!inFile.eof())
	{
		charBoxCount(charBoxVar, infile.get());
	}
	inFile.close();
};
	

int main()
{
	charBox alphaChars;
	charBox cryptoChars;
	charBuild(alphaChars);
	cryptoCharBuild(cryptoChars, 0);

	return 0;
}


/* Outline of what i need to do:
- create a character object containing the character and a count variable. set the inittial character value to null. and a pointer to the next object.
- create 2 27 length character object. one for a-z and ' '. 
- create another 27 length , but assign the character variable depending on whats read into it. stop at the 27th character. after that point to null.
