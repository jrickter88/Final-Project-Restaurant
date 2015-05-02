#include <iostream>
#include <iomanip>
#include "salad.h"
#include "beverage.h"
#include "sandwich.h"
#include "appetizer.h"

using namespace std;

void printMenu();
int chooseApp(appetizer);
int chooseBeverage();
int chooseSandwich();
int chooseSalad();

int main()
{
	//************declare objects in order to print menu prefix them with 'my'
	appetizer myApp;
	salad mySalad;
	beverage myBeverage;
	sandwich mySandwich;
	appetizer* yourApps;

	//***************declare neccessary variables
	int appChoice = -1;
	int beverageChoice = -1;
	int saladChoice = -1;
	int sandwichChoice = -1;
	int numApps;

	char appOption;
	char beverageOption;
	char saladOption;
	char sandwichOption;
	
	//*********************display menu
	printMenu();

	myBeverage.print();
	myApp.print();
	mySalad.print();
	mySandwich.print();

	system("pause");

	//*******************app section
	do
	{
		cout << "How many appetizers do you plan on ordering?" << endl;
		cin >> numApps;
		if(numApps < 0)
			cout << "That's an impossibility.  Please enter a non-negative number" << endl;
	}while(numApps < 0);

	yourApps = new appetizer[numApps];

	for(int i = 0; i < numApps; i++)
	{
		appChoice = chooseApp(myApp);
		yourApps[i].setChoice(appChoice);
		system("pause");
		system("cls");

	}
	



	system("pause");
	return 0;
}
//*******************************end main


void printMenu()
{
	cout << "\t\tWelcome to Rem0nstraunt" << endl;
	cout << "\t\t***********************" << endl << endl << endl;



}
//**************************** end print menu

int chooseApp(appetizer)
{
	appetizer myApp;

	
	char choice;
	int appChoice;

			
			do
			{
//				system("cls");
				cout << "Excellent.  Please select your choice by number. (1 - 5)" << endl;
				myApp.print();

				cin >> appChoice;

				if(appChoice == 1 || appChoice == 2 || appChoice == 3 || appChoice == 4 || appChoice == 5)
				{
					switch(appChoice)
					{
					case 1:
						cout << "Jalapeno Sticks.  Spicy" << endl;
						break;
					case 2:
						cout << "Mac and cheese bites.  Cheesy" << endl;
						break;
					case 3:
						cout << "Chicken tenders.  A delicious choice" << endl;
						break;
					case 4:
						cout << "Everyone loves a cup of soup." << endl;
						break;
					case 5:
						cout << "A steaming bowl of soup.  Yum." << endl;
						break;
					}

					return appChoice;
				}
				else
				{
					cout << "I'm sorry, that's not a valid option.  Please choose a number from 1 to 5" << endl;
					system("pause");
				}

			}while(appChoice != 1 || appChoice != 2 || appChoice != 3 || appChoice != 4 || appChoice != 5);
	

}
//*********************end choose app
