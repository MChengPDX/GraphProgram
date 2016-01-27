/*
 * Michael Cheng
 * CS 202 Winter 2016
 * Homework 1
 *
 * manager.h
 *
 * Includes school.h
 *
 * Holds prototypes to test functions for loading, deleting and displaying data
 *
 */


#include"school.h"


//class manager, derive from a school.
//In terms of princple, which is the manager of the school, a manager
//is its school plus more.
class manager: public school
{
    public:
        void testLoadHouseHold();
        void testLoadSchool();
        void findSchool();
        void testDelete();

};
