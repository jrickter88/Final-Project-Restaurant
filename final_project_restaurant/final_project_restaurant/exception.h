#ifndef exception_H
#define exception_H
#include <string>

using namespace std;

class notANum
{
public:
	notANum()
	{
		message = "Invalid input. Please enter a number.";
		
	}
	notANum (string e)
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