#include <string>
#include <iostream>
#include <iomanip>
#include "beverage.h"

using namespace std;

void beverage::setChoice(int i)
{
	string t[] = {"Soft drinks", "Milk", "Juice", "Iced tea", "Coffee"};
	double p[] = {1.95, 2.00, 2.50, 1.95, 1.75};

	switch (i)
	{
	case 1:
		type = t[0];
		price = p[0];
		break;
	case 2:
		type = t[1];
		price = p[1];
		break;
	case 3:
		type = t[2];
		price = p[2];
		break;
	case 4:
		type = t[3];
		price = p[3];
		break;
	case 5:
		type = t[4];
		price = p[4];
		break;
	default:
		type = "That is not a valid selection";
		price = 0.00;
		break;

	}

}

string beverage::getChoice() const
{
	return type;
}

double beverage::getPrice() const
{
	return price;
}

void beverage::print() const
{
	string t[] = {"Soft drinks", "Milk", "Juice", "Iced tea", "Coffee"};
	double p[] = {1.95, 2.00, 2.50, 1.95, 1.75};

	cout << "\tBEVERAGES" << endl << "\t*********" << endl;

	for(int i = 0; i < 5; i++)
	{
		cout << fixed << showpoint << setprecision(2);
		if(i == 0 || i == 3 || i == 4)
			cout << i +1 <<")" << t[i] << "\t\t$" << p[i] << endl;
		else
			cout << i +1 <<")" << t[i] << "\t\t\t$" << p[i] << endl;
	}
	cout << endl << endl;

}

beverage::beverage()
{
	int i = 0;
	setChoice(i);
}

beverage::beverage(int i)
{
	setChoice(i);
}

