/*
	Assignment 7:	Dr. Mutsumi Nakamura
	Student:		Jan Christian Chavez-Kortlang
	Email:			jchavezk@asu.edu
	ID:				1202073942

	Description: Utility functions for string manipulation.
*/

#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <algorithm>

using std::string;

int strToIndex(string name);
int strToInt(string number);
string extractToken(string& input, string delimeter);
#endif
