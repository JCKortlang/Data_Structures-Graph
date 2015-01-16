/*
	Assignment 7:	Dr. Mutsumi Nakamura
	Student:		Jan Christian Chavez-Kortlang
	Email:			jchavezk@asu.edu
	ID:				1202073942

	Description: Variable and function definitions for the main file.
*/

#ifndef ASSIGNMENT7_H
#define ASSIGNMENT7_H

#include "Graph.h"

int graphSize = -1;
string input = "";
Graph* graph;

void sizePrompt();
void nodePrompt();
void processNode(string input);
void processLinks(string token, GraphNode* node);


//Testing purposes.
//const string test1 = "Harry Kate(18) Fred(5) Carol(6)";
//const string test2 = "Alice James(25) Daisy(21) Kate(10)";
//const string test3 = "Carol Fred(2) Harry(6) Daisy(12)";
//const string test4 = "Ivy James(16) Bob(24)";
//const string test5 = "Daisy     Carol(12) Alice(21) Elvis(28)";
//const string test6 = "Elvis James(18) Daisy(28) Fred(29)";
//const string test7 = "Kate Alice(10) Fred(14) Harry(18) Gerald(20)";
//const string test8 = "Fred Kate(14) Carol(2) harry(5) Elvis(29)";
//const string test9 = "Gerald Kate(20) Bob(17) James(10)";
//const string test10 = "James Gerald(10) Elvis(18) Alice(25) Ivy(16)";
//const string test11 = "Bob Ivy(24) Gerald(17)";
//
//void unitTest()
//{
//	processNode(test1);
//	processNode(test2);
//	processNode(test3);
//	processNode(test4);
//	processNode(test5);
//	processNode(test6);
//	processNode(test7);
//	processNode(test8);
//	processNode(test9);
//	processNode(test10);
//	processNode(test11);
//}

#endif
