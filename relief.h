//relief.h
//this files contains all the .h files

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

class relief
{
    public:
        relief();
        relief(const relief & to_copy);
        ~relief();

        void display() const;
        void read();
        void add_relief();
        void remove_relief();
        void change_date();
            
    protected:
        char * relief_type;
        char * date;

};

class address
{
    public:
        address();
        address(char * street, char * zip);
        address(const address & to_copy);
        ~address();
        void display() const;
        void read();
        void change_address(char * new_street, char * new_zip);
        void set_address(char * new_street, char * new_zip);
        char * get_street();
        char * get_zip();

    protected:
        char * street;
        char * zip;
};

class housing: public relief
{
    public:
        housing();
        //housing(const housing & to_copy);
        housing(housing & to_copy);
        ~housing();

        void display() const;
        void read();
        void change_room();
        void change_address(char * new_city, char * new_zip);

    protected:
        int num_of_rooms;
        bool is_avail;
        address my_address;

};

class food: public relief
{
    public:
        food();
        food(const food &);
        ~food();

        void display() const;
        void read();
        bool compare_date(char *);

    protected:
        char * food_type;
        char * exp_date;
        int quantity;

};

class supplies: public relief
{
    public:
        supplies();
        supplies(const supplies &);
        ~supplies();

        void display() const;
        void read();

    protected:
        char * supply_type;
        int quantity;

};

class search_item
{
    public:
        search_item();
        search_item(const search_item &);
        search_item(char *);
        ~search_item();

        void display() const;
        void read();
        bool compare_item(char * to_find);

    protected:
        char * item;
        int count;
};

//====================NODE CLASS====================================//

//housing node
class hNode: public housing
{
    public:
        hNode();
        hNode(hNode & to_copy);
        ~hNode();

        hNode *& get_next();
        void connect_next(hNode * connect);
        void display () const;
        void read();

    protected:
        hNode * next;

};

// food node
class fNode: public food
{
    public:
        fNode();
        fNode(const fNode &);
        ~fNode();

        fNode *& get_next();
        void connect_next(fNode * connect);
        void display() const;
        void read();

    protected:
        fNode * next;

};

// supplies node
class sNode: public supplies 
{
    public:
        sNode();
        sNode(const sNode &);
        ~sNode();

        sNode *& get_next();
        void connect_next(sNode * connect);
        void display() const;
        void read();

    protected:
        sNode * next;

};

//search item node
class searchNode: public search_item
{
    public:
        searchNode();
        searchNode(const searchNode &);
        searchNode(char *);
        ~searchNode();

        searchNode *& get_next();
        void connect_next(searchNode * connect);
        void display () const;
        void read();

    protected:
        searchNode * next;
};

//===================LIST CLASS=====================================//

//Circular linked list to manage the relief types
//containes 3 rear pointer to allow me to manage 3 different list
class relief_list
{
    public:
        relief_list();
        ~relief_list();

        //housing node functions
        void display() const;
        void add_items(hNode & to_add);
        //void remove_items();
        void delete_all();

        //food node functions
        void add_items(fNode & to_add);
        void display2() const;
        void delete_all_2();
        int remove_expired(char *);

        //supplies node functions
        void add_items(sNode & to_add);
        void display3() const;
        void delete_all_3();

    protected:
        //housing node
        hNode * rear;
        void display(hNode * curr, hNode * rear) const;
        void delete_all(hNode * curr);

        //food node
        fNode * rear2;
        void display(fNode * curr, fNode * rear) const;
        void delete_all(fNode * curr);
        int remove_expired(fNode *, fNode *, fNode *&, char *);

        //supplies node
        sNode * rear3;
        void display(sNode * curr, sNode * rear) const;
        void delete_all(sNode * curr);

};

// List to keep track of searched items
class search_list
{
    public:
        search_list();
        ~search_list();

        void display() const;
        void add_search_item(char *);
        void find_item(char *);
        void delete_all();
        
    protected:
        searchNode * head;
        void find_item(searchNode *, char *);
        void display(searchNode *) const;
        void delete_all(searchNode *);

};
