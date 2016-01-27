
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

void school::remove_all()
{
    node_dll * current = head;
    while(current != NULL)
    {
        current = current -> get_next();
        delete head;
        head = current;

    }

    //head->get_next() = NULL;
    //head->get_prev() = NULL;
}

/*
void school::remove_all(node_dll * head)
{
    if(!head)
    {
        head = NULL;
        return;
    }
    else
    {
        remove_all(head->get_next());
        delete(head);
    }

}
*/

int school::return_lenght()
{
    int counter = 1;
    node_dll * current = head;

    while(current->get_next() != NULL)
    {
        current = current -> get_next();
        counter = counter + 1;
    }
    using std::cout;

    return counter;
}

void school::search_3_school()
{
    int counter = 1;
    node_dll * current = head;
    while(current != NULL && counter != 4)
    {
        current->display();
        current = current->get_next();
        counter++;
    }
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
    if(!head)
    {
        cout << "No data here" << endl;
        return;
    }
    node_dll*current = head;
    while(current!=NULL)
    {
        current->display();
        current = current->get_next();

    }
}

void school::remove_one(int position)
{
    int lenght = return_lenght();
    if(position > lenght)
    {
        cout << "The postion to delete is out of context " << endl;
    }
    else
    {
        node_dll * temp = head;
        int counter = 1;
        while(counter != position)
        {
            temp->display();
            temp = temp -> get_next();
            counter +=1;
        }
        cout << "This node will be deleted " << endl;
        temp ->display();
        if(temp->get_next() == NULL)
        {
            node_dll * temp2 = temp->get_prev();
            delete temp;
            temp2->get_next() = NULL;
            return;
        }
        if(temp->get_prev() == NULL)
        {
            node_dll * temp2 = temp->get_next();
            delete temp;
            head = temp2;
            return;
        }
        else
        {
            node_dll * back = temp->get_prev();
            back->get_next() = temp->get_next();
            delete temp;
        }
    }

}