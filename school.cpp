#include"school.h"
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
school::school()
{

    head = NULL;

}

school::~school()
{

}

void school::insert_school(char * a, char * b, char * c, char * d, char * e)
{
    node_dll * temp = new node_dll(a,b,c,d,e);
    temp->get_next()=NULL;
    temp->get_prev()=NULL;
    if(!head)
    {
        head = temp;
    }
    else
    {
        node_dll * current = head;
        while(current->get_next() != NULL)
        {
            current = current -> get_next();

        }
        current ->get_next() = temp;
        temp->get_prev() = current;

       
    }

}

void school::load_s()
{
    using namespace std;
    int SIZE = 1000;
    char school[SIZE], age[SIZE], classnum[SIZE],
         bestsize[SIZE], bestage[SIZE];

    ifstream load;
    load.open("s.txt");
    if(load)
    {
        while(!load.eof())
        {
            load.getline(school,SIZE,'\n');
            load.getline(age,SIZE,'\n');
            load.getline(classnum,SIZE,'\n');
            load.getline(bestsize,SIZE,'\n');
            load.getline(bestage,SIZE,'\n');
            load.ignore(SIZE, '\n');

            insert_school(school, age, classnum, bestsize, bestage);

        }

    }
    load.close();
}

void school::display_all()
{
    head->display();
    node_dll*current = head;
    while(current!=NULL)
    {
        current->display();
        current = current->get_next();

    }
}

