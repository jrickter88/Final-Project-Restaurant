#include <iostream>
#include <iomanip>
#include <fstream>
#include "salad.h"
#include "beverage.h"
#include "sandwich.h"
#include "appetizer.h"
#include "exception.h"
#include "invalidNum.h"

using namespace std;
//prototype functions
void printMenu(beverage, appetizer, salad, sandwich);
int getNumApp();
int getNumBev();
int getNumSalad();
int getNumSandwich();
int chooseApp(appetizer);
int chooseBeverage(beverage);
int chooseSandwich(sandwich);
int chooseSalad(salad);
int diningChoice();

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
	int inOrOut = 0;
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
	//************************dine in or carry-out
	inOrOut = diningChoice();

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


	
	myBeverage.print();
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

	mySalad.print();
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
	
	mySandwich.print();
		//*********************sandwich section
	numSandwich = getNumSandwich();
	yourSandwiches = new sandwich[numSandwich];
	//ordering sandwiches loop
	for(int i = 0; i < numBev; i++)
	{
		sandwichChoice = chooseSandwich(mySandwich);
		yourSandwiches[i].setChoice(sandwichChoice);
		sandwichTotalDue+= yourSandwiches[i].getPrice();
		system("pause");
		system("cls");

	}
	//Calculate the bill total
	billTotalDue = appTotalDue + bevTotalDue + saladTotalDue + sandwichTotalDue;
	//Add tax
	billTotalDue = billTotalDue * 1.06;
	//Add gratuity if dining in.
	if(inOrOut == 1)
		billTotalDue = billTotalDue * 1.2;
	
	cout << billTotalDue << "\n********************************bill total********************************";
	
	ofstream ofs;
    	ofs.open ("receipt.txt");

    	if (ofs.is_open())
    	{
		ofs << "Your total bill" << "\n";
		ofs << "Appetizers $" << appTotalDue << "\n";
		ofs << "Beverages $" << bevTotalDue << "\n";
		ofs << "Salads $" << saladTotalDue << "\n";
		ofs << "Sandwiches $" << sandwichTotalDue << "\n";
		ofs << fixed << showpoint << setprecision(2);
		ofs << "Your total bill comes out to $" << billTotalDue << "\n";
		std::cout << "\nYour receipt is saved to Receipt.txt\n";
		ofs.close();
	}
	else

    {
	  std::cout << "Error opening file";
    }

	system("pause");
	return 0;
}
//*******************************end main*******************************************************************
//					*******************************
//*************************************dine in or carry out
int diningChoice()
{
	int choice = 0;
	

	do{
		try
			{
				cout << "Will this be 1) dine in or 2) carry-out?" << endl;
				cin >> choice;
		
				if (cin.fail()) 
					throw notANum();
				else if(choice < 1 || choice > 2)
					throw invalidNum();
				
			}
		catch (notANum errorObj)
			{
				cout << errorObj.what() << endl;
				cin.clear();
				cin.ignore();
			}
		catch (invalidNum errorObj)
		{
			cout << errorObj.what() << endl;
		}
				
		}
	while(choice < 1 || choice > 2 || !cin);
	return choice;
			
}

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
		try
		{
		cout << "How many appetizers do you plan on ordering?" << endl;
		cin >> numApps;
		if(cin.fail())
			throw notANum();
		else if(numApps < 0)
			throw invalidNum();
		}
		catch (invalidNum errorObj)
		{
			cout << errorObj.what() << endl;
			system ("pause");
			system ("cls");
		}
		catch (notANum errorObj)
		{
			cout << errorObj.what() << endl;
			cin.clear();
			cin.ignore();
			system ("pause");
			system ("cls");
		}
	}while(numApps < 0);
	
	system("cls");
	
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
				try
				{
					cin >> appChoice;
					
					if (cin.fail())
						throw notANum();
					if (appChoice != 1 && appChoice != 2 && appChoice != 3 && appChoice != 4 && appChoice != 5)
						throw invalidNum();
				}
				catch (notANum errorObj)
				{
					cout << errorObj.what() << endl;
					cin.clear();
					cin.ignore();
					system ("pause");
					system ("cls");
				}
				catch (invalidNum errorObj)
				{
					cout << errorObj.what() << endl 
						 <<"You must enter a number between 1 and 5. Try again." << endl;
					system ("pause");
					system ("cls");
				}

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
					system("pause");
					system("cls");
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
		try
		{
		cout << "How many drinks do you plan on ordering?" << endl;
		
		cin >> numBev;
		
		if(cin.fail())
			throw notANum();
		
		else if(numBev < 0)
			throw invalidNum();
		}
		
		catch (notANum errorObj)
		{
			cout << errorObj.what() << endl;
			cin.clear();
			cin.ignore();
			system ("pause");
			system ("cls");
		}
		
		catch (invalidNum errorObj)
		{
			cout << errorObj.what() << endl;
			system ("pause");
			system ("cls");
		}
				
	}while(numBev < 0);

	system("cls");

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

				try
				{
					cin >> bevChoice;
					
					if (cin.fail())
						throw notANum();
					if (bevChoice != 1 && bevChoice != 2 && bevChoice != 3 && bevChoice != 4 && bevChoice != 5)
						throw invalidNum();
				}
				catch (notANum errorObj)
				{
					cout << errorObj.what() << endl;
					cin.clear();
					cin.ignore();
					system ("pause");
					system ("cls");
				}
				catch (invalidNum errorObj)
				{
					cout << errorObj.what() << endl 
						 <<"You must enter a number between 1 and 5. Try again." << endl;
					system ("pause");
					system ("cls");
				}

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
	
					system("pause");
					system("cls");
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
		try
		{
			cout << "How many salads do you plan on ordering?" << endl;
			cin >> numSalad;
		if(cin.fail())
			throw notANum();
		else if(numSalad < 0)
			throw invalidNum();
		}
		catch (invalidNum errorObj)
		{
			cout << errorObj.what() << endl;
			system ("pause");
			system ("cls");
		}
		catch (notANum errorObj)
		{
			cout << errorObj.what() << endl;
			cin.clear();
			cin.ignore();
			system ("pause");
			system ("cls");
		}
	}while(numSalad < 0);

	system("cls");

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

				try
				{
					cin >> saladChoice;
					
					if (cin.fail())
						throw notANum();
					if (saladChoice != 1 && saladChoice != 2 && saladChoice != 3 && saladChoice != 4 && saladChoice != 5)
						throw invalidNum();
				}
				catch (notANum errorObj)
				{
					cout << errorObj.what() << endl;
					cin.clear();
					cin.ignore();
					system ("pause");
					system ("cls");
				}
				catch (invalidNum errorObj)
				{
					cout << errorObj.what() << endl 
						 <<"You must enter a number between 1 and 5. Try again." << endl;
					system ("pause");
					system ("cls");
				}

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
					system("pause");
					system("cls");
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
		try
		{
		cout << "How many sandwiches do you plan on ordering?" << endl;
		cin >> numSandwich;
		if(cin.fail())
			throw notANum();
		else if(numSandwich < 0)
			throw invalidNum();
		}
		catch (invalidNum errorObj)
		{
			cout << errorObj.what() << endl;
			system ("pause");
			system ("cls");
		}
		catch (notANum errorObj)
		{
			cout << errorObj.what() << endl;
			cin.clear();
			cin.ignore();
			system ("pause");
			system ("cls");
		}
	}while(numSandwich < 0);

	system("cls");

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

				try
				{
					cin >> sandwichChoice;
					
					if (cin.fail())
						throw notANum();
					if (sandwichChoice != 1 && sandwichChoice != 2 && sandwichChoice != 3 && sandwichChoice != 4 && sandwichChoice != 5)
						throw invalidNum();
				}
				catch (notANum errorObj)
				{
					cout << errorObj.what() << endl;
					cin.clear();
					cin.ignore();
					system ("pause");
					system ("cls");
				}
				catch (invalidNum errorObj)
				{
					cout << errorObj.what() << endl 
						 <<"You must enter a number between 1 and 5. Try again." << endl;
					system ("pause");
					system ("cls");
				}

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
					system("pause");
					system("cls");
				}

			}while(sandwichChoice != 1 || sandwichChoice != 2 || sandwichChoice != 3 || sandwichChoice != 4 || sandwichChoice != 5);
}
