/*
 * Michael Cheng
 * CS 202 Homework 1
 * Winter 2016
 *
 * node_dll.h
 *
 * Holds class abstraction for doubly linked list. This node_dll is
 * dervied from school_infomration, which contains dynamic data for
 * incoming school information.
 *
 */


//Class abstraction for school information
class School_information
{
    private:
        char * school_name;
        char * age_group;
        char * number_of_classes;
        char * best_class_size;
        char * age_group_best;
    public:
        School_information();
        School_information(const School_information &);
        School_information(char * s, char * a, char * n, char * b, char * ag);
        ~School_information();
        void display();


};


//class abstraction for a node_dll, that will be used
//in a doubly linked list to store school information 
class node_dll:public School_information
{
    private:
        node_dll*next;
        node_dll*prev;

    public:
        node_dll();
        node_dll(const node_dll &);
        node_dll(const School_information &);
        node_dll(char * s, char * a, char * n, char * b, char * ag);
        ~node_dll();
        node_dll*&get_next();
        node_dll*&get_prev();

};
