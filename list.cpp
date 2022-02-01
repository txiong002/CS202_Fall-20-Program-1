//list.cpp
//File for all the list functions

#include "relief.h"

using namespace std;

//=====================CONSTRUCTOR AND DESTRUCTOR=======================
relief_list::relief_list():rear(NULL),rear2(NULL),rear3(NULL)
{

}

relief_list::~relief_list()
{
    if(rear){
        delete_all();
    }
    if(rear2){
        delete_all_2();
    }
    if(rear3){
        delete_all_3();
    }
}

search_list::search_list():head(NULL) {}

search_list::~search_list()
{
   if(head){
       delete_all();
   }
}

//==============RELIEF LIST FUNCTIONS============================

//void relief_list::add_items(const hNode * to_add)
void relief_list::add_items(hNode & to_add)
{
    //Add to empty list
    if(rear == NULL){

        rear = new hNode(to_add);
        rear->connect_next(rear);
        return;
    }
   
    //Insert at rear of list
    hNode * temp = new hNode(to_add);
    temp->connect_next(rear->get_next());
    rear->connect_next(temp);
    rear = temp;
    return; 

} 

void relief_list::display() const
{
    if(!rear) return;

    return display(rear->get_next(), rear);

}

void relief_list::display(hNode * curr, hNode * rear) const
{
    if(curr == rear){
        curr->display();
        cout << endl;
        return;
    }

    curr->display();
    cout << endl;

    return display(curr->get_next(), rear);
}

void relief_list::add_items(fNode & to_add)
{
    //Add to empty list
    if(rear2 == NULL){

        rear2 = new fNode(to_add);
        rear2->connect_next(rear2);
        return;
    }
   
    //Insert at rear of list
    fNode * temp = new fNode(to_add);
    temp->connect_next(rear2->get_next());
    rear2->connect_next(temp);
    rear2 = temp;
    return; 

} 

void relief_list::display2 () const
{
    if(!rear2){
        
        cout << "No items in inventory." << endl;
        return;
    }

    return display(rear2->get_next(), rear2);

}

void relief_list::display(fNode * curr, fNode * rear) const
{
    if(curr == rear2){
        curr->display();
        cout << endl;
        return;
    }

    curr->display();
    cout << endl;

    return display(curr->get_next(), rear2);
}

void relief_list::add_items(sNode & to_add)
{
    //Add to empty list
    if(rear3 == NULL){

        rear3 = new sNode(to_add);
        rear3->connect_next(rear3);
        return;
    }
   
    //Insert at rear of list
    sNode * temp = new sNode(to_add);
    temp->connect_next(rear3->get_next());
    rear3->connect_next(temp);
    rear3 = temp;
    return; 

} 

void relief_list::display3() const
{
    if(!rear3) return;

    return display(rear3->get_next(), rear3);

}

void relief_list::display(sNode * curr, sNode * rear) const
{
    if(curr == rear3){
        curr->display();
        cout << endl;
        return;
    }

    curr->display();
    cout << endl;

    return display(curr->get_next(), rear3);
}

void relief_list::delete_all()
{
    if(rear->get_next() == this->rear){

        delete rear;
        rear = NULL;
        return;
    }
    
    delete_all(rear->get_next());
}

void relief_list::delete_all(hNode * curr)
{
    if(curr == this->rear){

        delete rear;
        rear = NULL;
        return;
    }

    hNode * trail = curr;
    curr = curr->get_next();
    delete trail;
    trail = curr;

    delete_all(curr);
}

void relief_list::delete_all_2()
{
    if(rear2->get_next() == this->rear2){

        delete rear2;
        rear2 = NULL;
        return;
    }
    
    delete_all(rear2->get_next());
}

void relief_list::delete_all(fNode * curr)
{
    if(curr == this->rear2){

        delete rear2;
        rear2 = NULL;
        return;
    }

    fNode * trail = curr;
    curr = curr->get_next();
    delete trail;
    trail = curr;

    delete_all(curr);
}

void relief_list::delete_all_3()
{
    if(rear3->get_next() == this->rear3){

        delete rear3;
        rear3 = NULL;
        return;
    }
    
    delete_all(rear3->get_next());
}

void relief_list::delete_all(sNode * curr)
{
    if(curr == this->rear3){

        delete rear3;
        rear3 = NULL;
        return;
    }

    sNode * trail = curr;
    curr = curr->get_next();
    delete trail;
    trail = curr;

    delete_all(curr);
}

int relief_list::remove_expired(char * to_check)
{
    bool match;
    int count = 0;
    
    if(!rear2) return 0;
    
    if(rear2->get_next() == this->rear2){

        match = rear2->compare_date(to_check);

        if(match){
            
            delete rear2;
            rear2 = NULL;
            ++count;
        }
    }
    count = remove_expired(rear2->get_next(), rear2, rear2, to_check);
    return count;
}

int relief_list::remove_expired(fNode * curr, fNode * trail, fNode *& rear2, char * to_check)
{
    bool match;

    match = curr->compare_date(to_check);

    if(curr == rear2){

        if(match){

            trail->connect_next(rear2->get_next());
            rear2 = trail;
            delete curr;
            curr = NULL;

            return 1;
        }
        return 0;
    }
    
    if(match){
        
        fNode * temp = curr;
        curr = curr->get_next();
        trail->connect_next(curr);
        delete temp;
        temp = NULL;
        
        return remove_expired(curr, rear2, rear2, to_check) + 1;
    }
    
    return remove_expired(curr->get_next(), trail->get_next(), rear2, to_check);
}

//==========================SEARCH LIST FUNCTIONS=================================
void search_list::find_item(char * to_find)
{
    bool match;

    if(!head){
        
        cout << "Item not in list. Adding to list." << endl;
        add_search_item(to_find);
        
        return;
    }
    
    if(head->get_next() == NULL){

        match = head->compare_item(to_find);
        
        if(match){

            cout << "Item found!!!" << endl;
            return;
        }
        
        cout << "Item not in list. Adding to list." << endl;
        add_search_item(to_find);
        
        return;
    }
    
    return find_item(head,to_find);

}

void search_list::find_item(searchNode * head, char * to_find)
{
    bool match;

    if(head == NULL){

        cout << "Item not in list.  Will add to list." << endl;
        add_search_item(to_find);
        return;
    }

    match = head->compare_item(to_find);

    if(match){

        cout << "Item found!!!" << endl;
        return;
    }

    return find_item(head->get_next(), to_find);

}

void search_list::add_search_item(char * to_add)
{
    if(!head){

        head = new searchNode(to_add);
        head->get_next() = NULL;
        return;
    }
    searchNode * temp = new searchNode(to_add);
    temp->get_next() = head;
    head = temp;

    return;
}

void search_list::display() const
{

    if(!head) return;
    
    cout << "\nSearch History\n====================\n";

    if(head->get_next() == NULL){

        head->display();
        return;
    }
    return display(head);
}

void search_list::display(searchNode * head) const
{
    if(!head) return;

    head->display();

    display(head->get_next());
}

void search_list::delete_all()
{
    if(head->get_next() == NULL){

        delete head;
        head = NULL;
        return;
    }

    return delete_all(head);
}

void search_list::delete_all(searchNode * head)
{
    if(head->get_next() == NULL){

        delete head;
        head = NULL;
        return;
    }
    searchNode * temp = head->get_next();
    delete head;
    head = temp;

    delete_all(head);
}
