#ifndef beverage_H
#define beverage_H
#include <string>

using namespace std;

class beverage
{
public:
	void setChoice(int i);

	string getChoice() const;

	void setPrice(int i);

	double getPrice() const;

	void print() const;

	beverage();

	beverage(int i);

private:
	string type;
	double price;



};

#endif