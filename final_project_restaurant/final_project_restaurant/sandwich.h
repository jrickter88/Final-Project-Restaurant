#pragma once
#ifndef sandwich_H
#define sandwich_H
using namespace std;
#include <string>

class sandwich
{
public:
	void setChoice(int i);

	std::string getChoice() const;

	void setPrice(int i);

	double getPrice() const;

	void print() const;

	sandwich();

	sandwich(int i);

private:
	std::string type;
	double price;



};

#endif