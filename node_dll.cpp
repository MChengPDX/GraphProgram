#include"node_dll.h"
#include<iostream>
#include<cstring>

School_information::School_information():school_name(NULL),age_group(NULL),
    number_of_classes(NULL),best_class_size(NULL), age_group_best(NULL)
{


}

School_information::School_information(const School_information & from)
{
    school_name = new char[(strlen(from.school_name)+1)];
    strcpy(school_name, from.school_name);

    age_group = new char[(strlen(from.age_group)+1)];
    strcpy(age_group, from.age_group);

    number_of_classes = new char[(strlen(from.number_of_classes)+1)];
    strcpy(number_of_classes, from.number_of_classes);

    best_class_size = new char[(strlen(from.best_class_size)+1)];
    strcpy(best_class_size, from.best_class_size);

    age_group_best = new char[(strlen(from.age_group_best)+1)];
    strcpy(age_group_best, from.age_group_best);

}

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

School_information::~School_information()
{


}

void School_information::display()
{
    using std::cout;
    using std::endl;

    cout <<school_name<<endl;
    cout<<age_group<<endl;
    cout<<number_of_classes<<endl;
    cout<<best_class_size<<endl;
    cout<<age_group_best<<endl;

}

node_dll::node_dll()
{
    next = NULL;
    prev = NULL;

}

node_dll::~node_dll()
{

}

node_dll::node_dll(const node_dll & object):School_information(object)
{


}
node_dll::node_dll(const School_information & object):School_information(object)
{

}

node_dll::node_dll(char *s, char * a, char * n, char * b, char * ag):School_information(s, a, n, b, ag)
{

}
node_dll*&node_dll::get_next()
{
    return next;

}

node_dll*&node_dll::get_prev()
{
    return prev;
}
