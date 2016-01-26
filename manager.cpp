/*
 * Michael Cheng
 * CS 202 Homework 1 
 * Winter 2016
 *
 * adjListNode.h
 *
 */
#include"manager.h"
#include<iostream>


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

