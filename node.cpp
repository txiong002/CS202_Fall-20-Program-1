//node.cpp
//File for all the node functions

#include "relief.h"

//======================HOUSING NODE============================
hNode::hNode():next(NULL){}

//hNode::hNode(const hNode & to_copy):housing(to_copy)
hNode::hNode(hNode & to_copy):housing(to_copy)
{
   next = to_copy.next; 
}

hNode::~hNode()
{

}

hNode *& hNode::get_next()
{
    return this->next;
}

void hNode::connect_next(hNode * connect)
{
    this->next = connect;
    return;
}

void hNode::read()
{
    relief::read();
    housing::read();

    return;
}

void hNode::display () const
{
    relief::display();
    housing::display();

    return;
}

//==========================FOOD NODE=======================
fNode::fNode():next(NULL){}

fNode::fNode(const fNode & to_copy):food(to_copy)
{
   next = to_copy.next; 
}

fNode::~fNode()
{

}

fNode *& fNode::get_next()
{
    return this->next;
}

void fNode::connect_next(fNode * connect)
{
    this->next = connect;
    return;
}

void fNode::read()
{
    relief::read();
    food::read();

    return;
}

void fNode::display () const
{
    relief::display();
    food::display();

    return;
}

//======================SUPPLIES NODE==========================
sNode::sNode():next(NULL){}

sNode::sNode(const sNode & to_copy):supplies(to_copy)
{
   next = to_copy.next; 
}

sNode::~sNode()
{

}

sNode *& sNode::get_next()
{
    return this->next;
}

void sNode::connect_next(sNode * connect)
{
    this->next = connect;
    return;
}

void sNode::read()
{
    relief::read();
    supplies::read();

    return;
}

void sNode::display () const
{
    relief::display();
    supplies::display();

    return;
}

//====================SEARCH ITEM NODE==========================
searchNode::searchNode():next(NULL) {}

searchNode::searchNode(const searchNode & to_copy):search_item(to_copy)
{
    next = to_copy.next;
}

searchNode::searchNode(char * to_add):search_item(to_add)
{

}

searchNode::~searchNode() {}

searchNode *& searchNode::get_next()
{
    return this->next;
}

void searchNode::connect_next(searchNode * connect)
{
    this->next = connect;
    return;
}

void searchNode::read()
{
    search_item::read();
    return;
}

void searchNode::display() const
{
    search_item::display();
    return;
}

