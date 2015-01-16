/*
	Assignment 7:	Dr. Mutsumi Nakamura
	Student:		Jan Christian Chavez-Kortlang
	Email:			jchavezk@asu.edu
	ID:				1202073942

	Description: Data structure which contains a set of GraphNodes
*/

#ifndef GRAPH_H
#define GRAPH_H

#include "GraphNode.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Graph
{
public:
	Graph();
	Graph(int dimension);
	~Graph();

	void insertNode(GraphNode& node);
	void DepthFirstSearch();

	void printFounders();
	void printDiscoverTimes();
	void printFinishTimes();

private:
	void reInitialize();
	void DFSVisit(int index);

	unsigned int m_dimension;
	unsigned int m_time;
	GraphNode* m_nodeArray;
};
#endif
