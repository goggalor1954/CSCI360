#ifndef CHARBOX_H
#define CHARBOX_H
#include <queue>

class charBox //A class conting a char variable, and an int variable to count the occurance of the char.
{
private:
	int count;
	char name;
public:
	void add(){count=count+1;}
	void setName(char x){name =x;}
	int getCout(){return count;}
	char getName(){return name;}
	charBox()
	{
		count =0;
		name='\0';
	}
};




#endif
