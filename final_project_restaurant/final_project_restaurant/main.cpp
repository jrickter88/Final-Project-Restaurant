#include <iostream>
#include <iomanip>
#include "salad.h"
#include "beverage.h"
#include "sandwich.h"
#include "appetizer.h"

using namespace std;

void printMenu();

int main()
{
	appetizer myApp;
	salad mySalad;
	beverage myBeverage;
	sandwich mySandwich;

	printMenu();

	myBeverage.print();
	myApp.print();
	mySalad.print();
	mySandwich.print();


	system("pause");
	return 0;
}
//*******************************end main


void printMenu()
{
	cout << "\t\tWelcome to Rem0nstraunt" << endl;
	cout << "\t\t***********************" << endl << endl << endl;



}

