#include <string>
#include "sandwich.h"
#include <iostream>
using namespace std;

void sandwich::setChoice(int i)
{
	string t[] = {"Philly steak", "Stacked corn beef", "Chicken sandwich", "Reuben", "Egg salad"};
	double p[] = {9.35, 9.25, 5.35, 6.95, 3.95};

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

string sandwich::getChoice() const
{
	return type;
}

double sandwich::getPrice() const
{
	return price;
}

void sandwich::print() const
{
	string t[] = {"Philly steak", "Stacked corn beef", "Chicken sandwich", "Reuben", "Egg salad"};
	double p[] = {9.35, 9.25, 5.35, 6.95, 3.95};

	cout << "\tSANDWICHES" << endl << "\t**********" << endl;

	for(int i = 0; i < 5; i++)
	{
		cout << i +1 <<")" << t[i] << "\t$" << p[i] << endl;
	}

	cout << endl << endl;
}

sandwich::sandwich()
{
	int i = 0;
	setChoice(i);
}

sandwich::sandwich(int i)
{
	setChoice(i);
}

