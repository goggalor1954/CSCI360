//james Roesemann
//CSCi360-01
//Project 1
#include <iostream>
#include <queue>
#include "charBox.h"
using namespace std;

//fills the queue x with 26 elements
void buildCharBox(queue<charBox>* x)
{
	for(int i=0; i<27; i++){x->push(charBox());}
}

//if x == 90, set the name value of the element to x. thrn returns the element. if not, pops the first element to y, setes its name to x. calls alphaChar buils with x+1. pushes y into alphaCharBuilds return. the nreturns boxVar.
queue<charBox>* alphaCharBuild( queue<charBox>* boxVar, int x)
{
	if(boxVar->empty()) {return boxVar;}
	charBox y=boxVar->front();
	boxVar->pop();
	y.setName(x);
	boxVar=alphaCharBuild(boxVar, x+1);
	boxVar->push(y);
	return boxVar;
}
//set the first elements of the queue's name value to. ' '. Calls buildAlphaChar to fill in A-Z returns the queue
queue<charBox>* alphaCharBuild( queue<charBox>* boxVar)
{
	charBox y=boxVar->front();
	boxVar->pop();
	y.setName(' ');
	boxVar=alphaCharBuild(boxVar, 65);
	boxVar->push(y);
	return boxVar;
}
//recursivly counts the number of occurances of the entered character. doulbes as a way to enter new characters into the cryptoChars queue. if the elemets name variable == '\0' then it assignes the character to name , increments count by 1 and returns. if the entered character == name then it increments that character element by 1. if not pops the boxVar and calls chracterCount untill it finds the character or boxVar is empty. when entering text from moby dick the entered character must already set to Upper case. actually all characters alreay will be capatlized.
 
queue<charBox>* charCount( queue<charBox>* boxVar, char charVal)

{
	if(boxVar->empty()) { return boxVar;}//it should only get here when we are counting characters from moby dick. cryptoText should have exactly 26 types of characters.
	if(boxVar->front().getName()=='\0')
	{
		boxVar->front().setName(charVal);
		boxVar->front().add();
		return boxVar;
	}
	if(boxVar->front().getName()==charVal)
	{
		boxVar->front().add();
		return boxVar;
	}
	charBox temp=boxVar->front();
	boxVar->pop();
	boxVar=charCount(boxVar, charVal);
	boxVar->push(temp);
	return boxVar;
}
//


int main()
{
	queue<charBox> alphaChars;
	queue<charBox> cryptoChars;

	buildCharBox(&alphaChars);
	buildCharBox(&cryptoChars);

	alphaCharBuild(&alphaChars);

	//TEST
	while(!alphaChars.empty())
	{
		cout << alphaChars.front().getName() << endl;
		alphaChars.pop();
	}
	


	return 0;
}



	//if(charValcharVal<=122 && charVal>=97){charVal=charVal-32;} //in case its lowercase,
