/*
	Assignment 7:	Dr. Mutsumi Nakamura
	Student:		Jan Christian Chavez-Kortlang
	Email:			jchavezk@asu.edu
	ID:				1202073942

	Description: Contains the main function.
*/

#include "Assignment7.h"

int main()
{
	sizePrompt();
	cin >> graphSize;
	cout << graphSize << endl;
	//Flush the buffer.
	cin.ignore(20, '\n');

	//Read the blank line.
	getline(cin, input);

	graph = new Graph(graphSize);
	nodePrompt();

	do
	{
		getline(cin, input);
		processNode(input);
	} while(!input.empty());

	graph->DepthFirstSearch();

	graph->printFounders();
	graph->printDiscoverTimes();
	graph->printFinishTimes();

	return 1;
};

void processNode(string input)
{
	if (input.empty())
		return;

	string token;

	//Extracts the name and creates a new node using it.
	token = extractToken(input, " ");
	GraphNode* node = new GraphNode(token, graphSize);
	graph->insertNode(*node);

	do
	{
		//Extracts a token with the format "string(int)", and links it to the node created above.
		token = extractToken(input, " ");
		processLinks(token, node);
	} while (input.compare(token) != 0);
}

void processLinks(string token, GraphNode* node)
{
	string nameToken;
	string weightToken;
	int weight;

	nameToken = extractToken(token, "(");

	weightToken = extractToken(token, ")");
	weight = strToInt(weightToken);

	node->addLink(nameToken, weight);
}

void sizePrompt()
{
	cout << "Input the number of nodes." << endl;
}

void nodePrompt()
{
	cout << "Input the node data.\nFormat: NodeName Child_1(weight_1) Child_2(weight_2) ... Child_n(weight_n)" << endl;
}
