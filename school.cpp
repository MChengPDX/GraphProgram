/*
 * Michael Cheng
 * CS 202 Winter 2016
 * Homework 1
 *
 * school.cpp
 *
 * Holds implementation to school.h. School class is dervied from base class graph, which is an
 * abstraction of a map, in which every node is a county with household information. This school class
 * has a reletionship with a doubly linked data structure, which will be used to hold school infomration
 *
 */


#include"school.h"
#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;


//Constructor, setting head to NULL
school::school()
{

    head = NULL;

}


//desturctor, calls the remove function to deallcaote all dynamic
//memory that was used to load in school data
school::~school()
{
    remove_all();

}



//remove all data from a doubly linked list.
void school::remove_all()
{
    node_dll * current = head;
    //delete till there is nothing left
    while(current != NULL)
    {
        current = current -> get_next();
        delete head;
        head = current;

    }
    //set head back to nukk
    head = NULL;
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


//return the lenght of the linked list. used in remove-one function
//to determine where to delete within the linear linked list
int school::return_lenght()
{
    int counter = 1;
    node_dll * current = head;

    while(current->get_next() != NULL)
    {
        current = current -> get_next();
        counter = counter + 1;
    }

    return counter;
}


//returns the best three school in the area to match the house hold
//census information
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


//insert school infomration into dyanmic memory. Pushes this object all the wayy
//up to the school_infomration based class
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


//Load school informatiion from txt. Uses the fstream
//library
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


//Display all data within the linked list structure.
//Case 1: if there is no data, cout no data 
//case 2: display all the data
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


//remove from the doubly linked list
//case 1: if the input is not in the list
//case 2: removing from the head
//case 3: removing from the midddle
//case 4: removing from the end
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
        //delete at the end 
        if(temp->get_next() == NULL)
        {
            node_dll * temp2 = temp->get_prev();
            delete temp;
            temp2->get_next() = NULL;
            return;
        }
        //delete at the head
        if(temp->get_prev() == NULL)
        {
            node_dll * temp2 = temp->get_next();
            delete temp;
            head = temp2;
            return;
        }
        //else we are deleting in the middle
        else
        {
            node_dll * back = temp->get_prev();
            back->get_next() = temp->get_next();
            delete temp;
        }
    }

}
