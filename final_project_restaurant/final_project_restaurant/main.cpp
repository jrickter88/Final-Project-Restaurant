#include <iostream>
#include <iomanip>
#include "salad.h"
#include "beverage.h"
#include "sandwich.h"
#include "appetizer.h"

using namespace std;

void printMenu(beverage, appetizer, salad, sandwich);
int getNumApp();
int getNumBev();
int getNumSalad();
int getNumSandwich();
int chooseApp(appetizer);
int chooseBeverage(beverage);
int chooseSandwich(sandwich);
int chooseSalad(salad);

int main()
{
	//************declare objects in order to print menu prefix them with 'my'
	appetizer myApp;
	salad mySalad;
	beverage myBeverage;
	sandwich mySandwich;
	appetizer* yourApps;
	beverage* yourBeverages;
	salad* yourSalads;
	sandwich* yourSandwiches;
	//***************declare neccessary variables
	int appChoice = -1;
	int bevChoice = -1;
	int saladChoice = -1;
	int sandwichChoice = -1;
	int numApps = 0;
	int numBev = 0;
	int numSalad = 0;
	int numSandwich = 0;
	double appTotalDue = 0;
	double bevTotalDue = 0;
	double saladTotalDue = 0;
	double sandwichTotalDue = 0;
	double billTotalDue = 0;

	cout << fixed << showpoint << setprecision(2);
	//*********************display menu
	printMenu(myBeverage, myApp, mySalad, mySandwich);

	system("pause");

	//*******************app section
	numApps = getNumApp();

	yourApps = new appetizer[numApps];

	for(int i = 0; i < numApps; i++)
	{
		appChoice = chooseApp(myApp);
		yourApps[i].setChoice(appChoice);
		appTotalDue+= yourApps[i].getPrice();
		system("pause");
		system("cls");

	}

	system("pause");
	
	//****************beverage section
	numBev = getNumBev();
	yourBeverages = new beverage[numBev];

	for(int i = 0; i < numBev; i++)
	{
		bevChoice = chooseBeverage(myBeverage);
		yourBeverages[i].setChoice(bevChoice);
		bevTotalDue+= yourBeverages[i].getPrice();
		system("pause");
		system("cls");

	}

	//*********************salad section
	numSalad = getNumSalad();
	yourSalads = new salad[numSalad];

	for(int i = 0; i < numBev; i++)
	{
		saladChoice = chooseSalad(mySalad);
		yourSalads[i].setChoice(saladChoice);
		saladTotalDue+= yourSalads[i].getPrice();
		system("pause");
		system("cls");

	}

		//*********************sandwich section
	numSandwich = getNumSandwich();
	yourSandwiches = new sandwich[numSandwich];

	for(int i = 0; i < numBev; i++)
	{
		sandwichChoice = chooseSandwich(mySandwich);
		yourSandwiches[i].setChoice(sandwichChoice);
		sandwichTotalDue+= yourSandwiches[i].getPrice();
		system("pause");
		system("cls");

	}

	billTotalDue = appTotalDue + bevTotalDue + saladTotalDue + sandwichTotalDue;
	billTotalDue = billTotalDue * 1.2;
	cout << billTotalDue << "********************************bill total";

	system("pause");
	return 0;
}
//*******************************end main*******************************************************************
//					*******************************

void printMenu(beverage, appetizer, salad, sandwich)
{
	beverage myBeverage;
	appetizer myApp;
	salad mySalad;
	sandwich mySandwich;

	cout << "\t\tWelcome to Rem0nstraunt" << endl;
	cout << "\t\t***********************" << endl << endl << endl;

	myBeverage.print();
	myApp.print();
	mySalad.print();
	mySandwich.print();



}
//**************************** end print menu***************************************
//************************************************app functions

int getNumApp()
{
	int numApps;
	do
	{
		cout << "How many appetizers do you plan on ordering?" << endl;
		cin >> numApps;
		if(numApps < 0)
			cout << "That's an impossibility.  Please enter a non-negative number" << endl;
	}while(numApps < 0);

	return numApps;
}

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
						cout << "Right now, a bowl of soup would be nice." << endl;
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
//***************************************************end  app  functions

//**************************************************beverage functions
int getNumBev()
{
	int numBev;
	do
	{
		cout << "How many beverages do you plan on ordering?" << endl;
		cin >> numBev;
		if(numBev < 0)
			cout << "That's an impossibility.  Please enter a non-negative number" << endl;
	}while(numBev < 0);

	return numBev;
}

