#ifndef invalidNum_H
#define invalidNum_H
#include <string>

using namespace std;

class invalidNum
{
public:
	invalidNum()
	{
		message = "Invalid input. Please enter a valid number.";
		
	}
	invalidNum (string e)
	{
		message = e;
	}
	string what()
	{
		return message;
	}
private:
	string message;
	
};
#endif