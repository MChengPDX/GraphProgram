#include"node_dll.h"
#include"adjListNode.h"

class school:public graph
{
    private:
        node_dll * head;
    public:
        school();
        ~school();
        void display_all();
        void load_s();
        void insert_school(char * school, char * age, char * class_num, char *  bestsize, char * bestage);
        void remove_all(node_dll * head);
        void remove_all();
        void remove_one(int position);
        int return_lenght();
        void search_3_school();

};
