/*
 * Michael Cheng
 * CS 202 Homework 1 
 * Winter 2016
 *
 * adjListNode.h
 *
 */

#include"adjListNode.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdlib>
using namespace std;

Household_information::Household_information():county(NULL),age_group_information(NULL),races(NULL),med_income(NULL)
{

}

Household_information::Household_information(char * co, char * age, char * ra, char * med)
{
    county = new char [(strlen(co)+1)];
    strcpy(county, co);
    
    age_group_information = new char [(strlen(age)+1)];
    strcpy(age_group_information, age);

    races = new char [(strlen(ra)+1)];
    strcpy(races, ra);

    med_income = new char [(strlen(med)+1)];
    strcpy(med_income, med);

}

Household_information::Household_information(const Household_information & from)
{
    if(from.county)
    {
        county = new char [(strlen(from.county)+1)];
        strcpy(county, from.county);

    }
    if(from.age_group_information)
    {
        age_group_information = new char [(strlen(from.age_group_information)+1)];
        strcpy(age_group_information, from.age_group_information);
    }
    if(from.races)
    {
        races = new char [(strlen(from.races)+1)];
        strcpy(races, from.races);
    }
    if(from.med_income)
    {
        med_income = new char [strlen(from.med_income)+1];
        strcpy(med_income, from.med_income);
    }
}

Household_information::~Household_information()
{

}

void Household_information::display()
{
    cout << county<< endl;
    cout << age_group_information <<endl;
    cout << races << endl;
    cout << med_income << endl;
}

adjListNode::adjListNode()
{
	dest = 0;
	next = NULL;
}

adjListNode::adjListNode(char * c, char * a, char * r, char * m):Household_information(c,a,r,m)
{

}

adjListNode::adjListNode(const Household_information & to_copy):Household_information(to_copy)
{

}


adjListNode::~adjListNode()
{

}

adjListNode*&adjListNode::getNext()
{
	return next;
}

void adjListNode::setDest(int d)
{
    dest = d;
}

int adjListNode::getDest()
{
    return dest;

}

adjList::adjList()
{
	head = NULL;
}
adjList::~adjList()
{

}

void adjList::setHead()
{
    head = NULL;

}



graph::graph()
{
    vertex = 10;
    arrayList = new adjList[vertex];

	for(int i = 0; i < vertex; i++)
	{
		arrayList[i].setHead();
	}

}

graph::~graph()
{

}

adjListNode*&adjList::returnHead()
{
    return head;

}

adjListNode * graph::new_adjListNode(int dest, char * c, char * a, char * r, char * m)
{
    adjListNode *newDataNode = new adjListNode(c, a, r, m);
    newDataNode->setDest(dest);
    newDataNode->getNext()=NULL;

    return newDataNode;

}

void graph::g_setUp(int counter, char * c, char * a, char * r, char * m)
{
    int randCord = rand() % 4;
    addEdge(counter, randCord, c, a, r, m); 

}

void graph::h_load()
{
    int counter = 0;
    int s = 100;
    char county[s], age[s], med[s], race[s];
    ifstream load;
    load.open("c.txt");
    if(load)
    {
        while(!load.eof())
        {
            load.getline(county, s, '\n');
            load.getline(age, s, '\n');
            load.getline(med, s, '\n');
            load.getline(race, s, '\n');
            load.ignore(s, '\n');
            counter ++;

            addEdge(counter, counter+1, county, age, med, race);
        }

    }
    load.close();    

    


}

void graph::addEdge(int s, int d, char * c,  char * a, char * r, char * m)
{
    adjListNode * newNode = new_adjListNode(d,c, a, r, m);
    newNode->getNext() = arrayList[s].returnHead();
    arrayList[s].returnHead() = newNode;

    newNode = new_adjListNode(s,c, a, r, m);
    newNode->getNext() = arrayList[s].returnHead();
    arrayList[d].returnHead() = newNode;
}

void graph::printGraph()
{
    for(int i = 0; i < vertex; i++)
    {
        
        adjListNode * temp = arrayList[i].returnHead();
        cout << "List of vertex at " << i << endl;
        while(temp)
        {
            cout  << "At edge " << temp->getDest() << " ";
            cout << endl;
            temp->display();
            temp = temp->getNext();

         }
            cout << endl;
    }
}