int chooseBeverage(beverage)
{
	beverage myBev;

	
	char choice;
	int bevChoice;

			
			do
			{
//				system("cls");
				cout << "Excellent.  Please select your choice by number. (1 - 5)" << endl;
				myBev.print();

				cin >> bevChoice;

				if(bevChoice == 1 || bevChoice == 2 || bevChoice == 3 || bevChoice == 4 || bevChoice == 5)
				{
					switch(bevChoice)
					{
					case 1:
						cout << "A delicious soda." << endl;
						break;
					case 2:
						cout << "Milk.  It does a body good." << endl;
						break;
					case 3:
						cout << "A nice refreshing glass of juice." << endl;
						break;
					case 4:
						cout << "Iced tea.  So yummy on a hot day." << endl;
						break;
					case 5:
						cout << "We have the best cup of coffee.  Good choice." << endl;
						break;
					}

					return bevChoice;
				}
				else
				{
					cout << "I'm sorry, that's not a valid option.  Please choose a number from 1 to 5" << endl;
					system("pause");
				}

			}while(bevChoice != 1 || bevChoice != 2 || bevChoice != 3 || bevChoice != 4 || bevChoice != 5);
}

//*****************************************end beverage functions

//*******************************start salad functions

int getNumSalad()
{
	int numSalad;
	do
	{
		cout << "How many salads do you plan on ordering?" << endl;
		cin >> numSalad;
		if(numSalad < 0)
			cout << "That's an impossibility.  Please enter a non-negative number" << endl;
	}while(numSalad < 0);

	return numSalad;
}

int chooseSalad(salad)
{
	salad mySalad;

	
	char choice;
	int saladChoice;

			
			do
			{
//				system("cls");
				cout << "Excellent.  Please select your choice by number. (1 - 5)" << endl;
				mySalad.print();

				cin >> saladChoice;

				if(saladChoice == 1 || saladChoice == 2 || saladChoice == 3 || saladChoice == 4 || saladChoice == 5)
				{
					switch(saladChoice)
					{
					case 1:
						cout << "A house salad.  A nice start to any meal." << endl;
						break;
					case 2:
						cout << "It's a meal.  It's  a salad.  It's a chef salad!" << endl;
						break;
					case 3:
						cout << "A delicious, grilled chicken breast on a bed of greens." << endl;
						break;
					case 4:
						cout << "The cobb salad has a bit of everything: egg, bacon, turkey... Yum!" << endl;
						break;
					case 5:
						cout << "A lighter option, the tuna plate." << endl;
						break;
					}

					return saladChoice;
				}
				else
				{
					cout << "I'm sorry, that's not a valid option.  Please choose a number from 1 to 5" << endl;
					system("pause");
				}

			}while(saladChoice != 1 || saladChoice != 2 || saladChoice != 3 || saladChoice != 4 || saladChoice != 5);
}

//********************************************************************************
//						end salad functions

//*************************************************************************
//						start sandwich functions
int getNumSandwich()
{
	int numSandwich;
	do
	{
		cout << "How many sandwiches do you plan on ordering?" << endl;
		cin >> numSandwich;
		if(numSandwich < 0)
			cout << "That's an impossibility.  Please enter a non-negative number" << endl;
	}while(numSandwich < 0);

	return numSandwich;
}

int chooseSandwich(sandwich)
{
	sandwich mySandwich;

	
	char choice;
	int sandwichChoice;

			
			do
			{
//				system("cls");
				cout << "Excellent.  Please select your choice by number. (1 - 5)" << endl;
				mySandwich.print();

				cin >> sandwichChoice;

				if(sandwichChoice == 1 || sandwichChoice == 2 || sandwichChoice == 3 || sandwichChoice == 4 || sandwichChoice == 5)
				{
					switch(sandwichChoice)
					{
					case 1:
						cout << "The best Philly steak not found in Philly." << endl;
						break;
					case 2:
						cout << "Corned beef, stacked high." << endl;
						break;
					case 3:
						cout << "A grilled chicken breast on your choice of bread." << endl;
						break;
					case 4:
						cout << "Corned beef, swiss cheese, thousand island dressing, on rye.  Woo!" << endl;
						break;
					case 5:
						cout << "Egg salad, just like mom used to make." << endl;
						break;
					}

					return sandwichChoice;
				}
				else
				{
					cout << "I'm sorry, that's not a valid option.  Please choose a number from 1 to 5" << endl;
					system("pause");
				}

			}while(sandwichChoice != 1 || sandwichChoice != 2 || sandwichChoice != 3 || sandwichChoice != 4 || sandwichChoice != 5);
}