/*
 * Michael Cheng
 * CS 202 Homework 1 
 * Winter 2016
 *
 * node_dll.cpp
 * 
 * Implements function prototypes in node_dll.h
 * School_information class is the base class for node_dll,
 * essentially a a node_dll is a school plus more.
 * Class school will be using thhis node_dll. The reletionship that school
 * will have with node_dll is a has a relationship, since within a county
 * of school, it will have many schools, each individual school is
 * represented by nodes.
 * 
 */


#include"node_dll.h"
#include<iostream>
#include<cstring>


/*
 * School_inforomation class implementation
 *
 */


//Default constructor, intialized all dynamic memory with an
//intialization list. Setting them to the value of NULL
School_information::School_information():school_name(NULL),age_group(NULL),
    number_of_classes(NULL),best_class_size(NULL), age_group_best(NULL)
{

}


//Copy constructuor, takes in an object of school_information and 
//performs a deep copy. Any dynamic memory pointed to by the
//data memeber is duplicated and the contents of that memory is copy
School_information::School_information(const School_information & from)
{
    if(from.school_name)
    {
        school_name = new char[(strlen(from.school_name)+1)];
        strcpy(school_name, from.school_name);
    }
    if(from.age_group)
    {
        age_group = new char[(strlen(from.age_group)+1)];
        strcpy(age_group, from.age_group);
    }
    if(from.number_of_classes)
    {
        number_of_classes = new char[(strlen(from.number_of_classes)+1)];
        strcpy(number_of_classes, from.number_of_classes);
    }
    if(from.best_class_size)
    {
        best_class_size = new char[(strlen(from.best_class_size)+1)];
        strcpy(best_class_size, from.best_class_size);
    }
    if(from.age_group)
    {
        age_group_best = new char[(strlen(from.age_group_best)+1)];
        strcpy(age_group_best, from.age_group_best);
    }
}


//constructor that takes in dynamic memory 
School_information::School_information(char * s, char * a, char * n,
        char * b, char * ag)
{
    school_name = new char[(strlen(s)+1)];
    strcpy(school_name, s);

    age_group = new char[(strlen(a)+1)];
    strcpy(age_group, a);

    number_of_classes = new char[(strlen(n)+1)];
    strcpy(number_of_classes, n);

    best_class_size = new char[(strlen(b)+1)];
    strcpy(best_class_size, b);

    age_group_best = new char[(strlen(ag)+1)];
    strcpy(age_group_best, ag);


}


//destructor deallcationg memory that was use 
//to store school infomration
//
//reminder: add if statements 
School_information::~School_information()
{
   delete [] school_name;
   delete [] age_group;
   delete [] number_of_classes;
   delete [] best_class_size;
   delete [] age_group_best;
}


//displaying out the school information
//using std cout and endl for good programming practice
//avoid taking up the whole namespace 
void School_information::display()
{
    using std::cout;
    using std::endl;

    cout <<school_name<<endl;
    cout<<age_group<<endl;
    cout<<number_of_classes<<endl;
    cout<<best_class_size<<endl;
    cout<<age_group_best<<endl;
    cout<<endl;
    return;

}

/*
 * End of class school_information implementation 
 *
 */


/*
 * class  node_dll implementation
 * Will be used in class school, which will
 * represent a doubly linked list abstraction to
 * store school infomration
 *
 */


//constructor for node_dll
//sets next and prev to nnull
node_dll::node_dll()
{
    next = NULL;
    prev = NULL;

}


//destructor for node_dll
node_dll::~node_dll()
{

}


//copy  constructor, pushes up the object to the base class
node_dll::node_dll(const node_dll & object):School_information(object)
{


}


//calls on the school base class copy constructor
node_dll::node_dll(const School_information & object):School_information(object)
{

}


//copying dynamic memory to base class
node_dll::node_dll(char *s, char * a, char * n, char * b, char * ag):School_information(s, a, n, b, ag)
{

}


//return the value of next for traversal of the list
node_dll*&node_dll::get_next()
{
    return next;

}


//return previous value 
node_dll*&node_dll::get_prev()
{
    return prev;
}

/*
 * End of node_dll implementation
 *
 */
