i//Alex Rosa
//3/22/2016
//Purpose: Create a class called LargeInt to allow users to store and manipulate very large integers.
#include <iostream>
using namespace std;

#ifndef LargeInt_h
#define LargeInt_h


class LargeInt
{
	//To overload the >> operator as a nonmember function
	friend istream& operator>>(istream&, LargeInt&);

	//To overload the << operator as a nonmember function
	friend ostream& operator<<(ostream&, LargeInt&);

private:
	//Members variables
	//Holds all the integers
	int *Larray;
	//Holds the total array size
	int max;
	//Holds the array length
	int length;


public:
	// Constructor with default constructor
	LargeInt(int max = 500);

	//Copy constructor
	LargeInt(const LargeInt& other);

	//Destructor
	~LargeInt();

	//To overload operator+ to support addition of LargeInt values
	LargeInt operator+(LargeInt&);

	//To overload the assignment operator =
	LargeInt operator=(const LargeInt&);

	//To overload the comparison operator ==
	bool operator==(LargeInt&);


};
#endif