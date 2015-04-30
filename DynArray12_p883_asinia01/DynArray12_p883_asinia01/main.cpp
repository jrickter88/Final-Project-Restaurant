//Program:     Ch. 12 #1  Dynamic Arrays
//Programmer:  Andrew M. Siniarski
//				the dude abides
//Date:        April 27, 2015
//Description: Create a project that accepts a string in lowercase and outputs the 
//             string in uppercase using a dynamic array


#include <iostream>
#include <string>

using namespace std;

//function prototypes
void printAry(char* &name, int *size);
void initAry(char* &name, int *size);
void printUppercase(char* &name, int *size);
void getName(char* &name, int *size);
void deleteArray(char* &name, int *size);



int main()
{
	char* name;
	int arraySize;
	cout << "Enter the amount of characters you think that you'll use: ";
	cin >> arraySize;
	cout << endl;
	name = new char[arraySize];
	initAry(name, &arraySize);
	getName(name, &arraySize);
	printAry(name, &arraySize);
	printUppercase(name, &arraySize);
	deleteArray(name, &arraySize);

	system("pause");
	return 0;
} //end main

void printAry(char* &name, int *size)
{
	cout << "\n\n\nWhat the array holds after initialization:\n\n";
	for(int i = 0; i < *size; i++)
	{
		cout << name[i];
	}

	cout << "\n\n\n\n\n";

}//end printAry(char name[])

void initAry(char* &name, int *size)
{
	int i;
	for(i = 0; i < *size; i++)
	{
		name[i] = 'Z'; 
	}

}//end initAry(char name[])

void getName(char* &name, int *size)
{
	int i = 0;
	char nextChar;
	
	//prompt for user input
	cout << "Please enter a string of up to " << *size <<" characters in lower case letters.  Press <8> then <enter> when done: \n\n";

	nextChar = cin.peek();  //the peek function copies the next character from
	                        //the input stream into the variable without taking 
	                        //it out of the input stream.

	while(nextChar != '8')
	{
		//cout << "inside the loop";
	    cin >> name[i]; 
		i++;
	    nextChar = cin.peek();
	}

}//end getName(char name[])




void printUppercase(char* &name, int *size)
{
	cout << "The name you entered in uppercase letters is: \n\n";

	for(int i = 0; i < *size; i++)
	{
		if (name[i] != 'Z')
		{
			cout << static_cast<char>(toupper(name[i]));
		}
	}

	cout << endl <<endl;
}

void deleteArray(char* &name, int *size)
{
	//this will deallocate the memory space
	delete [] name;
	

	name = NULL;
	
}


