#include <string>
#include <iostream>
#include "salad.h"

using namespace std;

void salad::setChoice(int i)
{
	string t[] = {"House salad", "Chef salad", "Chicken salad", "Cobb salad", "Tuna plate"};
	double p[] = {3.59, 7.85, 6.95, 8.25, 5.95};

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

string salad::getChoice() const
{
	return type;
}

double salad::getPrice() const
{
	return price;
}

void salad::print() const
{
	string t[] = {"House salad", "Chef salad", "Chicken salad", "Cobb salad", "Tuna plate"};
	double p[] = {3.59, 7.85, 6.95, 8.25, 5.95};

	cout << "\tSALADS" << endl << "\t******" << endl;

	for(int i = 0; i < 5; i++)
	{
		cout << i +1 <<")" << t[i] << "\t$" << p[i] << endl;
	}
	cout << endl << endl;

}

salad::salad()
{
	int i = 0;
	setChoice(i);
}

salad::salad(int i)
{
	setChoice(i);
}

