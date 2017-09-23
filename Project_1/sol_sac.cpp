/*
James Roesemann
CSCI360
project 1
sol_sac.cpp

opens and reads in a file named corpus_clean.txt
outputs to corpus_freq.txt 
corpus_freq.txt contains, in decending order, a row containing the pairs  <letter>, <rel_freq> 
letter is a alphabetical or space character and rel_freq is a floting point number is the relitive frequency of its occurance.
*/

#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

//A class conting a char variable, and an int variable to count the occurance of the char.
class charBox
{
private:
	int count;
	char name;
	float freq;
public:
	void add(){count=count+1;}
	void setName(char x){name =x;}
	int getCount(){return count;}
	char getName(){return name;}
	float getFreq(){return freq;}
	void setFreq(int total){freq=float(count)/float(total);}
	charBox()
	{
		count =0;
		name='\0';
		freq=0;
	}
	charBox(char x)
	{
		count=0;
		name=x;
		freq=0;
	}
};

//fills the queue x with 27 elements 
void buildCharBox(queue<charBox>* x)
{
	for(int i=0; i<26; i++){x->push(charBox(i));}
}

//recursivly counts the number of occurances of the entered character. 
//doubles as a way to enter new characters into the queue. 
//if the elemets name variable == '\0' then it assignes the character to name , increments count by 1 and returns boxVar. 
//if the entered character == name then it increments that character element by 1 and returns boxVar.
// if not it pops the boxVar and calls charCount untill it finds the character or boxVar is empty. 
//altered from the last version to only count printable ascii characters.
 
queue<charBox>* charCount( queue<charBox>* boxVar, char charVal)
{
	if(charVal<32 || charVal>126){return boxVar;}
	//if boxVar is empty, return
	if(boxVar->empty()) //test. should only get here if there are more than 26 characters.
	{
		boxVar->push(charBox(charVal));
		boxVar->front().add();
		return boxVar;}
	//if the name of the front of boxVar is empty, assign it a name, increment it, and return box var.
	if(boxVar->front().getName()=='\0')
	{
		boxVar->front().setName(charVal);
		boxVar->front().add();
		return boxVar;
	}
	//if the front name of boxVar == charVal, increment it and return. 
	if(boxVar->front().getName()==charVal)
	{
		boxVar->front().add();
		return boxVar;
	}
	//if not, pop the front value of boxVar, store it, and pass it and char val to charCount. push it back into box var once it returns. then return box var.
	charBox temp=boxVar->front();
	boxVar->pop();
	boxVar=charCount(boxVar, charVal);
	boxVar->push(temp);
	return boxVar;
}
//returns an int with the total number of characters 
int getTotal(queue<charBox> boxVar)
{
	int total=0;
	while(!boxVar.empty())
	{
		total+=boxVar.front().getCount();
		boxVar.pop();
	}
	return total;
}
//computes the frequency of all the elements in the queue.
queue<charBox>* setFreq( queue<charBox>* boxVar, int total)
{
	if(boxVar->empty()){return boxVar;}
	boxVar->front().setFreq(total);
	charBox temp=boxVar->front();
	boxVar->pop();
	boxVar=setFreq(boxVar, total);
	boxVar->push(temp);
	return boxVar;
}

//searches the queue for the highest frequency element, outputs it to the given fstream. returnes the element to be deleted from the queue.
charBox getHighest( queue<charBox> boxVar, float highest, charBox element)
{
	//if boxVar is empty, return element.
	if(boxVar.empty())
	{
		return element;
	}
	//if the top of boxVar has a higher freq then highest, assign it to element and it's frequency to highest.
	if(boxVar.front().getFreq() > highest)
	{
		highest=boxVar.front().getFreq();
		element=boxVar.front();
	}
	boxVar.pop();
	return getHighest(boxVar, highest, element);
}
//searches through the queue and remove the matching element.
queue<charBox>* removeCharBox(queue<charBox>* boxVar, char name)
{	
	if(boxVar->empty()){return boxVar;}
	if(boxVar->front().getName() == name)
	{
		boxVar->pop();
		return boxVar;
	}
	charBox temp =boxVar->front();
	boxVar->pop();
	boxVar=removeCharBox( boxVar, name);
	boxVar->push(temp);
	return boxVar;	
}
//trying to fix this mess. removing characters that 


	
	

int main()
{
	char charTemp; //test variable
	

	queue<charBox> alphaChars;
	buildCharBox(&alphaChars);
	fstream infile, outfile;
	infile.open("ciphertext.txt");
	while(!infile.eof()
	){
		charTemp=infile.get();
		charCount( &alphaChars, charTemp);
	}
	infile.close();
	setFreq(&alphaChars, getTotal(alphaChars));
	outfile.open("cipher_freq.txt");
	
	charBox temp;

	while(!alphaChars.empty()) 	
	{
		temp=getHighest(alphaChars, 0, alphaChars.front().getName());
		outfile << temp.getName() << ", "<< temp.getFreq() << endl;
		cout << temp.getName() << ", "<< temp.getFreq() << endl;//test
		removeCharBox( &alphaChars, temp.getName());
	}



	outfile.close();

	

	return 0;
}
