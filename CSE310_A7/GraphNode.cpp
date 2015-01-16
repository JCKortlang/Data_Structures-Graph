/*
	Assignment 7:	Dr. Mutsumi Nakamura
	Student:		Jan Christian Chavez-Kortlang
	Email:			jchavezk@asu.edu
	ID:				1202073942

	Description: Function definitions of the GraphNode
*/

#include "GraphNode.h"

GraphNode::GraphNode()
{
	m_weight = -1;
	m_discoverTime = -1;
	m_finishTime = -1;
	m_nodeColor = White;
}
GraphNode::GraphNode(string name, int graphDimension)
{
	m_weight = -1;
	m_discoverTime = -1;
	m_finishTime = -1;
	m_nodeColor = White;
	m_name = name;
	m_linkWeightArrayLength = graphDimension;
	m_linkWeightArray = new int [graphDimension];
}
GraphNode::~GraphNode()
{
	if (m_linkWeightArray != NULL)
		delete[] m_linkWeightArray;
}
void GraphNode::addLink(string linkID, int linkWeight)
{
	int index = strToIndex(linkID);
	m_linkWeightArray[index] = linkWeight;
	m_linkCount++;
}
