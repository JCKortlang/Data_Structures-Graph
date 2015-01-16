/*
	Assignment 7:	Dr. Mutsumi Nakamura
	Student:		Jan Christian Chavez-Kortlang
	Email:			jchavezk@asu.edu
	ID:				1202073942

	Description: Contains the definitions of crucial Graph functions.
*/

#include "Graph.h"

Graph::Graph(){};

Graph::Graph(int dimension)
{
	m_dimension = dimension;
	m_nodeArray = new GraphNode[dimension];
}

Graph::~Graph()
{
	if (m_nodeArray != NULL)
		delete[] m_nodeArray;
}

void Graph::insertNode(GraphNode& node)
{
	int nodeIndex = strToIndex(node.getName());
	m_nodeArray[nodeIndex] = node;
}

void Graph::DFSVisit(int index)
{
	int* weightArray = m_nodeArray[index].getLinkWeightArray();
	int weightArrayLength = m_nodeArray[index].getLinkWeightArrayLength();

	// Once a node has been visitied it is marked as gray.
	m_nodeArray[index].setColor(Gray);
	m_nodeArray[index].setDiscoverTime(++m_time);

	// Iterates through each  of the node's linked nodes an recursively calls itself. 
	// It returns when a node's links have all previously been visited.
	for (int i = 0; i < weightArrayLength; i++)
	{
		GraphNode* linkedGraphNode;
		if (weightArray[i] > 0)
		{
			linkedGraphNode = &m_nodeArray[i];
			if (linkedGraphNode->getColor() == White)
			{
				linkedGraphNode->setFounderIndex(index);
				DFSVisit(i);
			}
		}
	}
	// A node whose links have all been visited is marked as black.
	m_nodeArray[index].setColor(Black);
	m_nodeArray[index].setFinishTime(++m_time);
}

void Graph::DepthFirstSearch()
{
	reInitialize();

	for (int i = 0; i < m_dimension; i++)
	{
		if (m_nodeArray[i].getColor() == White)
		{
			DFSVisit(i);
		}
	}
}

/*
	Resets the values of all of the graph's nodes prior to a Depth First Search.
*/
void Graph::reInitialize()
{
	for (int i = 0; i < m_dimension; i++)
	{
		m_nodeArray[i].setColor(White);
		m_nodeArray[i].setFounderIndex(-1);
	}
	m_time = 0;
}

/*
	Prints the pi values according to the specifications.
*/
void Graph::printFounders()
{
	int founderIndex;

	cout << "\nThe pi array contents:\n" << endl;

	for (int i = 0; i < m_dimension; i++)
	{
		string output = "pi[" + m_nodeArray[i].getName() + "] = ";
		founderIndex = m_nodeArray[i].getFounderIndex();

		if (founderIndex == -1)
		{
			output += "none";
		}
		else
		{
			output += m_nodeArray[founderIndex].getName();
		}
		cout << output << endl;
	}
}

/*
	Prints the d values according to the specifications.
*/
void Graph::printDiscoverTimes()
{
	cout << "\nThe d array contents:\n" << endl;

	for (int i = 0; i < m_dimension; i++)
	{
		cout << "d[" << m_nodeArray[i].getName() << "] = "
			<< m_nodeArray[i].getDiscoverTime() << endl;
	}
}

/*
	Prints the f values according to the specifications.
*/
void Graph::printFinishTimes()
{
	cout << "\nThe f Array Contents:\n" << endl;

	for (int i = 0; i < m_dimension; i++)
	{
		cout << "f[" << m_nodeArray[i].getName() << "] = "
			<< m_nodeArray[i].getFinishTime() << endl;
	}
}
