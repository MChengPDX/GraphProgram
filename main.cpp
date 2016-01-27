/*
 * Michael Cheng
 * CS 202 Homework 1 
 * Winter 2016
 *
 * Main.cpp
 *
 * The purpose of this program is to load a list of census household information into a graph data
 * structure, adjacenecy list, then schools data into a doubly linked list. Base class household information,
 * then a adjlistnode is dervied from this class. A Graph has an array of head pointers, a School claass is dervied from
 * this graph class, it also has a head pointer to a doubly linked list. That node doubly linked list is derived from
 * a base class school infomration.
 *
 * Utimately manager is dervied from school, to test all the funcntion.
 */


#include"manager.h"


//main function that calls on the manager class to test the implemented functions
int main()
{
    manager m;
    m.testLoadHouseHold();
    m.testLoadSchool();
    m.findSchool();
    m.testDelete();


}
