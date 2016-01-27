/*
 * Michael Cheng
 * CS 202 Homework 1 
 * Winter 2016
 *
 * manager.cpp
 *
 * Holds implementation from prototypes in manager.h. In this manager
 * class, it will provide test functions to see if txt files are loaded properly,
 * to see if removes and display functions are loaded properly
 *
 */
 
 
#include"manager.h"
#include<iostream>

/*
 * Manager Implementation Start
 *
 */

//Test function to check oif household information is loaded into the graph
void manager::testLoadHouseHold()
{
    using std::cout;
    using std::endl;
    
    school o;
    o.h_load(); //loading school infomration
    cout << "---------------------Displaying Household information--------------------";
    cout << endl;
    cout << endl;
    o.printGraph();
    

}


//Test function to test if schools are loaded into the doubly linked list
void manager::testLoadSchool()
{
    using std::cout;
    using std::endl;
    
    school o;
    o.load_s(); //loading household infomration
    cout << "---------------------Displaying School Information------------------------";
    cout << endl;
    cout << endl;
    o.display_all();
}


//Function to find the top 3 schools that fits in with the current household cencus
//information
void manager::findSchool()
{
    using std::cout;
    using std::endl;
    
    school o;
    o.load_s();
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "---Searching for the top 3 best school that will best fit these households--" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << endl;
    o.search_3_school();
}


//Testing deleting from doubly linked list. 
//case 1 remove from head
//case 2 remove from somewhere in the middle
//case 3 remove a node from the end
void manager::testDelete()
{
    using std::cout;
    using std::endl;
    
    school o;
    
    o.load_s();
    
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "--------------------Testing remove cases from DLL---------------------------" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    
    cout << "========= Testing removing from the beginning of the list ============" << endl;
    o.remove_one(1);
    cout << "============== Displaying afther removing head ================" << endl;
    o.display_all();
    
    cout << "============= Testing removing from the middle of the list ==============" << endl;
    o.remove_one(2);
    cout << "============== Displaying after removing something in the middle ===============" << endl;
    o.display_all();
    
    cout <<"====== Testing removing after the end of the list =========================" << endl;
    o.remove_one(3);
    cout << "=========== Displaying after removing at the end ======================" << endl;
    o.display_all();

    o.remove_all();
    cout << "====================== Displaying after removing all =================" << endl;
    o.display_all();
}

/*
 * Manager class implementation end
 *
 */

