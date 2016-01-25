

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

//Location Class
class graph
{
private:
	int vertex;
	adjList * arrayList;
public:
    graph();
	~graph();
	adjListNode * new_adjListNode(int dest,char * c, char * a, char * r, char * m);
	void addEdge(int s, int d,char * c, char * a, char * r, char * m);
	void printGraph();
    void h_load(); 
    void g_setUp(int counter, char * c, char * a, char * r, char * m);
};

