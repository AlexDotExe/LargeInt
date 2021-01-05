//Alex Rosa
//3/22/2016
//Purpose: Create a class called LargeInt to allow users to store and manipulate very large integers.

#include "LargeInt.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

istream& operator>>(istream& in, LargeInt& lar)
{
	string str;
	int x = 0;
	while(x < 1) 
	{	//Input occurs here
		getline(in, str);
		for (int i = 0; i < str.length(); i++) 
			//Input Validation
			if (str.length() > lar.max) { cout << "The max amount of digits allowed is" << lar.max << "please re-enter: "; x--; break; }
			
			else if (str.at(i) < 48 || str.at(i) > 57) {
				cout << "There are invalid characters in the number, please re-enter: ";
				x--; break;}
			
			else lar.Larray[i] = str.at(i) - 48;
		
			//Sets length if everything is good
			 lar.length = str.length(); x++; 
		}
	//SETS EVERY CHARACTER AS AN ELEMENT 
		return in;
}

ostream& operator<<(ostream& out, LargeInt& lar)
{
	for (int i = 0; i < lar.length; i++) cout << lar.Larray[i];
	return out;
}


LargeInt::LargeInt(int m)
{
	length = 1;
	max = m;
	Larray = new int[max];
}


LargeInt:: ~LargeInt()
{
	delete[] Larray;
	Larray = NULL;
}


LargeInt::LargeInt(const LargeInt& lar)
{
	max = lar.max;
	length = lar.length;
	Larray = new int[max];

	for (int i = 0; i < length; i++)
	{
		Larray[i] = lar.Larray[i];
	}
}



LargeInt LargeInt:: operator+(LargeInt& lar)
{
	//
	LargeInt temp;
	//Used to hold carry over value
	int hold = 0;
	//used to hold original length of either length or lar.length if they have been changed
	int lhold = 0;
	//used to indicate which instance's length has been modified
	int flag =0;

	if (length > lar.length) {
		for (int i = lar.length - 1, b = length - 1; b >= 0; i--, b--)
			if (i >= 0)lar.Larray[b] = lar.Larray[i];
			else lar.Larray[b] = 0;
			lhold = lar.length; lar.length = length; flag = 1;
	}
		
		if (length < lar.length) {
			temp.length = lar.length;
			for (int i = lar.length - 1, b = length - 1; i >= 0; i--, b--)
				if (b >= 0)  Larray[i] = Larray[b];
				else Larray[i] = 0;
				lhold = length; length = lar.length; flag = 2;
		}
	
	else temp.length = length;

	

	//Adds the two large integers,starts at last element/ones place
	for(int i = temp.length-1; i >= 0; i--)
	{
		temp.Larray[i] = Larray[i] + lar.Larray[i] + hold;
		if (temp.Larray[i] > 9)   {
			hold = 1;
			temp.Larray[i] -= 10; }
		else hold = 0;
	}

	//If hold still has 1 then extend length and add 
	if (hold == 1){
		temp.length++;
		for (int i = temp.length-1; i>0;i--)
		temp.Larray[i] = temp.Larray[i-1];
		temp.Larray[0] = 1;
	}
	
	if (flag==1)
		for (int i = 1, b = 0; i < length; i++)
			if (lar.Larray[i] != 0 && b == 0) { lar.Larray[b] = lar.Larray[i]; b++; lar.length = lhold; }
			else if(b!=0) { lar.Larray[b] = lar.Larray[i]; b++;  }
	
	else if (flag==2)
		for (int i = 1, b = 0; i < lar.length; i++)
			if (Larray[i] != 0 && b == 0) { Larray[b] = Larray[i]; b++; length = lhold; }
			else if(b!=0) { Larray[b] = Larray[i]; b++;}

			return temp;
}

LargeInt LargeInt:: operator=(const LargeInt& lar)
{
	//Verification of no self copy
	if (this != &lar){
		length = lar.length;
		for (int i = 0; i < length; i++)
		Larray[i] = lar.Larray[i];
		return *this;
	}

	else return *this;
}

bool LargeInt:: operator==(LargeInt& lar)
{
	if (length != lar.length)return false;
	
	else for (int i = 0; i < lar.length; i++)
		 if (Larray[i] != lar.Larray[i]) 
		 return false;
			
	return true;
}