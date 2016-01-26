/*
 * Michael Cheng
 * CS 202 Homework 1 
 * Winter 2016
 *
 * graph.cpp, implementation of prototypes from
 * adjListNode.h. In this abstraction of an
 * adjaceny list, each node will be an abstraction of
 * average house hold infomration per that county, which is a node.
 * the node will be inserted base on 2 gps cordinates, which will be 
 * presented by an array. Thus this will be an array of linear linked list.
 * AdjlistNode is a household information plus more, adjlist has a adjlist 
 * node and my class graph (which is the location class) will have an array
 * of adjlist head pointers .
 *
 */

#include"adjListNode.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdlib>
using namespace std;

/*
 *  Household_inforation implementations
 *
 */


//Constructor with an intialization list to intialize copy constructor dynamic memory 
Household_information::Household_information():county(NULL),age_group_information(NULL),races(NULL),med_income(NULL)
{

}


//Copy constructor
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


//Copy constructor that takes in a Hosehold_information object. Has if statements 
//to prevent from copying something that is not there
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


//destructor, deallocate memory 
Household_information::~Household_information()
{
    delete [] county;
    delete [] age_group_information;
    delete [] races;
    delete [] med_income;
}


//display out contents of the household_infomration
void Household_information::display()
{
    cout << county<< endl;
    cout << age_group_information <<endl;
    cout << races << endl;
    cout << med_income << endl;
    return;
}


/*
 * Household_informated implementation end
 *
 */


/*
 * adjListNode implementation
 *
 */


//default constructor, intialized dest to 0 and next pointer to null
adjListNode::adjListNode()
{
	dest = 0;
	next = NULL;
}


//copy constructor, calls the baseclass intialization life
adjListNode::adjListNode(char * c, char * a, char * r, char * m):Household_information(c,a,r,m)
{

}


//copy constructor that passes an object of household information up to the base class copy consturctor
//to copy in dynamic memory 
adjListNode::adjListNode(const Household_information & to_copy):Household_information(to_copy)
{

}


//destructor
adjListNode::~adjListNode()
{
    if(next != NULL)
    {
        delete next;
        next = NULL;

    }

}


//return a pointer to the address of next pointer, allows other function to obtain
//or set values of whatever next is pointed too. next here is a private member 
adjListNode*&adjListNode::getNext()
{
	return next;
}


//set destination when inserting household object into the graph
void adjListNode::setDest(int d)
{
    dest = d;
}


//return the value of destination
int adjListNode::getDest()
{
    return dest;

}


/*
 * AdjlistNode implementation End
 *
 */


/* 
 * AdjList implemetnation
 *
 */


//Constructuor
adjList::adjList()
{
	head = NULL;
}


//Destructor
adjList::~adjList()
{

}


//Set the value of head to null, used for intialization purposes within the 
//graph class, which is a "has a" reletionship with this adjlist class
void adjList::setHead()
{
    head = NULL;

}


/*
 * Adjlist impelmentedation end
 *
 */


/*
 * Graph impelmentation start
 *
 */


//default constructor, constrcutrs an array of headpointers size 10,
//then calls on the sethead function to set each function of head to null
graph::graph()
{
    vertex = 10;
    arrayList = new adjList[vertex];

	for(int i = 0; i < vertex; i++)
	{
		arrayList[i].setHead();
	}

}


//destructor, calls on the remove_all fuction to delete this array of head pointers 
graph::~graph()
{
    remove_all();
}


//used in destrutor, iterate through all elements of array and set each head pointer to null
//then delete the array
void graph::remove_all()
{
    for(int i = 0; i < 10; i++)
    {
        arrayList[i].setHead();
    }
    delete [] arrayList;



}


//returns the data value in head
adjListNode*&adjList::returnHead()
{
    return head;

}


//creates and return a new adjlistnode, with information that will be loaded from txt
adjListNode * graph::new_adjListNode(int dest, char * c, char * a, char * r, char * m)
{
    adjListNode *newDataNode = new adjListNode(c, a, r, m);
    newDataNode->setDest(dest);
    newDataNode->getNext()=NULL;

    return newDataNode;

}


//build the graph of household. county household infomration will be inserted in random order
void graph::g_setUp(int counter, char * c, char * a, char * r, char * m)
{
    int randCord = rand() % 4;
    addEdge(counter, randCord, c, a, r, m); 

}


//load househould infomration from c.txt thhen inserts it into the adjacney list
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
            //counter will be the source and counter +1 will be the denstiation 
            addEdge(counter, counter+1, county, age, med, race);
        }

    }
    load.close();    

    


}


//adding edge, takes in source, destintation as gps coordinates and dynamic char arrays
//as infomration for the average household in the county 
void graph::addEdge(int s, int d, char * c,  char * a, char * r, char * m)
{
    adjListNode * newNode = new_adjListNode(d,c, a, r, m);
    newNode->getNext() = arrayList[s].returnHead();
    arrayList[s].returnHead() = newNode;

    newNode = new_adjListNode(s,c, a, r, m);
    newNode->getNext() = arrayList[s].returnHead();
    arrayList[d].returnHead() = newNode;
}


//crawls through the array of head pointers and prints everything in each elements
//and also prints everything that is assoicated with each node within that array index
void graph::printGraph()
{
    for(int i = 0; i < vertex; i++)
    {
        
        adjListNode * temp = arrayList[i].returnHead();
        cout << "List of vertex at " << i << "------------------------------" << endl;
        while(temp)
        {
            cout  << "At edge " << temp->getDest() << " ";
            cout << endl;
            temp->display();
            temp = temp->getNext();

         }
            cout << endl;
    }
    return;
}


/*
 * Graph implementation end
 *
 */
