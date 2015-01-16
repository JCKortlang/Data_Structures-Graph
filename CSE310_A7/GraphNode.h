/*
	Assignment 7:	Dr. Mutsumi Nakamura
	Student:		Jan Christian Chavez-Kortlang
	Email:			jchavezk@asu.edu
	ID:				1202073942

	Description: Base data structure for of the Graph. It contains all of the properties required by the specifications.
*/

#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include "NodeColor.h"
#include "Utility.h"

class GraphNode
{
public:
	GraphNode();
	GraphNode(string name, int graphDimension);
	~GraphNode();

	void addLink(string linkID, int linkWeight);

	string getName()
	{
		return m_name;
	}
	int getWeight()
	{
		return m_weight;
	}
	int getDiscoverTime()
	{
		return m_discoverTime;
	}
	int getFinishTime()
	{
		return m_finishTime;
	}
	Color getColor()
	{
		return m_nodeColor;
	}
	int getFounderIndex()
	{
		return m_founderIndex;
	}
	int* getLinkWeightArray()
	{
		return m_linkWeightArray;
	}
	int getLinkWeightArrayLength()
	{
		return m_linkWeightArrayLength;
	}

	void setName(string name)
	{
		m_name = name;
	}
	void setDiscoverTime(int discoverTime)
	{
		m_discoverTime = discoverTime;
	}
	void setFinishTime(int finishTime)
	{
		m_finishTime = finishTime;
	}
	void setColor(Color color)
	{
		m_nodeColor = color;
	}
	void setFounderIndex(int founderIndex)
	{
		m_founderIndex = founderIndex;
	}

private:
	//Member variables
	string m_name;
	int m_weight;
	int m_discoverTime;
	int m_finishTime;
	int m_founderIndex;
	Color m_nodeColor;
	int* m_linkWeightArray;
	int m_linkWeightArrayLength;
	int m_linkCount;
};
#endif
