/*
 * Michael Cheng
 * CS 202 Homework 1 
 * Winter 2016
 *
 * adjListNode.h
 * househould_infomration will be the base class for adjListnode. In adjlist, it has a adjlistnode
 * and class graph with is an abstraction of my "city" will have an array of adjlist head pointers 
 *
 */

//Class Household_information, base class
class Household_information
{
    private:
        char * county;
        char * age_group_information;
        char * races;
        char * med_income;
    public:
        Household_information();
        Household_information(char * co, char * age, char * ra, char * med);
        Household_information(const Household_information &);
        ~Household_information();

        void display();

};


//class adjlistnode, dervied from household_infomration
class adjListNode:public Household_information
{
private:
	int dest;
	adjListNode * next;
public:
	adjListNode();
	adjListNode(char * c, char * a, char * r, char * m);
	adjListNode(const Household_information &);
	~adjListNode();
	adjListNode*&getNext();
    void setDest(int dest);
    int getDest();
};


//class adjlist, has an adjListNode
class adjList
{
private:
	adjListNode * head;
public:
	adjList();
	~adjList();
    void setHead();
    adjListNode*&returnHead();
};


//class graph, a location abstraction, with the data structure adjacency list
class graph
{
private:
	int vertex;
	adjList * arrayList;
public:
    graph();
	~graph();
    void remove_all();
	adjListNode * new_adjListNode(int dest,char * c, char * a, char * r, char * m);
	void addEdge(int s, int d,char * c, char * a, char * r, char * m);
	void printGraph();
    void h_load(); 
    void g_setUp(int counter, char * c, char * a, char * r, char * m);
};


