#ifndef CHARBOX_H
#define CHARBOX_H

//A class conting the char variables name and cryptName, an int variable to count the occurance of the char, and a float variable to store the frequencey of the occuring character.
class charBox
{
private:
	int count;
	char name, cryptName;
	float freq;
public:
	void add(){count=count+1;}
	void setName(char x){name =x;}
	void setCryptName(char x){cryptName=x;}
	void setFreq(int total){freq=float(count)/float(total);}
	int getCount(){return count;}
	char getName(){return name;}
	char getCryptName(){return cryptName;}
	float getFreq(){return freq;}

	charBox()
	{
		count =0;
		name='\0';
		cryptName='\0';
		freq=0;
	}
	charBox(char x)
	{
		count=0;
		name=x;
		cryptName='\0';
		freq=0;
	}
	charBox(char x, char y)
	{
		count=0;
		name=x;
		cryptName=y;
		freq=0;
	}
};


#endif
