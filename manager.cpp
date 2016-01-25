/*
 * Michael Cheng
 * CS 202 Homework 1 
 * Winter 2016
 *
 * adjListNode.h
 *
 */
#include"school.h"

int main()
{
    
    school s;
    s.load_s();
    s.display_all();
    s.h_load();
    s.printGraph();
    s.remove_all();
    s.display_all();
    return 0;
}
