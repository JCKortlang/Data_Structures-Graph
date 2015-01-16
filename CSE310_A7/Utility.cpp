/*
Assignment 7:	Dr. Mutsumi Nakamura
Student:		Jan Christian Chavez-Kortlang
Email:			jchavezk@asu.edu
ID:				1202073942

Description: Definitions of the utility functions for string manipulation.
*/

#include "Utility.h"

int strToIndex(string name)
{
	//Ensures the string is in the desired case for the following operation.
	std::transform(name.begin(), name.end(), name.begin(), ::toupper);
	return name[0] - 65;
}

int strToInt(string number)
{
	return atoi(number.c_str());
}

string extractToken(string& input, string delimeter)
{
	if (input.empty() || delimeter.empty())
		return NULL;

	string token;
	int delimeterIndex;

	while (token.empty() || token.compare(" ") == 0)
	{
		delimeterIndex = input.find(delimeter);
		token = input.substr(0, delimeterIndex);
		input.erase(0, delimeterIndex + delimeter.length());
	}
	return token;
}
