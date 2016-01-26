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

int main()
{
    manager m;
    m.testLoadHouseHold();
    m.testLoadSchool();
    m.findSchool();


}