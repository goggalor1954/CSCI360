//james Roesemann
//CSCi360-01
//Project 1
#include <iostream>
#include "charBox.h"
using namespace std;

//test function
void test(charBox* x, int y)
{
	if(x->getNext()==NULL)
	{
		return;
	}
	std::cout << y << ": " << &x << endl;
	test(x->getNext(), y-1);
	return;
}

int main()
{
	charBox alphaChar;
	charBox cryptoChar;
	charBuild(&alphaChar, 26);
	//charBuild(cryptoChar, 26);
//test
	test(&alphaChar, 30); //test

	//aplhaFill(& alphaChar);
	


	return 0;
};
