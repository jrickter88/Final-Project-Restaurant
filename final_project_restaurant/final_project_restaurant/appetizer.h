#ifndef appetizer_H
#define appetizer_H
#include <string>

using namespace std;

class appetizer
{
public:
	void setChoice(int i);

	string getChoice() const;

	void setPrice(int i);

	double getPrice() const;

	void print() const;

	appetizer();

	appetizer(int i);

private:
	string type;
	double price;



}

#endif