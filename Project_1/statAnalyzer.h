#ifndef STATANALYZER_H
#define STATANALYZER_H
#include "charBox.h"
#include <iostream>
#include <list>
#include <fstream>

//fills the std::list x with 27 elements 
void buildCharBox(std::list<charBox>* x)
{
	for(int i=0; i<27; i++){x->push_front(charBox());}
}

//recursivly counts the number of occurances of the entered character. 
//doubles as a way to enter new characters into the std::list. 
//if the elemets name variable == '\0' then it assignes the character to name , increments count by 1 and returns boxVar. 
//if the entered character == name then it increments that character element by 1 and returns boxVar.
// if not it pop_fronts the boxVar and calls charCount untill it finds the character or boxVar is empty. 
 
std::list<charBox>* charCount( std::list<charBox>* boxVar, char charVal)
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
int getTotal(std::list<charBox> boxVar)
{
	int total=0;
	while(!boxVar.empty())
	{
		total+=boxVar.front().getCount();
		boxVar.pop_front();
	}
	return total;
}
//computes the frequency of all the elements in the std::list.
std::list<charBox>* setFreq( std::list<charBox>* boxVar, int total)
{
	if(boxVar->empty()){return boxVar;}
	boxVar->front().setFreq(total);
	charBox temp=boxVar->front();
	boxVar->pop_front();
	boxVar=setFreq(boxVar, total);
	boxVar->push_front(temp);
	return boxVar;
}

//searches the std::list for the highest frequency element, outputs it to the given fstream. returnes the element to be deleted from the std::list.
charBox getHighest( std::list<charBox> boxVar, float highest, charBox element)
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
//searches through the std::list and remove the matching element.
std::list<charBox>* removeCharBox(std::list<charBox>* boxVar, char name)
{	
	if(boxVar->empty()){return boxVar;}
	if(boxVar->front().getName() == name)
	{
		boxVar->pop_front();
		return boxVar;
	}
	charBox temp =boxVar->front();
	boxVar->pop_front();
	boxVar->push_front(temp);
	return boxVar;
	
}
//modified version of charCount that just reads in cryptNamevalues for charBox.
std::list<charBox>* cryptInsert( std::list<charBox>* boxVar, char charVal)
{
	//if boxVar is empty, return
	if(boxVar->empty()) { return boxVar;}
	//if the name of the front of boxVar is empty, addign it a name, increment it, and return box var.
	if(boxVar->front().getCryptName()=='\0')
	{
		boxVar->front().setCryptName(charVal);
		return boxVar;
	}
	if(boxVar->front().getCryptName()==charVal){return boxVar;}
	//if not, pop_front the front value of boxVar, store it, and pass it and char val to charCount. push_front it back into box var once it returns. then return box var.
	charBox temp=boxVar->front();
	boxVar->pop_front();
	boxVar=cryptInsert(boxVar, charVal);
	boxVar->push_front(temp);
	return boxVar;
}
//searches boxVar for a cryptName that matches charVal. outputs the character name to the fstream.
std::list<charBox>* decrypt( std::list<charBox>* boxVar, std::fstream &outfile, char charVal)
{
	//if boxVar is empty
	if(boxVar->empty()){return boxVar;}
	//if the character is found
	if(boxVar->front().getCryptName()==charVal)
	{
		outfile << boxVar->front().getName();
		return boxVar;
	}
	charBox temp=boxVar->front();
	boxVar->pop_front();
	boxVar=decrypt(boxVar, outfile, charVal);
	boxVar->push_front(temp);
	return boxVar;
}



#endif
