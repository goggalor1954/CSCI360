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
using namespace std;



//fills the list x with 27 elements 
void buildCharBox(list<charBox>* x)
{
	for(int i=0; i<26; i++){x->push_front(charBox(i+65));}
	x->push_front(charBox(' '));
}

//recursivly counts the number of occurances of the entered character. 
//doubles as a way to enter new characters into the list. 
//if the elemets name variable == '\0' then it assignes the character to name , increments count by 1 and returns boxVar. 
//if the entered character == name then it increments that character element by 1 and returns boxVar.
// if not it pop_fronts the boxVar and calls charCount untill it finds the character or boxVar is empty. 
 
list<charBox>* charCount( list<charBox>* boxVar, char charVal)
{
	//if boxVar is empty, return
	if(boxVar->empty()) { return boxVar;}
	//if the name of the front of boxVar is empty, addign it a name, increment it, and return box var.
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
	//if not, pop_front the front value of boxVar, store it, and pass it and char val to charCount. push_front it back into box var once it returns. then return box var.
	charBox temp=boxVar->front();
	boxVar->pop_front();
	boxVar=charCount(boxVar, charVal);
	boxVar->push_front(temp);
	return boxVar;
}
//returns an int with the total number of characters 
int getTotal(list<charBox> boxVar)
{
	int total=0;
	while(!boxVar.empty())
	{
		total+=boxVar.front().getCount();
		boxVar.pop_front();
	}
	return total;
}
//computes the frequency of all the elements in the list.
list<charBox>* setFreq( list<charBox>* boxVar, int total)
{
	if(boxVar->empty()){return boxVar;}
	boxVar->front().setFreq(total);
	charBox temp=boxVar->front();
	boxVar->pop_front();
	boxVar=setFreq(boxVar, total);
	boxVar->push_front(temp);
	return boxVar;
}

//searches the list for the highest frequency element, outputs it to the given fstream. returnes the element to be deleted from the list.
charBox getHighest( list<charBox> boxVar, float highest, charBox element)
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
	boxVar.pop_front();
	return getHighest(boxVar, highest, element);
}
//searches through the list and remove the matching element.
list<charBox>* removeCharBox(list<charBox>* boxVar, char name)
{	
	if(boxVar->empty()){return boxVar;}
	if(boxVar->front().getName() == name)
	{
		boxVar->pop_front();
		return boxVar;
	}
	charBox temp =boxVar->front();
	boxVar->pop_front();
	boxVar=removeCharBox( boxVar, name);
	boxVar->push_front(temp);
	return boxVar;
	
}
	
	

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

