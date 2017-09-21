#ifndef CHARBOX_H
#define CHARBOX_H

class charBox //A class conting a char variable, an int variable to count the occurance of the char, and a pointer that point to the next charBox object.
{
	private:
	char name;
	int count;
	charBox* next;
	
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
	char getName(){return name;} //return the char value name
	int getCount(){return count;} //returns the int value count
	charBox* getNext(){return next;} //returns the pointer valuse next
	void setName(char x){name=x;} //sets the char value name
	void add(){count++;} //increments the count value by 1
	void setNext(charBox &x){next=&x;} // sets the pointer value next to the entered charBox object.
	void makeNext()
	{
		charBox* p = new charBox();
		this->next=p;
		//this->next->next==NULL;
	}
};


	void charBuild(charBox *charBoxVal, int x) // recursivly builds a charBox linked list of size x
{
	if(x==0) return;
	charBox p;
	charBoxVal->setNext(p);
	charBuild(charBoxVal->getNext(), x-1);
	//std::cout << "This: " << charBoxVar << std::endl; //test
	//std::cout << "next: " << charBoxVar->getNext() << std::endl; //test
}
	void aplhaFill(charBox *charBoxVal, char x) // recursivly fills the name values of the entered charBox from A-Z
	{
		charBoxVal->setName(x);
		std::cout << x << std::endl;
		std::cout << charBoxVal->getNext() << std::endl; //test
		if(charBoxVal->getNext()==NULL) return;
		aplhaFill(charBoxVal->getNext(), x+1);
	}

	void aplhaFill(charBox *charBoxVal) //sets the first name value of charBoxVal to ' ', fills in the rest of the the alphabet A-Z
	{
		std::cout << charBoxVal->getNext() << std::endl; //test
		charBoxVal->setName(' ');
		aplhaFill(charBoxVal, 'A');
	}
		






#endif
